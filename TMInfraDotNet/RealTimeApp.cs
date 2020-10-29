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

    class DelegateHandler<Env,T> : IHandler<Env,T>
    {
        private Action<TimedDataWithEnvironment<Env,T>> func;
        public DelegateHandler(Action<TimedDataWithEnvironment<Env,T>> func)
        {
            this.func = func;
        }
        public void handle(TimedDataWithEnvironment<Env,T> data)
        {
            func(data);
        }
    }

    interface SecondaryChecker
    {
        bool check(object x);
    }
    class VersionedDataChecker<Version,T> : SecondaryChecker where Version : IComparable
    {
        private Option<Version> lastVersion = Option.None<Version>();
        public bool check(object x)
        {
            var d = (VersionedData<Version,T>) x;
            if (lastVersion.HasValue && d.version.CompareTo(lastVersion.ValueOrFailure()) <= 0)
            {
                return false;
            }
            lastVersion = Option.Some(d.version);
            return true;
        }
    }
    class GroupedVersionedDataChecker<GroupID,Version,T> : SecondaryChecker where Version : IComparable
    {
        private Dictionary<GroupID,Version> lastVersion = new Dictionary<GroupID, Version>();
        public bool check(object x)
        {
            var d = (GroupedVersionedData<GroupID,Version,T>) x;
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
        private readonly bool useVersionChecker;
        private SecondaryChecker versionChecker = null;
        private long lastTime = 0;
        private object lockObj = new object();
        public TimeChecker()
        {
            var tType = typeof(T);
            bool useVersionChecker = false;
            if (tType.IsInterface)
            {
                if (tType.IsGenericType)
                {
                    if (tType.Name.Equals("VersionedData`2"))
                    {
                        var p = tType.GenericTypeArguments;
                        var checkerType = typeof(VersionedDataChecker<,>).MakeGenericType(p);
                        this.versionChecker = (SecondaryChecker) Activator.CreateInstance(checkerType);
                        useVersionChecker = true;
                    } else if (tType.Name.Equals("GroupedVersionedData`3"))
                    {
                        var p = tType.GenericTypeArguments;
                        var checkerType = typeof(GroupedVersionedDataChecker<,,>).MakeGenericType(p);
                        this.versionChecker = (SecondaryChecker) Activator.CreateInstance(checkerType);
                        useVersionChecker = true;
                    }
                }
            }
            if (!useVersionChecker)
            {
                foreach (var interf in tType.GetInterfaces())
                {
                    if (interf.IsGenericType)
                    {
                        if (interf.Name.Equals("VersionedData`2"))
                        {
                            var p = interf.GenericTypeArguments;
                            var checkerType = typeof(VersionedDataChecker<,>).MakeGenericType(p);
                            this.versionChecker = (SecondaryChecker) Activator.CreateInstance(checkerType);
                            useVersionChecker = true;
                            break;
                        } else if (interf.Name.Equals("GroupedVersionedData`3"))
                        {
                            var p = interf.GenericTypeArguments;
                            var checkerType = typeof(GroupedVersionedDataChecker<,,>).MakeGenericType(p);
                            this.versionChecker = (SecondaryChecker) Activator.CreateInstance(checkerType);
                            useVersionChecker = true;
                            break;
                        }
                    }
                }
            }
            this.useVersionChecker = useVersionChecker;
        }
        public bool check(WithTime<T> data) 
        {
            lock (lockObj)
            {
                var t = data.timePoint;
                if (lastTime > t)
                {
                    return false;
                }
                if (useVersionChecker) 
                {
                    if (!versionChecker.check(data.value))
                    {
                        return false;
                    }
                }
                lastTime = t;
                return true;
            }
        }
    }

    class TimeChecker2<T1,T2>
    {
        private readonly bool[] useVersionChecker;
        private SecondaryChecker[] versionChecker = {null, null};
        private long lastTime = 0;
        private WithTime<T1> copy1 = null;
        private WithTime<T2> copy2 = null;
        public TimeChecker2()
        {
            var tType = typeof(T1);
            bool[] flags = new bool[2] {false, false};
            if (tType.IsGenericType)
            {
                if (tType.Name.Equals("VersionedData`2"))
                {
                    var p = tType.GenericTypeArguments;
                    var checkerType = typeof(VersionedDataChecker<,>).MakeGenericType(p);
                    this.versionChecker[0] = (SecondaryChecker) Activator.CreateInstance(checkerType);
                    flags[0] = true;
                } else if (tType.Name.Equals("GroupedVersionedData`3"))
                {
                    var p = tType.GenericTypeArguments;
                    var checkerType = typeof(GroupedVersionedDataChecker<,,>).MakeGenericType(p);
                    this.versionChecker[0] = (SecondaryChecker) Activator.CreateInstance(checkerType);
                    flags[0] = true;
                }
            }
            tType = typeof(T2);
            if (tType.IsGenericType)
            {
                if (tType.Name.Equals("VersionedData`2"))
                {
                    var p = tType.GenericTypeArguments;
                    var checkerType = typeof(VersionedDataChecker<,>).MakeGenericType(p);
                    this.versionChecker[1] = (SecondaryChecker) Activator.CreateInstance(checkerType);
                    flags[1] = true;
                } else if (tType.Name.Equals("GroupedVersionedData`3"))
                {
                    var p = tType.GenericTypeArguments;
                    var checkerType = typeof(GroupedVersionedDataChecker<,,>).MakeGenericType(p);
                    this.versionChecker[1] = (SecondaryChecker) Activator.CreateInstance(checkerType);
                    flags[1] = true;
                }
            }
            this.useVersionChecker = flags;
        }
        public (bool, WithTime<T1>,WithTime<T2>) check1(WithTime<T1> data) 
        {
            var t = data.timePoint;
            if (lastTime > t)
            {
                return (false, copy1, copy2);
            }
            if (useVersionChecker[0]) 
            {
                if (!versionChecker[0].check(data.value))
                {
                    return (false, copy1, copy2);
                }
            }
            lastTime = t;
            copy1 = data;
            return (true, copy1, copy2);
        }
        public (bool, WithTime<T1>, WithTime<T2>) check2(WithTime<T2> data) 
        {
            var t = data.timePoint;
            if (lastTime > t)
            {
                return (false, copy1, copy2);
            }
            if (useVersionChecker[1]) 
            {
                if (!versionChecker[1].check(data.value))
                {
                    return (false, copy1, copy2);
                }
            }
            lastTime = t;
            copy2 = data;
            return (true, copy1, copy2);
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

    public interface IHandler2<Env,T1,T2>
    {
        IHandler<Env,T1> AsHandler1 {get;}
        IHandler<Env,T2> AsHandler2 {get;}
    }

    class ThreadedHandler2<Env,T1,T2> : IHandler2<Env,T1,T2>
    {
        private bool[] mask;
        private Action<Env,int,WithTime<T1>,WithTime<T2>> actuallyHandle;

        private Channel<(Env,int,object)> channel = Channel.CreateUnbounded<(Env,int,object)>();
        private TimeChecker2<T1,T2> checker = new TimeChecker2<T1,T2>();
        private bool ready(WithTime<T1> x1, WithTime<T2> x2)
        {
            if (mask[0] && x1 == null)
            {
                return false;
            }
            if (mask[1] && x2 == null)
            {
                return false;
            }
            return true;
        }
        private async void run()
        {
            while (await channel.Reader.WaitToReadAsync())
            {
                while (channel.Reader.TryRead(out (Env,int,object) item))
                {
                    switch (item.Item2)
                    {
                        case 0:
                        {
                            var d = (WithTime<T1>) item.Item3;
                            var checkRes = checker.check1(d);
                            if (checkRes.Item1 && ready(checkRes.Item2, checkRes.Item3))
                            {
                                actuallyHandle(item.Item1, item.Item2, checkRes.Item2, checkRes.Item3);
                            }
                            break;
                        }
                        case 1:
                        {
                            var d = (WithTime<T2>) item.Item3;
                            var checkRes = checker.check2(d);
                            if (checkRes.Item1 && ready(checkRes.Item2, checkRes.Item3))
                            {
                                actuallyHandle(item.Item1, item.Item2, checkRes.Item2, checkRes.Item3);
                            }
                            break;   
                        }
                        default:
                            break;
                    }
                }
            }
        }
        public ThreadedHandler2(Action<Env,int,WithTime<T1>,WithTime<T2>> actualHandler, bool[] mask)
        {
            this.actuallyHandle = actualHandler;
            this.mask = mask;
            new Thread(this.run).Start();
        }
        public ThreadedHandler2(Action<Env,int,WithTime<T1>,WithTime<T2>> actualHandler)
        {
            this.actuallyHandle = actualHandler;
            this.mask = new bool[] {true, true};
            new Thread(this.run).Start();
        }
        public void handle1(TimedDataWithEnvironment<Env,T1> data)
        {
            channel.Writer.WriteAsync(
                (data.environment, 0, data.timedData)
            );
        }
        public void handle2(TimedDataWithEnvironment<Env,T2> data)
        {
            channel.Writer.WriteAsync(
                (data.environment, 1, data.timedData)
            );
        }
        public IHandler<Env,T1> AsHandler1 {
            get {
                return new DelegateHandler<Env,T1>(this.handle1);
            }
        }
        public IHandler<Env,T2> AsHandler2 {
            get {
                return new DelegateHandler<Env,T2>(this.handle2);
            }
        }
    }

    public class NonThreadedHandler2<Env,T1,T2> : IHandler2<Env,T1,T2>
    {
        private bool[] mask;
        private Action<Env,int,WithTime<T1>,WithTime<T2>> actuallyHandle;

        private TimeChecker2<T1,T2> checker = new TimeChecker2<T1,T2>();
        private object lockObj = new object();
        private bool ready(WithTime<T1> x1, WithTime<T2> x2)
        {
            if (mask[0] && x1 == null)
            {
                return false;
            }
            if (mask[1] && x2 == null)
            {
                return false;
            }
            return true;
        }
        public NonThreadedHandler2(Action<Env,int,WithTime<T1>,WithTime<T2>> actualHandler, bool[] mask)
        {
            this.actuallyHandle = actualHandler;
            this.mask = mask;
        }
        public NonThreadedHandler2(Action<Env,int,WithTime<T1>,WithTime<T2>> actualHandler)
        {
            this.actuallyHandle = actualHandler;
            this.mask = new bool[] {true, true};
        }
        public void handle1(TimedDataWithEnvironment<Env,T1> data)
        {
            lock (lockObj)
            {
                var checkRes = checker.check1(data.timedData);
                if (checkRes.Item1 && ready(checkRes.Item2, checkRes.Item3))
                {
                    actuallyHandle(data.environment, 0, checkRes.Item2, checkRes.Item3);
                }
            }
        }
        public void handle2(TimedDataWithEnvironment<Env,T2> data)
        {
            lock (lockObj)
            {
                var checkRes = checker.check2(data.timedData);
                if (checkRes.Item1 && ready(checkRes.Item2, checkRes.Item3))
                {
                    actuallyHandle(data.environment, 1, checkRes.Item2, checkRes.Item3);
                }
            }
        }
        public IHandler<Env,T1> AsHandler1 {
            get {
                return new DelegateHandler<Env,T1>(this.handle1);
            }
        }
        public IHandler<Env,T2> AsHandler2 {
            get {
                return new DelegateHandler<Env,T2>(this.handle2);
            }
        }
    }

    public class Producer<Env, T>
    {
        private object lockObj = new object();
        private List<IHandler<Env,T>> handlers = new List<IHandler<Env, T>>();
        private static bool canClone = (!(typeof(T).IsValueType)) && (typeof(T) is ICloneable);
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
                            ICloneable v = (ICloneable) data.timedData.value;
                            foreach (var h in handlers)
                            {
                                h.handle(new TimedDataWithEnvironment<Env, T>(
                                    data.environment
                                    , new WithTime<T>(
                                        data.timedData.timePoint
                                        , (T) v.Clone()
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
    
    public abstract class AbstractAction2<Env,T1,T2,OutT> : Producer<Env,OutT>, IHandler2<Env,T1,T2>
    {
        public abstract IHandler<Env,T1> AsHandler1 {get;}
        public abstract IHandler<Env,T2> AsHandler2 {get;}
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
                if (res.HasValue)
                {
                    publish(res.ValueOrFailure());
                }
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
                if (res.HasValue)
                {
                    var yVal = res.ValueOrFailure();
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
        public static AbstractAction<Env,T1,T2> enhancedMaybe<T1,T2>(Func<long,T1,Option<T2>> f, bool threaded) 
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
        public static AbstractAction<Env,T1,T2> enhancedMulti<T1,T2>(Func<long,T1,List<T2>> f, bool threaded)
        {
            return new KleisliMultiAction<T1,T2>(KleisliUtils<Env>.enhancedMaybe<T1,List<T2>>(
                (long d, T1 x) => {
                    return Option.Some<List<T2>>(f(d, x));
                }
            ), threaded);
        }
        public static AbstractAction<Env,T1,T2> kleisliMulti<T1,T2>(Func<TimedDataWithEnvironment<Env,T1>,Option<TimedDataWithEnvironment<Env,List<T2>>>> f, bool threaded)
        {
            return new KleisliMultiAction<T1,T2>(f, threaded);
        }
        class KleisliAction2<T1,T2,OutT> : AbstractAction2<Env,T1,T2,OutT>
        {
            private Func<int,TimedDataWithEnvironment<Env,T1>,TimedDataWithEnvironment<Env,T2>,Option<TimedDataWithEnvironment<Env,OutT>>> func;
            public void actuallyHandle(Env env, int which, WithTime<T1> t1, WithTime<T2> t2)
            {
                var res = func(
                    which 
                    , new TimedDataWithEnvironment<Env, T1>(
                        env, t1
                    )
                    , new TimedDataWithEnvironment<Env, T2>(
                        env, t2
                    )
                );
                if (res.HasValue)
                {
                    publish(res.ValueOrFailure());
                }
            }
            private IHandler2<Env,T1,T2> realHandler;
            public KleisliAction2(Func<int,TimedDataWithEnvironment<Env,T1>,TimedDataWithEnvironment<Env,T2>,Option<TimedDataWithEnvironment<Env,OutT>>> func, bool threaded, bool[] mask)
            {
                this.func = func;
                if (threaded)
                {
                    this.realHandler = new ThreadedHandler2<Env,T1,T2>(this.actuallyHandle, mask);
                }
                else
                {
                    this.realHandler = new NonThreadedHandler2<Env,T1,T2>(this.actuallyHandle, mask);
                }
            }
            public KleisliAction2(Func<int,TimedDataWithEnvironment<Env,T1>,TimedDataWithEnvironment<Env,T2>,Option<TimedDataWithEnvironment<Env,OutT>>> func, bool threaded)
            {
                this.func = func;
                if (threaded)
                {
                    this.realHandler = new ThreadedHandler2<Env,T1,T2>(this.actuallyHandle);
                }
                else
                {
                    this.realHandler = new NonThreadedHandler2<Env,T1,T2>(this.actuallyHandle);
                }
            }
            public override IHandler<Env,T1> AsHandler1 {
                get {
                    return realHandler.AsHandler1;
                }
            }
            public override IHandler<Env,T2> AsHandler2 {
                get {
                    return realHandler.AsHandler2;
                }
            }
        }
        class KleisliMultiAction2<T1,T2,OutT> : AbstractAction2<Env,T1,T2,OutT>
        {
            private Func<int,TimedDataWithEnvironment<Env,T1>,TimedDataWithEnvironment<Env,T2>,Option<TimedDataWithEnvironment<Env,List<OutT>>>> func;
            public void actuallyHandle(Env env, int which, WithTime<T1> t1, WithTime<T2> t2)
            {
                var res = func(
                    which 
                    , new TimedDataWithEnvironment<Env, T1>(
                        env, t1
                    )
                    , new TimedDataWithEnvironment<Env, T2>(
                        env, t2
                    )
                );
                if (res.HasValue)
                {
                    var yVal = res.ValueOrFailure();
                    var count = yVal.timedData.value.Count;
                    var ii = 0;
                    foreach (var item in yVal.timedData.value)
                    {
                        publish(new TimedDataWithEnvironment<Env, OutT>(
                            yVal.environment
                            , new WithTime<OutT>(
                                yVal.timedData.timePoint
                                , item
                                , (yVal.timedData.finalFlag && (ii == count-1))
                            )
                        ));
                        ++ii;
                    }
                }
            }
            private IHandler2<Env,T1,T2> realHandler;
            public KleisliMultiAction2(Func<int,TimedDataWithEnvironment<Env,T1>,TimedDataWithEnvironment<Env,T2>,Option<TimedDataWithEnvironment<Env,List<OutT>>>> func, bool threaded, bool[] mask)
            {
                this.func = func;
                if (threaded)
                {
                    this.realHandler = new ThreadedHandler2<Env,T1,T2>(this.actuallyHandle, mask);
                }
                else
                {
                    this.realHandler = new NonThreadedHandler2<Env,T1,T2>(this.actuallyHandle, mask);
                }
            }
            public KleisliMultiAction2(Func<int,TimedDataWithEnvironment<Env,T1>,TimedDataWithEnvironment<Env,T2>,Option<TimedDataWithEnvironment<Env,List<OutT>>>> func, bool threaded)
            {
                this.func = func;
                if (threaded)
                {
                    this.realHandler = new ThreadedHandler2<Env,T1,T2>(this.actuallyHandle);
                }
                else
                {
                    this.realHandler = new NonThreadedHandler2<Env,T1,T2>(this.actuallyHandle);
                }
            }
            public override IHandler<Env,T1> AsHandler1 {
                get {
                    return realHandler.AsHandler1;
                }
            }
            public override IHandler<Env,T2> AsHandler2 {
                get {
                    return realHandler.AsHandler2;
                }
            }
        }
        public static AbstractAction2<Env,T1,T2,OutT> liftPure2<T1,T2,OutT>(Func<int,T1,T2,OutT> f, bool threaded, bool[] mask) 
        {
            return new KleisliAction2<T1,T2,OutT>(KleisliUtils<Env>.liftPure2<T1,T2,OutT>(f), threaded, mask);
        }
        public static AbstractAction2<Env,T1,T2,OutT> liftMaybe<T1,T2,OutT>(Func<int,T1,T2,Option<OutT>> f, bool threaded, bool[] mask) 
        {
            return new KleisliAction2<T1,T2,OutT>(KleisliUtils<Env>.liftMaybe2<T1,T2,OutT>(f), threaded, mask);
        }
        public static AbstractAction2<Env,T1,T2,OutT> enhancedMaybe2<T1,T2,OutT>(Func<int,long,T1,T2,Option<OutT>> f, bool threaded, bool[] mask) 
        {
            return new KleisliAction2<T1,T2,OutT>(KleisliUtils<Env>.enhancedMaybe2<T1,T2,OutT>(f), threaded);
        }
        public static AbstractAction2<Env,T1,T2,OutT> kleisli2<T1,T2,OutT>(Func<int,TimedDataWithEnvironment<Env,T1>,TimedDataWithEnvironment<Env,T2>,Option<TimedDataWithEnvironment<Env,OutT>>> f, bool threaded, bool[] mask) 
        {
            return new KleisliAction2<T1,T2,OutT>(f, threaded, mask);
        }
        public static AbstractAction2<Env,T1,T2,OutT> liftMulti2<T1,T2,OutT>(Func<int,T1,T2,List<OutT>> f, bool threaded, bool[] mask)
        {
            return new KleisliMultiAction2<T1,T2,OutT>(KleisliUtils<Env>.liftPure2<T1,T2,List<OutT>>(f), threaded, mask);
        }
        public static AbstractAction2<Env,T1,T2,OutT> enhancedMulti2<T1,T2,OutT>(Func<int,long,T1,T2,List<OutT>> f, bool threaded, bool[] mask)
        {
            return new KleisliMultiAction2<T1,T2,OutT>(KleisliUtils<Env>.enhancedMaybe2<T1,T2,List<OutT>>(
                (int which, long d, T1 x1, T2 x2) => {
                    return Option.Some(f(which, d, x1, x2));
                }
            ), threaded, mask);
        }
        public static AbstractAction2<Env,T1,T2,OutT> kleisliMulti2<T1,T2,OutT>(Func<int,TimedDataWithEnvironment<Env,T1>,TimedDataWithEnvironment<Env,T2>,Option<TimedDataWithEnvironment<Env,List<OutT>>>> f, bool threaded, bool[] mask)
        {
            return new KleisliMultiAction2<T1,T2,OutT>(f, threaded, mask);
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