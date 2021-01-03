#ifndef TM_KIT_INFRA_VERSIONED_DATA_HPP_
#define TM_KIT_INFRA_VERSIONED_DATA_HPP_

#include <memory>
#include <optional>
#include <functional>
#include <type_traits>
#include <array>
#include <map>

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

    template <
        class GroupIDType
        , class VersionType
        , class DataType
        , class CmpType=std::less<VersionType>
        , class Enable=void
    >
    struct GroupedVersionedData {};

    template <
        class GroupIDType
        , class VersionType
        , class DataType
        , class CmpType
    >
    struct GroupedVersionedData<
        GroupIDType, VersionType, DataType, CmpType
        , std::enable_if_t<
            std::is_copy_constructible_v<VersionType> 
            && std::is_default_constructible_v<VersionType>
            && std::is_copy_constructible_v<GroupIDType>
            && std::is_default_constructible_v<GroupIDType>>
    > {
        using GroupID = GroupIDType;
        using Version = VersionType;
        using Data = DataType;
        using Cmp = CmpType;

        GroupIDType groupID;
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
        VersionChecker(VersionedData<VersionType,DataType,CmpType> const &t) 
            : lastVersion_(t.version), cmp_() {}
        bool checkVersion(VersionedData<VersionType,DataType,CmpType> const &t) {
            if (!lastVersion_ || cmp_(*lastVersion_, t.version)) {
                lastVersion_ = t.version;
                return true;
            } else {
                return false;
            }
        }
    };
    template <class GroupIDType, class VersionType, class DataType, class CmpType>
    class VersionChecker<GroupedVersionedData<GroupIDType, VersionType, DataType, CmpType>> {
    private:
        std::unordered_map<GroupIDType, VersionType> lastVersion_;
        CmpType cmp_;
    public:
        VersionChecker() : lastVersion_(), cmp_() {}
        VersionChecker(GroupedVersionedData<GroupIDType, VersionType, DataType, CmpType> const &t) 
            : lastVersion_({t.groupID, t.version}), cmp_() {}
        bool checkVersion(GroupedVersionedData<GroupIDType, VersionType,DataType,CmpType> const &t) {
            auto iter = lastVersion_.find(t.groupID);
            if (iter == lastVersion_.end()) {
                lastVersion_.insert({t.groupID, t.version});
                return true;
            }
            if (cmp_(iter->second, t.version)) {
                iter->second = t.version;
                return true;
            }
            return false;
        }
    };
    template <class VersionType, class DataType, class CmpType>
    class VersionChecker<VersionedData<VersionType, std::optional<DataType>, CmpType>> {
    private:
        std::optional<VersionType> lastVersion_;
        CmpType cmp_;
    public:
        VersionChecker() : lastVersion_(std::nullopt), cmp_() {}
        VersionChecker(VersionedData<VersionType,std::optional<DataType>,CmpType> const &t) 
            : lastVersion_(t.version), cmp_() {}
        bool checkVersion(VersionedData<VersionType,std::optional<DataType>,CmpType> const &t) {
            if (!t.data) {
                lastVersion_ = std::nullopt;
                return true;
            }
            if (!lastVersion_ || cmp_(*lastVersion_, t.version)) {
                lastVersion_ = t.version;
                return true;
            } else {
                return false;
            }
        }
    };
    template <class GroupIDType, class VersionType, class DataType, class CmpType>
    class VersionChecker<GroupedVersionedData<GroupIDType, VersionType, std::optional<DataType>, CmpType>> {
    private:
        std::unordered_map<GroupIDType, VersionType> lastVersion_;
        CmpType cmp_;
    public:
        VersionChecker() : lastVersion_(), cmp_() {}
        VersionChecker(GroupedVersionedData<GroupIDType, VersionType, std::optional<DataType>, CmpType> const &t) 
            : lastVersion_({t.groupID, t.version}), cmp_() {}
        bool checkVersion(GroupedVersionedData<GroupIDType, VersionType,std::optional<DataType>,CmpType> const &t) {
            if (!t.data) {
                lastVersion_.erase(t.groupID);
                return true;
            }
            auto iter = lastVersion_.find(t.groupID);
            if (iter == lastVersion_.end()) {
                lastVersion_.insert({t.groupID, t.version});
                return true;
            }
            if (cmp_(iter->second, t.version)) {
                iter->second = t.version;
                return true;
            }
            return false;
        }
    };
    template <class A>
    class VersionChecker<std::unique_ptr<A>> {
    private:
        VersionChecker<std::decay_t<A>> a_;
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
        VersionChecker<std::decay_t<A>> a_;
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
        VersionChecker<std::decay_t<A>> a_;
        VersionChecker<std::decay_t<B>> b_;
    public:
        VersionChecker() : a_(), b_() {}
        bool checkVersion(std::tuple<A,B> const &t) {
            return (a_.checkVersion(std::get<0>(t)) && b_.checkVersion(std::get<1>(t)));
        }
    };

    template <class T, size_t N>
    struct FullArrayComparer {
        bool operator()(std::array<T,N> const &a, std::array<T,N> const &b) const {
            for (size_t ii=0; ii<N; ++ii) {
                if (a[ii] < b[ii]) {
                    return true;
                }
                if (a[ii] > b[ii]) {
                    return false;
                }
            }
            return false;
        }
    };

    template <class T, size_t N>
    struct ArrayComparerWithSkip {
        bool operator()(std::array<T,N> const &a, std::array<T,N> const &b) const {
            static const T defaultVal {};
            for (size_t ii=0; ii<N; ++ii) {
                if (a[ii] == defaultVal || b[ii] == defaultVal) {
                    continue;
                }
                if (a[ii] < b[ii]) {
                    return true;
                }
                if (a[ii] > b[ii]) {
                    return false;
                }
            }
            return false;
        }
    };

    template <class T, size_t N>
    struct ArrayComparerWithOptional {
        bool operator()(std::array<std::optional<T>,N> const &a, std::array<std::optional<T>,N> const &b) const {
            for (size_t ii=0; ii<N; ++ii) {
                if (!a[ii] || !b[ii]) {
                    continue;
                }
                if (*(a[ii]) < *(b[ii])) {
                    return true;
                }
                if (*(a[ii]) > *(b[ii])) {
                    return false;
                }
            }
            return false;
        }
    };

    //only map (not unordered_map) is allowed because it maintains ordering between keys
    template <class Key, class T, class KeyCmp=std::less<Key>>
    struct MapComparerWithSkip {
        KeyCmp cmp_;
        bool operator()(std::map<Key,T,KeyCmp> const &a, std::map<Key,T,KeyCmp> const &b) const {
            static const T defaultVal {};
            auto aIter = a.begin();
            auto bIter = b.begin();
            while (aIter != a.end() && bIter != b.end()) {
                if (aIter->second == defaultVal) {
                    ++aIter;
                    continue;
                }
                if (bIter->second == defaultVal) {
                    ++bIter;
                    continue;
                }
                //if there is a key that only occurs in one map
                //, we ignore it in comparison
                if (cmp_(aIter->first, bIter->first)) {
                    ++aIter;
                    continue;
                }
                if (cmp_(bIter->first, aIter->first)) {
                    ++bIter;
                    continue; 
                }
                if (aIter->second < bIter->second) {
                    return true;
                }
                if (aIter->second > bIter->second) {
                    return false;
                }
                ++aIter;
                ++bIter;
            }
            if (aIter == a.end()) {
                if (bIter == b.end()) {
                    return false;
                } else {
                    while (bIter != b.end()) {
                        if (bIter->second != defaultVal) {
                            return true;
                        }
                        ++bIter;
                    }
                    return false;
                }
            } else {
                return false;
            }
        }
    };

    namespace withtime_utils {
        template <class VersionType, class DataType, class CmpType>
        inline void updateVersionedData(VersionedData<VersionType,DataType,CmpType> &dest
                                , VersionedData<VersionType,DataType,CmpType> &&src) {
            VersionChecker<VersionedData<VersionType,DataType,CmpType>> checker(dest);
            if (checker.checkVersion(src)) {
                dest = std::move(src);
            }
        }
        template <class GroupIDType, class VersionType, class DataType, class CmpType>
        inline void updateVersionedData(GroupedVersionedData<GroupIDType,VersionType,DataType,CmpType> &dest
                                , VersionedData<VersionType,DataType,CmpType> &&src) {
            VersionChecker<VersionedData<VersionType,DataType,CmpType>> checker(
                VersionedData<VersionType,DataType,CmpType> {dest.version, dest.data}
            );
            if (checker.checkVersion(src)) {
                dest.version = std::move(src.version);
                dest.data = std::move(src.data);
            }
        }
    }
    
} } } }

#endif
