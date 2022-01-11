template <class A0, class A1>
class TimeChecker<false, std::variant<A0,A1>> {
private:
    std::bitset<2> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1>
class TimeChecker<true, std::variant<A0,A1>> {
private:
    std::bitset<2> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2>
class TimeChecker<false, std::variant<A0,A1,A2>> {
private:
    std::bitset<3> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2>
class TimeChecker<true, std::variant<A0,A1,A2>> {
private:
    std::bitset<3> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3>
class TimeChecker<false, std::variant<A0,A1,A2,A3>> {
private:
    std::bitset<4> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3>
class TimeChecker<true, std::variant<A0,A1,A2,A3>> {
private:
    std::bitset<4> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4>> {
private:
    std::bitset<5> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4>> {
private:
    std::bitset<5> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5>> {
private:
    std::bitset<6> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5>> {
private:
    std::bitset<6> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6>> {
private:
    std::bitset<7> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6>> {
private:
    std::bitset<7> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {
private:
    std::bitset<8> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {
private:
    std::bitset<8> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
private:
    std::bitset<9> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
private:
    std::bitset<9> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
private:
    std::bitset<10> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
private:
    std::bitset<10> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> {
private:
    std::bitset<11> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> {
private:
    std::bitset<11> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> {
private:
    std::bitset<12> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> {
private:
    std::bitset<12> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> {
private:
    std::bitset<13> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> {
private:
    std::bitset<13> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> {
private:
    std::bitset<14> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> {
private:
    std::bitset<14> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> {
private:
    std::bitset<15> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> {
private:
    std::bitset<15> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> {
private:
    std::bitset<16> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
    std::optional<typename StateT::TimePointType> tp15_;
    VersionChecker<A15> versionChecker15_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_(), tp15_(std::nullopt), versionChecker15_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        case 15:
            if (!versionChecker15_.checkVersion(std::get<15>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp15_ && data.timedData.timePoint < *tp15_) {
                    return false;
                }
            }
            tp15_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(15);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> {
private:
    std::bitset<16> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
    std::optional<typename StateT::TimePointType> tp15_;
    VersionChecker<A15> versionChecker15_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_(), tp15_(std::nullopt), versionChecker15_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        case 15:
            if (!versionChecker15_.checkVersion(std::get<15>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp15_ && data.timedData.timePoint < *tp15_) {
                    return false;
                }
            }
            tp15_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(15);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> {
private:
    std::bitset<17> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
    std::optional<typename StateT::TimePointType> tp15_;
    VersionChecker<A15> versionChecker15_;
    std::optional<typename StateT::TimePointType> tp16_;
    VersionChecker<A16> versionChecker16_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_(), tp15_(std::nullopt), versionChecker15_(), tp16_(std::nullopt), versionChecker16_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        case 15:
            if (!versionChecker15_.checkVersion(std::get<15>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp15_ && data.timedData.timePoint < *tp15_) {
                    return false;
                }
            }
            tp15_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(15);
            }
            break;
        case 16:
            if (!versionChecker16_.checkVersion(std::get<16>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp16_ && data.timedData.timePoint < *tp16_) {
                    return false;
                }
            }
            tp16_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(16);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> {
private:
    std::bitset<17> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
    std::optional<typename StateT::TimePointType> tp15_;
    VersionChecker<A15> versionChecker15_;
    std::optional<typename StateT::TimePointType> tp16_;
    VersionChecker<A16> versionChecker16_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_(), tp15_(std::nullopt), versionChecker15_(), tp16_(std::nullopt), versionChecker16_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        case 15:
            if (!versionChecker15_.checkVersion(std::get<15>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp15_ && data.timedData.timePoint < *tp15_) {
                    return false;
                }
            }
            tp15_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(15);
            }
            break;
        case 16:
            if (!versionChecker16_.checkVersion(std::get<16>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp16_ && data.timedData.timePoint < *tp16_) {
                    return false;
                }
            }
            tp16_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(16);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> {
private:
    std::bitset<18> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
    std::optional<typename StateT::TimePointType> tp15_;
    VersionChecker<A15> versionChecker15_;
    std::optional<typename StateT::TimePointType> tp16_;
    VersionChecker<A16> versionChecker16_;
    std::optional<typename StateT::TimePointType> tp17_;
    VersionChecker<A17> versionChecker17_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_(), tp15_(std::nullopt), versionChecker15_(), tp16_(std::nullopt), versionChecker16_(), tp17_(std::nullopt), versionChecker17_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        case 15:
            if (!versionChecker15_.checkVersion(std::get<15>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp15_ && data.timedData.timePoint < *tp15_) {
                    return false;
                }
            }
            tp15_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(15);
            }
            break;
        case 16:
            if (!versionChecker16_.checkVersion(std::get<16>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp16_ && data.timedData.timePoint < *tp16_) {
                    return false;
                }
            }
            tp16_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(16);
            }
            break;
        case 17:
            if (!versionChecker17_.checkVersion(std::get<17>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp17_ && data.timedData.timePoint < *tp17_) {
                    return false;
                }
            }
            tp17_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(17);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> {
private:
    std::bitset<18> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
    std::optional<typename StateT::TimePointType> tp15_;
    VersionChecker<A15> versionChecker15_;
    std::optional<typename StateT::TimePointType> tp16_;
    VersionChecker<A16> versionChecker16_;
    std::optional<typename StateT::TimePointType> tp17_;
    VersionChecker<A17> versionChecker17_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_(), tp15_(std::nullopt), versionChecker15_(), tp16_(std::nullopt), versionChecker16_(), tp17_(std::nullopt), versionChecker17_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        case 15:
            if (!versionChecker15_.checkVersion(std::get<15>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp15_ && data.timedData.timePoint < *tp15_) {
                    return false;
                }
            }
            tp15_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(15);
            }
            break;
        case 16:
            if (!versionChecker16_.checkVersion(std::get<16>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp16_ && data.timedData.timePoint < *tp16_) {
                    return false;
                }
            }
            tp16_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(16);
            }
            break;
        case 17:
            if (!versionChecker17_.checkVersion(std::get<17>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp17_ && data.timedData.timePoint < *tp17_) {
                    return false;
                }
            }
            tp17_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(17);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> {
private:
    std::bitset<19> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
    std::optional<typename StateT::TimePointType> tp15_;
    VersionChecker<A15> versionChecker15_;
    std::optional<typename StateT::TimePointType> tp16_;
    VersionChecker<A16> versionChecker16_;
    std::optional<typename StateT::TimePointType> tp17_;
    VersionChecker<A17> versionChecker17_;
    std::optional<typename StateT::TimePointType> tp18_;
    VersionChecker<A18> versionChecker18_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_(), tp15_(std::nullopt), versionChecker15_(), tp16_(std::nullopt), versionChecker16_(), tp17_(std::nullopt), versionChecker17_(), tp18_(std::nullopt), versionChecker18_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        case 15:
            if (!versionChecker15_.checkVersion(std::get<15>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp15_ && data.timedData.timePoint < *tp15_) {
                    return false;
                }
            }
            tp15_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(15);
            }
            break;
        case 16:
            if (!versionChecker16_.checkVersion(std::get<16>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp16_ && data.timedData.timePoint < *tp16_) {
                    return false;
                }
            }
            tp16_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(16);
            }
            break;
        case 17:
            if (!versionChecker17_.checkVersion(std::get<17>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp17_ && data.timedData.timePoint < *tp17_) {
                    return false;
                }
            }
            tp17_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(17);
            }
            break;
        case 18:
            if (!versionChecker18_.checkVersion(std::get<18>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp18_ && data.timedData.timePoint < *tp18_) {
                    return false;
                }
            }
            tp18_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(18);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> {
private:
    std::bitset<19> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
    std::optional<typename StateT::TimePointType> tp15_;
    VersionChecker<A15> versionChecker15_;
    std::optional<typename StateT::TimePointType> tp16_;
    VersionChecker<A16> versionChecker16_;
    std::optional<typename StateT::TimePointType> tp17_;
    VersionChecker<A17> versionChecker17_;
    std::optional<typename StateT::TimePointType> tp18_;
    VersionChecker<A18> versionChecker18_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_(), tp15_(std::nullopt), versionChecker15_(), tp16_(std::nullopt), versionChecker16_(), tp17_(std::nullopt), versionChecker17_(), tp18_(std::nullopt), versionChecker18_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        case 15:
            if (!versionChecker15_.checkVersion(std::get<15>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp15_ && data.timedData.timePoint < *tp15_) {
                    return false;
                }
            }
            tp15_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(15);
            }
            break;
        case 16:
            if (!versionChecker16_.checkVersion(std::get<16>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp16_ && data.timedData.timePoint < *tp16_) {
                    return false;
                }
            }
            tp16_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(16);
            }
            break;
        case 17:
            if (!versionChecker17_.checkVersion(std::get<17>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp17_ && data.timedData.timePoint < *tp17_) {
                    return false;
                }
            }
            tp17_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(17);
            }
            break;
        case 18:
            if (!versionChecker18_.checkVersion(std::get<18>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp18_ && data.timedData.timePoint < *tp18_) {
                    return false;
                }
            }
            tp18_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(18);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class TimeChecker<false, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> {
private:
    std::bitset<20> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
    std::optional<typename StateT::TimePointType> tp15_;
    VersionChecker<A15> versionChecker15_;
    std::optional<typename StateT::TimePointType> tp16_;
    VersionChecker<A16> versionChecker16_;
    std::optional<typename StateT::TimePointType> tp17_;
    VersionChecker<A17> versionChecker17_;
    std::optional<typename StateT::TimePointType> tp18_;
    VersionChecker<A18> versionChecker18_;
    std::optional<typename StateT::TimePointType> tp19_;
    VersionChecker<A19> versionChecker19_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_(), tp15_(std::nullopt), versionChecker15_(), tp16_(std::nullopt), versionChecker16_(), tp17_(std::nullopt), versionChecker17_(), tp18_(std::nullopt), versionChecker18_(), tp19_(std::nullopt), versionChecker19_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> const &data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        case 15:
            if (!versionChecker15_.checkVersion(std::get<15>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp15_ && data.timedData.timePoint < *tp15_) {
                    return false;
                }
            }
            tp15_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(15);
            }
            break;
        case 16:
            if (!versionChecker16_.checkVersion(std::get<16>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp16_ && data.timedData.timePoint < *tp16_) {
                    return false;
                }
            }
            tp16_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(16);
            }
            break;
        case 17:
            if (!versionChecker17_.checkVersion(std::get<17>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp17_ && data.timedData.timePoint < *tp17_) {
                    return false;
                }
            }
            tp17_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(17);
            }
            break;
        case 18:
            if (!versionChecker18_.checkVersion(std::get<18>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp18_ && data.timedData.timePoint < *tp18_) {
                    return false;
                }
            }
            tp18_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(18);
            }
            break;
        case 19:
            if (!versionChecker19_.checkVersion(std::get<19>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp19_ && data.timedData.timePoint < *tp19_) {
                    return false;
                }
            }
            tp19_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(19);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> {
private:
    std::bitset<20> finalMask_;
    std::optional<typename StateT::TimePointType> tp0_;
    VersionChecker<A0> versionChecker0_;
    std::optional<typename StateT::TimePointType> tp1_;
    VersionChecker<A1> versionChecker1_;
    std::optional<typename StateT::TimePointType> tp2_;
    VersionChecker<A2> versionChecker2_;
    std::optional<typename StateT::TimePointType> tp3_;
    VersionChecker<A3> versionChecker3_;
    std::optional<typename StateT::TimePointType> tp4_;
    VersionChecker<A4> versionChecker4_;
    std::optional<typename StateT::TimePointType> tp5_;
    VersionChecker<A5> versionChecker5_;
    std::optional<typename StateT::TimePointType> tp6_;
    VersionChecker<A6> versionChecker6_;
    std::optional<typename StateT::TimePointType> tp7_;
    VersionChecker<A7> versionChecker7_;
    std::optional<typename StateT::TimePointType> tp8_;
    VersionChecker<A8> versionChecker8_;
    std::optional<typename StateT::TimePointType> tp9_;
    VersionChecker<A9> versionChecker9_;
    std::optional<typename StateT::TimePointType> tp10_;
    VersionChecker<A10> versionChecker10_;
    std::optional<typename StateT::TimePointType> tp11_;
    VersionChecker<A11> versionChecker11_;
    std::optional<typename StateT::TimePointType> tp12_;
    VersionChecker<A12> versionChecker12_;
    std::optional<typename StateT::TimePointType> tp13_;
    VersionChecker<A13> versionChecker13_;
    std::optional<typename StateT::TimePointType> tp14_;
    VersionChecker<A14> versionChecker14_;
    std::optional<typename StateT::TimePointType> tp15_;
    VersionChecker<A15> versionChecker15_;
    std::optional<typename StateT::TimePointType> tp16_;
    VersionChecker<A16> versionChecker16_;
    std::optional<typename StateT::TimePointType> tp17_;
    VersionChecker<A17> versionChecker17_;
    std::optional<typename StateT::TimePointType> tp18_;
    VersionChecker<A18> versionChecker18_;
    std::optional<typename StateT::TimePointType> tp19_;
    VersionChecker<A19> versionChecker19_;
    mutable std::mutex mutex_;
public:
    TimeChecker() :
        finalMask_(), tp0_(std::nullopt), versionChecker0_(), tp1_(std::nullopt), versionChecker1_(), tp2_(std::nullopt), versionChecker2_(), tp3_(std::nullopt), versionChecker3_(), tp4_(std::nullopt), versionChecker4_(), tp5_(std::nullopt), versionChecker5_(), tp6_(std::nullopt), versionChecker6_(), tp7_(std::nullopt), versionChecker7_(), tp8_(std::nullopt), versionChecker8_(), tp9_(std::nullopt), versionChecker9_(), tp10_(std::nullopt), versionChecker10_(), tp11_(std::nullopt), versionChecker11_(), tp12_(std::nullopt), versionChecker12_(), tp13_(std::nullopt), versionChecker13_(), tp14_(std::nullopt), versionChecker14_(), tp15_(std::nullopt), versionChecker15_(), tp16_(std::nullopt), versionChecker16_(), tp17_(std::nullopt), versionChecker17_(), tp18_(std::nullopt), versionChecker18_(), tp19_(std::nullopt), versionChecker19_(), mutex_()
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> const &data) {
        std::lock_guard<std::mutex> _(mutex_);
        switch (data.timedData.value.index()) {
        case 0:
            if (!versionChecker0_.checkVersion(std::get<0>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp0_ && data.timedData.timePoint < *tp0_) {
                    return false;
                }
            }
            tp0_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(0);
            }
            break;
        case 1:
            if (!versionChecker1_.checkVersion(std::get<1>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp1_ && data.timedData.timePoint < *tp1_) {
                    return false;
                }
            }
            tp1_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(1);
            }
            break;
        case 2:
            if (!versionChecker2_.checkVersion(std::get<2>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp2_ && data.timedData.timePoint < *tp2_) {
                    return false;
                }
            }
            tp2_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(2);
            }
            break;
        case 3:
            if (!versionChecker3_.checkVersion(std::get<3>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp3_ && data.timedData.timePoint < *tp3_) {
                    return false;
                }
            }
            tp3_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(3);
            }
            break;
        case 4:
            if (!versionChecker4_.checkVersion(std::get<4>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp4_ && data.timedData.timePoint < *tp4_) {
                    return false;
                }
            }
            tp4_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(4);
            }
            break;
        case 5:
            if (!versionChecker5_.checkVersion(std::get<5>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp5_ && data.timedData.timePoint < *tp5_) {
                    return false;
                }
            }
            tp5_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(5);
            }
            break;
        case 6:
            if (!versionChecker6_.checkVersion(std::get<6>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp6_ && data.timedData.timePoint < *tp6_) {
                    return false;
                }
            }
            tp6_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(6);
            }
            break;
        case 7:
            if (!versionChecker7_.checkVersion(std::get<7>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp7_ && data.timedData.timePoint < *tp7_) {
                    return false;
                }
            }
            tp7_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(7);
            }
            break;
        case 8:
            if (!versionChecker8_.checkVersion(std::get<8>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp8_ && data.timedData.timePoint < *tp8_) {
                    return false;
                }
            }
            tp8_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(8);
            }
            break;
        case 9:
            if (!versionChecker9_.checkVersion(std::get<9>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp9_ && data.timedData.timePoint < *tp9_) {
                    return false;
                }
            }
            tp9_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(9);
            }
            break;
        case 10:
            if (!versionChecker10_.checkVersion(std::get<10>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp10_ && data.timedData.timePoint < *tp10_) {
                    return false;
                }
            }
            tp10_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(10);
            }
            break;
        case 11:
            if (!versionChecker11_.checkVersion(std::get<11>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp11_ && data.timedData.timePoint < *tp11_) {
                    return false;
                }
            }
            tp11_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(11);
            }
            break;
        case 12:
            if (!versionChecker12_.checkVersion(std::get<12>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp12_ && data.timedData.timePoint < *tp12_) {
                    return false;
                }
            }
            tp12_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(12);
            }
            break;
        case 13:
            if (!versionChecker13_.checkVersion(std::get<13>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp13_ && data.timedData.timePoint < *tp13_) {
                    return false;
                }
            }
            tp13_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(13);
            }
            break;
        case 14:
            if (!versionChecker14_.checkVersion(std::get<14>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp14_ && data.timedData.timePoint < *tp14_) {
                    return false;
                }
            }
            tp14_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(14);
            }
            break;
        case 15:
            if (!versionChecker15_.checkVersion(std::get<15>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp15_ && data.timedData.timePoint < *tp15_) {
                    return false;
                }
            }
            tp15_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(15);
            }
            break;
        case 16:
            if (!versionChecker16_.checkVersion(std::get<16>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp16_ && data.timedData.timePoint < *tp16_) {
                    return false;
                }
            }
            tp16_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(16);
            }
            break;
        case 17:
            if (!versionChecker17_.checkVersion(std::get<17>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp17_ && data.timedData.timePoint < *tp17_) {
                    return false;
                }
            }
            tp17_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(17);
            }
            break;
        case 18:
            if (!versionChecker18_.checkVersion(std::get<18>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp18_ && data.timedData.timePoint < *tp18_) {
                    return false;
                }
            }
            tp18_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(18);
            }
            break;
        case 19:
            if (!versionChecker19_.checkVersion(std::get<19>(data.timedData.value))) {
                return false;
            }
            if (StateT::CheckTime) {
                if (tp19_ && data.timedData.timePoint < *tp19_) {
                    return false;
                }
            }
            tp19_ = data.timedData.timePoint;
            if (data.timedData.finalFlag) {
                finalMask_.set(19);
            }
            break;
        }
        return true;
    }
    inline bool isFinalUpdate() const {
        std::lock_guard<std::mutex> _(mutex_);
        return finalMask_.all();
    }
};