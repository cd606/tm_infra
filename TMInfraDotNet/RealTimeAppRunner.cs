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

        public readonly struct Source<T>
        {
            public readonly Producer<Env,T> producer;
            public Source(Producer<Env,T> producer)
            {
                this.producer = producer;
            }
        }
        public readonly struct Sink<T>
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
}