using System;
using Optional;
using Optional.Unsafe;

namespace Dev.CD606.TM.Infra
{
    public static class KleisliUtils<Env>
    {
        public static 
            Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T2>>> 
            liftPure<T1,T2>(Func<T1,T2> f)
        {
            return (TimedDataWithEnvironment<Env,T1> x) => {
                return Option.Some(
                    InfraUtils.mapTimedDataWithEnvironment(f, x)
                );
            };
        }
        public static 
            Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T2>>> 
            liftMaybe<T1,T2>(Func<T1,Option<T2>> f) 
        {
            return (TimedDataWithEnvironment<Env,T1> x) => {
                var y = f(x.timedData.value);
                if (y.HasValue)
                {
                    return Option.Some(
                        new TimedDataWithEnvironment<Env, T2>(
                            x.environment
                            , new WithTime<T2>(
                                x.timedData.timePoint
                                , y.ValueOrFailure()
                                , x.timedData.finalFlag
                            )
                        )
                    );
                }
                else
                {
                    return Option.None<TimedDataWithEnvironment<Env,T2>>();
                }
            };
        }
        public static 
            Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T2>>> 
            enhancedMaybe<T1,T2>(Func<DateTimeOffset,T1,Option<T2>> f) 
        {
            return (TimedDataWithEnvironment<Env,T1> x) => {
                var y = f(x.timedData.timePoint, x.timedData.value);
                if (y.HasValue)
                {
                    return Option.Some(
                        new TimedDataWithEnvironment<Env, T2>(
                            x.environment
                            , new WithTime<T2>(
                                x.timedData.timePoint
                                , y.ValueOrFailure()
                                , x.timedData.finalFlag
                            )
                        )
                    );
                }
                else
                {
                    return Option.None<TimedDataWithEnvironment<Env,T2>>();
                }
            };
        }
        public static 
            Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T3>>> 
            compose<T1,T2,T3>(
                Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T2>>> f1
                , Func<TimedDataWithEnvironment<Env,T2>, Option<TimedDataWithEnvironment<Env,T3>>> f2
            ) 
        {
            return (TimedDataWithEnvironment<Env,T1> x) => {
                var y = f1(x);
                if (y.HasValue)
                {
                    return f2(y.ValueOrFailure());
                }
                else
                {
                    return Option.None<TimedDataWithEnvironment<Env,T3>>();
                }
            };
        }
    }
}