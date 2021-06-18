#ifndef TM_KIT_INFRA_DECLARATIVE_GRAPH_HPP_
#define TM_KIT_INFRA_DECLARATIVE_GRAPH_HPP_

#include <tm_kit/infra/GenericLift.hpp>
#include <tm_kit/infra/AutoConnectionSubGraph.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {

    template <class R>
    class OneDeclarativeGraphItem;

    template <class R>
    class DeclarativeGraph {
    private:
        std::function<void(R &r, std::string const &outerPrefix)> f_;
    public:
        DeclarativeGraph(std::string const &prefix, std::vector<OneDeclarativeGraphItem<R>> const &items);
        void operator()(R &r, std::string const &outerPrefix="") const {
            f_(r, outerPrefix);
        }
    };

    template <class R>
    class OneDeclarativeGraphItem {
    private:
        std::function<void(R &, std::string const &)> registration_;

        template <class X>
        class RegistrationResolver {};

        template <class T>
        class RegistrationResolver<std::shared_ptr<T>> {
        public:
            static std::function<void(R &, std::string const &)> resolve(std::string const &name, std::shared_ptr<T> const &x) {
                if constexpr (R::AppType::template IsImporter<T>::Value) {
                    return [name,x](R &r, std::string const &prefix) {
                        r.registerImporter((prefix==""?name:(prefix+"/"+name)), x);
                    };
                } else if constexpr (R::AppType::template IsExporter<T>::Value) {
                    return [name,x](R &r, std::string const &prefix) {
                        r.registerExporter((prefix==""?name:(prefix+"/"+name)), x);
                    };
                } else if constexpr (R::AppType::template IsAction<T>::Value) {
                    return [name,x](R &r, std::string const &prefix) {
                        r.registerAction((prefix==""?name:(prefix+"/"+name)), x);
                    };
                } else {
                    throw std::runtime_error("Bad registration resolution");
                }
            }
        };
        template <class X>
        struct IsSharedPtr {
            static constexpr bool Value = false;
        };
        template <class T>
        struct IsSharedPtr<std::shared_ptr<T>> {
            static constexpr bool Value = true;
        };
    public:
        template <class F, typename=std::enable_if_t<
            !std::is_convertible_v<std::decay_t<F>, std::string>
            && !IsSharedPtr<std::decay_t<F>>::Value
        >>
        OneDeclarativeGraphItem(std::string const &name, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) : registration_() {
            auto component = GenericLift<typename R::AppType>::lift(std::move(f), liftParam);
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        }
        template <class F>
        OneDeclarativeGraphItem(std::string const &name, LiftAsMulti &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) : registration_() {
            auto component = GenericLift<typename R::AppType>::liftMulti(std::move(f), liftParam);
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        }
        template <class T>
        OneDeclarativeGraphItem(std::string const &name, std::shared_ptr<T> const &t) {
            registration_ = RegistrationResolver<std::shared_ptr<T>>::resolve(name, t);
        }
        template <class A, class B>
        OneDeclarativeGraphItem(std::string const &name, typename R::AppType::template AbstractOnOrderFacility<A,B> *facility) : registration_() {
            auto component = R::AppType::template fromAbstractOnOrderFacility<A,B>(facility);
            registration_ = [name,component](R &r, std::string const &prefix) {
                r.registerOnOrderFacility((prefix==""?name:(prefix+"/"+name)), component);
            };
        }
        template <class A, class B, class C>
        OneDeclarativeGraphItem(std::string const &name, typename R::AppType::template AbstractIntegratedLocalOnOrderFacility<A,B,C> *facility) : registration_() {
            auto component = R::AppType::template localOnOrderFacility<A,B,C>(facility);
            registration_ = [name,component](R &r, std::string const &prefix) {
                r.registerLocalOnOrderFacility((prefix==""?name:(prefix+"/"+name)), component);
            };
        }
        template <class A, class B, class C>
        OneDeclarativeGraphItem(std::string const &name, typename R::AppType::template AbstractIntegratedOnOrderFacilityWithExternalEffects<A,B,C> *facility) : registration_() {
            auto component = R::AppType::template onOrderFacilityWithExternalEffects<A,B,C>(facility);
            registration_ = [name,component](R &r, std::string const &prefix) {
                r.registerOnOrderFacilityWithExternalEffects((prefix==""?name:(prefix+"/"+name)), component);
            };
        }
        template <class A, class B, class C, class D>
        OneDeclarativeGraphItem(std::string const &name, typename R::AppType::template AbstractIntegratedVIEOnOrderFacility<A,B,C,D> *facility) : registration_() {
            auto component = R::AppType::template vieOnOrderFacility<A,B,C,D>(facility);
            registration_ = [name,component](R &r, std::string const &prefix) {
                r.registerVIEOnOrderFacility((prefix==""?name:(prefix+"/"+name)), component);
            };
        }
        template <class A>
        OneDeclarativeGraphItem(std::string const &name, VacuousImporterItem<A> &&) : registration_() {
            auto component = R::AppType::template vacuousImporter<A>();
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);      
        }
        template <class A>
        OneDeclarativeGraphItem(std::string const &name, TrivialExporterItem<A> &&) : registration_() {
            auto component = R::AppType::template trivialExporter<A>();
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);      
        }
        OneDeclarativeGraphItem(std::string const &source, std::string const &sink) {
            registration_ = [source,sink](R &r, std::string const &prefix) {
                r.dynamicConnect(
                    (prefix=="")?source:(prefix+"/"+source)
                    , 0
                    , (prefix=="")?sink:(prefix+"/"+sink)
                    , 0
                );
            };
        }
        OneDeclarativeGraphItem(std::string const &sourceName, std::size_t sourceIdx, std::string const &sink) {
            registration_ = [sourceName,sourceIdx,sink](R &r, std::string const &prefix) {
                r.dynamicConnect(
                    (prefix=="")?sourceName:(prefix+"/"+sourceName)
                    , sourceIdx
                    , (prefix=="")?sink:(prefix+"/"+sink)
                    , 0
                );
            };
        }
        OneDeclarativeGraphItem(std::string const &source, std::string const &sinkName, std::size_t sinkIdx) {
            registration_ = [source,sinkName,sinkIdx](R &r, std::string const &prefix) {
                r.dynamicConnect(
                    (prefix=="")?source:(prefix+"/"+source)
                    , 0
                    , (prefix=="")?sinkName:(prefix+"/"+sinkName)
                    , sinkIdx
                );
            };
        }        
        OneDeclarativeGraphItem(std::string const &sourceName, std::size_t sourceIdx, std::string const &sinkName, std::size_t sinkIdx) {
            registration_ = [sourceName,sourceIdx,sinkName,sinkIdx](R &r, std::string const &prefix) {
                r.dynamicConnect(
                    (prefix=="")?sourceName:(prefix+"/"+sourceName)
                    , sourceIdx
                    , (prefix=="")?sinkName:(prefix+"/"+sinkName)
                    , sinkIdx
                );
            };
        }
        OneDeclarativeGraphItem(std::string const &source, std::string const &facility, std::string const &sink) {
            registration_ = [source,facility,sink](R &r, std::string const &prefix) {
                r.dynamicPlaceOrder(
                    (prefix=="")?source:(prefix+"/"+source)
                    , 0
                    , facility
                    , (prefix=="")?sink:(prefix+"/"+sink)
                    , 0
                );
            };
        }
        OneDeclarativeGraphItem(std::string const &sourceName, std::size_t sourceIdx, std::string const &facility, std::string const &sink) {
            registration_ = [sourceName,sourceIdx,facility,sink](R &r, std::string const &prefix) {
                r.dynamicPlaceOrder(
                    (prefix=="")?sourceName:(prefix+"/"+sourceName)
                    , sourceIdx
                    , facility
                    , (prefix=="")?sink:(prefix+"/"+sink)
                    , 0
                );
            };
        }
        OneDeclarativeGraphItem(std::string const &source, std::string const &facility, std::string const &sinkName, std::size_t sinkIdx) {
            registration_ = [source,facility,sinkName,sinkIdx](R &r, std::string const &prefix) {
                r.dynamicPlaceOrder(
                    (prefix=="")?source:(prefix+"/"+source)
                    , 0
                    , facility
                    , (prefix=="")?sinkName:(prefix+"/"+sinkName)
                    , sinkIdx
                );
            };
        }        
        OneDeclarativeGraphItem(std::string const &sourceName, std::size_t sourceIdx, std::string const &facility, std::string const &sinkName, std::size_t sinkIdx) {
            registration_ = [sourceName,sourceIdx,facility,sinkName,sinkIdx](R &r, std::string const &prefix) {
                r.dynamicPlaceOrder(
                    (prefix=="")?sourceName:(prefix+"/"+sourceName)
                    , sourceIdx
                    , facility
                    , (prefix=="")?sinkName:(prefix+"/"+sinkName)
                    , sinkIdx
                );
            };
        }
        OneDeclarativeGraphItem(DeclarativeGraph<R> &&graph) : registration_() {
            registration_ = [graph=std::move(graph)](R &r, std::string const &prefix) {
                graph(r, prefix);
            };
        }
        void doRegistration(R &r, std::string const &prefix) const {
            registration_(r, prefix);
        }
    };

    template <class R>
    DeclarativeGraph<R>::DeclarativeGraph(std::string const &prefix, std::vector<OneDeclarativeGraphItem<R>> const &items) {
        f_ = [prefix,items](R &r, std::string const &outerPrefix) {
            for (auto const &item : items) {
                item.doRegistration(r, ((outerPrefix=="")?prefix:(outerPrefix+"/"+prefix)));
            }
        };
    };

} } } }

#endif