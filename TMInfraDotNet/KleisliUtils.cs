using System;
using Optional;

namespace Dev.CD606.TM.Infra
{
    public static class KleisliUtils 
    {
        public static 
            Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T2>>> 
            liftPure<Env,T1,T2>(Func<T1,T2> f) where Env : EnvBase
        {
            return (TimedDataWithEnvironment<Env,T1> x) => {
                return Option.Some(
                    InfraUtils.mapTimedDataWithEnvironment(f, x)
                );
            };
        }
        public static 
            Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T2>>> 
            liftMaybe<Env,T1,T2>(Func<T1,Option<T2>> f) where Env : EnvBase
        {
            return (TimedDataWithEnvironment<Env,T1> x) => {
                var y = f(x.timedData.value);
                return y.Match(
                    some : yVal => Option.Some(
                        new TimedDataWithEnvironment<Env, T2>(
                            x.environment
                            , new WithTime<T2>(
                                x.timedData.timePoint
                                , yVal
                                , x.timedData.finalFlag
                            )
                        )
                    )
                    , none : () => Option.None<TimedDataWithEnvironment<Env,T2>>()
                );
            };
        }
        public static 
            Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T2>>> 
            enhancedMaybe<Env,T1,T2>(Func<DateTimeOffset,T1,Option<T2>> f) where Env : EnvBase
        {
            return (TimedDataWithEnvironment<Env,T1> x) => {
                var y = f(x.timedData.timePoint, x.timedData.value);
                return y.Match(
                    some : yVal => Option.Some(
                        new TimedDataWithEnvironment<Env, T2>(
                            x.environment
                            , new WithTime<T2>(
                                x.timedData.timePoint
                                , yVal
                                , x.timedData.finalFlag
                            )
                        )
                    )
                    , none : () => Option.None<TimedDataWithEnvironment<Env,T2>>()
                );
            };
        }
        public static 
            Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T3>>> 
            compose<Env,T1,T2,T3>(
                Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T2>>> f1
                , Func<TimedDataWithEnvironment<Env,T2>, Option<TimedDataWithEnvironment<Env,T3>>> f2
            ) where Env : EnvBase
        {
            return (TimedDataWithEnvironment<Env,T1> x) => {
                var y = f1(x);
                return y.Match(
                    some : yVal => f2(yVal)
                    , none : () => Option.None<TimedDataWithEnvironment<Env,T3>>()
                );
            };
        }
    }
}