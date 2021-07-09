#ifndef TM_KIT_INFRA_KLEISLI_UTILS_HPP_
#define TM_KIT_INFRA_KLEISLI_UTILS_HPP_

#include <functional>
#include <utility>
#include <tm_kit/infra/WithTimeData.hpp>

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
            friend class KleisliUtils<M>;
        public:
            KleisliFromPure(F &&f) : f_(std::move(f)) {}

            using InputType = A;
            using B = decltype(f_(A()));
            using OutputType = B;
            typename M::template Data<B> operator()(typename M::template InnerData<A> &&x) {
                return M::template pureInnerDataLift<A>(f_, std::move(x));
            }
        };
        template <class A, class F>
        class KleisliFromMaybe {
        private:
            F f_;
            friend class KleisliUtils<M>;
        public:
            KleisliFromMaybe(F &&f) : f_(std::move(f)) {}
            
            using InputType = A;
            using B = typename decltype(f_(A()))::value_type;
            using OutputType = B;
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
            friend class KleisliUtils<M>;
        public:
            KleisliFromEnhancedMaybe(F &&f) : f_(std::move(f)) {}

            using InputType = A;
            using B = typename decltype(f_(std::tuple<typename M::TimePoint, A>()))::value_type;
            using OutputType = B;
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
        class KleisliHolder {
        private:
            F f_;
            friend class KleisliUtils<M>;
        public:
            KleisliHolder(F &&f) : f_(std::move(f)) {}

            using InputType = A;
            using B = typename decltype(f_(std::move(* (typename M::template InnerData<A> *) nullptr)))::value_type::ValueType;
            using OutputType = B;
            typename M::template Data<B> operator()(typename M::template InnerData<A> &&x) {
                return f_(std::move(x));
            }
        };
        template <class A, class F>
        class KleisliExporterFromPure {
        private:
            F f_;
            friend class KleisliUtils<M>;
        public:
            KleisliExporterFromPure(F &&f) : f_(std::move(f)) {}

            using InputType = A;
            using OutputType = void;
            void operator()(typename M::template InnerData<A> &&x) {
                f_(std::move(x.timedData.value));
            }
        };
        template <class A, class F>
        class KleisliExporterHolder {
        private:
            F f_;
            friend class KleisliUtils<M>;
        public:
            KleisliExporterHolder(F &&f) : f_(std::move(f)) {}

            using InputType = A;
            using OutputType = void;
            void operator()(typename M::template InnerData<A> &&x) {
                f_(std::move(x));
            }
        };
        template <class F, class G>
        class ComposedKleisli {
        private:
            F f_;
            G g_;
            friend class KleisliUtils<M>;
        public:
            ComposedKleisli(F &&f, G &&g) : f_(std::move(f)), g_(std::move(g)) {}

            using InputType = typename F::InputType;
            using A = InputType;
            using B = typename decltype(f_(std::move(* (typename M::template InnerData<A> *) nullptr)))::value_type::ValueType;
            using C = typename decltype(g_(std::move(* (typename M::template InnerData<B> *) nullptr)))::value_type::ValueType;
            using OutputType = C;
            typename M::template Data<C> operator()(typename M::template InnerData<A> &&x) {
                typename M::template Data<B> y = f_(std::move(x));
                if (y) {
                    return g_(std::move(*y));
                } else {
                    return std::nullopt;
                }
            }
        };
        template <class F, class G>
        class ComposedKleisliExporter {
        private:
            F f_;
            G g_;
            friend class KleisliUtils<M>;
        public:
            ComposedKleisliExporter(F &&f, G &&g) : f_(std::move(f)), g_(std::move(g)) {}

            using InputType = typename F::InputType;
            using A = InputType;
            using B = typename decltype(f_(std::move(* (typename M::template InnerData<A> *) nullptr)))::value_type::ValueType;
            using OutputType = void;
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
        static KleisliHolder<A, F> kleisli(F &&f) {
            return KleisliHolder<A, F>(std::move(f));
        }
        template <class A, class F>
        static KleisliExporterFromPure<A, F> exporterFromPure(F &&f) {
            return KleisliExporterFromPure<A, F>(std::move(f));
        }
        template <class A, class F>
        static KleisliExporterHolder<A, F> exporterHolder(F &&f) {
            return KleisliExporterHolder<A, F>(std::move(f));
        }
        template <class F, class G>
        static auto compose(F &&f, G &&g) {
            if constexpr (std::is_same_v<typename G::OutputType, void>) {
                return ComposedKleisliExporter<F, G>(std::move(f), std::move(g));
            } else {
                return ComposedKleisli<F, G>(std::move(f), std::move(g));
            }
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromPure<A,F> &&f, KleisliFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable {
                //std::cerr << "P->P\n";
                return g(f(std::move(a)));
            };
            return KleisliFromPure<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromPure<A,F> &&f, KleisliFromMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable {
                //std::cerr << "P->M\n";
                return g(f(std::move(a)));
            };
            return KleisliFromMaybe<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromPure<A,F> &&f, KleisliFromEnhancedMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable {
                //std::cerr << "P->EM\n";
                return g(std::tuple<typename M::TimePoint, B> { std::get<0>(a), f(std::move(std::get<1>(a))) });
            };
            return KleisliFromEnhancedMaybe<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromPure<A,F> &&f, KleisliHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "P->K\n";
                return g(M::template pureInnerDataLift<A>(f, std::move(a)));
            };
            return KleisliHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromPure<A,F> &&f, KleisliExporterFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable {
                //std::cerr << "P->E\n";
                g(f(std::move(a)));
            };
            return KleisliExporterFromPure<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromPure<A,F> &&f, KleisliExporterHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "P->KE\n";
                g(M::template pureInnerDataLift<A>(f, std::move(a)));
            };
            return KleisliExporterHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMaybe<A,F> &&f, KleisliFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable 
                -> std::optional<decltype(g.f_(std::move(*((B *) nullptr))))>
            {
                //std::cerr << "M->P\n";
                auto b = f(std::move(a));
                if (b) {
                    return g(std::move(*b));
                } else {
                    return std::nullopt;
                }
            };
            return KleisliFromMaybe<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMaybe<A,F> &&f, KleisliFromMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable 
                -> decltype(g.f_(std::move(*((B *) nullptr))))
            {
                //std::cerr << "M->M\n";
                auto b = f(std::move(a));
                if (b) {
                    return g(std::move(*b));
                } else {
                    return std::nullopt;
                }
            };
            return KleisliFromMaybe<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMaybe<A,F> &&f, KleisliFromEnhancedMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))
            {
                //std::cerr << "M->EM\n";
                auto b = f(std::move(std::get<1>(a)));
                if (b) {
                    return g(std::tuple<typename M::TimePoint, B> { std::get<0>(a), std::move(*b) });
                } else {
                    return std::nullopt;
                }
            };
            return KleisliFromEnhancedMaybe<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMaybe<A,F> &&f, KleisliHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> decltype(g.f_(std::move(*((typename M::InnerData<B> *) nullptr))))
            {
                //std::cerr << "M->K\n";
                auto b = f(std::move(a.timedData.value));
                if (b) {
                    return g(typename M::template InnerData<B> { 
                        a.environment 
                        , {
                            a.timedData.timePoint 
                            , std::move(*b)
                            , a.timedData.finalFlag
                        }
                    });
                } else {
                    return std::nullopt;
                }
            };
            return KleisliHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMaybe<A,F> &&f, KleisliExporterFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable {
                //std::cerr << "M->E\n";
                auto b = f(std::move(a));
                if (b) {
                    g(std::move(*b));
                }
            };
            return KleisliExporterFromPure<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMaybe<A,F> &&f, KleisliFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> std::optional<decltype(g.f_(std::move(*((B *) nullptr))))>
            {
                //std::cerr << "EM->P\n";
                auto b = f(std::move(a));
                if (b) {
                    return g(std::move(*b));
                } else {
                    return std::nullopt;
                }
            };
            return KleisliFromEnhancedMaybe<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMaybe<A,F> &&f, KleisliFromMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> decltype(g.f_(std::move(*((B *) nullptr))))
            {
                //std::cerr << "EM->M\n";
                auto b = f(std::move(a));
                if (b) {
                    return g(std::move(*b));
                } else {
                    return std::nullopt;
                }
            };
            return KleisliFromEnhancedMaybe<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMaybe<A,F> &&f, KleisliFromEnhancedMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))
            {
                //std::cerr << "EM->EM\n";
                auto b = f(std::tuple<typename M::TimePoint, A> { std::get<0>(a), std::move(std::get<1>(a)) });
                if (b) {
                    return g(std::tuple<typename M::TimePoint, B> { std::get<0>(a), std::move(*b) });
                } else {
                    return std::nullopt;
                }
            };
            return KleisliFromEnhancedMaybe<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMaybe<A,F> &&f, KleisliHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> decltype(g.f_(std::move(*((typename M::InnerData<B> *) nullptr))))
            {
                //std::cerr << "EM->K\n";
                auto b = f(std::tuple<typename M::TimePoint, A> {a.timedData.timePoint, std::move(a.timedData.value)});
                if (b) {
                    return g(typename M::template InnerData<B> { 
                        a.environment 
                        , {
                            a.timedData.timePoint 
                            , std::move(*b)
                            , a.timedData.finalFlag
                        }
                    });
                } else {
                    return std::nullopt;
                }
            };
            return KleisliHolder<A,decltype(h)>(std::move(h));
        }
        template <class F, class G>
        static ComposedKleisliExporter<F, G> composeExporter(F &&f, G &&g) {
            return ComposedKleisliExporter<F, G>(std::move(f), std::move(g));
        }
        
        template <class A, class B>
        static std::shared_ptr<typename M::template Action<A,B>> action(KleisliFunction<A,B> &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisli<A>(std::move(f), liftParam);
        }
        template <class A, class F>
        static auto action(KleisliFromPure<A,F> &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisli<A>(std::move(f), liftParam);
        }
        template <class A, class F>
        static auto action(KleisliFromMaybe<A,F> &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisli<A>(std::move(f), liftParam);
        }
        template <class A, class F>
        static auto action(KleisliFromEnhancedMaybe<A,F> &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisli<A>(std::move(f), liftParam);
        }
        template <class A, class F>
        static auto action(KleisliHolder<A,F> &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisli<A>(std::move(f), liftParam);
        }
        template <class F, class G>
        static auto action(ComposedKleisli<F,G> &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisli<typename F::InputType>(std::move(f), liftParam);
        }
        template <class F>
        static auto action(F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisli<typename F::InputType>(std::move(f), liftParam);
        }
    };
} } } }

#endif