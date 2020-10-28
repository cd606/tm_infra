using System;

namespace Dev.CD606.TM.Infra
{
    public class Key<T>
    {
        public readonly string id;
        public readonly T key;
        public Key(string id, T key) {
            this.id = id;
            this.key = key;
        }
        public Key(T key) {
            this.id = Guid.NewGuid().ToString();
            this.key = key;
        }
    }

    public class KeyedData<A,B>
    {
        public readonly Key<A> key;
        public readonly B data;
        public KeyedData(Key<A> key, B data) {
            this.key = key;
            this.data = data;
        }
    }

    public class VersionedData<Version, T> where Version : IComparable
    {
        public readonly Version version;
        public readonly T data;
        public VersionedData(Version version, T data) {
            this.version = version;
            this.data = data;
        }
    }

    public class GroupedVersionedData<GroupID, Version, T> where Version : IComparable
    {
        public readonly GroupID groupID;
        public readonly Version version;
        public readonly T data;
        public GroupedVersionedData(GroupID groupID, Version version, T data) {
            this.groupID = groupID;
            this.version = version;
            this.data = data;
        }
    }

    public class WithTime<T> 
    {
        public readonly DateTimeOffset timePoint;
        public readonly T value;
        public readonly bool finalFlag;
        public WithTime(DateTimeOffset timePoint, T value, bool finalFlag) {
            this.timePoint = timePoint;
            this.value = value;
            this.finalFlag = finalFlag;
        }
    }

    public class TimedDataWithEnvironment<Env, T>
    {
        public readonly Env environment;
        public readonly WithTime<T> timedData;
        public TimedDataWithEnvironment(Env environment, WithTime<T> timedData) {
            this.environment = environment;
            this.timedData = timedData;
        }
    }

    public enum LogLevel 
    {
        Trace,
        Debug,
        Info,
        Warning,
        Error,
        Critical
    }

    public interface EnvBase 
    {
        DateTimeOffset now();
        void log(LogLevel level, string s);
        void exit();
    }

    public static class InfraUtils 
    {
        public static Key<T> keyify<T>(T x) 
        {
            return new Key<T>(x);
        }
        public static TimedDataWithEnvironment<Env,T> pureTimedDataWithEnvironment<Env,T>(Env env, T t, bool finalFlag=false) where Env : EnvBase 
        {
            return new TimedDataWithEnvironment<Env, T>(
                env
                , new WithTime<T>(
                    env.now()
                    , t
                    , finalFlag
                )
            );
        }
        public static TimedDataWithEnvironment<Env,T2> mapTimedDataWithEnvironment<Env,T1,T2>(Func<T1,T2> func, TimedDataWithEnvironment<Env,T1> x)
        {
            return new TimedDataWithEnvironment<Env, T2>(
                x.environment
                , new WithTime<T2>(
                    x.timedData.timePoint
                    , func(x.timedData.value)
                    , x.timedData.finalFlag
                )
            );
        } 
    }
}
