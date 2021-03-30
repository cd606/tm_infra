#ifndef TM_KIT_INFRA_KLEISLI_UTILS_HPP_
#define TM_KIT_INFRA_KLEISLI_UTILS_HPP_

#include <functional>
#include <utility>

//The reason these utilities are introduced is that,
//in RealTimeApp and SinglePassIterationApp, the Actions are 
//are applicative arrows, something like
// Stream a -> Stream b
//And this is why, while we might easily decorate a Kleisli arrow of
// InnerData a -> Data b
//into
// InnerData a -> Data (a,b)
//, it is impossible to simply translate this into a decoration of 
//Actions. (which is why OnOrderFacility's implementation is so 
//"un-natural")
//And moreover, while it is possible to compose Actions (i.e. co-Kleisli
//arrows), such composition does not directly allow a "reverse extraction"
//of a Kleisli arrow out of the composed actions. (which is also why the 
//composition between OnOrderFacility and Action looks so "un-natural").
//This means the composed Actions are not as efficient as they could be.
//
//For all these reasons, we provide some functional utilities on 
//the Kleisli arrows. The idea is that, by expressing everything in the
//"Kleisli space", and then finally make one conversion into "co-Kleisi space",
//we can achieve more natural-looking code and better efficiency.
//These utilities are only supplied for single-input Kleisli arrows because
//multi-input Actions are in general specific logics and do not need
//generic manipulation so much.

namespace dev { namespace cd606 { namespace tm { namespace infra {
    template <class M>
    class KleisliUtils {
    public:
        //The reason we need these inner-classes is that we want to 
        //be able to return them from functions, and lambdas cannot 
        //be returned. Moreover, std::function is not satisfactory 
        //because if the underlying F is not copy-constructible, there
        //will be a lot of issues
        //But we will also provide a std::function definition for convenience

        template <class A, class B>
        using KleisliFunction = std::function<typename M::template Data<B>(typename M::template InnerData<A>)>;

    private:
        template <class A, class F>
        class KleisliFromPure {
        private:
            F f_;
        public:
            KleisliFromPure(F &&f) : f_(std::move(f)) {}

            using B = decltype(f_(A()));
            typename M::template Data<B> operator()(typename M::template InnerData<A> &&x) {
                return M::template pureInnerDataLift<A>(f_, std::move(x));
            }
        };
        template <class A, class F>
        class KleisliFromMaybe {
        private:
            F f_;
        public:
            KleisliFromMaybe(F &&f) : f_(std::move(f)) {}
            
            using B = typename decltype(f_(A()))::value_type;
            typename M::template Data<B> operator()(typename M::template InnerData<A> &&x) {
                auto res = f_(std::move(x.timedData.value));
                if (res) {
                    return M::template pureInnerData<B>(x.environment, {x.timedData.timePoint, std::move(*res), x.timedData.finalFlag});
                } else {
                    return std::nullopt;
                }
            }
        };
        template <class A, class F>
        class KleisliFromEnhancedMaybe {
        private:
            F f_;
        public:
            KleisliFromEnhancedMaybe(F &&f) : f_(std::move(f)) {}
 
            using B = typename decltype(f_(std::tuple<typename M::TimePoint, A>()))::value_type;
            typename M::template Data<B> operator()(typename M::template InnerData<A> &&x) {
                auto res = f_(std::tuple<typename M::TimePoint,A> {x.timedData.timePoint, std::move(x.timedData.value)});
                if (res) {
                    return M::template pureInnerData<B>(x.environment, {x.timedData.timePoint, std::move(*res), x.timedData.finalFlag});
                } else {
                    return std::nullopt;
                }
            }
        };
        template <class A, class F>
        class KleisliMultiFromPure {
        private:
            F f_;
        public:
            KleisliMultiFromPure(F &&f) : f_(std::move(f)) {}
 
            using B = typename decltype(f_(A()))::value_type;
            typename M::template Data<std::vector<B>> operator()(typename M::template InnerData<A> &&x) {
                auto res = f_(std::move(x.timedData.value));
                return M::template pureInnerData<std::vector<B>>(x.environment, {x.timedData.timePoint, std::move(res), x.timedData.finalFlag});
            }
        };
        template <class A, class F>
        class KleisliMultiFromEnhancedMulti {
        private:
            F f_;
        public:
            KleisliMultiFromEnhancedMulti(F &&f) : f_(std::move(f)) {}
 
            using B = typename decltype(f_(std::tuple<typename M::TimePoint, A>()))::value_type;
            typename M::template Data<std::vector<B>> operator()(typename M::template InnerData<A> &&x) {
                auto res = f_(std::tuple<typename M::TimePoint,A> {x.timedData.timePoint, std::move(x.timedData.value)});
                return M::template pureInnerData<std::vector<B>>(x.environment, {x.timedData.timePoint, std::move(res), x.timedData.finalFlag});
            }
        };
        template <class A, class F>
        class KleisliHolder {
        private:
            F f_;
        public:
            KleisliHolder(F &&f) : f_(std::move(f)) {}

