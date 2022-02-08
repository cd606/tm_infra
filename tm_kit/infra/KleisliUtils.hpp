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
        class KleisliFromMulti {
        private:
            F f_;
            friend class KleisliUtils<M>;
        public:
            KleisliFromMulti(F &&f) : f_(std::move(f)) {}
            
            using InputType = A;
            using B = typename decltype(f_(A()))::value_type;
            using OutputType = B;
            typename M::template Data<std::vector<B>> operator()(typename M::template InnerData<A> &&x) {
                auto res = f_(std::move(x.timedData.value));
                if (res) {
                    return M::template pureInnerData<std::vector<B>>(x.environment, {x.timedData.timePoint, std::move(*res), x.timedData.finalFlag});
                } else {
                    return std::nullopt;
                }
            }
        };
        template <class A, class F>
        class KleisliFromEnhancedMulti {
        private:
            F f_;
            friend class KleisliUtils<M>;
        public:
            KleisliFromEnhancedMulti(F &&f) : f_(std::move(f)) {}
            
            using InputType = A;
            using B = typename decltype(f_(std::tuple<typename M::TimePoint, A>()))::value_type;
            using OutputType = B;
            typename M::template Data<std::vector<B>> operator()(typename M::template InnerData<A> &&x) {
                auto res = f_(std::tuple<typename M::TimePoint,A> {x.timedData.timePoint, std::move(x.timedData.value)});
                if (res) {
                    return M::template pureInnerData<std::vector<B>>(x.environment, {x.timedData.timePoint, std::move(*res), x.timedData.finalFlag});
                } else {
                    return std::nullopt;
                }
            }
        };
        template <class A, class F>
        class KleisliMultiHolder {
        private:
            F f_;
            friend class KleisliUtils<M>;
        public:
            KleisliMultiHolder(F &&f) : f_(std::move(f)) {}

            using InputType = A;
            using B = typename decltype(f_(std::move(* (typename M::template InnerData<A> *) nullptr)))::value_type::ValueType::value_type;
            using OutputType = B;
            typename M::template Data<std::vector<B>> operator()(typename M::template InnerData<A> &&x) {
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
        static KleisliFromMulti<A, F> liftMulti(F &&f) {
            return KleisliFromMulti<A, F>(std::move(f));
        }
        template <class A, class F>
        static KleisliFromEnhancedMulti<A, F> enhancedMulti(F &&f) {
            return KleisliFromEnhancedMulti<A, F>(std::move(f));
        }
        template <class A, class F>
        static KleisliMultiHolder<A, F> kleisliMulti(F &&f) {
            return KleisliMultiHolder<A, F>(std::move(f));
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
        static auto compose(KleisliFromPure<A,F> &&f, KleisliFromMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable {
                //std::cerr << "P->Mul\n";
                return g(f(std::move(a)));
            };
            return KleisliFromMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromPure<A,F> &&f, KleisliFromEnhancedMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable {
                //std::cerr << "P->EMul\n";
                return g(std::tuple<typename M::TimePoint, B> { std::get<0>(a), f(std::move(std::get<1>(a))) });
            };
            return KleisliFromEnhancedMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromPure<A,F> &&f, KleisliMultiHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "P->KMul\n";
                return g(M::template pureInnerDataLift<A>(f, std::move(a)));
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
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
                -> decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))
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
        static auto compose(KleisliFromMaybe<A,F> &&f, KleisliFromMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable 
                -> decltype(g.f_(std::move(*((B *) nullptr))))
            {
                //std::cerr << "M->Mul\n";
                auto b = f(std::move(a));
                if (b) {
                    return g(std::move(*b));
                } else {
                    return std::nullopt;
                }
            };
            return KleisliFromMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMaybe<A,F> &&f, KleisliFromEnhancedMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))
            {
                //std::cerr << "M->EMul\n";
                auto b = f(std::move(std::get<1>(a)));
                if (b) {
                    return g(std::tuple<typename M::TimePoint, B> { std::get<0>(a), std::move(*b) });
                } else {
                    return std::nullopt;
                }
            };
            return KleisliFromEnhancedMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMaybe<A,F> &&f, KleisliMultiHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))
            {
                //std::cerr << "M->KMul\n";
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
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
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
        static auto compose(KleisliFromMaybe<A,F> &&f, KleisliExporterHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "M->KE\n";
                auto b = f(std::move(a.timedData.value));
                if (b) {
                    g(typename M::template InnerData<B> {
                        a.environment 
                        , {
                            a.timedData.timePoint 
                            , std::move(*b)
                            , a.timedData.finalFlag
                        }
                    });
                }
            };
            return KleisliExporterHolder<A,decltype(h)>(std::move(h));
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
                -> decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))
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
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMaybe<A,F> &&f, KleisliFromMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> decltype(g.f_(std::move(*((B *) nullptr))))
            {
                //std::cerr << "EM->Mul\n";
                auto b = f(std::move(a));
                if (b) {
                    return g(std::move(*b));
                } else {
                    return std::nullopt;
                }
            };
            return KleisliFromEnhancedMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMaybe<A,F> &&f, KleisliFromEnhancedMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))
            {
                //std::cerr << "EM->EMul\n";
                auto b = f(std::tuple<typename M::TimePoint, A> { std::get<0>(a), std::move(std::get<1>(a)) });
                if (b) {
                    return g(std::tuple<typename M::TimePoint, B> { std::get<0>(a), std::move(*b) });
                } else {
                    return std::nullopt;
                }
            };
            return KleisliFromEnhancedMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMaybe<A,F> &&f, KleisliMultiHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))
            {
                //std::cerr << "EM->KMul\n";
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
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMaybe<A,F> &&f, KleisliExporterFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "EM->E\n";
                auto b = f(std::tuple<typename M::TimePoint, A> {a.timedData.timePoint, std::move(a.timedData.value)});
                if (b) {
                    g(std::move(*b));
                }
            };
            return KleisliExporterHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMaybe<A,F> &&f, KleisliExporterHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "EM->KE\n";
                auto b = f(std::tuple<typename M::TimePoint, A> {a.timedData.timePoint, std::move(a.timedData.value)});
                if (b) {
                    g(typename M::template InnerData<B> {
                        a.environment 
                        , {
                            a.timedData.timePoint 
                            , std::move(*b)
                            , a.timedData.finalFlag
                        }
                    });
                }
            };
            return KleisliExporterHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliHolder<A,F> &&f, KleisliFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<decltype(g.f_(std::move(*((B *) nullptr))))>
            {
                //std::cerr << "K->P\n";
                auto b = f(std::move(a));
                if (b) {
                    return typename M::template InnerData<decltype(g(std::move(*((B *) nullptr))))> {
                        b->environment 
                        , {
                            b->timedData.timePoint  
                            , g(std::move(b->timedData.value))
                            , b->timedData.finalFlag
                        }
                    };  
                } else {
                    return std::nullopt;
                }
            };
            return KleisliHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliHolder<A,F> &&f, KleisliFromMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type>
            {
                //std::cerr << "K->M\n";
                auto b = f(std::move(a));
                if (b) {
                    auto c = g(std::move(b->timedData.value));
                    if (c) {
                        return typename M::template InnerData<typename decltype(g(std::move(*((B *) nullptr))))::value_type> {
                            b->environment 
                            , {
                                b->timedData.timePoint  
                                , std::move(*c)
                                , b->timedData.finalFlag
                            }
                        };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
            };
            return KleisliHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliHolder<A,F> &&f, KleisliFromEnhancedMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type>
            {
                //std::cerr << "K->EM\n";
                auto b = f(std::move(a));
                if (b) {
                    auto c = g(std::tuple<typename M::TimePoint, B> {b->timedData.timePoint, std::move(b->timedData.value)});
                    if (c) {
                        return typename M::template InnerData<typename decltype(g(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type> {
                            b->environment 
                            , {
                                b->timedData.timePoint  
                                , std::move(*c)
                                , b->timedData.finalFlag
                            }
                        };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
            };
            return KleisliHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliHolder<A,F> &&f, KleisliHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))
            {
                //std::cerr << "K->K\n";
                auto b = f(std::move(a));
                if (b) {
                    return g(std::move(*b));
                } else {
                    return std::nullopt;
                }
            };
            return KleisliHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliHolder<A,F> &&f, KleisliFromMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type>>
            {
                //std::cerr << "K->Mul\n";
                auto b = f(std::move(a));
                if (b) {
                    return typename M::template InnerData<std::vector<typename decltype(g(std::move(*((B *) nullptr))))::value_type>> {
                        b->environment 
                        , {
                            b->timedData.timePoint  
                            , g(std::move(b->timedData.value))
                            , b->timedData.finalFlag
                        }
                    };
                } else {
                    return std::nullopt;
                }
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliHolder<A,F> &&f, KleisliFromEnhancedMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type>>
            {
                //std::cerr << "K->EMul\n";
                auto b = f(std::move(a));
                if (b) {
                    return typename M::template InnerData<std::vector<typename decltype(g(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type>> {
                        b->environment 
                        , {
                            b->timedData.timePoint  
                            , g(std::tuple<typename M::TimePoint, B> {b->timedData.timePoint, std::move(b->timedData.value)})
                            , b->timedData.finalFlag
                        }
                    };
                } else {
                    return std::nullopt;
                }
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliHolder<A,F> &&f, KleisliMultiHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))
            {
                //std::cerr << "K->KMul\n";
                auto b = f(std::move(a));
                if (b) {
                    return g(std::move(*b));
                } else {
                    return std::nullopt;
                }
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliHolder<A,F> &&f, KleisliExporterFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "K->E\n";
                auto b = f(std::move(a));
                if (b) {
                    g(std::move(b->timedData.value));
                }
            };
            return KleisliExporterHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliHolder<A,F> &&f, KleisliExporterHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "K->KE\n";
                auto b = f(std::move(a));
                if (b) {
                    g(std::move(*b));
                }
            };
            return KleisliExporterHolder<A,decltype(h)>(std::move(h));
        }
        /*
        template <class F, class G>
        static ComposedKleisliExporter<F, G> composeExporter(F &&f, G &&g) {
            return ComposedKleisliExporter<F, G>(std::move(f), std::move(g));
        }
        */
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMulti<A,F> &&f, KleisliFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable 
                -> std::vector<decltype(g.f_(std::move(*((B *) nullptr))))>
            {
                //std::cerr << "Mul->P\n";
                std::vector<decltype(g.f_(std::move(*((B *) nullptr))))> output;
                for (auto &&x : f(std::move(a))) {
                    output.push_back(g(std::move(x)));
                }
                return std::move(output);
            };
            return KleisliFromMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMulti<A,F> &&f, KleisliFromMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable 
                -> std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type>
            {
                //std::cerr << "Mul->M\n";
                std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type> output;
                for (auto &&x : f(std::move(a))) {
                    auto y = g(std::move(x));
                    if (y) {
                        output.push_back(std::move(*y));
                    }
                    output.push_back(g(std::move(x)));
                }
                return std::move(output);
            };
            return KleisliFromMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMulti<A,F> &&f, KleisliFromEnhancedMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type>
            {
                //std::cerr << "Mul->EM\n";
                std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type> output;
                for (auto &&x : f(std::move(a))) {
                    auto y = g(std::tuple<typename M::TimePoint, B> { std::get<0>(a), std::move(x) });
                    if (y) {
                        output.push_back(std::move(*y));
                    }
                    output.push_back(g(std::move(x)));
                }
                return std::move(output);
            };
            return KleisliFromEnhancedMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMulti<A,F> &&f, KleisliHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType>>
            {
                //std::cerr << "Mul->K\n";
                std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType> output;
                typename M::TimePoint tp = a.timedData.timePoint;
                bool finalFlag = false;

                for (auto &&x : f(std::move(a.timedData.value))) {
                    auto y = g(typename M::template InnerData<B> { 
                        a.environment 
                        , {
                            a.timedData.timePoint 
                            , std::move(x)
                            , a.timedData.finalFlag
                        }
                    });
                    if (y) {
                        finalFlag = y->timedData.finalFlag;
                        tp = y->timedData.timePoint;
                        output.push_back(std::move(y->timedData.value));
                    }
                }
                return typename M::template InnerData<std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType>> {
                    a.environment
                    , {
                        tp 
                        , std::move(output)
                        , finalFlag
                    }
                };
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMulti<A,F> &&f, KleisliFromMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable 
                -> std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type>
            {
                //std::cerr << "Mul->Mul\n";
                std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type> output;
                for (auto &&x : f(std::move(a))) {
                    for (auto &&y : g(std::move(x))) {
                        output.push_back(std::move(y));
                    }
                }
                return std::move(output);
            };
            return KleisliFromMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMulti<A,F> &&f, KleisliFromEnhancedMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type>
            {
                //std::cerr << "Mul->EMul\n";
                std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type> output;
                for (auto &&x : f(std::move(std::get<1>(a)))) {
                    for (auto &&y: g(std::tuple<typename M::TimePoint, B> { std::get<0>(a), std::move(x) })) {
                        output.push_back(std::move(y));
                    }
                }
                return std::move(output);
            };
            return KleisliFromEnhancedMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMulti<A,F> &&f, KleisliMultiHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))
            {
                //std::cerr << "Mul->KMul\n";
                std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType::value_type> output;
                typename M::TimePoint tp = a.timedData.timePoint;
                bool finalFlag = false;

                for (auto &&x : f(std::move(a.timedData.value))) {
                    auto y = g(typename M::template InnerData<B> { 
                        a.environment 
                        , {
                            a.timedData.timePoint 
                            , std::move(x)
                            , a.timedData.finalFlag
                        }
                    });
                    if (y) {
                        finalFlag = y->timedData.finalFlag;
                        tp = y->timedData.timePoint;
                        for (auto &&y1 : std::move(y->timedData.value)) {
                            output.push_back(std::move(y1));
                        }
                    }
                }
                return typename M::template InnerData<std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType>> {
                    a.environment
                    , {
                        tp 
                        , std::move(output)
                        , finalFlag
                    }
                };
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMulti<A,F> &&f, KleisliExporterFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](A &&a) mutable {
                //std::cerr << "M->E\n";
                for (auto &&x: f(std::move(a))) {
                    g(std::move(x));
                }
            };
            return KleisliExporterFromPure<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromMulti<A,F> &&f, KleisliExporterHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "M->KE\n";
                for (auto &&x : f(std::move(a.timedData.value))) {
                    g(typename M::template InnerData<B> {
                        a.environment 
                        , {
                            a.timedData.timePoint 
                            , std::move(x)
                            , a.timedData.finalFlag
                        }
                    });
                }
            };
            return KleisliExporterHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMulti<A,F> &&f, KleisliFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> std::vector<decltype(g.f_(std::move(*((B *) nullptr))))>
            {
                //std::cerr << "EMul->P\n";
                std::vector<decltype(g.f_(std::move(*((B *) nullptr))))> output;
                for (auto &&x: f(std::move(a))) {
                    output.push_back(g(std::move(x)));
                }
                return std::move(output);
            };
            return KleisliFromEnhancedMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMulti<A,F> &&f, KleisliFromMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type>
            {
                //std::cerr << "EMul->M\n";
                std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type> output;
                for (auto &&x: f(std::move(a))) {
                    auto y = g(std::move(x));
                    if (y) {
                        output.push_back(std::move(*y));
                    }
                }
                return std::move(output);
            };
            return KleisliFromEnhancedMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMulti<A,F> &&f, KleisliFromEnhancedMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type>
            {
                //std::cerr << "EMul->EM\n";
                std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type> output;
                for (auto &&x : f(std::tuple<typename M::TimePoint, A> { std::get<0>(a), std::move(std::get<1>(a)) })) {
                    auto y = g(std::tuple<typename M::TimePoint, B> { std::get<0>(a), std::move(x) });
                    if (y) {
                        output.push_back(std::move(*y));
                    }
                }
                return std::move(output);
            };
            return KleisliFromEnhancedMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMulti<A,F> &&f, KleisliHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType>>
            {
                //std::cerr << "EMul->K\n";
                std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType> output;
                typename M::TimePoint tp = a.timedData.timePoint;
                bool finalFlag = false;
                for (auto &&x: f(std::tuple<typename M::TimePoint, A> {a.timedData.timePoint, std::move(a.timedData.value)})) {
                    auto y = g(typename M::template InnerData<B> { 
                        a.environment 
                        , {
                            a.timedData.timePoint 
                            , std::move(x)
                            , a.timedData.finalFlag
                        }
                    });
                    if (y) {
                        tp = y->timedData.timePoint;
                        finalFlag = y->timedData.finalFlag;
                        output.push_back(std::move(y->timedData.value));
                    }
                }
                return typename M::template InnerData<std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType>> {
                    a.environment
                    , {
                        tp 
                        , std::move(output)
                        , finalFlag
                    }
                };
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMulti<A,F> &&f, KleisliFromMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type>
            {
                //std::cerr << "EMul->Mul\n";
                std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type> output;
                for (auto &&x: f(std::move(a))) {
                    for (auto &&y : g(std::move(x))) {
                        output.push_back(std::move(y));
                    }
                }
                return std::move(output);
            };
            return KleisliFromEnhancedMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMulti<A,F> &&f, KleisliFromEnhancedMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](std::tuple<typename M::TimePoint, A> &&a) mutable 
                -> std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type>
            {
                //std::cerr << "EMul->EMul\n";
                std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type> output;
                for (auto &&x : f(std::tuple<typename M::TimePoint, A> { std::get<0>(a), std::move(std::get<1>(a)) })) {
                    for (auto &&y : g(std::tuple<typename M::TimePoint, B> { std::get<0>(a), std::move(x) })) {
                        output.push_back(std::move(y));
                    }
                }
                return std::move(output);
            };
            return KleisliFromEnhancedMulti<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMulti<A,F> &&f, KleisliMultiHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType::Value_type>>
            {
                //std::cerr << "EMul->KMul\n";
                std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType::Value_type> output;
                typename M::TimePoint tp = a.timedData.timePoint;
                bool finalFlag = false;
                for (auto &&x : f(std::tuple<typename M::TimePoint, A> {a.timedData.timePoint, std::move(a.timedData.value)})) {
                    auto y = g(typename M::template InnerData<B> { 
                        a.environment 
                        , {
                            a.timedData.timePoint 
                            , std::move(x)
                            , a.timedData.finalFlag
                        }
                    });
                    if (y) {
                        tp = y->timedData.timePoint;
                        finalFlag = y->timedData.finalFlag;
                        for (auto &&y1 : y->timedData.value) {
                            output.push_back(std::move(y1));
                        }
                    }
                }
                return typename M::template InnerData<std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType::Value_type>> {
                    a.environment 
                    , {
                        tp
                        , std::move(output)
                        , finalFlag
                    }
                };
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMulti<A,F> &&f, KleisliExporterFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "EMul->E\n";
                for (auto &&x : f(std::tuple<typename M::TimePoint, A> {a.timedData.timePoint, std::move(a.timedData.value)})) {
                    g(std::move(x));
                }
            };
            return KleisliExporterHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliFromEnhancedMulti<A,F> &&f, KleisliExporterHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "EMul->KE\n";
                for (auto &&x : f(std::tuple<typename M::TimePoint, A> {a.timedData.timePoint, std::move(a.timedData.value)})) {
                    g(typename M::template InnerData<B> {
                        a.environment 
                        , {
                            a.timedData.timePoint 
                            , std::move(x)
                            , a.timedData.finalFlag
                        }
                    });
                }
            };
            return KleisliExporterHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliMultiHolder<A,F> &&f, KleisliFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<decltype(g.f_(std::move(*((B *) nullptr))))>>
            {
                //std::cerr << "KMul->P\n";
                std::vector<decltype(g.f_(std::move(*((B *) nullptr))))> output;
                auto b = f(std::move(a));
                if (!b) {
                    return std::nullopt;
                }
                for (auto &&x : std::move(b->timedData.value)) {
                    output.push_back(g(std::move(x)));
                }
                return typename M::template InnerData<std::vector<decltype(g.f_(std::move(*((B *) nullptr))))>> {
                    b->environment 
                    , {
                        b->timedData.value.timePoint
                        , std::move(output)
                        , b->timedData.value.finalFlag
                    }
                };
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliMultiHolder<A,F> &&f, KleisliFromMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type>>
            {
                //std::cerr << "KMul->M\n";
                auto b = f(std::move(a));
                if (b) {
                    std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type> output;
                    for (auto &&x: std::move(b->timedData.value)) {
                        auto c = g(std::move(x));
                        if (c) {
                            output.push_back(std::move(*c));
                        }
                    }
                    return typename M::template InnerData<std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type>> {
                        b->environment
                        , {
                            b->timedData.timePoint
                            , std::move(output)
                            , b->timedData.finalFlag
                        }
                    };
                } else {
                    return std::nullopt;
                }
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliMultiHolder<A,F> &&f, KleisliFromEnhancedMaybe<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type>>
            {
                //std::cerr << "KMul->EM\n";
                auto b = f(std::move(a));
                if (b) {
                    std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type> output;
                    for (auto &&x : std::move(b->timedData.value)) {
                        auto c = g(std::tuple<typename M::TimePoint, B> {b->timedData.timePoint, std::move(x)});
                        if (c) {
                            output.push_back(std::move(*c));
                        }
                    }
                    return typename M::template InnerData<std::vector<typename decltype(g(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type>> {
                        b->environment 
                        , {
                            b->timedData.timePoint  
                            , std::move(output)
                            , b->timedData.finalFlag
                        }
                    };
                } else {
                    return std::nullopt;
                }
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliMultiHolder<A,F> &&f, KleisliHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType>>
            {
                //std::cerr << "KMul->K\n";
                auto b = f(std::move(a));
                if (b) {
                    std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType> output;
                    typename M::TimePoint tp = b->timedData.timePoint;
                    bool finalFlag = b->timedData.finalFlag;
                    for (auto &&x : std::move(b->timedData.value)) {
                        auto c = g(typename M::template InnerData<B> {
                            b->environment 
                            , {
                                b->timedData.timePoint
                                , std::move(x)
                                , b->timedData.finalFlag
                            }
                        });
                        if (c) {
                            tp = c->timedData.timePoint;
                            finalFlag = c->timedData.finalFlag;
                            output.push_back(std::move(c->timedData.value));
                        }
                    }
                    return typename M::template InnerData<std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType>> {
                        b->environment
                        , {
                            tp 
                            , std::move(output)
                            , finalFlag
                        }
                    };
                } else {
                    return std::nullopt;
                }
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliMultiHolder<A,F> &&f, KleisliFromMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type>>
            {
                //std::cerr << "KMul->Mul\n";
                auto b = f(std::move(a));
                if (b) {
                    std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type> output;
                    for (auto &&x: std::move(b->timedData.value)) {
                        for (auto &&y : g(std::move(x))) {
                            output.push_back(std::move(y));
                        }
                    }
                    return typename M::template InnerData<std::vector<typename decltype(g.f_(std::move(*((B *) nullptr))))::value_type>> {
                        b->environment 
                        , {
                            b->timedData.timePoint  
                            , std::move(output)
                            , b->timedData.finalFlag
                        }
                    };
                } else {
                    return std::nullopt;
                }
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliMultiHolder<A,F> &&f, KleisliFromEnhancedMulti<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type>>
            {
                //std::cerr << "KMul->EMul\n";
                auto b = f(std::move(a));
                if (b) {
                    std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type> output;
                    for (auto &&x : std::move(b->timedData.value)) {
                        for (auto &&y : g(std::tuple<typename M::TimePoint, B> {b->timedData.timePoint, std::move(x)})) {
                            output.push_back(std::move(y));
                        }
                    }
                    return typename M::template InnerData<std::vector<typename decltype(g.f_(std::move(*((std::tuple<typename M::TimePoint, B> *) nullptr))))::value_type>> {
                        b->environment 
                        , {
                            b->timedData.timePoint  
                            , std::move(output)
                            , b->timedData.finalFlag
                        }
                    };
                } else {
                    return std::nullopt;
                }
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliMultiHolder<A,F> &&f, KleisliMultiHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable 
                -> typename M::template Data<std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType::value_type>>
            {
                //std::cerr << "KMul->KMul\n";
                auto b = f(std::move(a));
                if (b) {
                    std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType::value_type> output;
                    typename M::TimePoint tp = b->timedData.timePoint;
                    bool finalFlag = b->timedData.finalFlag;
                    for (auto &&x : std::move(b->timedData.value)) {
                        auto c = g(typename M::template InnerData<B> {
                            b->environment 
                            , {
                                b->timedData.timePoint
                                , std::move(x)
                                , b->timedData.finalFlag
                            }
                        });
                        if (c) {
                            tp = c->timedData.timePoint;
                            finalFlag = c->timedData.finalFlag;
                            for (auto &&y : std::move(c->timedData.value)) {
                                output.push_back(std::move(y));
                            }
                        }
                    }
                    return typename M::template InnerData<std::vector<typename decltype(g.f_(std::move(*((typename M::template InnerData<B> *) nullptr))))::value_type::ValueType::value_type>> {
                        b->environment 
                        , {
                            tp 
                            , std::move(output)
                            , finalFlag
                        }
                    };
                } else {
                    return std::nullopt;
                }
            };
            return KleisliMultiHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliMultiHolder<A,F> &&f, KleisliExporterFromPure<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "KMul->E\n";
                auto b = f(std::move(a));
                if (b) {
                    for (auto &&x : std::move(b->timedData.value)) {
                        g(std::move(x));
                    }
                }
            };
            return KleisliExporterHolder<A,decltype(h)>(std::move(h));
        }
        template <class A, class F, class B, class G>
        static auto compose(KleisliMultiHolder<A,F> &&f, KleisliExporterHolder<B,G> &&g) {
            auto h = [f=std::move(f.f_),g=std::move(g.f_)](typename M::template InnerData<A> &&a) mutable {
                //std::cerr << "KMul->KE\n";
                auto b = f(std::move(a));
                if (b) {
                    for (auto &&x : std::move(b->timedData.value)) {
                        g(typename M::template InnerData<B> {
                            b->environment 
                            , {
                                b->timedData.timePoint
                                , std::move(x)
                                , b->timedData.finalFlag
                            }
                        });
                    }
                }
            };
            return KleisliExporterHolder<A,decltype(h)>(std::move(h));
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
        template <class A, class F>
        static auto action(KleisliFromMulti<A,F> &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisliMulti<A>(std::move(f), liftParam);
        }
        template <class A, class F>
        static auto action(KleisliFromEnhancedMulti<A,F> &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisliMulti<A>(std::move(f), liftParam);
        }
        template <class A, class F>
        static auto action(KleisliMultiHolder<A,F> &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisliMulti<A>(std::move(f), liftParam);
        }
        template <class F, class G>
        static auto action(ComposedKleisli<F,G> &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisli<typename F::InputType>(std::move(f), liftParam);
        }
        template <class F>
        static auto action(F &&f, LiftParameters<typename M::TimePoint> const &liftParam = LiftParameters<typename M::TimePoint>()) {
            return M::template kleisli<typename F::InputType>(std::move(f), liftParam);
        }

        template <class T>
        class IsAlreadyWrapped {
        public:
            static constexpr bool value = false;
        };
        template <class A, class F>
        class IsAlreadyWrapped<KleisliFromPure<A,F>> {
        public:
            static constexpr bool value = true;
        };
        template <class A, class F>
        class IsAlreadyWrapped<KleisliFromMaybe<A,F>> {
        public:
            static constexpr bool value = true;
        };
        template <class A, class F>
        class IsAlreadyWrapped<KleisliFromEnhancedMaybe<A,F>> {
        public:
            static constexpr bool value = true;
        };
        template <class A, class F>
        class IsAlreadyWrapped<KleisliHolder<A,F>> {
        public:
            static constexpr bool value = true;
        };
        template <class A, class F>
        class IsAlreadyWrapped<KleisliFromMulti<A,F>> {
        public:
            static constexpr bool value = true;
        };
        template <class A, class F>
        class IsAlreadyWrapped<KleisliFromEnhancedMulti<A,F>> {
        public:
            static constexpr bool value = true;
        };
        template <class A, class F>
        class IsAlreadyWrapped<KleisliMultiHolder<A,F>> {
        public:
            static constexpr bool value = true;
        };
        template <class A, class F>
        class IsAlreadyWrapped<KleisliExporterFromPure<A,F>> {
        public:
            static constexpr bool value = true;
        };
        template <class A, class F>
        class IsAlreadyWrapped<KleisliExporterHolder<A,F>> {
        public:
            static constexpr bool value = true;
        };
        template <class F, class G>
        class IsAlreadyWrapped<ComposedKleisli<F,G>> {
        public:
            static constexpr bool value = true;
        };
        template <class F, class G>
        class IsAlreadyWrapped<ComposedKleisliExporter<F,G>> {
        public:
            static constexpr bool value = true;
        };
    };
} } } }

#endif