using System;
using Here;

namespace Dev.CD606.TM.Infra
{
    public static class KleisliUtils<Env>
    {
        public static 
            Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T2>>> 
            liftPure<T1,T2>(Func<T1,T2> f)
        {
            return (TimedDataWithEnvironment<Env,T1> x) => {
                return InfraUtils.mapTimedDataWithEnvironment(f, x);
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
                    return new TimedDataWithEnvironment<Env, T2>(
                        x.environment
                        , new WithTime<T2>(
                            x.timedData.timePoint
                            , y.Unwrap()
                            , x.timedData.finalFlag
                        )
                    );
                }
                else
                {
                    return Option.None;
                }
            };
        }
        public static 
            Func<TimedDataWithEnvironment<Env,T1>, Option<TimedDataWithEnvironment<Env,T2>>> 
            enhancedMaybe<T1,T2>(Func<long,T1,Option<T2>> f) 
        {
            return (TimedDataWithEnvironment<Env,T1> x) => {
                var y = f(x.timedData.timePoint, x.timedData.value);
                if (y.HasValue)
                {
                    return new TimedDataWithEnvironment<Env, T2>(
                        x.environment
                        , new WithTime<T2>(
                            x.timedData.timePoint
                            , y.Unwrap()
                            , x.timedData.finalFlag
                        )
                    );
                }
                else
                {
                    return Option.None;
                }
            };
        }
        public static 
            Func<int, TimedDataWithEnvironment<Env,T1>, TimedDataWithEnvironment<Env,T2>, Option<TimedDataWithEnvironment<Env,OutT>>> 
            liftPure2<T1,T2,OutT>(Func<int,T1,T2,OutT> f)
        {
            return (int which, TimedDataWithEnvironment<Env,T1> x1, TimedDataWithEnvironment<Env,T2> x2) => {
                return new TimedDataWithEnvironment<Env, OutT>(
                    (which == 0? x1.environment : x2.environment)
                    , new WithTime<OutT>(
                        (which == 0? x1.timedData.timePoint : x2.timedData.timePoint)
                        , f(which, x1.timedData.value, x2.timedData.value)
                        , (x1.timedData.finalFlag && x2.timedData.finalFlag)
                    )
                );
            };
        }
        public static 
            Func<int, TimedDataWithEnvironment<Env,T1>, TimedDataWithEnvironment<Env,T2>, Option<TimedDataWithEnvironment<Env,OutT>>> 
            liftMaybe2<T1,T2,OutT>(Func<int,T1,T2,Option<OutT>> f)
        {
            return (int which, TimedDataWithEnvironment<Env,T1> x1, TimedDataWithEnvironment<Env,T2> x2) => {
                var y = f(which, x1.timedData.value, x2.timedData.value);
                if (y.HasValue)
                {
                    return new TimedDataWithEnvironment<Env, OutT>(
                        (which == 0? x1.environment : x2.environment)
                        , new WithTime<OutT>(
                            (which == 0? x1.timedData.timePoint : x2.timedData.timePoint)
                            , y.Unwrap()
                            , (x1.timedData.finalFlag && x2.timedData.finalFlag)
                        )
                    );
                }
                else
                {
                    return Option.None;
                }
            };
        }
        public static 
            Func<int, TimedDataWithEnvironment<Env,T1>, TimedDataWithEnvironment<Env,T2>, Option<TimedDataWithEnvironment<Env,OutT>>> 
            enhancedMaybe2<T1,T2,OutT>(Func<int,long,T1,T2,Option<OutT>> f)
        {
            return (int which, TimedDataWithEnvironment<Env,T1> x1, TimedDataWithEnvironment<Env,T2> x2) => {
                var y = f(which, (which==0? x1.timedData.timePoint : x2.timedData.timePoint), x1.timedData.value, x2.timedData.value);
                if (y.HasValue)
                {
                    return new TimedDataWithEnvironment<Env, OutT>(
                        (which == 0? x1.environment : x2.environment)
                        , new WithTime<OutT>(
                            (which == 0? x1.timedData.timePoint : x2.timedData.timePoint)
                            , y.Unwrap()
                            , (x1.timedData.finalFlag && x2.timedData.finalFlag)
                        )
                    );
                }
                else
                {
                    return Option.None;
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
                    return f2(y.Unwrap());
                }
                else
                {
                    return Option.None;
                }
            };
        }
    }
}