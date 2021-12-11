#ifndef TM_KIT_INFRA_DECLARATIVE_GRAPH_HPP_
#define TM_KIT_INFRA_DECLARATIVE_GRAPH_HPP_

#include <tm_kit/infra/GenericLift.hpp>
#include <tm_kit/infra/NodeClassifier.hpp>
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

    struct DeclarativeGraphChain {
    private:
        std::vector<std::string> nodes_;
    public:
        DeclarativeGraphChain(std::vector<std::string> const &nodes) : nodes_(nodes) {}
        template <class R>
        void connect(R &r, std::string const &prefix) const {
            if (nodes_.size() >= 2) {
                for (int ii=1; ii<nodes_.size(); ++ii) {
                    r.dynamicConnect(
                        (prefix=="")?nodes_[ii-1]:(prefix+"/"+nodes_[ii-1])
                        , 0
                        , (prefix=="")?nodes_[ii]:(prefix+"/"+nodes_[ii])
                        , 0
                    );
                }
            }
        }
    };

    template <class R>
    class GenericComponentLiftAndRegistration {
    private:
        R *p_;
        std::string prefix_;
    public:
        GenericComponentLiftAndRegistration(R &r, std::string const &prefix="") : p_(&r), prefix_(prefix) {}  
        template <class F>
        auto operator()(std::string const &name, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) ->
            decltype(
                GenericLift<typename R::AppType>::lift(std::move(f), liftParam)
            );
        template <class F>
        auto operator()(std::string const &name, LiftAsMulti &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) ->
            decltype(
                GenericLift<typename R::AppType>::lift(LiftAsMulti {}, std::move(f), liftParam)
            );
        template <class F>
        auto operator()(std::string const &name, LiftAsFacility &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) ->
            decltype(
                GenericLift<typename R::AppType>::lift(LiftAsFacility {}, std::move(f), liftParam)
            );
        template <class DelayTrigger, class F>
        auto operator()(std::string const &name, DelayImporter<DelayTrigger> &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) ->
            decltype(
                GenericLift<typename R::AppType>::lift(DelayImporter<DelayTrigger> {}, std::move(f), liftParam)
            );
        template <class LazyInput, class F>
        auto operator()(std::string const &name, LazyImporter<LazyInput> &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) ->
            decltype(
                GenericLift<typename R::AppType>::lift(LazyImporter<LazyInput> {}, std::move(f), liftParam)
            );
        template <class F>
        auto operator()(std::string const &name, CurtailAction &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) ->
            decltype(
                GenericLift<typename R::AppType>::lift(CurtailAction {}, std::move(f), liftParam)
            );
    };

    template <class R>
    class OneDeclarativeGraphItem {
    private:
        std::function<void(R &, std::string const &)> registration_;
        friend class GenericComponentLiftAndRegistration<R>;

        template <class X>
        class RegistrationResolver {};

        template <class T>
        class RegistrationResolver<std::shared_ptr<T>> {
        public:
            static std::function<void(R &, std::string const &)> resolve(std::string const &name, std::shared_ptr<T> const &x) {
                if constexpr (NodeClassifier<typename R::AppType>::template IsImporter<T>::Value) {
                    return [name,x](R &r, std::string const &prefix) {
                        r.registerImporter((prefix==""?name:(prefix+"/"+name)), x);
                    };
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsExporter<T>::Value) {
                    return [name,x](R &r, std::string const &prefix) {
                        r.registerExporter((prefix==""?name:(prefix+"/"+name)), x);
                    };
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsAction<T>::Value) {
                    return [name,x](R &r, std::string const &prefix) {
                        r.registerAction((prefix==""?name:(prefix+"/"+name)), x);
                    };
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsOnOrderFacility<T>::Value) {
                    return [name,x](R &r, std::string const &prefix) {
                        r.registerOnOrderFacility((prefix==""?name:(prefix+"/"+name)), x);
                    };
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsLocalOnOrderFacility<T>::Value) {
                    return [name,x](R &r, std::string const &prefix) {
                        r.registerLocalOnOrderFacility((prefix==""?name:(prefix+"/"+name)), x);
                    };
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsOnOrderFacilityWithExternalEffects<T>::Value) {
                    return [name,x](R &r, std::string const &prefix) {
                        r.registerOnOrderFacilityWithExternalEffects((prefix==""?name:(prefix+"/"+name)), x);
                    };
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsVIEOnOrderFacility<T>::Value) {
                    return [name,x](R &r, std::string const &prefix) {
                        r.registerVIEOnOrderFacility((prefix==""?name:(prefix+"/"+name)), x);
                    };
                } else {
                    throw std::runtime_error(std::string("Bad registration resolution for '")+name+"'");
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
        template <class F>
        OneDeclarativeGraphItem(std::string const &name, LiftAsFacility &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) : registration_() {
            auto component = GenericLift<typename R::AppType>::liftFacility(std::move(f), liftParam);
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        }
        template <class DelayTrigger, class F>
        OneDeclarativeGraphItem(std::string const &name, DelayImporter<DelayTrigger> &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) : registration_() {
            auto component = GenericLift<typename R::AppType>::lift(DelayImporter<DelayTrigger> {}, std::move(f), liftParam);
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        }
        template <class LazyInput, class F>
        OneDeclarativeGraphItem(std::string const &name, LazyImporter<LazyInput> &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) : registration_() {
            auto component = GenericLift<typename R::AppType>::lift(LazyImporter<LazyInput> {}, std::move(f), liftParam);
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        }
        template <class F>
        OneDeclarativeGraphItem(std::string const &name, CurtailAction &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) : registration_() {
            auto component = GenericLift<typename R::AppType>::lift(CurtailAction{}, std::move(f), liftParam);
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        }
        template <class T>
        OneDeclarativeGraphItem(std::string const &name, std::shared_ptr<T> const &t) {
            registration_ = RegistrationResolver<std::shared_ptr<T>>::resolve(name, t);
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
        template <class A>
        OneDeclarativeGraphItem(std::string const &name, PassThroughActionItem<A> &&) : registration_() {
            auto component = R::AppType::template passThroughAction<A>();
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);      
        }
        OneDeclarativeGraphItem(DeclarativeGraphChain &&chain) {
            registration_ = [chain=std::move(chain)](R &r, std::string const &prefix) {
                chain.template connect<R>(r, prefix);
            };
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
                    , (prefix=="")?facility:(prefix+"/"+facility)
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
                    , (prefix=="")?facility:(prefix+"/"+facility)
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
                    , (prefix=="")?facility:(prefix+"/"+facility)
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
                    , (prefix=="")?facility:(prefix+"/"+facility)
                    , (prefix=="")?sinkName:(prefix+"/"+sinkName)
                    , sinkIdx
                );
            };
        }
        OneDeclarativeGraphItem(std::string const &source, std::string const &facility, std::monostate const &) {
            registration_ = [source,facility](R &r, std::string const &prefix) {
                r.dynamicPlaceOrder(
                    (prefix=="")?source:(prefix+"/"+source)
                    , 0
                    , (prefix=="")?facility:(prefix+"/"+facility)
                    , std::nullopt
                    , 0
                );
            };
        }
        OneDeclarativeGraphItem(std::string const &sourceName, std::size_t sourceIdx, std::string const &facility, std::monostate const &) {
            registration_ = [sourceName,sourceIdx,facility](R &r, std::string const &prefix) {
                r.dynamicPlaceOrder(
                    (prefix=="")?sourceName:(prefix+"/"+sourceName)
                    , sourceIdx
                    , (prefix=="")?facility:(prefix+"/"+facility)
                    , std::nullopt
                    , 0
                );
            };
        }
#if !defined(_MSC_VER) && !defined(__llvm__) && defined(__GNUC__) && (__GNUC__ <= 10)
        template <class Src, class Snk>
        OneDeclarativeGraphItem(std::string const &sourceName, std::function<void(R &, Src, Snk)> const &facilitioid, std::string const &sinkName) {
            using A = typename std::decay_t<Src>::TheDataTypeOfThisSource::KeyType;
            using B = typename std::decay_t<Snk>::value_type::TheDataTypeOfThisSink::DataType;
#else    
        template <class A, class B>
        OneDeclarativeGraphItem(std::string const &sourceName, typename R::template FacilitioidConnector<A,B> const &facilitioid, std::string const &sinkName) {
#endif
            registration_ = [sourceName,facilitioid,sinkName](R &r, std::string const &/*prefix*/) {
                facilitioid(
                    r 
                    , r.template sourceByName<typename R::AppType::template Key<A>>(sourceName)
                    , r.template sinkByName<typename R::AppType::template KeyedData<A,B>>(sinkName)
                );
            };
        }
        template <class T>
        OneDeclarativeGraphItem(typename R::template Sourceoid<T> const &sourceoid, std::string const &sinkName) {
            registration_ = [sourceoid,sinkName](R &r, std::string const &/*prefix*/) {
                sourceoid(
                    r 
                    , r.template sinkByName<T>(sinkName)
                );
            };
        }
        template <class T>
        OneDeclarativeGraphItem(std::string const &sourceName, typename R::template Sinkoid<T> const &sinkoid) {
            registration_ = [sourceName,sinkoid](R &r, std::string const &/*prefix*/) {
                sinkoid(
                    r 
                    , r.template sourceByName<T>(sourceName)
                );
            };
        }
        template <class T>
        OneDeclarativeGraphItem(typename R::template Source<T> &&source, std::string const &sinkName) {
            registration_ = [source=std::move(source),sinkName](R &r, std::string const &/*prefix*/) mutable {
                r.connect(
                    std::move(source)
                    , r.template sinkByName<T>(sinkName)
                );
            };
        }
        template <class T>
        OneDeclarativeGraphItem(std::string const &sourceName, typename R::template Sink<T> const &sink) {
            registration_ = [sourceName,sink](R &r, std::string const &/*prefix*/) {
                r.connect(
                    r.template sourceByName<T>(sourceName)
                    , sink
                );
            };
        }
        template <class T>
        OneDeclarativeGraphItem(typename R::template Source<T> &&source, typename R::template Sink<T> const &sink) {
            registration_ = [source=std::move(source),sink](R &r, std::string const &/*prefix*/) mutable {
                r.connect(
                    std::move(source)
                    , sink
                );
            };
        }
        template <class T>
        OneDeclarativeGraphItem(typename R::template Source<T> &&source, typename R::template Sinkoid<T> const &sinkoid) {
            registration_ = [source=std::move(source),sinkoid](R &r, std::string const &/*prefix*/) mutable {
                sinkoid(
                    r
                    , std::move(source)
                );
            };
        }
        template <class T>
        OneDeclarativeGraphItem(typename R::template Sourceoid<T> const &sourceoid, typename R::template Sink<T> const &sink) {
            registration_ = [sourceoid,sink](R &r, std::string const &/*prefix*/) mutable {
                sourceoid(
                    r
                    , sink
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

    template <class R>
    template <class F>
    auto GenericComponentLiftAndRegistration<R>::operator()(std::string const &name, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam) ->
        decltype(
            GenericLift<typename R::AppType>::lift(std::move(f), liftParam)
        )
    {
        auto component = GenericLift<typename R::AppType>::lift(std::move(f), liftParam);
        auto registration = OneDeclarativeGraphItem<R>::template RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        registration(*p_, prefix_);
        return component;
    }
    template <class R>
    template <class F>
    auto GenericComponentLiftAndRegistration<R>::operator()(std::string const &name, LiftAsMulti &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam) ->
        decltype(
            GenericLift<typename R::AppType>::lift(LiftAsMulti{}, std::move(f), liftParam)
        )
    {
        auto component = GenericLift<typename R::AppType>::lift(LiftAsMulti{}, std::move(f), liftParam);
        auto registration = OneDeclarativeGraphItem<R>::template RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        registration(*p_, prefix_);
        return component;
    }
    template <class R>
    template <class F>
    auto GenericComponentLiftAndRegistration<R>::operator()(std::string const &name, LiftAsFacility &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam) ->
        decltype(
            GenericLift<typename R::AppType>::lift(LiftAsFacility{}, std::move(f), liftParam)
        )
    {
        auto component = GenericLift<typename R::AppType>::lift(LiftAsFacility{}, std::move(f), liftParam);
        auto registration = OneDeclarativeGraphItem<R>::template RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        registration(*p_, prefix_);
        return component;
    }
    template <class R>
    template <class DelayTrigger, class F>
    auto GenericComponentLiftAndRegistration<R>::operator()(std::string const &name, DelayImporter<DelayTrigger> &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam) ->
        decltype(
            GenericLift<typename R::AppType>::lift(DelayImporter<DelayTrigger>{}, std::move(f), liftParam)
        )
    {
        auto component = GenericLift<typename R::AppType>::lift(DelayImporter<DelayTrigger>{}, std::move(f), liftParam);
        auto registration = OneDeclarativeGraphItem<R>::template RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        registration(*p_, prefix_);
        return component;
    }
    template <class R>
    template <class LazyInput, class F>
    auto GenericComponentLiftAndRegistration<R>::operator()(std::string const &name, LazyImporter<LazyInput> &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam) ->
        decltype(
            GenericLift<typename R::AppType>::lift(LazyImporter<LazyInput>{}, std::move(f), liftParam)
        )
    {
        auto component = GenericLift<typename R::AppType>::lift(LazyImporter<LazyInput>{}, std::move(f), liftParam);
        auto registration = OneDeclarativeGraphItem<R>::template RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        registration(*p_, prefix_);
        return component;
    }
    template <class R>
    template <class F>
    auto GenericComponentLiftAndRegistration<R>::operator()(std::string const &name, CurtailAction &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam) ->
        decltype(
            GenericLift<typename R::AppType>::lift(CurtailAction{}, std::move(f), liftParam)
        )
    {
        auto component = GenericLift<typename R::AppType>::lift(CurtailAction{}, std::move(f), liftParam);
        auto registration = OneDeclarativeGraphItem<R>::template RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        registration(*p_, prefix_);
        return component;
    }

} } } }

#endif