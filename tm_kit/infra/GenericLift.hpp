#ifndef TM_KIT_INFRA_GENERIC_LIFT_HPP_
#define TM_KIT_INFRA_GENERIC_LIFT_HPP_

#include <functional>
#include <type_traits>
#include <tm_kit/infra/WithTimeData.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {
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
        };
        template <class A, class B>
        class GenericLiftTypeFinder<A (*)(B)> {
        public:
            using InputType = std::decay_t<B>;
            using OutputType = std::decay_t<A>;
        };
        template <class A, class B>
        class GenericLiftTypeFinder<A (&)(B)> {
        public:
            using InputType = std::decay_t<B>;
            using OutputType = std::decay_t<A>;
        };
        template <class A, class B>
        class GenericLiftTypeFinder<std::function<A(B)>> {
        public:
            using InputType = std::decay_t<B>;
            using OutputType = std::decay_t<A>;
        };
        template <class A, class B>
        class GenericLiftImpl {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template liftPure<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
        class GenericLiftImpl<A, std::optional<B>> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template liftMaybe<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
        class GenericLiftImpl<std::tuple<typename M::TimePoint, A>, std::optional<B>> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template enhancedMaybe<A>(std::move(f), liftParam);
            }
        };
        template <class A, class B>
        class GenericLiftImpl<typename M::InnerData<A>, typename M::Data<B>> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template kleisli<A>(std::move(f), liftParam);
            }
        };
        template <class A>
        class GenericLiftImpl<A, void> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template pureExporter<A>(std::move(f), liftParam);
            }
        };
        template <class A>
        class GenericLiftImpl<typename M::InnerData<A>, void> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template simpleExporter<A>(std::move(f), liftParam);
            }
        };
        template <class A>
        class GenericLiftImpl<typename M::EnvironmentType *, std::tuple<bool, typename M::template Data<A>>> {
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
        class GenericLiftMultiImpl<typename M::InnerData<A>, typename M::Data<std::vector<B>>> {
        public:
            template <class F>
            static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam) {
                return M::template kleisliMulti<A>(std::move(f), liftParam);
            }
        };
    public:
        template <class F>
        static auto lift(F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint> {}) {
            return GenericLiftImpl<
                typename GenericLiftTypeFinder<F>::InputType
                , typename GenericLiftTypeFinder<F>::OutputType
            >::template lift<F>(std::move(f), liftParam);
        }
        template <class F>
        static auto liftMulti(F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint> {}) {
            return GenericLiftMultiImpl<
                typename GenericLiftTypeFinder<F>::InputType
                , typename GenericLiftTypeFinder<F>::OutputType
            >::template lift<F>(std::move(f), liftParam);
        }
    };
} } } }

#endif