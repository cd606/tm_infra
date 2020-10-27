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

    public static class RealTimeAppUtils
    {
        class SimpleImporter<Env,T> : AbstractImporter<Env,T> where Env : EnvBase
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

            }
        }
        public static AbstractImporter<Env,T> simpleImporter<Env,T>(
            Action<Env, Action<T, bool>> generator
        ) where Env : EnvBase
        {
            return new SimpleImporter<Env,T>(generator);
        }

        public class TriggerImporter<Env, T> : AbstractImporter<Env, T> where Env : EnvBase
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
        public static TriggerImporter<Env,T> triggerImporter<Env,T>() where Env : EnvBase
        {
            return new TriggerImporter<Env, T>();
        }
        public class ConstTriggerImporter<Env, T> : AbstractImporter<Env, T> where Env : EnvBase
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
        public static ConstTriggerImporter<Env,T> constTriggerImporter<Env,T>(T t) where Env : EnvBase
        {
            return new ConstTriggerImporter<Env, T>(t);
        }
        public static AbstractImporter<Env,T> constFirstPushImporter<Env,T>(T t) where Env : EnvBase
        {
            return simpleImporter<Env,T>(
                (Env env, Action<T, bool> pub) => {
                    pub(t, true);
                }
            );
        }
        public static AbstractImporter<Env,Key<T>> constFirstPushKeyImporter<Env,T>(T t) where Env : EnvBase
        {
            return simpleImporter<Env,Key<T>>(
                (Env env, Action<Key<T>, bool> pub) => {
                    pub(InfraUtils.keyify<T>(t), true);
                }
            );
        }
        class SimpleExporter<Env, T> : AbstractExporter<Env, T> where Env : EnvBase
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
        public static AbstractExporter<Env,T> simpleExporter<Env,T>(Action<TimedDataWithEnvironment<Env,T>> f, bool threaded) where Env : EnvBase
        {
            return new SimpleExporter<Env,T>(f, threaded);
        }
        public static AbstractExporter<Env,T> pureExporter<Env,T>(Action<T> f, bool threaded) where Env : EnvBase
        {
            return simpleExporter<Env,T>(
                (TimedDataWithEnvironment<Env,T> data) => {
                    f(data.timedData.value);
                }
                , threaded
            );
        }
    }
}