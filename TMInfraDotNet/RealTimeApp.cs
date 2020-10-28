using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Channels;
using Optional;
using Optional.Unsafe;

namespace Dev.CD606.TM.Infra.RealTimeApp
{
    public interface IExternalComponent<Env>
    {
        void start(Env env);
    }
    public interface IHandler<Env,T>
    {
        void handle(TimedDataWithEnvironment<Env,T> data);
    }

    class VersionedDataChecker<Version,T> where Version : IComparable
    {
        private Option<Version> lastVersion = Option.None<Version>();
        public bool check(dynamic x)
        {
            VersionedData<Version,T> d = x.value;
            if (lastVersion.HasValue && d.version.CompareTo(lastVersion.ValueOrFailure()) <= 0)
            {
                return false;
            }
            lastVersion = Option.Some(d.version);
            return true;
        }
    }
    class GroupedVersionedDataChecker<GroupID,Version,T> where Version : IComparable
    {
        private Dictionary<GroupID,Version> lastVersion = new Dictionary<GroupID, Version>();
        public bool check(dynamic x)
        {
            GroupedVersionedData<GroupID,Version,T> d = x.value;
            Version v;
            if (lastVersion.TryGetValue(d.groupID, out v))
            {
                if (d.version.CompareTo(v) <= 0) 
                {
                    return false;
                }
                else
                {
                    lastVersion[d.groupID] = d.version;
                    return true;
                }
            }
            else
            {
                lastVersion.Add(d.groupID, d.version);
                return true;
            }
        }
    }

    class TimeChecker<T>
    {
        private dynamic versionChecker = null;
        private Option<DateTimeOffset> lastTime = Option.None<DateTimeOffset>();
        private object lockObj = new object();
        public TimeChecker()
        {
            var tType = typeof(T);
            if (tType.IsValueType && !tType.IsEnum && tType.IsGenericType)
            {
                if (tType.Name.Equals("VersionedData`2"))
                {
                    var p = tType.GenericTypeArguments;
                    var checkerType = typeof(VersionedDataChecker<,>).MakeGenericType(p);
                    this.versionChecker = Activator.CreateInstance(checkerType);
                } else if (tType.Name.Equals("GroupedVersionedData`3"))
                {
                    var p = tType.GenericTypeArguments;
                    var checkerType = typeof(GroupedVersionedDataChecker<,,>).MakeGenericType(p);
                    this.versionChecker = Activator.CreateInstance(checkerType);
                }
            }
        }
        public bool check(WithTime<T> data) 
        {
            lock (lockObj)
            {
                if (lastTime.HasValue && lastTime.ValueOrFailure() > data.timePoint)
                {
                    return false;
                }
                if (versionChecker != null) 
                {
                    if (!versionChecker.check(data))
                    {
                        return false;
                    }
                }
                lastTime = Option.Some(data.timePoint);
                return true;
            }
        }
    }

    class ThreadedHandler<Env,T> : IHandler<Env,T>
    {
        private Action<TimedDataWithEnvironment<Env,T>> actuallyHandle;
        private Channel<TimedDataWithEnvironment<Env,T>> channel = Channel.CreateUnbounded<TimedDataWithEnvironment<Env,T>>();
        private TimeChecker<T> checker = new TimeChecker<T>();
        private async void run()
        {
            while (await channel.Reader.WaitToReadAsync())
            {
                while (channel.Reader.TryRead(out TimedDataWithEnvironment<Env,T> item))
                {
                    actuallyHandle(item);
                }
            }
        }
        public ThreadedHandler(Action<TimedDataWithEnvironment<Env,T>> actualHandler)
        {
            this.actuallyHandle = actualHandler;
            new Thread(this.run).Start();
        }
        public void handle(TimedDataWithEnvironment<Env,T> data)
        {
            if (checker.check(data.timedData))
            {
                channel.Writer.WriteAsync(data);
            }
        }
    }

     public class NonThreadedHandler<Env,T> : IHandler<Env,T>
    {
        private Action<TimedDataWithEnvironment<Env,T>> actuallyHandle;
        private TimeChecker<T> checker = new TimeChecker<T>();
        public NonThreadedHandler(Action<TimedDataWithEnvironment<Env,T>> actualHandler)
        {
            this.actuallyHandle = actualHandler;
        }
        public void handle(TimedDataWithEnvironment<Env,T> data)
        {
            if (checker.check(data.timedData))
            {
                actuallyHandle(data);
            }
        }
    }

