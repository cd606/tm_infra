#ifndef TM_KIT_INFRA_VERSIONED_DATA_HPP_
#define TM_KIT_INFRA_VERSIONED_DATA_HPP_

#include <optional>
#include <functional>
#include <mutex>
#include <type_traits>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    template <
        class VersionType
        , class DataType
        , class CmpType=std::less<VersionType>
        , class Enable=void
    >
    struct VersionedData {};

    template <
        class VersionType
        , class DataType
        , class CmpType
    >
    struct VersionedData<
        VersionType, DataType, CmpType
        , std::enable_if_t<std::is_copy_constructible_v<VersionType> && std::is_default_constructible_v<VersionType>>
    > {
        using Version = VersionType;
        using Data = DataType;
        using Cmp = CmpType;

        VersionType version;
        DataType data;
    };

    template <class T>
    class VersionChecker {
    public:
        static bool checkVersion(T const &) {
            return true;
        }
    };
    template <class VersionType, class DataType, class CmpType>
    class VersionChecker<VersionedData<VersionType, DataType, CmpType>> {
    private:
        std::optional<VersionType> lastVersion_;
        CmpType cmp_;
    public:
        VersionChecker() : lastVersion_(std::nullopt), cmp_() {}
        bool checkVersion(VersionedData<VersionType,DataType,CmpType> const &t) {
            if (!lastVersion_ || cmp_(*lastVersion_, t.version)) {
                lastVersion_ = t.version;
                return true;
            } else {
                return false;
            }
        }
    };
    template <class A>
    class VersionChecker<std::unique_ptr<A>> {
    private:
        VersionChecker<A> a_;
    public:
        VersionChecker() : a_() {}
        bool checkVersion(std::unique_ptr<A> const &t) {
            if (!t) {
                return true; //an empty pointer is assumed to be new version
            }
            return (a_.checkVersion(*t));
        }
    };
    template <class A>
    class VersionChecker<std::shared_ptr<A>> {
    private:
        VersionChecker<A> a_;
    public:
        VersionChecker() : a_() {}
        bool checkVersion(std::shared_ptr<A> const &t) {
            if (!t) {
                return true; //an empty pointer is assumed to be new version
            }
            return (a_.checkVersion(*t));
        }
    };
    template <class A, class B>
    class VersionChecker<std::tuple<A,B>> {
    private:
        VersionChecker<A> a_;
        VersionChecker<B> b_;
    public:
        VersionChecker() : a_(), b_() {}
        bool checkVersion(std::tuple<A,B> const &t) {
            return (a_.checkVersion(std::get<0>(t)) && b_.checkVersion(std::get<1>(t)));
        }
    };
    
} } } }

#endif