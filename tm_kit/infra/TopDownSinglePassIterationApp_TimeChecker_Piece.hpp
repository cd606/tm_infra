template <class A0, class A1>
class TimeChecker<std::variant<A0,A1>> {
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
template <class A0, class A1, class A2>
class TimeChecker<std::variant<A0,A1,A2>> {
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
template <class A0, class A1, class A2, class A3>
class TimeChecker<std::variant<A0,A1,A2,A3>> {
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
template <class A0, class A1, class A2, class A3, class A4>
class TimeChecker<std::variant<A0,A1,A2,A3,A4>> {
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
template <class A0, class A1, class A2, class A3, class A4, class A5>
class TimeChecker<std::variant<A0,A1,A2,A3,A4,A5>> {
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6>> {
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
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