    public class Producer<Env, T>
    {
        private object lockObj = new object();
        private List<IHandler<Env,T>> handlers = new List<IHandler<Env, T>>();
        private static bool canClone = (typeof(T) is ICloneable);
        public void addHandler(IHandler<Env,T> handler)
        {
            lock (lockObj)
            {
                if (!handlers.Contains(handler))
                {
                    handlers.Add(handler);
                }
            }
        }
        public void publish(TimedDataWithEnvironment<Env,T> data)
        {
            lock (lockObj)
            {
                switch (handlers.Count)
                {
                    case 0:
                        return;
                    case 1:
                        handlers[0].handle(data);
                        break;
                    default:
                        if (canClone)
                        {
                            dynamic v = data.timedData.value;
                            foreach (var h in handlers)
                            {
                                h.handle(new TimedDataWithEnvironment<Env, T>(
                                    data.environment
                                    , new WithTime<T>(
                                        data.timedData.timePoint
                                        , v.Clone()
                                        , data.timedData.finalFlag
                                    )
                                ));
                            }
                        }
                        else
                        {
                            foreach (var h in handlers)
                            {
                                h.handle(data);
                            }
                        }
                        break;
                }
            }
        }
    }

    public abstract class AbstractImporter<Env, T> : Producer<Env, T>, IExternalComponent<Env> where Env : EnvBase 
    {
        public abstract void start(Env env);
    }

    public interface AbstractExporter<Env, T> : IHandler<Env, T>, IExternalComponent<Env> where Env : EnvBase
    {
    }
    
    public abstract class AbstractAction<Env,T1,T2> : Producer<Env,T2>, IHandler<Env,T1> where Env : EnvBase
    {
        public abstract void handle(TimedDataWithEnvironment<Env,T1> data);
    }
    public class KeyedDataProducer<Env,T1,T2> 
    {
        private object lockObj = new object();
        private Dictionary<string, (T1, IHandler<Env,KeyedData<T1,T2>>)> handlers = new Dictionary<string, (T1, IHandler<Env, KeyedData<T1, T2>>)>();
        protected void addHandler(Key<T1> key, IHandler<Env,KeyedData<T1,T2>> handler)
        {
            lock (lockObj)
            {
                if (!handlers.ContainsKey(key.id))
                {
                    handlers.Add(key.id, (key.key, handler));
                }
            }
        }
        public void publish(TimedDataWithEnvironment<Env,Key<T2>> data)
        {
            lock (lockObj)
            {
                if (handlers.TryGetValue(data.timedData.value.id, out (T1, IHandler<Env,KeyedData<T1,T2>>) handler))
                {
                    handler.Item2.handle(new TimedDataWithEnvironment<Env,KeyedData<T1,T2>>(
                        data.environment
                        , new WithTime<KeyedData<T1, T2>>(
                            data.timedData.timePoint
                            , new KeyedData<T1, T2>(
                                new Key<T1>(handler.Item1)
                                , data.timedData.value.key
                            )
                            , data.timedData.finalFlag
                        )
                    ));
                    if (data.timedData.finalFlag)
                    {
                        handlers.Remove(data.timedData.value.id);
                    }
                }
            }
        }
    }
    public abstract class AbstractOnOrderFacility<Env,T1,T2> : KeyedDataProducer<Env,T1,T2>, IHandler<Env,Key<T1>>, IExternalComponent<Env> where Env : EnvBase
    {
        public abstract void start(Env env);
        public abstract void handle(TimedDataWithEnvironment<Env,Key<T1>> data);
        public void placeRequest(TimedDataWithEnvironment<Env,Key<T1>> data, IHandler<Env,KeyedData<T1,T2>> responseHandler)
        {
            addHandler(data.timedData.value, responseHandler);
            handle(data);
        }
        public void placeRequestAndForget(TimedDataWithEnvironment<Env,Key<T1>> data)
        {
            handle(data);
        }
    }

