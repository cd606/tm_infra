#ifndef TM_KIT_INFRA_SYNCHRONOUS_RUNNER_HPP_
#define TM_KIT_INFRA_SYNCHRONOUS_RUNNER_HPP_

#include <tm_kit/infra/WithTimeData.hpp>
#include <tm_kit/infra/BasicWithTimeApp.hpp>
#include <tm_kit/infra/RealTimeApp.hpp>
#include <tm_kit/infra/SinglePassIterationApp.hpp>
#include <tm_kit/infra/TopDownSinglePassIterationApp.hpp>
#include <tm_kit/infra/AppClassifier.hpp>

#include <unordered_set>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    template <class M>
    class SynchronousRunner {
    public:
        using AppType = M;  
        using EnvironmentType = typename M::EnvironmentType;
        template <class T>
        using ImporterPtr = std::shared_ptr<typename M::template Importer<T>>;
        template <class T1, class T2>
        using OnOrderFacilityPtr = std::shared_ptr<typename M::template OnOrderFacility<T1,T2>>;
        template <class T>
        using ExporterPtr = std::shared_ptr<typename M::template Exporter<T>>;
    private:
        typename M::EnvironmentType *env_;
        M app_;
        std::unordered_set<typename M::IExternalComponent *> startedComponents_;
        std::unordered_set<std::shared_ptr<void>> components_;
        std::mutex mutex_;
    public:
        SynchronousRunner(typename M::EnvironmentType *env) : env_(env), app_(), startedComponents_(), components_(), mutex_() {}
        ~SynchronousRunner() = default;
        SynchronousRunner(SynchronousRunner const &) = delete;
        SynchronousRunner &operator=(SynchronousRunner const &) = delete;
        SynchronousRunner(SynchronousRunner &&) = delete;
        SynchronousRunner &operator=(SynchronousRunner &&) = delete;

        typename M::EnvironmentType *environment() const {
            return env_;
        }

        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        std::unique_ptr<typename M::template SynchronousRunResult<T>> importItem(
            std::shared_ptr<typename M::template Importer<T>> const &importer
        ) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                components_.insert(std::static_pointer_cast<void>(importer));
                auto *p = app_.template importerAsExternalComponent<T>(importer);
                if (startedComponents_.find(p) != startedComponents_.end()) {
                    throw std::runtime_error("SynchronousRunner::importItem: importer previously started");
                }
                startedComponents_.insert(p);
            }
            return app_.template runUnstartedImporterSynchronously<T>(env_, importer);
        }
        template <class T, class Condition, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        std::unique_ptr<typename M::template SynchronousRunResult<T>> importItemUntil(
            std::shared_ptr<typename M::template Importer<T>> const &importer
            , Condition const &condition
        ) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                components_.insert(std::static_pointer_cast<void>(importer));
                auto *p = app_.template importerAsExternalComponent<T>(importer);
                if (startedComponents_.find(p) != startedComponents_.end()) {
                    throw std::runtime_error("SynchronousRunner::importItem: importer previously started");
                }
                startedComponents_.insert(p);
            }
            return app_.template runUnstartedImporterSynchronouslyUntil<T>(
                env_
                , importer
                , std::function<bool(typename M::template InnerData<T> const &)>(condition)
            );
        }
        //The parameter order is trying to imitate the order in AppRunner
        template <class T1, class T2>
        std::unique_ptr<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>> placeOrderWithFacility(
            typename M::template InnerData<typename M::template Key<T1>> &&key
            , std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> const &facility
        ) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                components_.insert(std::static_pointer_cast<void>(facility));
                auto *p = app_.template facilityAsExternalComponent<T1,T2>(facility);
                if (p) {
                    if (startedComponents_.find(p) == startedComponents_.end()) {
                        app_.template startFacilitySynchronously<T1,T2>(env_, facility);
                        startedComponents_.insert(p);
                    }
                } else {
                    app_.template startFacilitySynchronously<T1,T2>(env_, facility);
                }
            }
            return app_.template runStartedFacilitySynchronously<T1,T2>(env_, facility, std::move(key));
        }
        template <class T1, class T2>
        std::unique_ptr<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>> placeOrderWithFacility(
            typename M::template InnerData<T1> &&key
            , std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> const &facility
        ) {
            return placeOrderWithFacility<T1,T2>(
                std::move(key).mapMove(&(M::template keyify<T1>))
                , facility
            );
        }
        template <class T1, class T2>
        std::unique_ptr<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>> placeOrderWithFacility(
            T1 &&key
            , std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> const &facility
        ) {
            return placeOrderWithFacility<T1,T2>(
                M::template pureInnerData<T1>(env_, std::move(key)).mapMove(&(M::template keyify<T1>))
                , facility
            );
        }
    private:
        template <class T1, class T2>
        friend class SynchronousFacilityStreamer;
        template <class T1, class T2>
        void streamOrderToFacility(
            typename M::template InnerData<typename M::template Key<T1>> &&key
            , std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> const &facility
            , typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>> *output
        ) {
            return app_.template streamToStartedFacilitySynchronously<T1,T2>(env_, facility, std::move(key), output);
        }
    public:
        template <class T1, class T2>
        class SynchronousFacilityStreamer {
        private:
            friend class SynchronousRunner;
            SynchronousRunner *parent_;
            typename M::EnvironmentType *env_;
            typename M::EnvironmentType::IDType id_;
            bool first_;
            std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> facility_;
            std::unique_ptr<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>> result_;
        public:
            SynchronousFacilityStreamer(SynchronousRunner *parent, typename M::EnvironmentType *env, std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> const &facility)
                : parent_(parent)
                , env_(env)
                , id_(M::EnvironmentType::new_id())
                , first_(true)
                , facility_(facility)
                , result_()
            {} 
            ~SynchronousFacilityStreamer() = default;
            SynchronousFacilityStreamer(SynchronousFacilityStreamer const &) = delete;
            SynchronousFacilityStreamer &operator=(SynchronousFacilityStreamer const &) = delete;
            SynchronousFacilityStreamer(SynchronousFacilityStreamer &&) = default;
            SynchronousFacilityStreamer &operator=(SynchronousFacilityStreamer &&) = default;
            typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>> *operator->() {
                return result_.get();
            }
            typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>> &operator*() {
                return *result_;
            }
            void operator<<(typename M::template InnerData<T1> &&key) {
                if (first_) {
                    result_ = parent_->template placeOrderWithFacility<T1,T2>(
                        std::move(key).mapMove(
                            [this](T1 &&x) -> typename M::template Key<T1> {
                                return {id_, std::move(x)};
                            }
                        )
                        , facility_
                    );
                    first_ = false;
                } else {
                    parent_->template streamOrderToFacility<T1,T2>(
                        std::move(key).mapMove(
                            [this](T1 &&x) -> typename M::template Key<T1> {
                                return {id_, std::move(x)};
                            }
                        )
                        , facility_
                        , result_.get()
                    );
                }
            }
            void operator<<(T1 &&key) {
                operator<<(M::template pureInnerData<T1>(env_, std::move(key)));
            }
        };
        template <class T1, class T2>
        SynchronousFacilityStreamer<T1,T2> facilityStreamer(
            std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> const &facility
        ) {
            static_assert(
                app_classification_v<M> != AppClassification::SinglePass
                , "single pass iteration app does not support synchronous facility streamer" 
            );
            {
                std::lock_guard<std::mutex> _(mutex_);
                components_.insert(std::static_pointer_cast<void>(facility));
                auto *p = app_.template facilityAsExternalComponent<T1,T2>(facility);
                if (p) {
                    if (startedComponents_.find(p) == startedComponents_.end()) {
                        app_.template startFacilitySynchronously<T1,T2>(env_, facility);
                        startedComponents_.insert(p);
                    }
                } else {
                    app_.template startFacilitySynchronously<T1,T2>(env_, facility);
                }
            }
            return SynchronousFacilityStreamer<T1,T2>(
                this 
                , env_ 
                , facility
            );
        }

        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        void exportItem(
            std::shared_ptr<typename M::template Exporter<T>> const &exporter
            , typename M::template InnerData<T> &&data
        ) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                components_.insert(std::static_pointer_cast<void>(exporter));
                auto *p = app_.template exporterAsExternalComponent<T>(exporter);
                if (startedComponents_.find(p) != startedComponents_.end()) {
                    app_.template startExporterSynchronously<T>(env_, exporter);
                    startedComponents_.insert(p);
                }
            }
            return app_.template runStartedExporterSynchronously<T>(env_, exporter, std::move(data));
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        void exportItem(
            std::shared_ptr<typename M::template Exporter<T>> const &exporter
            , T &&data
        ) {
            exportItem<T>(exporter, M::template pureInnerData<T>(env_, std::move(data)));
        }
    };

    template <class Env>
    class SynchronousRunner<BasicWithTimeApp<Env>> {
    public:
        using M = BasicWithTimeApp<Env>;
        using AppType = M;  
        using EnvironmentType = typename M::EnvironmentType;
        template <class T>
        using ImporterPtr = std::shared_ptr<typename M::template Importer<T>>;
        template <class T1, class T2>
        using OnOrderFacilityPtr = std::shared_ptr<typename M::template OnOrderFacility<T1,T2>>;
        template <class T>
        using ExporterPtr = std::shared_ptr<typename M::template Exporter<T>>;
    private:
        typename M::EnvironmentType *env_;
        M app_;
    public:
        SynchronousRunner(typename M::EnvironmentType *env) : env_(env), app_() {}
        ~SynchronousRunner() = default;
        SynchronousRunner(SynchronousRunner const &) = delete;
        SynchronousRunner &operator=(SynchronousRunner const &) = delete;
        SynchronousRunner(SynchronousRunner &&) = delete;
        SynchronousRunner &operator=(SynchronousRunner &&) = delete;

        typename M::EnvironmentType *environment() const {
            return env_;
        }

        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        std::unique_ptr<typename M::template SynchronousRunResult<T>> importItem(
            std::shared_ptr<typename M::template Importer<T>> const &importer
        ) {
            return std::make_unique<typename M::template SynchronousRunResult<T>>();
        }
        template <class T, class Condition, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        std::unique_ptr<typename M::template SynchronousRunResult<T>> importItemUntil(
            std::shared_ptr<typename M::template Importer<T>> const &importer
            , Condition const &condition
        ) {
            return std::make_unique<typename M::template SynchronousRunResult<T>>();
        }
        //The parameter order is trying to imitate the order in AppRunner
        template <class T1, class T2>
        std::unique_ptr<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>> placeOrderWithFacility(
            typename M::template InnerData<typename M::template Key<T1>> &&key
            , std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> const &facility
        ) {
            return std::make_unique<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>>();
        }
        template <class T1, class T2>
        std::unique_ptr<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>> placeOrderWithFacility(
            typename M::template InnerData<T1> &&key
            , std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> const &facility
        ) {
            return std::make_unique<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>>();
        }
        template <class T1, class T2>
        std::unique_ptr<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>> placeOrderWithFacility(
            T1 &&key
            , std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> const &facility
        ) {
            return std::make_unique<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>>();
        }
        template <class T1, class T2>
        class SynchronousFacilityStreamer {
        private:
            std::unique_ptr<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>> result_;
        public:
            SynchronousFacilityStreamer(SynchronousRunner *parent, typename M::EnvironmentType *env, std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> const &facility)
                : result_(std::make_unique<typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>>>())
            {} 
            ~SynchronousFacilityStreamer() = default;
            SynchronousFacilityStreamer(SynchronousFacilityStreamer const &) = delete;
            SynchronousFacilityStreamer &operator=(SynchronousFacilityStreamer const &) = delete;
            SynchronousFacilityStreamer(SynchronousFacilityStreamer &&) = default;
            SynchronousFacilityStreamer &operator=(SynchronousFacilityStreamer &&) = default;
            typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>> *operator->() {
                return result_.get();
            }
            typename M::template SynchronousRunResult<typename M::template KeyedData<T1,T2>> &operator*() {
                return *(result_.get());
            }
            void operator<<(typename M::template InnerData<T1> &&key) {}
            void operator<<(T1 &&key) {}
        };
        template <class T1, class T2>
        SynchronousFacilityStreamer<T1,T2> facilityStreamer(
            std::shared_ptr<typename M::template OnOrderFacility<T1,T2>> const &facility
        ) {
            return SynchronousFacilityStreamer<T1,T2>(
                this 
                , env_ 
                , facility
            );
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        void exportItem(
            std::shared_ptr<typename M::template Exporter<T>> const &exporter
            , typename M::template InnerData<T> &&data
        ) {
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        void exportItem(
            std::shared_ptr<typename M::template Exporter<T>> const &exporter
            , T &&data
        ) {
        }
    };
} } } }

#endif