            using B = typename decltype(f_(std::move(* (typename M::template InnerData<A> *) nullptr)))::value_type::ValueType;
            typename M::template Data<B> operator()(typename M::template InnerData<A> &&x) {
                return f_(std::move(x));
            }
        };
        template <class A, class F>
        class KleisliMultiHolder {
        private:
            F f_;
        public:
            KleisliMultiHolder(F &&f) : f_(std::move(f)) {}

            using B = typename decltype(f_(std::move(* (typename M::template InnerData<A> *) nullptr)))::value_type::ValueType;
            typename M::template Data<B> operator()(typename M::template InnerData<A> &&x) {
                return f_(std::move(x));
            }
        };
        template <class A, class F, class G>
        class ComposedKleisli {
        private:
            F f_;
            G g_;
        public:
            ComposedKleisli(F &&f, G &&g) : f_(std::move(f)), g_(std::move(g)) {}

            using B = typename decltype(f_(std::move(* (typename M::template InnerData<A> *) nullptr)))::value_type::ValueType;
            using C = typename decltype(g_(std::move(* (typename M::template InnerData<B> *) nullptr)))::value_type::ValueType;
            typename M::template Data<C> operator()(typename M::template InnerData<A> &&x) {
                typename M::template Data<B> y = f_(std::move(x));
                if (y) {
                    return g_(std::move(*y));
                } else {
                    return std::nullopt;
                }
            }
        };
        template <class A, class F, class G>
        class ComposedKleisliExporter {
        private:
            F f_;
            G g_;
        public:
            ComposedKleisliExporter(F &&f, G &&g) : f_(std::move(f)), g_(std::move(g)) {}

            using B = typename decltype(f(std::move(* (typename M::template InnerData<A> *) nullptr)))::value_type::ValueType;
            void operator()(typename M::template InnerData<A> &&x) {
                typename M::template Data<B> y = f_(std::move(x));
                if (y) {
                    g_(std::move(*y));
                }
            }
        };
    public:
        template <class A, class F>
        static KleisliFromPure<A, F> liftPure(F &&f) {
            return KleisliFromPure<A, F>(std::move(f));
        }
        template <class A, class F>
        static KleisliFromMaybe<A, F> liftMaybe(F &&f) {
            return KleisliFromMaybe<A, F>(std::move(f));
        }
        template <class A, class F>
        static KleisliFromEnhancedMaybe<A, F> enhancedMaybe(F &&f) {
            return KleisliFromEnhancedMaybe<A, F>(std::move(f));
        }
        template <class A, class F>
        static KleisliMultiFromPure<A, F> liftMulti(F &&f) {
            return KleisliMultiFromPure<A, F>(std::move(f));
        }
        template <class A, class F>
        static KleisliMultiFromEnhancedMulti<A, F> enhancedMulti(F &&f) {
            return KleisliMultiFromEnhancedMulti<A, F>(std::move(f));
        }
        template <class A, class F>
        static KleisliHolder<A, F> kleisli(F &&f) {
            return KleisliHolder<A, F>(std::move(f));
        }
        template <class A, class F>
        static KleisliMultiHolder<A, F> kleisliMulti(F &&f) {
            return KleisliMultiHolder<A, F>(std::move(f));
        }
        template <class A, class F, class G>
        static ComposedKleisli<A, F, G> compose(F &&f, G &&g) {
            return ComposedKleisli<A, F, G>(std::move(f), std::move(g));
        }
        template <class A, class F, class G>
        static ComposedKleisliExporter<A, F, G> composeExporter(F &&f, G &&g) {
            return ComposedKleisliExporter<A, F, G>(std::move(f), std::move(g));
        }
        
        template <class A, class B>
        static std::shared_ptr<typename M::template Action<A,B>> action(KleisliFunction<A,B> &&f) {
            return M::template kleisli<A>(std::move(f));
        }
        template <class A, class F>
        static auto action(KleisliFromPure<A,F> &&f) {
            return M::template kleisli<A>(std::move(f));
        }
        template <class A, class F>
        static auto action(KleisliFromMaybe<A,F> &&f) {
            return M::template kleisli<A>(std::move(f));
        }
        template <class A, class F>
        static auto action(KleisliFromEnhancedMaybe<A,F> &&f) {
            return M::template kleisli<A>(std::move(f));
        }
        template <class A, class F>
        static auto action(KleisliHolder<A,F> &&f) {
            return M::template kleisli<A>(std::move(f));
        }
        template <class A, class F>
        static auto action(KleisliMultiFromPure<A,F> &&f) {
            return M::template kleisliMulti<A>(std::move(f));
        }
        template <class A, class F>
        static auto action(KleisliMultiFromEnhancedMulti<A,F> &&f) {
            return M::template kleisliMulti<A>(std::move(f));
        }
        template <class A, class F>
        static auto action(KleisliMultiHolder<A,F> &&f) {
            return M::template kleisliMulti<A>(std::move(f));
        }
        template <class A, class F, class G>
        static auto action(ComposedKleisli<A,F,G> &&f) {
            return M::template kleisli<A>(std::move(f));
        }
        template <class F>
        static auto action(F &&f) {
            return M::template kleisli<typename F::InputType>(std::move(f));
        }
    };
} } } }

#endif