using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Channels;
using Here;

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
        private Option<Version> lastVersion = Option.None;
        public bool check(object x)
        {
            var d = (VersionedData<Version,T>) x;
            if (lastVersion.HasValue && d.version.CompareTo(lastVersion.Unwrap()) <= 0)
            {
                return false;
            }
            lastVersion = d.version;
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
                        if (!p[0].Name.Equals("NoVersion")) {
                            var checkerType = typeof(VersionedDataChecker<,>).MakeGenericType(p);
                            this.versionChecker = (SecondaryChecker) Activator.CreateInstance(checkerType);
                            useVersionChecker = true;
                        }
                    } else if (tType.Name.Equals("GroupedVersionedData`3"))
                    {
                        var p = tType.GenericTypeArguments;
                        if (!p[1].Name.Equals("NoVersion")) {
                            var checkerType = typeof(GroupedVersionedDataChecker<,,>).MakeGenericType(p);
                            this.versionChecker = (SecondaryChecker) Activator.CreateInstance(checkerType);
                            useVersionChecker = true;
                        }
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
                            if (!p[0].Name.Equals("NoVersion")) {
                                var checkerType = typeof(VersionedDataChecker<,>).MakeGenericType(p);
                                this.versionChecker = (SecondaryChecker) Activator.CreateInstance(checkerType);
                                useVersionChecker = true;
                            }
                            break;
                        } else if (interf.Name.Equals("GroupedVersionedData`3"))
                        {
                            var p = interf.GenericTypeArguments;
                            if (!p[1].Name.Equals("NoVersion")) {
                                var checkerType = typeof(GroupedVersionedDataChecker<,,>).MakeGenericType(p);
                                this.versionChecker = (SecondaryChecker) Activator.CreateInstance(checkerType);
                                useVersionChecker = true;
                            }
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
        private Option<long> time1 = Option.None;
        private Option<long> time2 = Option.None;
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
        public bool check(WithTime<Either<T1,T2>> data) 
        {
            var t = data.timePoint;
            return data.value.Match(
                (T2 t2) => {
                    if (t >= time2.Unwrap(0)) {
                        time2 = t;
                        if (useVersionChecker[1]) {
                            return versionChecker[1].check(t2);
                        } else {
                            return true;
                        }
                    } else {
                        return false;
                    }
                }, 
                (T1 t1) => {
                    if (t >= time1.Unwrap(0)) {
                        time1 = t;
                        if (useVersionChecker[0]) {
                            return versionChecker[0].check(t1);
                        } else {
                            return true;
                        }
                    } else {
                        return false;
                    }
                }
            );
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
        private Action<TimedDataWithEnvironment<Env,Either<T1,T2>>> actuallyHandle;

        private Channel<(Env,int,object)> channel = Channel.CreateUnbounded<(Env,int,object)>();
        private TimeChecker2<T1,T2> checker = new TimeChecker2<T1,T2>();
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
                            var data = new WithTime<Either<T1, T2>>(
                                d.timePoint, Either.Left(d.value), d.finalFlag
                            );
                            var checkRes = checker.check(data);
                            if (checkRes)
                            {
                                actuallyHandle(
                                    new TimedDataWithEnvironment<Env, Either<T1, T2>>(
                                        item.Item1, data
                                    )
                                );
                            }
                            break;
                        }
                        case 1:
                        {
                            var d = (WithTime<T2>) item.Item3;
                            var data = new WithTime<Either<T1, T2>>(
                                d.timePoint, Either.Right(d.value), d.finalFlag
                            );
                            var checkRes = checker.check(data);
                            if (checkRes)
                            {
                                actuallyHandle(
                                    new TimedDataWithEnvironment<Env, Either<T1, T2>>(
                                        item.Item1, data
                                    )
                                );
                            }
                            break;   
                        }
                        default:
                            break;
                    }
                }
            }
        }
        public ThreadedHandler2(Action<TimedDataWithEnvironment<Env,Either<T1,T2>>> actualHandler)
        {
            this.actuallyHandle = actualHandler;
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
        private Action<TimedDataWithEnvironment<Env,Either<T1,T2>>> actuallyHandle;

        private TimeChecker2<T1,T2> checker = new TimeChecker2<T1,T2>();
        private object lockObj = new object();
        public NonThreadedHandler2(Action<TimedDataWithEnvironment<Env,Either<T1,T2>>> actualHandler)
        {
            this.actuallyHandle = actualHandler;
        }
        public void handle1(TimedDataWithEnvironment<Env,T1> data)
        {
            lock (lockObj)
            {
                var eitherData = new TimedDataWithEnvironment<Env,Either<T1,T2>>(
                    data.environment, new WithTime<Either<T1, T2>>(
                        data.timedData.timePoint, Either.Left(data.timedData.value), data.timedData.finalFlag
                    )
                );
                var checkRes = checker.check(eitherData.timedData);
                if (checkRes)
                {
                    actuallyHandle(eitherData);
                }
            }
        }
        public void handle2(TimedDataWithEnvironment<Env,T2> data)
        {
            lock (lockObj)
            {
                var eitherData = new TimedDataWithEnvironment<Env,Either<T1,T2>>(
                    data.environment, new WithTime<Either<T1, T2>>(
                        data.timedData.timePoint, Either.Right(data.timedData.value), data.timedData.finalFlag
                    )
                );
                var checkRes = checker.check(eitherData.timedData);
                if (checkRes)
                {
                    actuallyHandle(eitherData);
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
        private static bool canClone = (!(typeof(T).IsValueType)) && (typeof(T).GetInterface("ICloneable") != null);
        protected void copyHandlersTo(Producer<Env,T> other)
        {
            if (other != this)
            {
                lock (lockObj)
                {
                    foreach (var h in handlers)
                    {
                        other.addHandler(h);
                    }
                }
            }
        }
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
                                new Key<T1>(data.timedData.value.id, handler.Item1)
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

        class UniformSimpleImporter<T> : AbstractImporter<Env,T>
        {
            private Env env;
            private Func<Env, (bool, Option<TimedDataWithEnvironment<Env,T>>)> generator;
            public UniformSimpleImporter(Func<Env, (bool, Option<TimedDataWithEnvironment<Env,T>>)> generator)
            {
                this.generator = generator;
            }
            private void run()
            {
                while (true) 
                {
                    var x = generator(env);
                    if (x.Item2) 
                    {
                        publish(x.Item2.Unwrap());
                    }
                    if (!x.Item1) 
                    {
                        break;
                    }
                }
            }
            public override void start(Env env)
            {
                this.env = env;
                new Thread(this.run).Start();
            }
        }
        public static AbstractImporter<Env,T> uniformSimpleImporter<T>(
            Func<Env, (bool, Option<TimedDataWithEnvironment<Env,T>>)> generator
        ) 
        {
            return new UniformSimpleImporter<T>(generator);
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
                    publish(res.Unwrap());
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
                    var yVal = res.Unwrap();
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
        class ContinuationAction<T1,T2> : AbstractAction<Env,T1,T2>
        {
            private Action<TimedDataWithEnvironment<Env,T1>,Action<TimedDataWithEnvironment<Env,T2>>> func;
            public void actuallyHandle(TimedDataWithEnvironment<Env,T1> data)
            {
                func(data, this.publish);
            }
            private IHandler<Env,T1> realHandler;
            public ContinuationAction(Action<TimedDataWithEnvironment<Env,T1>,Action<TimedDataWithEnvironment<Env,T2>>> func, bool threaded)
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
        public class DelayedImporter<T1,T2> : AbstractAction<Env,T1,T2> 
        {
            private AbstractImporter<Env,T2> importer;
            private volatile bool started;
            public DelayedImporter(AbstractImporter<Env,T2> importer)
            {
                this.importer = importer;
                this.started = false;
            }
            public override void handle(TimedDataWithEnvironment<Env,T1> data)
            {
                if (!started)
                {
                    started = true;
                    copyHandlersTo(importer);
                    importer.start(data.environment);
                }
            }
        }
        public class LazyImporter<T1,T2> : AbstractAction<Env,T1,T2> 
        {
            private Func<T1,AbstractImporter<Env,T2>> importerFactory;
            private volatile bool started;
            public LazyImporter(Func<T1,AbstractImporter<Env,T2>> importerFactory)
            {
                this.importerFactory = importerFactory;
                this.started = false;
            }
            public override void handle(TimedDataWithEnvironment<Env,T1> data)
            {
                if (!started)
                {
                    started = true;
                    var importer = importerFactory(data.timedData.value);
                    copyHandlersTo(importer);
                    importer.start(data.environment);
                }
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
                    return f(d, x);
                }
            ), threaded);
        }
        public static AbstractAction<Env,T1,T2> kleisliMulti<T1,T2>(Func<TimedDataWithEnvironment<Env,T1>,Option<TimedDataWithEnvironment<Env,List<T2>>>> f, bool threaded)
        {
            return new KleisliMultiAction<T1,T2>(f, threaded);
        }
        public static AbstractAction<Env,T1,T2> continuationAction<T1,T2>(Action<TimedDataWithEnvironment<Env,T1>,Action<TimedDataWithEnvironment<Env,T2>>> f, bool threaded)
        {
            return new ContinuationAction<T1,T2>(f, threaded);
        }
        public static AbstractAction<Env,T1,T2> delayedImporter<T1,T2>(AbstractImporter<Env,T2> importer)
        {
            return new DelayedImporter<T1,T2>(importer);
        } 
        public static AbstractAction<Env,T1,T2> lazyImporter<T1,T2>(Func<T1,AbstractImporter<Env,T2>> importerFactory)
        {
            return new LazyImporter<T1,T2>(importerFactory);
        } 
        class KleisliAction2<T1,T2,OutT> : AbstractAction2<Env,T1,T2,OutT>
        {
            private Func<TimedDataWithEnvironment<Env,Either<T1,T2>>,Option<TimedDataWithEnvironment<Env,OutT>>> func;
            public void actuallyHandle(TimedDataWithEnvironment<Env,Either<T1,T2>> data)
            {
                var res = func(
                    data
                );
                if (res.HasValue)
                {
                    publish(res.Unwrap());
                }
            }
            private IHandler2<Env,T1,T2> realHandler;
            public KleisliAction2(Func<TimedDataWithEnvironment<Env,Either<T1,T2>>,Option<TimedDataWithEnvironment<Env,OutT>>> func, bool threaded)
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
            private Func<TimedDataWithEnvironment<Env,Either<T1,T2>>,Option<TimedDataWithEnvironment<Env,List<OutT>>>> func;
            public void actuallyHandle(TimedDataWithEnvironment<Env,Either<T1,T2>> data)
            {
                var res = func(
                    data
                );
                if (res.HasValue)
                {
                    var yVal = res.Unwrap();
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
            public KleisliMultiAction2(Func<TimedDataWithEnvironment<Env,Either<T1,T2>>,Option<TimedDataWithEnvironment<Env,List<OutT>>>> func, bool threaded)
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
        public static AbstractAction2<Env,T1,T2,OutT> liftPure2<T1,T2,OutT>(Func<Either<T1,T2>,OutT> f, bool threaded) 
        {
            return new KleisliAction2<T1,T2,OutT>(KleisliUtils<Env>.liftPure<Either<T1,T2>,OutT>(f), threaded);
        }
        public static AbstractAction2<Env,T1,T2,OutT> liftMaybe<T1,T2,OutT>(Func<Either<T1,T2>,Option<OutT>> f, bool threaded) 
        {
            return new KleisliAction2<T1,T2,OutT>(KleisliUtils<Env>.liftMaybe<Either<T1,T2>,OutT>(f), threaded);
        }
        public static AbstractAction2<Env,T1,T2,OutT> enhancedMaybe2<T1,T2,OutT>(Func<long,Either<T1,T2>,Option<OutT>> f, bool threaded) 
        {
            return new KleisliAction2<T1,T2,OutT>(KleisliUtils<Env>.enhancedMaybe<Either<T1,T2>,OutT>(f), threaded);
        }
        public static AbstractAction2<Env,T1,T2,OutT> kleisli2<T1,T2,OutT>(Func<TimedDataWithEnvironment<Env,Either<T1,T2>>,Option<TimedDataWithEnvironment<Env,OutT>>> f, bool threaded) 
        {
            return new KleisliAction2<T1,T2,OutT>(f, threaded);
        }
        public static AbstractAction2<Env,T1,T2,OutT> liftMulti2<T1,T2,OutT>(Func<Either<T1,T2>,List<OutT>> f, bool threaded)
        {
            return new KleisliMultiAction2<T1,T2,OutT>(KleisliUtils<Env>.liftPure<Either<T1,T2>,List<OutT>>(f), threaded);
        }
        public static AbstractAction2<Env,T1,T2,OutT> enhancedMulti2<T1,T2,OutT>(Func<long,Either<T1,T2>,List<OutT>> f, bool threaded)
        {
            return new KleisliMultiAction2<T1,T2,OutT>(KleisliUtils<Env>.enhancedMaybe<Either<T1,T2>,List<OutT>>(
                (long d, Either<T1,T2> x) => {
                    return f(d, x);
                }
            ), threaded);
        }
        public static AbstractAction2<Env,T1,T2,OutT> kleisliMulti2<T1,T2,OutT>(Func<TimedDataWithEnvironment<Env,Either<T1,T2>>,Option<TimedDataWithEnvironment<Env,List<OutT>>>> f, bool threaded)
        {
            return new KleisliMultiAction2<T1,T2,OutT>(f, threaded);
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