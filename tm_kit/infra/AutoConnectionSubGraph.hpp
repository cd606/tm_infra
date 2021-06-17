#ifndef TM_KIT_INFRA_AUTO_CONNECTION_SUB_GRAPH_HPP_
#define TM_KIT_INFRA_AUTO_CONNECTION_SUB_GRAPH_HPP_

#include <tm_kit/infra/GenericLift.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {

    template <class A>
    class VacuousImporterItem {};
    template <class A>
    class TrivialExporterItem {};

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
            static std::function<void(R &, std::string const &)> resolve(std::string const &name, std::shared_ptr<T> const &x) {
                if constexpr (R::AppType::template IsImporter<T>::Value) {
                    return [name,x](R &r) {
                        r.registerImporter(name, x);
                        r.connectSourceToAllSinks(r.importItem(x));
                    };
                } else if constexpr (R::AppType::template IsExporter<T>::Value) {
                    return [name,x](R &r) {
                        r.registerExporter(name, x);
                        r.connectTypedSinkToAllNodes(r.exporterAsSink(x));
                    };
                } else if constexpr (R::AppType::template IsAction<T>::Value) {
                    return RegistrationResolverActionHelper<
                            typename T::InputType 
                            , typename T::OutputType
                        >::resolve(name, x);
                } else {
                    throw std::runtime_error("Bad registration resolution");
                }
            }
        };

    public:
        template <class F>
        OneAutoConnectionItem(std::string const &name, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) : registration_() {
            auto component = GenericLift<typename R::AppType>::lift(std::move(f), liftParam);
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        }
        template <class F>
        OneAutoConnectionItem(std::string const &name, LiftAsMulti &&, F &&f, LiftParameters<typename R::AppType::TimePoint> const &liftParam = LiftParameters<typename R::AppType::TimePoint> {}) : registration_() {
            auto component = GenericLift<typename R::AppType>::liftMulti(std::move(f), liftParam);
            registration_ = RegistrationResolver<std::decay_t<decltype(component)>>::resolve(name, component);
        }
        template <class A, class B>
        OneAutoConnectionItem(std::string const &name, typename R::AppType::template AbstractOnOrderFacility<A,B> *facility) : registration_() {
            auto component = R::AppType::template fromAbstractOnOrderFacility<A,B>(facility);
            registration_ = [name,component](R &r) {
                r.registerOnOrderFacility(name, component);
                r.connnectFacilioidToAllPossiblePlaces(r.facilityConnector(component));
            };
        }
        template <class A, class B, class C>
        OneAutoConnectionItem(std::string const &name, typename R::AppType::template AbstractIntegratedLocalOnOrderFacility<A,B,C> *facility) : registration_() {
            auto component = R::AppType::template localOnOrderFacility<A,B,C>(facility);
            registration_ = [name,component](R &r) {
                r.registerLocalOnOrderFacility(name, component);
                r.connnectFacilioidToAllPossiblePlaces(r.facilityConnector(component));
                r.connectTypedSinkToAllNodes(r.localFacilityAsSink(component));
            };
        }
        template <class A, class B, class C>
        OneAutoConnectionItem(std::string const &name, typename R::AppType::template AbstractIntegratedOnOrderFacilityWithExternalEffects<A,B,C> *facility) : registration_() {
            auto component = R::AppType::template onOrderFacilityWithExternalEffects<A,B,C>(facility);
            registration_ = [name,component](R &r) {
                r.registerOnOrderFacilityWithExternalEffects(name, component);
                r.connnectFacilioidToAllPossiblePlaces(r.facilityConnector(component));
                r.connectSourceToAllSinks(r.facilityWithExternalEffectsAsSource(component));
            };
        }
        template <class A, class B, class C, class D>
        OneAutoConnectionItem(std::string const &name, typename R::AppType::template AbstractIntegratedVIEOnOrderFacility<A,B,C,D> *facility) : registration_() {
            auto component = R::AppType::template vieOnOrderFacility<A,B,C,D>(facility);
            registration_ = [name,component](R &r) {
                r.registerVIEOnOrderFacility(name, component);
                r.connnectFacilioidToAllPossiblePlaces(r.facilityConnector(component));
                r.connectTypedSinkToAllNodes(r.vieFacilityAsSink(component));
                r.connectSourceToAllSinks(r.vieFacilityAsSource(component));
            };
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