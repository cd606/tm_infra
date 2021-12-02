#ifndef TM_KIT_INFRA_AUTO_CONNECTION_SUB_GRAPH_HPP_
#define TM_KIT_INFRA_AUTO_CONNECTION_SUB_GRAPH_HPP_

#include <tm_kit/infra/GenericLift.hpp>
#include <tm_kit/infra/NodeClassifier.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {

    template <class A>
    class VacuousImporterItem {};
    template <class A>
    class TrivialExporterItem {};
    template <class A>
    class PassThroughActionItem {};

    template <class R>
    class OneAutoConnectionItem {
    private:
        std::function<void(R &)> registration_;

        template <class A, class B>
        class RegistrationResolverActionHelper {
        private:
            template <size_t N, size_t K>
            static void connectSink_internal_(R &r, typename R::template ActionPtr<A,B> const &action) {
                if constexpr (K < N) {
                    r.connectTypedSinkToAllNodes(AppRunnerHelper::ActionAsSink<N,K>::template call<R,A,B>(r, action));
                    connectSink_internal_<N,K+1>(r, action);
                }
            }
        public:
            static std::function<void(R &)> resolve(std::string const &name, typename R::template ActionPtr<A,B> const &action) {
                return [name,action](R &r) {
                    r.registerAction(name, action);
                    r.connectSourceToAllSinks(r.actionAsSource(action));
                    if constexpr (withtime_utils::IsVariant<A>::Value) {
                        connectSink_internal_<std::variant_size_v<A>,0>(r, action);
                    } else {
                        r.connectTypedSinkToAllNodes(r.actionAsSink(action));
                    }
                };
            }
        };

        template <class X>
        class RegistrationResolver {};

        template <class T>
        class RegistrationResolver<std::shared_ptr<T>> {
        public:
            static std::function<void(R &)> resolve(std::string const &name, std::shared_ptr<T> const &x) {
                if constexpr (NodeClassifier<typename R::AppType>::template IsImporter<T>::Value) {
                    return [name,x](R &r) {
                        r.registerImporter(name, x);
                        r.connectSourceToAllSinks(r.importItem(x));
                    };
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsExporter<T>::Value) {
                    return [name,x](R &r) {
                        r.registerExporter(name, x);
                        r.connectTypedSinkToAllNodes(r.exporterAsSink(x));
                    };
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsAction<T>::Value) {
                    return RegistrationResolverActionHelper<
                            typename T::InputType 
                            , typename T::OutputType
                        >::resolve(name, x);
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsOnOrderFacility<T>::Value) {
                    return [name,x](R &r) {
                        r.registerOnOrderFacility(name, x);
                        r.connnectFacilioidToAllPossiblePlaces(r.template facilityConnector<typename T::InputType, typename T::OutputType>(x));
                    };
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsLocalOnOrderFacility<T>::Value) {
                    return [name,x](R &r) {
                        r.registerLocalOnOrderFacility(name, x);
                        r.connnectFacilioidToAllPossiblePlaces(r.template localFacilityConnector<typename T::InputType, typename T::OutputType, typename T::DataType>(x));
                        r.connectTypedSinkToAllNodes(r.localFacilityAsSink(x));
                    };
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsOnOrderFacilityWithExternalEffects<T>::Value) {
                    return [name,x](R &r) {
                        r.registerLocalOnOrderFacility(name, x);
                        r.connnectFacilioidToAllPossiblePlaces(r.template facilityWithLocalEffectsConnector<typename T::InputType, typename T::OutputType, typename T::DataType>(x));
                        r.connectSourceToAllSinks(r.facilityWithExternalEffectsAsSource(x));
                    };
                } else if constexpr (NodeClassifier<typename R::AppType>::template IsVIEOnOrderFacility<T>::Value) {
                    return [name,x](R &r) {
                        r.registerLocalOnOrderFacility(name, x);
                        r.connnectFacilioidToAllPossiblePlaces(r.template vieFacilityConnector<typename T::InputType, typename T::OutputType, typename T::ExtraInputType, typename T::ExtraOutputType>(x));
                        r.connectTypedSinkToAllNodes(r.vieFacilityAsSink(x));
                        r.connectSourceToAllSinks(r.vieFacilityAsSource(x));
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
            !IsSharedPtr<std::decay_t<F>>::Value
        >>
        OneAutoConnectionItem(std::string const &name, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) : registration_() {
            auto component = GenericLift<typename R::AppType>::lift(std::move(f), liftParam);
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        }
        template <class F>
        OneAutoConnectionItem(std::string const &name, LiftAsMulti &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) : registration_() {
            auto component = GenericLift<typename R::AppType>::liftMulti(std::move(f), liftParam);
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        }
        template <class F>
        OneAutoConnectionItem(std::string const &name, LiftAsFacility &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) : registration_() {
            auto component = GenericLift<typename R::AppType>::liftFacility(std::move(f), liftParam);
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        }
        template <class T>
        OneAutoConnectionItem(std::string const &name, std::shared_ptr<T> const &t) {
            registration_ = RegistrationResolver<std::shared_ptr<T>>::resolve(name, t);
        }
        template <class A>
        OneAutoConnectionItem(std::string const &name, VacuousImporterItem<A> &&) : registration_() {
            auto component = R::AppType::template vacuousImporter<A>();
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);      
        }
        template <class A>
        OneAutoConnectionItem(std::string const &name, TrivialExporterItem<A> &&) : registration_() {
            auto component = R::AppType::template trivialExporter<A>();
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);      
        }
        template <class A>
        OneAutoConnectionItem(std::string const &name, PassThroughActionItem<A> &&) : registration_() {
            auto component = R::AppType::template passThroughAction<A>();
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);      
        }
        template <class A>
        OneAutoConnectionItem(typename R::template Source<A> &&s) : registration_() {
            registration_ = [s=std::move(s)](R &r) {
                r.connectSourceToAllSinks(s.clone());
            };
        }
        template <class A>
        OneAutoConnectionItem(typename R::template Sink<A> const &s) : registration_() {
            registration_ = [s](R &r) {
                r.connectTypedSinkToAllNodes(s);
            };
        }
        template <class A, class B>
        OneAutoConnectionItem(typename R::template FacilitioidConnector<A,B> const &f) : registration_() {
            registration_ = [f](R &r) {
                r.connnectFacilioidToAllPossiblePlaces(f);
            };
        }
        void doRegistration(R &r) const {
            registration_(r);
        }
    };

    template <class R>
    class AutoConnectionSubGraph {
    public:
        AutoConnectionSubGraph(R &r, std::vector<OneAutoConnectionItem<R>> const &items) {
            for (auto const &item : items) {
                item.doRegistration(r);
            }
        }
    };

} } } }

#endif