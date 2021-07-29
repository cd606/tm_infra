using System;
using System.Threading.Tasks;
using System.Collections.Generic;

namespace Dev.CD606.TM.Infra.RealTimeApp
{
    public class Runner<Env> where Env : EnvBase
    {
        private Env env;
        private List<IExternalComponent<Env>> importers = new List<IExternalComponent<Env>>();
        private List<IExternalComponent<Env>> exporters = new List<IExternalComponent<Env>>();
        private List<IExternalComponent<Env>> otherComponents = new List<IExternalComponent<Env>>();
        private object lockObj = new object();

        public Runner(Env env)
        {
            this.env = env;
        }

        public class Source<T>
        {
            public readonly Producer<Env,T> producer;
            public Source(Producer<Env,T> producer)
            {
                this.producer = producer;
            }
        }
        public class Sink<T>
        {
            public readonly IHandler<Env,T> handler;
            public Sink(IHandler<Env,T> handler)
            {
                this.handler = handler;
            }
        }
        public void connect<T>(Source<T> source, Sink<T> sink)
        {
            source.producer.addHandler(sink.handler);
        }
        public Source<T> importItem<T>(AbstractImporter<Env,T> importer)
        {
            lock (lockObj)
            {
                if (!importers.Contains(importer))
                {
                    importers.Add(importer);
                }
            }
            return new Source<T>(importer);
        }
        public Sink<T> exporterAsSink<T>(AbstractExporter<Env,T> exporter)
        {
            lock (lockObj)
            {
                if (!exporters.Contains(exporter))
                {
                    exporters.Add(exporter);
                }
            }
            return new Sink<T>(exporter);
        }
        public void exportItem<T>(AbstractExporter<Env,T> exporter, Source<T> item)
        {
            connect(item, exporterAsSink(exporter));
        }
        public Source<T2> actionAsSource<T1,T2>(AbstractAction<Env,T1,T2> action)
        {
            return new Source<T2>(action);
        }
        public Sink<T1> actionAsSink<T1,T2>(AbstractAction<Env,T1,T2> action)
        {
            return new Sink<T1>(action);
        }
        public Source<T2> execute<T1,T2>(AbstractAction<Env,T1,T2> action, Source<T1> item)
        {
            connect(item, actionAsSink(action));
            return actionAsSource(action);
        }
        public void placeOrderWithFacility<T1,T2>(Source<Key<T1>> source, AbstractOnOrderFacility<Env,T1,T2> facility, Sink<KeyedData<T1,T2>> sink)
        {
            var facilityAdapter = new NonThreadedHandler<Env,Key<T1>>(
                (TimedDataWithEnvironment<Env,Key<T1>> data) => {
                    facility.placeRequest(data, sink.handler);
                }
            );
            lock (lockObj)
            {
                if (!otherComponents.Contains(facility))
                {
                    otherComponents.Add(facility);
                }
                source.producer.addHandler(facilityAdapter);
            }
        }
        public void placeOrderWithFacilityAndForget<T1,T2>(Source<Key<T1>> source, AbstractOnOrderFacility<Env,T1,T2> facility)
        {
            var facilityAdapter = new NonThreadedHandler<Env,Key<T1>>(
                (TimedDataWithEnvironment<Env,Key<T1>> data) => {
                    facility.placeRequestAndForget(data);
                }
            );
            lock (lockObj)
            {
                if (!otherComponents.Contains(facility))
                {
                    otherComponents.Add(facility);
                }
                source.producer.addHandler(facilityAdapter);
            }
        }
        public Source<OutT> execute_2_1<T1,T2,OutT>(AbstractAction2<Env,T1,T2,OutT> action, Source<T1> src) 
        {
            connect(src, actionAsSink2_1(action));
            return actionAsSource2(action);
        }
        public Source<OutT> execute_2_2<T1,T2,OutT>(AbstractAction2<Env,T1,T2,OutT> action, Source<T2> src) 
        {
            connect(src, actionAsSink2_2(action));
            return actionAsSource2(action);
        }
        public Source<OutT> actionAsSource2<T1,T2,OutT>(AbstractAction2<Env,T1,T2,OutT> action)
        {
            return new Source<OutT>(action);
        }
        public Sink<T1> actionAsSink2_1<T1,T2,OutT>(AbstractAction2<Env,T1,T2,OutT> action)
        {
            return new Sink<T1>(action.AsHandler1);
        }
        public Sink<T2> actionAsSink2_2<T1,T2,OutT>(AbstractAction2<Env,T1,T2,OutT> action)
        {
            return new Sink<T2>(action.AsHandler2);
        }
        public void finalize()
        {
            lock (lockObj)
            {
                foreach (var e in exporters)
                {
                    e.start(env);
                }
                foreach (var e in otherComponents)
                {
                    e.start(env);
                }
                foreach (var e in importers)
                {
                    e.start(env);
                }
            }
        }
    }

