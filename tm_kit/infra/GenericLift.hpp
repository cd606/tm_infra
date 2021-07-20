#ifndef TM_KIT_INFRA_GENERIC_LIFT_HPP_
#define TM_KIT_INFRA_GENERIC_LIFT_HPP_

#include <functional>
#include <type_traits>
#include <tm_kit/infra/WithTimeData.hpp>
#include <tm_kit/infra/KleisliUtils.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    class LiftAsMulti {};
    class LiftAsFacility {};
    template <class TriggerType>
    class DelayImporter {};
    template <class InputType>
    class LazyImporter {};
    class CurtailAction {};

    template <class M>
    class GenericLift {
    private:
        template <class F>
        class GenericLiftTypeFinder {
        private:
            using T = std::decay_t<decltype(&F::operator())>;

            template <class X>
            class Types {
            };
            template <class A, class B>
            class Types<A (F::*)(B)> {
            public:
                using InputType = std::decay_t<B>;
                using OutputType = std::decay_t<A>;
            };
            template <class A, class B>
            class Types<A (F::*)(B) const> {
            public:
                using InputType = std::decay_t<B>;
                using OutputType = std::decay_t<A>;
            };
            template <class A, class B>
            class Types<A (F::*)(B) volatile> {
            public:
                using InputType = std::decay_t<B>;
                using OutputType = std::decay_t<A>;
            };
            template <class A, class B>
            class Types<A (F::*)(B) &> {
            public:
                using InputType = std::decay_t<B>;
                using OutputType = std::decay_t<A>;
            };
            template <class A, class B>
            class Types<A (F::*)(B) &&> {
            public:
                using InputType = std::decay_t<B>;
                using OutputType = std::decay_t<A>;
            };
        public:
            using InputType = typename Types<T>::InputType;
            using OutputType = typename Types<T>::OutputType;
#ifdef _MSC_VER
            static constexpr bool IsBareFunction = false;
#endif
        };
        template <class A, class B>
        class GenericLiftTypeFinder<A (*)(B)> {
        public:
            using InputType = std::decay_t<B>;
            using OutputType = std::decay_t<A>;
#ifdef _MSC_VER
            static constexpr bool IsBareFunction = false;
#endif
        };
        template <class A, class B>
        class GenericLiftTypeFinder<A (&)(B)> {
        public:
            using InputType = std::decay_t<B>;
            using OutputType = std::decay_t<A>;
#ifdef _MSC_VER
            static constexpr bool IsBareFunction = false;
#endif
        };
        template <class A, class B>
        class GenericLiftTypeFinder<A(B)> {
        public:
            using InputType = std::decay_t<B>;
            using OutputType = std::decay_t<A>;
#ifdef _MSC_VER
            static constexpr bool IsBareFunction = true;
#endif
        };
        template <class A, class B>
        class GenericLiftTypeFinder<std::function<A(B)>> {
        public:
            using InputType = std::decay_t<B>;
            using OutputType = std::decay_t<A>;
#ifdef _MSC_VER
            static constexpr bool IsBareFunction = false;
#endif
        };
        template <class X>
        struct IsInnerData {
            static constexpr bool Value = false;
        };
        template <class T>
    #if _MSC_VER
        struct IsInnerData<TimedDataWithEnvironment<T, typename M::StateType, typename M::TimePoint>> {
    #else
        struct IsInnerData<typename M::template InnerData<T>> {
    #endif
            static constexpr bool Value = true;
        };
        
        template <class A, class B, bool IsID=IsInnerData<A>::Value>
        class GenericLiftImpl {};

        template <class A, class B>
        class GenericLiftImpl<A, B, false> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template liftPure<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
        class GenericLiftImpl<A, std::optional<B>, false> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template liftMaybe<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
        class GenericLiftImpl<std::tuple<typename M::TimePoint, A>, std::optional<B>, false> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template enhancedMaybe<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
    #if _MSC_VER
        class GenericLiftImpl<TimedDataWithEnvironment<A, typename M::StateType, typename M::TimePoint>, std::optional<TimedDataWithEnvironment<B, typename M::StateType, typename M::TimePoint>>, true> {
    #else
        class GenericLiftImpl<typename M::template InnerData<A>, typename M::template Data<B>, true> {
    #endif
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template kleisli<A>(std::move(f), liftParam);
            }
        };
        template <class A>
        class GenericLiftImpl<A, void, false> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template pureExporter<A>(std::move(f), liftParam);
            }
        };
        template <class A>
    #ifdef _MSC_VER
        class GenericLiftImpl<A, void, true> {
    #else
        class GenericLiftImpl<typename M::template InnerData<A>, void, true> {
    #endif
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
    #ifdef _MSC_VER
                return M::template simpleExporter<typename A::ValueType>(std::move(f), liftParam);
    #else
                return M::template simpleExporter<A>(std::move(f), liftParam); 
    #endif
            }
        };
        template <class A>
    #ifdef _MSC_VER 
        class GenericLiftImpl<typename M::EnvironmentType *, std::tuple<bool, std::optional<TimedDataWithEnvironment<A, typename M::StateType, typename M::TimePoint>>>, false> {
    #else
        class GenericLiftImpl<typename M::EnvironmentType *, std::tuple<bool, typename M::template Data<A>>, false> {
    #endif
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template uniformSimpleImporter<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
        class GenericLiftMultiImpl {
        };
        template <class A, class B>
        class GenericLiftMultiImpl<A, std::vector<B>> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template liftMulti<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
        class GenericLiftMultiImpl<std::tuple<typename M::TimePoint, A>, std::vector<B>> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template enhancedMulti<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
    #ifdef _MSC_VER
        class GenericLiftMultiImpl<TimedDataWithEnvironment<A, typename M::StateType, typename M::TimePoint>, std::optional<TimedDataWithEnvironment<std::vector<B>, typename M::StateType, typename M::TimePoint>>> {
    #else
        class GenericLiftMultiImpl<typename M::template InnerData<A>, typename M::template Data<std::vector<B>>> {
    #endif
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template kleisliMulti<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B, bool IsID=IsInnerData<A>::Value>
        class GenericLiftFacilityImpl {};

        template <class A, class B>
        class GenericLiftFacilityImpl<A, B, false> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template liftPureOnOrderFacility<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
        class GenericLiftFacilityImpl<A, std::optional<B>, false> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template liftMaybeOnOrderFacility<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
        class GenericLiftFacilityImpl<std::tuple<typename M::TimePoint, A>, std::optional<B>, false> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template enhancedMaybeOnOrderFacility<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
    #if _MSC_VER
        class GenericLiftFacilityImpl<TimedDataWithEnvironment<A, typename M::StateType, typename M::TimePoint>, std::optional<TimedDataWithEnvironment<B, typename M::StateType, typename M::TimePoint>>, true> {
    #else
        class GenericLiftFacilityImpl<typename M::template InnerData<A>, typename M::template Data<B>, true> {
    #endif
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template kleisliOnOrderFacility<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B, bool IsID=IsInnerData<A>::Value>
        class GenericLiftKUImpl {};

        template <class A, class B>
        class GenericLiftKUImpl<A, B, false> {
        public:
            template <class F>
            static auto lift(F &&f) {
                return KleisliUtils<M>::template liftPure<A>(std::move(f));
            }
        };
        template <class A, class B>
        class GenericLiftKUImpl<A, std::optional<B>, false> {
        public:
            template <class F>
            static auto lift(F &&f) {
                return KleisliUtils<M>::template liftMaybe<A>(std::move(f));
            }
        };
        template <class A, class B>
        class GenericLiftKUImpl<std::tuple<typename M::TimePoint, A>, std::optional<B>, false> {
        public:
            template <class F>
            static auto lift(F &&f) {
                return KleisliUtils<M>::template enhancedMaybe<A>(std::move(f));
            }
        };
        template <class A, class B>
    #if _MSC_VER
        class GenericLiftKUImpl<TimedDataWithEnvironment<A, typename M::StateType, typename M::TimePoint>, std::optional<TimedDataWithEnvironment<B, typename M::StateType, typename M::TimePoint>>, true> {
    #else
        class GenericLiftKUImpl<typename M::template InnerData<A>, typename M::template Data<B>, true> {
    #endif
        public:
            template <class F>
            static auto lift(F &&f) {
                return KleisliUtils<M>::template kleisli<A>(std::move(f));
            }
        };
        template <class A>
        class GenericLiftKUImpl<A, void, false> {
        public:
            template <class F>
            static auto lift(F &&f) {
                return KleisliUtils<M>::template exporterFromPure<A>(std::move(f));
            }
        };
        template <class A>
    #ifdef _MSC_VER
        class GenericLiftKUImpl<A, void, true> {
    #else
        class GenericLiftKUImpl<typename M::template InnerData<A>, void, true> {
    #endif
        public:
            template <class F>
            static auto lift(F &&f) {
    #ifdef _MSC_VER
                return KleisliUtils<M>::template exporterHolder<typename A::ValueType>(std::move(f));
    #else
                return KleisliUtils<M>::template exporterHolder<A>(std::move(f)); 
    #endif
            }
        };
    public:
        template <class F>
        static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint> {}) {
#ifdef _MSC_VER            
            if constexpr (GenericLiftTypeFinder<F>::IsBareFunction) {
                return lift<F*>(&f, liftParam);
            } else {
#endif
                return GenericLiftImpl<
                    typename GenericLiftTypeFinder<F>::InputType
                    , typename GenericLiftTypeFinder<F>::OutputType
                >::template lift<F>(std::move(f), liftParam);
#ifdef _MSC_VER
            }
#endif
        }
        template <class F>
        static auto liftMulti(F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint> {}) {
#ifdef _MSC_VER            
            if constexpr (GenericLiftTypeFinder<F>::IsBareFunction) {
                return liftMulti<F*>(&f, liftParam);
            } else {
#endif
                return GenericLiftMultiImpl<
                    typename GenericLiftTypeFinder<F>::InputType
                    , typename GenericLiftTypeFinder<F>::OutputType
                >::template lift<F>(std::move(f), liftParam);
#ifdef _MSC_VER
            }
#endif
        }
        template <class F>
        static auto liftFacility(F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint> {}) {
#ifdef _MSC_VER            
            if constexpr (GenericLiftTypeFinder<F>::IsBareFunction) {
                return liftFacility<F*>(&f, liftParam);
            } else {
#endif
                return GenericLiftFacilityImpl<
                    typename GenericLiftTypeFinder<F>::InputType
                    , typename GenericLiftTypeFinder<F>::OutputType
                >::template lift<F>(std::move(f), liftParam);
#ifdef _MSC_VER
            }
#endif
        }
        template <class F>
        static auto liftKU(F &&f) {
#ifdef _MSC_VER            
            if constexpr (GenericLiftTypeFinder<F>::IsBareFunction) {
                return liftKU<F*>(&f);
            } else {
#endif
                if constexpr (KleisliUtils<M>::template IsAlreadyWrapped<std::decay_t<F>>::value) {
                    return std::move(f);
                } else {
                    return GenericLiftKUImpl<
                        typename GenericLiftTypeFinder<F>::InputType
                        , typename GenericLiftTypeFinder<F>::OutputType
                    >::template lift<F>(std::move(f));
                }
#ifdef _MSC_VER
            }
#endif
        }
        template <class F>
        static auto lift(LiftAsMulti &&, F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint> {}) {
            return liftMulti<F>(std::move(f), liftParam);
        }
        template <class F>
        static auto lift(LiftAsFacility &&, F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint> {}) {
            return liftFacility<F>(std::move(f), liftParam);
        }
        template <class DelayTrigger, class F>
        static auto lift(DelayImporter<DelayTrigger> &&, F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint> {}) {
            auto imp = lift<F>(std::move(f), liftParam);
            return M::template delayedImporter<DelayTrigger, typename std::decay_t<decltype(*imp)>::DataType>(std::move(*imp));
        }
        template <class LazyInput, class F>
        static auto lift(LazyImporter<LazyInput> &&, F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint> {}) {
            auto factory = [f=std::move(f),liftParam](LazyInput &&input) mutable {
                return M::template uniformSimpleImporter<
                    typename std::decay_t<decltype(
                        std::get<1>((f(std::move(* ((LazyInput *) nullptr))))((typename M::EnvironmentType *) nullptr))
                    )>::value_type::ValueType
                >(f(std::move(input)), liftParam);
            };
            return M::template lazyImporter<LazyInput, typename std::decay_t<decltype(*factory(std::move(* ((LazyInput *) nullptr))))>::DataType>(factory);
        }
        template <class F>
        static auto lift(CurtailAction &&, F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint> {}) {
            auto action = lift<F>(std::move(f), liftParam);
            return M::template curtailedAction<typename std::decay_t<decltype(*action)>::InputType, typename std::decay_t<decltype(*action)>::OutputType>(std::move(*action));
        }
    };
} } } }

#endif