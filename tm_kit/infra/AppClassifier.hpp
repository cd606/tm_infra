#ifndef TM_KIT_INFRA_APP_CLASSIFIER_HPP_
#define TM_KIT_INFRA_APP_CLASSIFIER_HPP_

#include <tm_kit/infra/BasicWithTimeApp.hpp>
#include <tm_kit/infra/RealTimeApp.hpp>
#include <tm_kit/infra/SinglePassIterationApp.hpp>
#include <tm_kit/infra/TopDownSinglePassIterationApp.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    enum class AppClassification {
        Empty 
        , BasicWithTime = Empty
        , RealTime
        , SinglePass 
        , SinglePassIteration = SinglePass 
        , TopDown
        , TopDownSinglePass = TopDown 
        , TopDownSinglePassIteration = TopDown
    };

    template <class M>
    class AppClassifier {};

    template <class Env>
    class AppClassifier<BasicWithTimeApp<Env>> {
    public:
        static constexpr AppClassification TheClassification = AppClassification::Empty;
    };
    template <class Env>
    class AppClassifier<RealTimeApp<Env>> {
    public:
        static constexpr AppClassification TheClassification = AppClassification::RealTime;
    };
    template <class Env>
    class AppClassifier<SinglePassIterationApp<Env>> {
    public:
        static constexpr AppClassification TheClassification = AppClassification::SinglePass;
    };
    template <class Env>
    class AppClassifier<TopDownSinglePassIterationApp<Env>> {
    public:
        static constexpr AppClassification TheClassification = AppClassification::TopDown;
    };

    template <class M>
    constexpr AppClassification app_classification_v = AppClassifier<M>::TheClassification;

    template <class M, class MutexType=std::mutex>
    using AppSpecificMutex = std::conditional_t<app_classification_v<M> == AppClassification::RealTime, MutexType, bool>;

    template <class M, class MutexType=std::mutex>
    using AppSpecificLockGuard = std::conditional_t<app_classification_v<M> == AppClassification::RealTime, std::lock_guard<MutexType>, bool>;

} } } }

#endif