    public class SynchronousRunner<Env> where Env : EnvBase
    {
        private Env env;
        private HashSet<IExternalComponent<Env>> startedComponents;
        private object lockObj;
        public SynchronousRunner(Env env)
        {
            this.env = env;
            this.startedComponents = new HashSet<IExternalComponent<Env>>();
            this.lockObj = new object();
        }
        private class ResultHolder<T> 
        {
            private TaskCompletionSource<TimedDataWithEnvironment<Env,T>> promise;
            private LinkedList<Task<TimedDataWithEnvironment<Env,T>>> results;
            private object lockObj = new object();

            public ResultHolder()
            {
                promise = new TaskCompletionSource<TimedDataWithEnvironment<Env, T>>();
                results = new LinkedList<Task<TimedDataWithEnvironment<Env, T>>>();
                results.AddLast(new LinkedListNode<Task<TimedDataWithEnvironment<Env, T>>>(
                    promise.Task
                ));
            }
            public void Push(TimedDataWithEnvironment<Env,T> data, bool noNewPromise)
            {
                lock (lockObj)
                {
                    bool final = data.timedData.finalFlag;
                    var oldPromise = promise;
                    if (!final && !noNewPromise)
                    {
                        promise = new TaskCompletionSource<TimedDataWithEnvironment<Env, T>>();
                        results.AddLast(new LinkedListNode<Task<TimedDataWithEnvironment<Env, T>>>(
                            promise.Task
                        ));
                    }
                    oldPromise.SetResult(data);
                }
            }
            public async Task<TimedDataWithEnvironment<Env,T>> Front()
            {
                Task<TimedDataWithEnvironment<Env,T>> task;
                lock (lockObj)
                {
                    task = results.First.Value;
                }
                return await task;
            }
            public async Task<TimedDataWithEnvironment<Env,T>> Back()
            {
                Task<TimedDataWithEnvironment<Env,T>> task;
                lock (lockObj)
                {
                    task = results.Last.Value;
                }
                return await task;
            }
            public void PopFront()
            {
                lock (lockObj)
                {
                    results.RemoveFirst();
                }
            }
            public bool Empty
            {
                get 
                {
                    lock (lockObj)
                    {
                        return results.Count == 0;
                    }
                }
            }
        }
        private class ImporterHandler1<T> : IHandler<Env, T>
        {
            private ResultHolder<T> resultHolder;
            public ImporterHandler1(ResultHolder<T> resultHolder)
            {
                this.resultHolder = resultHolder;
            }
            public void handle(TimedDataWithEnvironment<Env,T> data)
            {
                resultHolder.Push(data, false);
            }
        }
        public async IAsyncEnumerable<TimedDataWithEnvironment<Env,T>> importItem<T>(AbstractImporter<Env,T> importer)
        {
            ResultHolder<T> holder= new ResultHolder<T>();
            lock (lockObj)
            {
                if (startedComponents.Contains(importer))
                {
                    throw new InvalidOperationException(
                        "importer previously started"
                    );
                }
                importer.addHandler(new ImporterHandler1<T>(holder));
                importer.start(env);
                startedComponents.Add(importer);
            }
            while (!holder.Empty)
            {
                yield return await holder.Front();
                holder.PopFront();
            }
        }
        private class ImporterHandler2<T> : IHandler<Env, T>
        {
            private ResultHolder<T> resultHolder;
            private Predicate<TimedDataWithEnvironment<Env,T>> condition;
            private bool alreadySatisfied;
            public ImporterHandler2(ResultHolder<T> resultHolder, Predicate<TimedDataWithEnvironment<Env,T>> condition)
            {
                this.resultHolder = resultHolder;
                this.condition = condition;
                this.alreadySatisfied = false;
            }
            public void handle(TimedDataWithEnvironment<Env,T> data)
            {
                lock (this)
                {
                    if (!alreadySatisfied)
                    {
                        alreadySatisfied = condition(data);
                        resultHolder.Push(data, alreadySatisfied);   
                    }
                }
            }
        }
        public async IAsyncEnumerable<TimedDataWithEnvironment<Env,T>> importItemUntil<T>(
            AbstractImporter<Env,T> importer
            , Predicate<TimedDataWithEnvironment<Env,T>> condition
        )
        {
            ResultHolder<T> holder= new ResultHolder<T>();
            lock (lockObj)
            {
                if (startedComponents.Contains(importer))
                {
                    throw new InvalidOperationException(
                        "importer previously started"
                    );
                }
                importer.addHandler(new ImporterHandler2<T>(holder,condition));
                importer.start(env);
                startedComponents.Add(importer);
            }
            while (!holder.Empty)
            {
                yield return await holder.Front();
                holder.PopFront();
            }
        }
        public async IAsyncEnumerable<TimedDataWithEnvironment<Env,KeyedData<T1,T2>>> placeOrderWithFacility<T1,T2>(
            TimedDataWithEnvironment<Env,Key<T1>> key
            , AbstractOnOrderFacility<Env,T1,T2> facility
        )
        {
            ResultHolder<KeyedData<T1,T2>> holder = new ResultHolder<KeyedData<T1, T2>>();
            if (facility is IExternalComponent<Env>)
            {
                var p = facility as IExternalComponent<Env>;
                lock (lockObj)
                {
                    if (!startedComponents.Contains(p))
                    {
                        p.start(env);
                        startedComponents.Add(p);
                    }
                }
            }
            facility.placeRequest(key, new ImporterHandler1<KeyedData<T1,T2>>(holder));
            while (!holder.Empty)
            {
                yield return await holder.Front();
                holder.PopFront();
            }
        }
        public async IAsyncEnumerable<TimedDataWithEnvironment<Env,KeyedData<T1,T2>>> placeOrderWithFacility<T1,T2>(
            TimedDataWithEnvironment<Env,T1> key
            , AbstractOnOrderFacility<Env,T1,T2> facility
        )
        {
            await foreach (var x in placeOrderWithFacility(
                new TimedDataWithEnvironment<Env, Key<T1>>(
                    key.environment, new WithTime<Key<T1>>(
                        key.timedData.timePoint
                        , new Key<T1>(key.timedData.value)
                        , key.timedData.finalFlag
                    )
                )
                , facility
            )) 
            {
                yield return x;
            }
        }
        public async IAsyncEnumerable<TimedDataWithEnvironment<Env,KeyedData<T1,T2>>> placeOrderWithFacility<T1,T2>(
            T1 key
            , AbstractOnOrderFacility<Env,T1,T2> facility
        )
        {
            await foreach (var x in placeOrderWithFacility(
                new TimedDataWithEnvironment<Env, Key<T1>>(
                    env, new WithTime<Key<T1>>(
                        env.now()
                        , new Key<T1>(key)
                        , false
                    )
                )
                , facility
            )) 
            {
                yield return x;
            }
        }
        public class FacilityStreamer<T1,T2>
        {
            private Env env;
            private AbstractOnOrderFacility<Env,T1,T2> facility;
            private ResultHolder<KeyedData<T1,T2>> resultHolder;            
            private string id;
            private bool first;
            public FacilityStreamer(Env env, AbstractOnOrderFacility<Env,T1,T2> facility)
            {
                this.env = env;
                this.facility = facility;
                this.resultHolder = new ResultHolder<KeyedData<T1, T2>>();
                this.id = Guid.NewGuid().ToString();
                this.first = true;
            }
            public void Send(TimedDataWithEnvironment<Env,T1> data)
            {
                if (first)
                {
                    facility.placeRequest(new TimedDataWithEnvironment<Env, Key<T1>>(
                        data.environment, new WithTime<Key<T1>>(
                            data.timedData.timePoint
                            , new Key<T1>(id, data.timedData.value)
                            , data.timedData.finalFlag
                        )
                    ), new ImporterHandler1<KeyedData<T1,T2>>(resultHolder));
                    first = false;
                }
                else 
                {
                    facility.handle(new TimedDataWithEnvironment<Env, Key<T1>>(
                        data.environment, new WithTime<Key<T1>>(
                            data.timedData.timePoint
                            , new Key<T1>(id, data.timedData.value)
                            , data.timedData.finalFlag
                        )
                    ));
                }
            }
            public void Send(T1 data)
            {
                Send(new TimedDataWithEnvironment<Env, T1>(
                    env
                    , new WithTime<T1>(
                        env.now(), data, false
                    )
                ));
            }
            public async IAsyncEnumerable<TimedDataWithEnvironment<Env,KeyedData<T1,T2>>> Results()
            {
                while (!resultHolder.Empty)
                {
                    yield return await resultHolder.Front();
                    resultHolder.PopFront();
                }
            }
        }
        public FacilityStreamer<T1,T2> facilityStreamer<T1,T2>(AbstractOnOrderFacility<Env,T1,T2> facility)
        {
            if (facility is IExternalComponent<Env>)
            {
                var p = facility as IExternalComponent<Env>;
                lock (lockObj)
                {
                    if (!startedComponents.Contains(p))
                    {
                        p.start(env);
                        startedComponents.Add(p);
                    }
                }
            }
            return new FacilityStreamer<T1,T2>(env, facility);
        }
        public void exportItem<T>(
            AbstractExporter<Env, T> exporter 
            , TimedDataWithEnvironment<Env,T> data
        )
        {
            lock (lockObj)
            {
                if (!startedComponents.Contains(exporter))
                {
                    exporter.start(env);
                    startedComponents.Add(exporter);
                }
            }
            exporter.handle(data);
        }
        public void exportItem<T>(
            AbstractExporter<Env, T> exporter 
            , T data
        )
        {
            exportItem(
                exporter 
                , new TimedDataWithEnvironment<Env, T>(
                    env, new WithTime<T>(
                        env.now()
                        , data 
                        , false
                    )
                )
            );
        }
    }
}