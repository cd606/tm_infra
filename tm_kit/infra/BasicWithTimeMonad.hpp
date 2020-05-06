#ifndef TM_KIT_INFRA_BASIC_WITHTIME_MONAD_HPP_
#define TM_KIT_INFRA_BASIC_WITHTIME_MONAD_HPP_

#include <future>
#include <tm_kit/infra/WithTimeData.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {

    template <class StateT>
    class BasicWithTimeMonad {
    private:
        friend class MonadRunner<BasicWithTimeMonad>;
        BasicWithTimeMonad() = default;
        ~BasicWithTimeMonad() = default;
    public:
        using TimePoint = typename StateT::TimePointType;
        using StateType = StateT;
        using EnvironmentType = StateT;
        template <class T>
        using TimedDataType = WithTime<T, TimePoint>;
        template <class T>
        using Key = Key<T,StateT>;
        template <class A, class B>
        using KeyedData = KeyedData<A,B,StateT>;

        template <class T>
        using InnerData = TimedDataWithEnvironment<T, StateType, TimePoint>;

        template <class T>
        static InnerData<T> pureInnerData(StateT *env, T &&t, bool finalFlag = false) {
            return withtime_utils::pureTimedDataWithEnvironment<T, StateT, TimePoint>(env, std::move(t), finalFlag);
        }
        template <class T>
        static InnerData<T> pureInnerData(StateT *env, TimedDataType<T> &&t, bool preserveTime=false) {
            return withtime_utils::pureTimedDataWithEnvironment<T, StateT, TimePoint>(env, std::move(t), preserveTime);
        }
        template <class T>
        static InnerData<T> pureInnerData(InnerData<T> &&t, bool preserveTime=false) {
            return withtime_utils::pureTimedDataWithEnvironment<T, StateT, TimePoint>(std::move(t), preserveTime);
        }
        template <class A, class F>
        static auto pureInnerDataLift(StateT *environment, F const &f, TimedDataType<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime);
        }
        template <class A, class F>
        static auto pureInnerDataLift(F const &f, InnerData<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime);
        }

        template <class T>
        using Data = TimedMonadData<T,StateT>;

        //we don't allow any action to manufacture KeyedData "out of the blue"
        //, but it is ok to manipulate Keys, so the check is one-sided
        template <class A, class B, std::enable_if_t<!is_keyed_data_v<B>, int> = 0>
        using Action = TimedMonadModelKleisli<A,B,StateT>;

        template <class A, class B>
        using OnOrderFacility = TimedMonadModelKleisli<Key<A>,KeyedData<A,B>,StateT>;

    private:
        template <class A, class B>
        static Data<B> apply(Action<A,B> const &action, Data<A> &&x) {
            return withtime_utils::timedMonadApply(action, std::move(x));
        }
        template <class A, class B>
        static Data<KeyedData<A,B>> applyAtOnOrderFacility(OnOrderFacility<A,B> const &action, Data<Key<A>> &&x) {
            return withtime_utils::timedMonadApply(action, std::move(x));
        }

    private:
        template <class T1, class T2, class T3>
        static Action<T1,T3> compose_(Action<T1,T2> &&f1, Action<T2,T3> &&f2) {
            return [f1=std::move(f1),f2=std::move(f2)](InnerData<T1> &&t) {
                return apply(f2, f1(std::move(t)));
            };
        }

        //This lifts A->B to Action<A,B>
        template <class A, class F>
        static auto liftPure_(F &&f, bool suggestThreaded=false, FanInParamMask const &notUsed=FanInParamMask()) 
            -> Action<A, decltype(f(A()))> {
            return [f=std::move(f)](InnerData<A> &&d) -> Data<decltype(f(A()))> {
                return {
                    pureInnerDataLift(f, std::move(d))
                };
            };
        }
        //This lifts A->optional<B> to Action<A,B>
        template <class A, class F>
        static auto liftMaybe_(F &&f, bool suggestThreaded=false) 
            -> Action<A, typename decltype(f(A()))::value_type> {
            return [f=std::move(f)](InnerData<A> &&d) -> Data<typename decltype(f(A()))::value_type> {
                auto x = f(std::move(d.timedData.value));
                if (x) {
                    return {
                        pureInnerData<typename decltype(f(A()))::value_type>(d.environment, {d.timedData.timePoint, std::move(*x), d.timedData.finalFlag})
                    };
                } else {
                    return {std::nullopt};
                }
            };
        }
        //This lifts (time,A)->optional<B> to Action<A,B>
        template <class A, class F>
        static auto enhancedMaybe_(F &&f, bool suggestThreaded=false) 
            -> Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type> {
            return [f=std::move(f)](InnerData<A> &&d) -> Data<typename decltype(f(std::tuple<TimePoint, A>()))::value_type> {
                auto x = f(std::tuple<TimePoint, A> {d.timedData.timePoint, std::move(d.timedData.value)});
                if (x) {
                    return {
                        pureInnerData<typename decltype(f(std::tuple<TimePoint,A>()))::value_type>(d.environment, {d.timedData.timePoint, std::move(*x), d.timedData.finalFlag})
                    };
                } else {
                    return {std::nullopt};
                }
            };
        }
        //This lifts InnerData<A>->Data<B> to Action<A,B>
        template <class A, class F>
        static auto kleisli_(F &&f, bool suggestThreaded=false) 
            -> Action<A, typename decltype(f(pureInnerData(nullptr,A())))::ValueType> {
            return [f=std::move(f)](InnerData<A> &&d) -> decltype(f(std::move(d))) {
                return f(std::move(d));
            };
        }
        //this lifts A->B to OnOrderFacility<A,B>
        template <class A, class F>
        static auto liftPureOnOrderFacility_(F &&f, bool suggestThreaded=false, FanInParamMask const &notUsed=FanInParamMask()) 
            -> OnOrderFacility<A, decltype(f(A()))> {
            return [f=std::move(f)](InnerData<Key<A>> &&d) -> Data<KeyedData<A,decltype(f(A()))>> {
                return {
                    pureInnerDataLift([f=std::move(f)](Key<A> &&k) {
                        return withtime_utils::keyedDataFromKey(f, std::move(k));
                    }, std::move(d))
                };
            };
        }
        //this lifts A->optional<B> to OnOrderFacility<A,B>
        template <class A, class F>
        static auto liftMaybeOnOrderFacility_(F &&f, bool suggestThreaded=false) 
            -> OnOrderFacility<A, typename decltype(f(A()))::value_type> {
            return [f=std::move(f)](InnerData<Key<A>> &&d) -> Data<KeyedData<A,typename decltype(f(A()))::value_type>> {
                Key<A> keyCopy = d.timedData.value;
                auto x = f(std::move(d.timedData.value.key()));
                if (x) {
                    return {
                        pureInnerData<KeyedData<A,typename decltype(f(A()))::value_type>>(d.environment, {d.timedData.timePoint, {keyCopy, std::move(*x)}, d.timedData.finalFlag})
                    };
                } else {
                    return std::nullopt;
                }
            };
        }
        //this lifts (time,A)->optional<B> to OnOrderFacility<A,B>
        template <class A, class F>
        static auto enhancedMaybeOnOrderFacility_(F &&f, bool suggestThreaded=false) 
            -> OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type> {
            return [f=std::move(f)](InnerData<Key<A>> &&d) -> Data<KeyedData<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
                Key<A> keyCopy = d.timedData.value;
                auto x = f(std::tuple<TimePoint,A> {d.timedData.timePoint, std::move(d.timedData.value.key())});
                if (x) {
                    return {
                        pureInnerData<KeyedData<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(d.environment, {d.timedData.timePoint, {keyCopy, std::move(*x)}, d.timedData.finalFlag})
                    };
                } else {
                    return std::nullopt;
                }
            };
        }
        //This lifts InnerData<A>->Data<B> to Action<A,B>
        template <class A, class F>
        static auto kleisliOnOrderFacility_(F &&f, bool suggestThreaded=false) 
            -> OnOrderFacility<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType> {
            using B = typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType;
            return [f=std::move(f)](InnerData<Key<A>> &&d) -> Data<KeyedData<A,B>> {                
                Key<A> keyCopy = d.timedData.value;
                InnerData<A> x = pureInnerDataLift([](Key<A> &&k) -> A {
                    return k.key();
                }, std::move(d));
                Data<B> y = f(std::move(x));
                if (!y) {
                    return std::nullopt;
                }
                return pureInnerDataLift([keyCopy=std::move(keyCopy)](B &&b) -> KeyedData<A,B> {
                    return {std::move(keyCopy), std::move(b)};
                }, std::move(*y));
            };
        }

        template <class I0, class O0, class I1, class O1>
        static OnOrderFacility<I0,O0> wrappedOnOrderFacility_(OnOrderFacility<I1,O1> &&toWrap, Action<Key<I0>,Key<I1>> &&inputT, Action<Key<O1>,Key<O0>> &&outputT) {
            return [toWrap=std::move(toWrap),inputT=std::move(inputT),outputT=std::move(outputT)](InnerData<Key<I0>> &&x) -> Data<KeyedData<I0,O0>> {
                Key<I0> keyCopy = x.timedData.value;
                Data<Key<I1>> i1 = inputT(std::move(x));
                if (i1) {
                    Data<KeyedData<I1,O1>> o1WithKey = toWrap(std::move(*i1));
                    if (o1WithKey) {
                        InnerData<Key<O1>> o1 = pureInnerDataLift([](KeyedData<I1,O1> &&a) -> Key<O1> {
                            return {a.key.id(), std::move(a.data)};
                        }, std::move(*o1WithKey));
                        Data<Key<O0>> o0 = outputT(std::move(o1));
                        if (o0) {
                            return {
                                pureInnerDataLift([keyCopy](Key<O0> &&a) -> KeyedData<I0,O0> {
                                    return {keyCopy, std::move(a.key())};
                                }, std::move(*o0))
                            };
                        } 
                    }
                }
                return std::nullopt;
            };
        }
    public:
        template <class T1, class T2, class T3>
        static std::shared_ptr<Action<T1,T3>> compose(Action<T1,T2> &&f1, Action<T2,T3> &&f2) {
            return std::make_shared<Action<T1,T3>>(compose_<T1,T2,T3>(std::move(f1), std::move(f2)));
        }

        //This lifts A->B to Action<A,B>
        template <class A, class F>
        static auto liftPure(F &&f, bool suggestThreaded=false, FanInParamMask const &notUsed=FanInParamMask()) 
            -> std::shared_ptr<decltype(liftPure_<A,F>(std::move(f), suggestThreaded, notUsed))> {
            return std::make_shared<decltype(liftPure_<A,F>(std::move(f), suggestThreaded, notUsed))>(
                liftPure_<A,F>(std::move(f), suggestThreaded, notUsed)
            );
        }
        //This lifts A->optional<B> to Action<A,B>
        template <class A, class F>
        static auto liftMaybe(F &&f, bool suggestThreaded=false) 
            -> std::shared_ptr<decltype(liftMaybe_<A,F>(std::move(f), suggestThreaded))> {
            return std::make_shared<decltype(liftMaybe_<A,F>(std::move(f), suggestThreaded))>(
                liftMaybe_<A,F>(std::move(f), suggestThreaded)
            );
        }
        //This lifts (time,A)->optional<B> to Action<A,B>
        template <class A, class F>
        static auto enhancedMaybe(F &&f, bool suggestThreaded=false) 
            -> std::shared_ptr<decltype(enhancedMaybe_<A,F>(std::move(f), suggestThreaded))> {
            return std::make_shared<decltype(enhancedMaybe_<A,F>(std::move(f), suggestThreaded))>(
                enhancedMaybe_<A,F>(std::move(f), suggestThreaded)
            );
        }
        //This lifts InnerData<A>->Data<B> to Action<A,B>
        template <class A, class F>
        static auto kleisli(F &&f, bool suggestThreaded=false) 
            -> std::shared_ptr<decltype(kleisli_<A,F>(std::move(f), suggestThreaded))> {
            return std::make_shared<decltype(kleisli_<A,F>(std::move(f), suggestThreaded))>(
                kleisli_<A,F>(std::move(f), suggestThreaded)
            );
        }
        //this lifts A->B to OnOrderFacility<A,B>
        template <class A, class F>
        static auto liftPureOnOrderFacility(F &&f, bool suggestThreaded=false, FanInParamMask const &notUsed=FanInParamMask()) 
            -> std::shared_ptr<decltype(liftPureOnOrderFacility_<A,F>(std::move(f), suggestThreaded, notUsed))> {
            return std::make_shared<decltype(liftPureOnOrderFacility_<A,F>(std::move(f), suggestThreaded, notUsed))>(
                liftPureOnOrderFacility_<A,F>(std::move(f), suggestThreaded, notUsed)
            );
        }
        //this lifts A->optional<B> to OnOrderFacility<A,B>
        template <class A, class F>
        static auto liftMaybeOnOrderFacility(F &&f, bool suggestThreaded=false) 
            -> std::shared_ptr<decltype(liftMaybeOnOrderFacility_<A,F>(std::move(f), suggestThreaded))> {
            return std::make_shared<decltype(liftMaybeOnOrderFacility_<A,F>(std::move(f), suggestThreaded))>(
                liftMaybeOnOrderFacility_<A,F>(std::move(f), suggestThreaded)
            );
        }
        //this lifts (time,A)->optional<B> to OnOrderFacility<A,B>
        template <class A, class F>
        static auto enhancedMaybeOnOrderFacility(F &&f, bool suggestThreaded=false) 
            -> std::shared_ptr<decltype(enhancedMaybeOnOrderFacility_<A,F>(std::move(f), suggestThreaded))> {
            return std::make_shared<decltype(enhancedMaybeOnOrderFacility_<A,F>(std::move(f), suggestThreaded))>(
                enhancedMaybeOnOrderFacility_<A,F>(std::move(f), suggestThreaded)
            );
        }
        //This lifts InnerData<A>->Data<B> to Action<A,B>
        template <class A, class F>
        static auto kleisliOnOrderFacility(F &&f, bool suggestThreaded=false) 
            -> std::shared_ptr<decltype(kleisliOnOrderFacility_<A,F>(std::move(f), suggestThreaded))> {
            return std::make_shared<decltype(kleisliOnOrderFacility_<A,F>(std::move(f), suggestThreaded))>(
                kleisliOnOrderFacility_<A,F>(std::move(f), suggestThreaded)
            );
        }

        template <class I0, class O0, class I1, class O1>
        static auto wrappedOnOrderFacility(OnOrderFacility<I1,O1> &&toWrap, Action<Key<I0>,Key<I1>> &&inputT, Action<Key<O1>,Key<O0>> &&outputT) 
            -> std::shared_ptr<decltype(wrappedOnOrderFacility_<I0,O0,I1,O1>(std::move(toWrap), std::move(inputT), std::move(outputT)))> {
            return std::make_shared<decltype(wrappedOnOrderFacility_<I0,O0,I1,O1>(std::move(toWrap), std::move(inputT), std::move(outputT)))>(
                wrappedOnOrderFacility_<I0,O0,I1,O1>(std::move(toWrap), std::move(inputT), std::move(outputT))
            );
        }
    
    #include <tm_kit/infra/BasicWithTimeMonad_VariantAndMerge_Piece.hpp>
    #include <tm_kit/infra/BasicWithTimeMonad_Pure_Maybe_Kleisli_Piece.hpp>
    
    public:   
        template <class T>
        class Source {
        private:
            friend class BasicWithTimeMonad;
            Data<T> data;
            Source(Data<T> &&d) : data(std::move(d)) {}
        public:
            Source clone() const {
                return Source {
                    withtime_utils::clone(data)
                };
            }
        };
        template <class T>
        class Sink {
        private:
            friend class BasicWithTimeMonad;
            std::function<void(Source<T> &&)> action;
            Sink(std::function<void(Source<T> &&)> f) : action(f) {}
        };

        //KeyedData cannot be imported "out of the blue"
        template <class T, std::enable_if_t<!is_keyed_data_v<T>,int> = 0>
        using Importer = std::function<Data<T>(StateT * const)>;

        //Keys and KeyedData can be exported, for example to be written to database,
        //so there is no check on the exporter
        template <class T>
        using Exporter = std::function<void(InnerData<T> &&)>;

        template <class T, class F>
        static std::shared_ptr<Importer<T>> simpleImporter(F &&f) {
            return std::make_shared<Importer<T>>( std::move(f) );
        }
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> simpleExporter(F &&f) {
            return std::make_shared<Exporter<T>>( std::move(f) );
        }
        
    private:
        template <class T1, class T2>
        static Importer<T2> composeImporter_(Importer<T1> &&orig, Action<T1,T2> &&post) {
            return [orig=std::move(orig),post=std::move(post)](StateT * const env) -> Data<T2> {
                auto d = orig(env);
                if (d) {
                    return post(std::move(*d));
                } else {
                    return std::nullopt;
                }
            };
        }
        template <class T1, class T2>
        static Exporter<T1> composeExporter_(Action<T1,T2> &&pre, Exporter<T2> &&orig) {
            return [pre=std::move(pre),orig=std::move(orig)](InnerData<T1> &&t1) {
                auto t2 = pre(std::move(t1));
                if (t2) {
                    orig(std::move(*t2));
                }
            };
        }
    public:
        template <class T1, class T2>
        static std::shared_ptr<Importer<T2>> composeImporter(Importer<T1> &&orig, Action<T1,T2> &&post) {
            return std::make_shared<Importer<T2>>(composeImporter_<T1,T2>(std::move(orig), std::move(post)));
        }
        template <class T1, class T2>
        static std::shared_ptr<Exporter<T1>> composeExporter(Action<T1,T2> &&pre, Exporter<T2> &&orig) {
            return std::make_shared<Exporter<T1>>(composeExporter_<T1,T2>(std::move(pre), std::move(orig)));
        }
    
    public:
        template <class A, class B, class C>
        struct LocalOnOrderFacility {
            OnOrderFacility<A,B> facility;
            Exporter<C> exporter;
        };

        template <class A, class B, class C>
        static std::shared_ptr<LocalOnOrderFacility<A,B,C>> localOnOrderFacility(
            OnOrderFacility<A,B> &&facility, Exporter<C> &&exporter
        ) {
            return std::make_shared<LocalOnOrderFacility<A,B,C>>(LocalOnOrderFacility<A,B,C> {std::move(facility), std::move(exporter)});
        }
        
        template <class I0, class O0, class I1, class O1, class C>
        static std::shared_ptr<LocalOnOrderFacility<I0,O0,C>> wrappedLocalOnOrderFacility(LocalOnOrderFacility<I1,O1,C> &&toWrap, Action<Key<I0>,Key<I1>> &&inputT, Action<Key<O1>,Key<O0>> &&outputT) {
            return std::make_shared<LocalOnOrderFacility<I0,O0,C>>(LocalOnOrderFacility<I0,O0,C> {
                std::move(*wrappedOnOrderFacility(std::move(toWrap.facility), std::move(inputT), std::move(outputT)))
                , std::move(toWrap.exporter)
            });
        }
   
    private:
        template <class T>
        Source<T> importerAsSource(StateT *env, Importer<T> &importer) {
            return {importer(env)};
        }
        template <class A, class B>
        Source<B> actionAsSource(StateT *env, Action<A,B> &action) {
            return {action(pureInnerData(env, A()))};
        }
        template <class A, class B>
        Source<B> execute(Action<A,B> &action, Source<A> &&variable) {
            return {apply(action, std::move(variable.data))};
        }

        #include <tm_kit/infra/BasicWithTimeMonad_ExecuteAction_Piece.hpp> 

        template <class T>
        Sink<T> exporterAsSink(Exporter<T> &exporter) {
            return Sink<T> {
                [&exporter](Source<T> &&src) {
                    if (src.data) {
                        exporter(std::move(*(src.data)));
                    }
                }
            };
        }
        template <class A, class B>
        Sink<A> actionAsSink(Action<A,B> &action) {
            return Sink<A> {
                [this,&action](Source<A> &&src) {
                    execute(action, std::move(src));
                }
            };
        }

        #include <tm_kit/infra/BasicWithTimeMonad_VariantSink_Piece.hpp>

        template <class A, class B>
        void placeOrderWithFacility(Source<Key<A>> &&input, OnOrderFacility<A,B> &facility, Sink<KeyedData<A,B>> const &sink) {
            sink.action(applyAtOnOrderFacility(facility, std::move(input.data)));
        }  
        template <class A, class B>
        void placeOrderWithFacilityAndForget(Source<Key<A>> &&input, OnOrderFacility<A,B> &facility) {
            applyAtOnOrderFacility(facility, std::move(input.data));
        }  

        template <class A, class B, class C>
        void placeOrderWithLocalFacility(Source<Key<A>> &&input, LocalOnOrderFacility<A,B,C> &facility, Sink<KeyedData<A,B>> const &sink) {
            sink.action(applyAtOnOrderFacility(facility.facility, std::move(input.data)));
        } 
        template <class A, class B, class C>
        void placeOrderWithLocalFacilityAndForget(Source<Key<A>> &&input, LocalOnOrderFacility<A,B,C> &facility) {
            applyAtOnOrderFacility(facility.facility, std::move(input.data));
        } 
        template <class A, class B, class C>
        Sink<C> localFacilityAsSink(LocalOnOrderFacility<A,B,C> &facility) {
            return Sink<C> {
                [&facility](Source<C> &&src) {
                    if (src.data) {
                        facility.exporter(std::move(*(src.data)));
                    }
                }
            };
        }

        template <class T>
        void connect(Source<T> &&src, Sink<T> const &sink) {
            sink.action(std::move(src));
        }

        std::function<void(StateT *)> finalize() {   
            return [](StateT *) {
            };        
        }

    public:
        template <class X>
        struct GetDataType {
        };
        template <class T>
        struct GetDataType<Importer<T>> {
            using DataType = T;
        };
        template <class T>
        struct GetDataType<Exporter<T>> {
            using DataType = T;
        };
        template <class A, class B, class C>
        struct GetDataType<LocalOnOrderFacility<A,B,C>> {
            using DataType = C;
        };
        template <class X>
        struct GetInputOutputType {
        };
        template <class A, class B>
        struct GetInputOutputType<Action<A,B>> {
            using InputType = A;
            using OutputType = B;
        };
        template <class A, class B>
        struct GetInputOutputType<OnOrderFacility<A,B>> {
            using InputType = A;
            using OutputType = B;
        };
        template <class A, class B, class C>
        struct GetInputOutputType<LocalOnOrderFacility<A,B,C>> {
            using InputType = A;
            using OutputType = B;
        };
    };

}}}}

#endif