    public static class RealTimeAppUtils<Env> where Env : EnvBase
    {
        class SimpleImporter<T> : AbstractImporter<Env,T>
        {
            private Env env;
            private Action<Env, Action<T, bool>> generator;
            public SimpleImporter(Action<Env, Action<T, bool>> generator)
            {
                this.generator = generator;
            }
            private void run()
            {
                generator(env, (T t, bool finalFlag) => {
                    publish(InfraUtils.pureTimedDataWithEnvironment<Env,T>(env, t, finalFlag));
                });
            }
            public override void start(Env env)
            {
                this.env = env;
                new Thread(this.run).Start();
            }
        }
        public static AbstractImporter<Env,T> simpleImporter<T>(
            Action<Env, Action<T, bool>> generator
        ) 
        {
            return new SimpleImporter<T>(generator);
        }

        public class TriggerImporter<T> : AbstractImporter<Env, T> 
        {
            private Env env;
            public override void start(Env env)
            {
                this.env = env;
            }
            public void trigger(T t)
            {
                publish(InfraUtils.pureTimedDataWithEnvironment(env, t, false));
            }
        }
        public static TriggerImporter<T> triggerImporter<T>()
        {
            return new TriggerImporter<T>();
        }
        public class ConstTriggerImporter<T> : AbstractImporter<Env, T> 
        {
            private Env env;
            private T t;
            public ConstTriggerImporter(T t) 
            {
                this.t = t;
            }
            public override void start(Env env)
            {
                this.env = env;
            }
            public void trigger()
            {
                publish(InfraUtils.pureTimedDataWithEnvironment(env, t, false));
            }
        }
        public static ConstTriggerImporter<T> constTriggerImporter<T>(T t) 
        {
            return new ConstTriggerImporter<T>(t);
        }
        public static AbstractImporter<Env,T> constFirstPushImporter<T>(T t) 
        {
            return simpleImporter<T>(
                (Env env, Action<T, bool> pub) => {
                    pub(t, true);
                }
            );
        }
        public static AbstractImporter<Env,Key<T>> constFirstPushKeyImporter<T>(T t) 
        {
            return simpleImporter<Key<T>>(
                (Env env, Action<Key<T>, bool> pub) => {
                    pub(InfraUtils.keyify<T>(t), true);
                }
            );
        }
        class SimpleExporter<T> : AbstractExporter<Env, T>
        {
            private IHandler<Env,T> realHandler;
            public SimpleExporter(Action<TimedDataWithEnvironment<Env,T>> f, bool threaded)
            {
                if (threaded)
                {
                    realHandler = new ThreadedHandler<Env,T>(f);
                }
                else
                {
                    realHandler = new NonThreadedHandler<Env,T>(f);
                }
            }
            public void start(Env env)
            {
            }
            public void handle(TimedDataWithEnvironment<Env,T> data)
            {
                realHandler.handle(data);
            }
        }
        public static AbstractExporter<Env,T> simpleExporter<T>(Action<TimedDataWithEnvironment<Env,T>> f, bool threaded) 
        {
            return new SimpleExporter<T>(f, threaded);
        }
        public static AbstractExporter<Env,T> pureExporter<T>(Action<T> f, bool threaded)
        {
            return simpleExporter<T>(
                (TimedDataWithEnvironment<Env,T> data) => {
                    f(data.timedData.value);
                }
                , threaded
            );
        }
        class KleisliAction<T1,T2> : AbstractAction<Env,T1,T2>
        {
            private Func<TimedDataWithEnvironment<Env,T1>,Option<TimedDataWithEnvironment<Env,T2>>> func;
            public void actuallyHandle(TimedDataWithEnvironment<Env,T1> data)
            {
                var res = func(data);
                res.Match(
                    some : (yVal) => {
                        publish(yVal);
                    }
                    , none : () => {}
                );
            }
            private IHandler<Env,T1> realHandler;
            public KleisliAction(Func<TimedDataWithEnvironment<Env,T1>,Option<TimedDataWithEnvironment<Env,T2>>> func, bool threaded)
            {
                this.func = func;
                if (threaded)
                {
                    this.realHandler = new ThreadedHandler<Env,T1>(this.actuallyHandle);
                }
                else
                {
                    this.realHandler = new NonThreadedHandler<Env,T1>(this.actuallyHandle);
                }
            }
            public override void handle(TimedDataWithEnvironment<Env,T1> data)
            {
                realHandler.handle(data);
            }
        }
        class KleisliMultiAction<T1,T2> : AbstractAction<Env,T1,T2>
        {
            private Func<TimedDataWithEnvironment<Env,T1>,Option<TimedDataWithEnvironment<Env,List<T2>>>> func;
            public void actuallyHandle(TimedDataWithEnvironment<Env,T1> data)
            {
                var res = func(data);
                res.Match(
                    some : (yVal) => {
                        var itemCount = yVal.timedData.value.Count;
                        var ii = 0;
                        foreach (var item in yVal.timedData.value)
                        {
                            publish(new TimedDataWithEnvironment<Env, T2>(
                                yVal.environment
                                , new WithTime<T2>(
                                    yVal.timedData.timePoint
                                    , item
                                    , (yVal.timedData.finalFlag && (ii == (itemCount-1)))
                                )
                            ));
                            ++ii;
                        }
                    }
                    , none : () => {}
                );
            }
            private IHandler<Env,T1> realHandler;
            public KleisliMultiAction(Func<TimedDataWithEnvironment<Env,T1>,Option<TimedDataWithEnvironment<Env,List<T2>>>> func, bool threaded)
            {
                this.func = func;
                if (threaded)
                {
                    this.realHandler = new ThreadedHandler<Env,T1>(this.actuallyHandle);
                }
                else
                {
                    this.realHandler = new NonThreadedHandler<Env,T1>(this.actuallyHandle);
                }
            }
            public override void handle(TimedDataWithEnvironment<Env,T1> data)
            {
                realHandler.handle(data);
            }
        }
        public static AbstractAction<Env,T1,T2> liftPure<T1,T2>(Func<T1,T2> f, bool threaded) 
        {
            return new KleisliAction<T1,T2>(KleisliUtils<Env>.liftPure<T1,T2>(f), threaded);
        }
        public static AbstractAction<Env,T1,T2> liftMaybe<T1,T2>(Func<T1,Option<T2>> f, bool threaded) 
        {
            return new KleisliAction<T1,T2>(KleisliUtils<Env>.liftMaybe<T1,T2>(f), threaded);
        }
        public static AbstractAction<Env,T1,T2> enhancedMaybe<T1,T2>(Func<DateTimeOffset,T1,Option<T2>> f, bool threaded) 
        {
            return new KleisliAction<T1,T2>(KleisliUtils<Env>.enhancedMaybe<T1,T2>(f), threaded);
        }
        public static AbstractAction<Env,T1,T2> kleisli<T1,T2>(Func<TimedDataWithEnvironment<Env,T1>,Option<TimedDataWithEnvironment<Env,T2>>> f, bool threaded) 
        {
            return new KleisliAction<T1,T2>(f, threaded);
        }
        public static AbstractAction<Env,T1,T2> liftMulti<T1,T2>(Func<T1,List<T2>> f, bool threaded)
        {
            return new KleisliMultiAction<T1,T2>(KleisliUtils<Env>.liftPure<T1,List<T2>>(f), threaded);
        }
        public static AbstractAction<Env,T1,T2> enhancedMulti<T1,T2>(Func<DateTimeOffset,T1,List<T2>> f, bool threaded)
        {
            return new KleisliMultiAction<T1,T2>(KleisliUtils<Env>.enhancedMaybe<T1,List<T2>>(
                (DateTimeOffset d, T1 x) => {
                    return Option.Some<List<T2>>(f(d, x));
                }
            ), threaded);
        }
        public static AbstractAction<Env,T1,T2> kleisliMulti<T1,T2>(Func<TimedDataWithEnvironment<Env,T1>,Option<TimedDataWithEnvironment<Env,List<T2>>>> f, bool threaded)
        {
            return new KleisliMultiAction<T1,T2>(f, threaded);
        }

        public static void terminateAtTimePoint(Env env, DateTimeOffset tp)
        {
            Thread.Sleep(tp-DateTimeOffset.Now);
            env.exit();
        }
        public static void terminateAfterDuration(Env env, TimeSpan d)
        {
            Thread.Sleep(d);
            env.exit();
        }
        public static void immediatelyTerminate(Env env)
        {
            env.exit();
        }
        public static void runForever(Env env, Func<bool> checker, TimeSpan d)
        {
            while (checker())
            {
                Thread.Sleep(d);
            }
            env.exit();
        }
        public static void runForever(Env env, Func<bool> checker)
        {
            while (checker())
            {
                Thread.Sleep(TimeSpan.FromSeconds(100));
            }
            env.exit();
        }
        public static void runForever(Env env)
        {
            while (true)
            {
                Thread.Sleep(TimeSpan.FromSeconds(100));
            }
        }
    }
}