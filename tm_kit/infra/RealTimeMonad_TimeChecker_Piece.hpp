template <class A0, class A1>
class TimeChecker<std::variant<A0,A1>> {
private:
    FanInParamMask requireMask_;
    bool hasData0_;
    WithTime<A0, typename StateT::TimePointType> a0_;
    bool hasData1_;
    WithTime<A1, typename StateT::TimePointType> a1_;
    int lastIdx_;
public:
    TimeChecker(FanInParamMask const &requireMask=FanInParamMask()) :
        requireMask_(requireMask), hasData0_(false), a0_(), hasData1_(false), a1_(), lastIdx_(-1)
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1>, StateT, typename StateT::TimePointType> &&data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (StateT::CheckTime) {
                if (hasData0_ && data.timedData.timePoint < a0_.timePoint) {
                    return false;
                }
            }
            hasData0_ = true;
            a0_ = {data.timedData.timePoint, std::move(std::get<0>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 0;
            break;
        case 1:
            if (StateT::CheckTime) {
                if (hasData1_ && data.timedData.timePoint < a1_.timePoint) {
                    return false;
                }
            }
            hasData1_ = true;
            a1_ = {data.timedData.timePoint, std::move(std::get<1>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 1;
            break;
        }
        return true;
    }
    inline int lastIdx() const {
        return lastIdx_;
    }
    inline bool good() const {
        return (
            (!requireMask_[0] || hasData0_) && 
            (!requireMask_[1] || hasData1_)
        );
    }
    inline WithTime<A0, typename StateT::TimePointType> const &get0() const {
        return a0_;
    }
    inline WithTime<A1, typename StateT::TimePointType> const &get1() const {
        return a1_;
    }
};
template <class A0, class A1, class A2>
class TimeChecker<std::variant<A0,A1,A2>> {
private:
    FanInParamMask requireMask_;
    bool hasData0_;
    WithTime<A0, typename StateT::TimePointType> a0_;
    bool hasData1_;
    WithTime<A1, typename StateT::TimePointType> a1_;
    bool hasData2_;
    WithTime<A2, typename StateT::TimePointType> a2_;
    int lastIdx_;
public:
    TimeChecker(FanInParamMask const &requireMask=FanInParamMask()) :
        requireMask_(requireMask), hasData0_(false), a0_(), hasData1_(false), a1_(), hasData2_(false), a2_(), lastIdx_(-1)
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2>, StateT, typename StateT::TimePointType> &&data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (StateT::CheckTime) {
                if (hasData0_ && data.timedData.timePoint < a0_.timePoint) {
                    return false;
                }
            }
            hasData0_ = true;
            a0_ = {data.timedData.timePoint, std::move(std::get<0>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 0;
            break;
        case 1:
            if (StateT::CheckTime) {
                if (hasData1_ && data.timedData.timePoint < a1_.timePoint) {
                    return false;
                }
            }
            hasData1_ = true;
            a1_ = {data.timedData.timePoint, std::move(std::get<1>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 1;
            break;
        case 2:
            if (StateT::CheckTime) {
                if (hasData2_ && data.timedData.timePoint < a2_.timePoint) {
                    return false;
                }
            }
            hasData2_ = true;
            a2_ = {data.timedData.timePoint, std::move(std::get<2>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 2;
            break;
        }
        return true;
    }
    inline int lastIdx() const {
        return lastIdx_;
    }
    inline bool good() const {
        return (
            (!requireMask_[0] || hasData0_) && 
            (!requireMask_[1] || hasData1_) && 
            (!requireMask_[2] || hasData2_)
        );
    }
    inline WithTime<A0, typename StateT::TimePointType> const &get0() const {
        return a0_;
    }
    inline WithTime<A1, typename StateT::TimePointType> const &get1() const {
        return a1_;
    }
    inline WithTime<A2, typename StateT::TimePointType> const &get2() const {
        return a2_;
    }
};
template <class A0, class A1, class A2, class A3>
class TimeChecker<std::variant<A0,A1,A2,A3>> {
private:
    FanInParamMask requireMask_;
    bool hasData0_;
    WithTime<A0, typename StateT::TimePointType> a0_;
    bool hasData1_;
    WithTime<A1, typename StateT::TimePointType> a1_;
    bool hasData2_;
    WithTime<A2, typename StateT::TimePointType> a2_;
    bool hasData3_;
    WithTime<A3, typename StateT::TimePointType> a3_;
    int lastIdx_;
public:
    TimeChecker(FanInParamMask const &requireMask=FanInParamMask()) :
        requireMask_(requireMask), hasData0_(false), a0_(), hasData1_(false), a1_(), hasData2_(false), a2_(), hasData3_(false), a3_(), lastIdx_(-1)
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType> &&data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (StateT::CheckTime) {
                if (hasData0_ && data.timedData.timePoint < a0_.timePoint) {
                    return false;
                }
            }
            hasData0_ = true;
            a0_ = {data.timedData.timePoint, std::move(std::get<0>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 0;
            break;
        case 1:
            if (StateT::CheckTime) {
                if (hasData1_ && data.timedData.timePoint < a1_.timePoint) {
                    return false;
                }
            }
            hasData1_ = true;
            a1_ = {data.timedData.timePoint, std::move(std::get<1>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 1;
            break;
        case 2:
            if (StateT::CheckTime) {
                if (hasData2_ && data.timedData.timePoint < a2_.timePoint) {
                    return false;
                }
            }
            hasData2_ = true;
            a2_ = {data.timedData.timePoint, std::move(std::get<2>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 2;
            break;
        case 3:
            if (StateT::CheckTime) {
                if (hasData3_ && data.timedData.timePoint < a3_.timePoint) {
                    return false;
                }
            }
            hasData3_ = true;
            a3_ = {data.timedData.timePoint, std::move(std::get<3>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 3;
            break;
        }
        return true;
    }
    inline int lastIdx() const {
        return lastIdx_;
    }
    inline bool good() const {
        return (
            (!requireMask_[0] || hasData0_) && 
            (!requireMask_[1] || hasData1_) && 
            (!requireMask_[2] || hasData2_) && 
            (!requireMask_[3] || hasData3_)
        );
    }
    inline WithTime<A0, typename StateT::TimePointType> const &get0() const {
        return a0_;
    }
    inline WithTime<A1, typename StateT::TimePointType> const &get1() const {
        return a1_;
    }
    inline WithTime<A2, typename StateT::TimePointType> const &get2() const {
        return a2_;
    }
    inline WithTime<A3, typename StateT::TimePointType> const &get3() const {
        return a3_;
    }
};
template <class A0, class A1, class A2, class A3, class A4>
class TimeChecker<std::variant<A0,A1,A2,A3,A4>> {
private:
    FanInParamMask requireMask_;
    bool hasData0_;
    WithTime<A0, typename StateT::TimePointType> a0_;
    bool hasData1_;
    WithTime<A1, typename StateT::TimePointType> a1_;
    bool hasData2_;
    WithTime<A2, typename StateT::TimePointType> a2_;
    bool hasData3_;
    WithTime<A3, typename StateT::TimePointType> a3_;
    bool hasData4_;
    WithTime<A4, typename StateT::TimePointType> a4_;
    int lastIdx_;
public:
    TimeChecker(FanInParamMask const &requireMask=FanInParamMask()) :
        requireMask_(requireMask), hasData0_(false), a0_(), hasData1_(false), a1_(), hasData2_(false), a2_(), hasData3_(false), a3_(), hasData4_(false), a4_(), lastIdx_(-1)
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType> &&data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (StateT::CheckTime) {
                if (hasData0_ && data.timedData.timePoint < a0_.timePoint) {
                    return false;
                }
            }
            hasData0_ = true;
            a0_ = {data.timedData.timePoint, std::move(std::get<0>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 0;
            break;
        case 1:
            if (StateT::CheckTime) {
                if (hasData1_ && data.timedData.timePoint < a1_.timePoint) {
                    return false;
                }
            }
            hasData1_ = true;
            a1_ = {data.timedData.timePoint, std::move(std::get<1>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 1;
            break;
        case 2:
            if (StateT::CheckTime) {
                if (hasData2_ && data.timedData.timePoint < a2_.timePoint) {
                    return false;
                }
            }
            hasData2_ = true;
            a2_ = {data.timedData.timePoint, std::move(std::get<2>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 2;
            break;
        case 3:
            if (StateT::CheckTime) {
                if (hasData3_ && data.timedData.timePoint < a3_.timePoint) {
                    return false;
                }
            }
            hasData3_ = true;
            a3_ = {data.timedData.timePoint, std::move(std::get<3>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 3;
            break;
        case 4:
            if (StateT::CheckTime) {
                if (hasData4_ && data.timedData.timePoint < a4_.timePoint) {
                    return false;
                }
            }
            hasData4_ = true;
            a4_ = {data.timedData.timePoint, std::move(std::get<4>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 4;
            break;
        }
        return true;
    }
    inline int lastIdx() const {
        return lastIdx_;
    }
    inline bool good() const {
        return (
            (!requireMask_[0] || hasData0_) && 
            (!requireMask_[1] || hasData1_) && 
            (!requireMask_[2] || hasData2_) && 
            (!requireMask_[3] || hasData3_) && 
            (!requireMask_[4] || hasData4_)
        );
    }
    inline WithTime<A0, typename StateT::TimePointType> const &get0() const {
        return a0_;
    }
    inline WithTime<A1, typename StateT::TimePointType> const &get1() const {
        return a1_;
    }
    inline WithTime<A2, typename StateT::TimePointType> const &get2() const {
        return a2_;
    }
    inline WithTime<A3, typename StateT::TimePointType> const &get3() const {
        return a3_;
    }
    inline WithTime<A4, typename StateT::TimePointType> const &get4() const {
        return a4_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
class TimeChecker<std::variant<A0,A1,A2,A3,A4,A5>> {
private:
    FanInParamMask requireMask_;
    bool hasData0_;
    WithTime<A0, typename StateT::TimePointType> a0_;
    bool hasData1_;
    WithTime<A1, typename StateT::TimePointType> a1_;
    bool hasData2_;
    WithTime<A2, typename StateT::TimePointType> a2_;
    bool hasData3_;
    WithTime<A3, typename StateT::TimePointType> a3_;
    bool hasData4_;
    WithTime<A4, typename StateT::TimePointType> a4_;
    bool hasData5_;
    WithTime<A5, typename StateT::TimePointType> a5_;
    int lastIdx_;
public:
    TimeChecker(FanInParamMask const &requireMask=FanInParamMask()) :
        requireMask_(requireMask), hasData0_(false), a0_(), hasData1_(false), a1_(), hasData2_(false), a2_(), hasData3_(false), a3_(), hasData4_(false), a4_(), hasData5_(false), a5_(), lastIdx_(-1)
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> &&data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (StateT::CheckTime) {
                if (hasData0_ && data.timedData.timePoint < a0_.timePoint) {
                    return false;
                }
            }
            hasData0_ = true;
            a0_ = {data.timedData.timePoint, std::move(std::get<0>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 0;
            break;
        case 1:
            if (StateT::CheckTime) {
                if (hasData1_ && data.timedData.timePoint < a1_.timePoint) {
                    return false;
                }
            }
            hasData1_ = true;
            a1_ = {data.timedData.timePoint, std::move(std::get<1>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 1;
            break;
        case 2:
            if (StateT::CheckTime) {
                if (hasData2_ && data.timedData.timePoint < a2_.timePoint) {
                    return false;
                }
            }
            hasData2_ = true;
            a2_ = {data.timedData.timePoint, std::move(std::get<2>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 2;
            break;
        case 3:
            if (StateT::CheckTime) {
                if (hasData3_ && data.timedData.timePoint < a3_.timePoint) {
                    return false;
                }
            }
            hasData3_ = true;
            a3_ = {data.timedData.timePoint, std::move(std::get<3>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 3;
            break;
        case 4:
            if (StateT::CheckTime) {
                if (hasData4_ && data.timedData.timePoint < a4_.timePoint) {
                    return false;
                }
            }
            hasData4_ = true;
            a4_ = {data.timedData.timePoint, std::move(std::get<4>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 4;
            break;
        case 5:
            if (StateT::CheckTime) {
                if (hasData5_ && data.timedData.timePoint < a5_.timePoint) {
                    return false;
                }
            }
            hasData5_ = true;
            a5_ = {data.timedData.timePoint, std::move(std::get<5>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 5;
            break;
        }
        return true;
    }
    inline int lastIdx() const {
        return lastIdx_;
    }
    inline bool good() const {
        return (
            (!requireMask_[0] || hasData0_) && 
            (!requireMask_[1] || hasData1_) && 
            (!requireMask_[2] || hasData2_) && 
            (!requireMask_[3] || hasData3_) && 
            (!requireMask_[4] || hasData4_) && 
            (!requireMask_[5] || hasData5_)
        );
    }
    inline WithTime<A0, typename StateT::TimePointType> const &get0() const {
        return a0_;
    }
    inline WithTime<A1, typename StateT::TimePointType> const &get1() const {
        return a1_;
    }
    inline WithTime<A2, typename StateT::TimePointType> const &get2() const {
        return a2_;
    }
    inline WithTime<A3, typename StateT::TimePointType> const &get3() const {
        return a3_;
    }
    inline WithTime<A4, typename StateT::TimePointType> const &get4() const {
        return a4_;
    }
    inline WithTime<A5, typename StateT::TimePointType> const &get5() const {
        return a5_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6>> {
private:
    FanInParamMask requireMask_;
    bool hasData0_;
    WithTime<A0, typename StateT::TimePointType> a0_;
    bool hasData1_;
    WithTime<A1, typename StateT::TimePointType> a1_;
    bool hasData2_;
    WithTime<A2, typename StateT::TimePointType> a2_;
    bool hasData3_;
    WithTime<A3, typename StateT::TimePointType> a3_;
    bool hasData4_;
    WithTime<A4, typename StateT::TimePointType> a4_;
    bool hasData5_;
    WithTime<A5, typename StateT::TimePointType> a5_;
    bool hasData6_;
    WithTime<A6, typename StateT::TimePointType> a6_;
    int lastIdx_;
public:
    TimeChecker(FanInParamMask const &requireMask=FanInParamMask()) :
        requireMask_(requireMask), hasData0_(false), a0_(), hasData1_(false), a1_(), hasData2_(false), a2_(), hasData3_(false), a3_(), hasData4_(false), a4_(), hasData5_(false), a5_(), hasData6_(false), a6_(), lastIdx_(-1)
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> &&data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (StateT::CheckTime) {
                if (hasData0_ && data.timedData.timePoint < a0_.timePoint) {
                    return false;
                }
            }
            hasData0_ = true;
            a0_ = {data.timedData.timePoint, std::move(std::get<0>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 0;
            break;
        case 1:
            if (StateT::CheckTime) {
                if (hasData1_ && data.timedData.timePoint < a1_.timePoint) {
                    return false;
                }
            }
            hasData1_ = true;
            a1_ = {data.timedData.timePoint, std::move(std::get<1>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 1;
            break;
        case 2:
            if (StateT::CheckTime) {
                if (hasData2_ && data.timedData.timePoint < a2_.timePoint) {
                    return false;
                }
            }
            hasData2_ = true;
            a2_ = {data.timedData.timePoint, std::move(std::get<2>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 2;
            break;
        case 3:
            if (StateT::CheckTime) {
                if (hasData3_ && data.timedData.timePoint < a3_.timePoint) {
                    return false;
                }
            }
            hasData3_ = true;
            a3_ = {data.timedData.timePoint, std::move(std::get<3>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 3;
            break;
        case 4:
            if (StateT::CheckTime) {
                if (hasData4_ && data.timedData.timePoint < a4_.timePoint) {
                    return false;
                }
            }
            hasData4_ = true;
            a4_ = {data.timedData.timePoint, std::move(std::get<4>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 4;
            break;
        case 5:
            if (StateT::CheckTime) {
                if (hasData5_ && data.timedData.timePoint < a5_.timePoint) {
                    return false;
                }
            }
            hasData5_ = true;
            a5_ = {data.timedData.timePoint, std::move(std::get<5>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 5;
            break;
        case 6:
            if (StateT::CheckTime) {
                if (hasData6_ && data.timedData.timePoint < a6_.timePoint) {
                    return false;
                }
            }
            hasData6_ = true;
            a6_ = {data.timedData.timePoint, std::move(std::get<6>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 6;
            break;
        }
        return true;
    }
    inline int lastIdx() const {
        return lastIdx_;
    }
    inline bool good() const {
        return (
            (!requireMask_[0] || hasData0_) && 
            (!requireMask_[1] || hasData1_) && 
            (!requireMask_[2] || hasData2_) && 
            (!requireMask_[3] || hasData3_) && 
            (!requireMask_[4] || hasData4_) && 
            (!requireMask_[5] || hasData5_) && 
            (!requireMask_[6] || hasData6_)
        );
    }
    inline WithTime<A0, typename StateT::TimePointType> const &get0() const {
        return a0_;
    }
    inline WithTime<A1, typename StateT::TimePointType> const &get1() const {
        return a1_;
    }
    inline WithTime<A2, typename StateT::TimePointType> const &get2() const {
        return a2_;
    }
    inline WithTime<A3, typename StateT::TimePointType> const &get3() const {
        return a3_;
    }
    inline WithTime<A4, typename StateT::TimePointType> const &get4() const {
        return a4_;
    }
    inline WithTime<A5, typename StateT::TimePointType> const &get5() const {
        return a5_;
    }
    inline WithTime<A6, typename StateT::TimePointType> const &get6() const {
        return a6_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {
private:
    FanInParamMask requireMask_;
    bool hasData0_;
    WithTime<A0, typename StateT::TimePointType> a0_;
    bool hasData1_;
    WithTime<A1, typename StateT::TimePointType> a1_;
    bool hasData2_;
    WithTime<A2, typename StateT::TimePointType> a2_;
    bool hasData3_;
    WithTime<A3, typename StateT::TimePointType> a3_;
    bool hasData4_;
    WithTime<A4, typename StateT::TimePointType> a4_;
    bool hasData5_;
    WithTime<A5, typename StateT::TimePointType> a5_;
    bool hasData6_;
    WithTime<A6, typename StateT::TimePointType> a6_;
    bool hasData7_;
    WithTime<A7, typename StateT::TimePointType> a7_;
    int lastIdx_;
public:
    TimeChecker(FanInParamMask const &requireMask=FanInParamMask()) :
        requireMask_(requireMask), hasData0_(false), a0_(), hasData1_(false), a1_(), hasData2_(false), a2_(), hasData3_(false), a3_(), hasData4_(false), a4_(), hasData5_(false), a5_(), hasData6_(false), a6_(), hasData7_(false), a7_(), lastIdx_(-1)
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> &&data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (StateT::CheckTime) {
                if (hasData0_ && data.timedData.timePoint < a0_.timePoint) {
                    return false;
                }
            }
            hasData0_ = true;
            a0_ = {data.timedData.timePoint, std::move(std::get<0>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 0;
            break;
        case 1:
            if (StateT::CheckTime) {
                if (hasData1_ && data.timedData.timePoint < a1_.timePoint) {
                    return false;
                }
            }
            hasData1_ = true;
            a1_ = {data.timedData.timePoint, std::move(std::get<1>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 1;
            break;
        case 2:
            if (StateT::CheckTime) {
                if (hasData2_ && data.timedData.timePoint < a2_.timePoint) {
                    return false;
                }
            }
            hasData2_ = true;
            a2_ = {data.timedData.timePoint, std::move(std::get<2>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 2;
            break;
        case 3:
            if (StateT::CheckTime) {
                if (hasData3_ && data.timedData.timePoint < a3_.timePoint) {
                    return false;
                }
            }
            hasData3_ = true;
            a3_ = {data.timedData.timePoint, std::move(std::get<3>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 3;
            break;
        case 4:
            if (StateT::CheckTime) {
                if (hasData4_ && data.timedData.timePoint < a4_.timePoint) {
                    return false;
                }
            }
            hasData4_ = true;
            a4_ = {data.timedData.timePoint, std::move(std::get<4>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 4;
            break;
        case 5:
            if (StateT::CheckTime) {
                if (hasData5_ && data.timedData.timePoint < a5_.timePoint) {
                    return false;
                }
            }
            hasData5_ = true;
            a5_ = {data.timedData.timePoint, std::move(std::get<5>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 5;
            break;
        case 6:
            if (StateT::CheckTime) {
                if (hasData6_ && data.timedData.timePoint < a6_.timePoint) {
                    return false;
                }
            }
            hasData6_ = true;
            a6_ = {data.timedData.timePoint, std::move(std::get<6>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 6;
            break;
        case 7:
            if (StateT::CheckTime) {
                if (hasData7_ && data.timedData.timePoint < a7_.timePoint) {
                    return false;
                }
            }
            hasData7_ = true;
            a7_ = {data.timedData.timePoint, std::move(std::get<7>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 7;
            break;
        }
        return true;
    }
    inline int lastIdx() const {
        return lastIdx_;
    }
    inline bool good() const {
        return (
            (!requireMask_[0] || hasData0_) && 
            (!requireMask_[1] || hasData1_) && 
            (!requireMask_[2] || hasData2_) && 
            (!requireMask_[3] || hasData3_) && 
            (!requireMask_[4] || hasData4_) && 
            (!requireMask_[5] || hasData5_) && 
            (!requireMask_[6] || hasData6_) && 
            (!requireMask_[7] || hasData7_)
        );
    }
    inline WithTime<A0, typename StateT::TimePointType> const &get0() const {
        return a0_;
    }
    inline WithTime<A1, typename StateT::TimePointType> const &get1() const {
        return a1_;
    }
    inline WithTime<A2, typename StateT::TimePointType> const &get2() const {
        return a2_;
    }
    inline WithTime<A3, typename StateT::TimePointType> const &get3() const {
        return a3_;
    }
    inline WithTime<A4, typename StateT::TimePointType> const &get4() const {
        return a4_;
    }
    inline WithTime<A5, typename StateT::TimePointType> const &get5() const {
        return a5_;
    }
    inline WithTime<A6, typename StateT::TimePointType> const &get6() const {
        return a6_;
    }
    inline WithTime<A7, typename StateT::TimePointType> const &get7() const {
        return a7_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
private:
    FanInParamMask requireMask_;
    bool hasData0_;
    WithTime<A0, typename StateT::TimePointType> a0_;
    bool hasData1_;
    WithTime<A1, typename StateT::TimePointType> a1_;
    bool hasData2_;
    WithTime<A2, typename StateT::TimePointType> a2_;
    bool hasData3_;
    WithTime<A3, typename StateT::TimePointType> a3_;
    bool hasData4_;
    WithTime<A4, typename StateT::TimePointType> a4_;
    bool hasData5_;
    WithTime<A5, typename StateT::TimePointType> a5_;
    bool hasData6_;
    WithTime<A6, typename StateT::TimePointType> a6_;
    bool hasData7_;
    WithTime<A7, typename StateT::TimePointType> a7_;
    bool hasData8_;
    WithTime<A8, typename StateT::TimePointType> a8_;
    int lastIdx_;
public:
    TimeChecker(FanInParamMask const &requireMask=FanInParamMask()) :
        requireMask_(requireMask), hasData0_(false), a0_(), hasData1_(false), a1_(), hasData2_(false), a2_(), hasData3_(false), a3_(), hasData4_(false), a4_(), hasData5_(false), a5_(), hasData6_(false), a6_(), hasData7_(false), a7_(), hasData8_(false), a8_(), lastIdx_(-1)
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> &&data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (StateT::CheckTime) {
                if (hasData0_ && data.timedData.timePoint < a0_.timePoint) {
                    return false;
                }
            }
            hasData0_ = true;
            a0_ = {data.timedData.timePoint, std::move(std::get<0>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 0;
            break;
        case 1:
            if (StateT::CheckTime) {
                if (hasData1_ && data.timedData.timePoint < a1_.timePoint) {
                    return false;
                }
            }
            hasData1_ = true;
            a1_ = {data.timedData.timePoint, std::move(std::get<1>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 1;
            break;
        case 2:
            if (StateT::CheckTime) {
                if (hasData2_ && data.timedData.timePoint < a2_.timePoint) {
                    return false;
                }
            }
            hasData2_ = true;
            a2_ = {data.timedData.timePoint, std::move(std::get<2>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 2;
            break;
        case 3:
            if (StateT::CheckTime) {
                if (hasData3_ && data.timedData.timePoint < a3_.timePoint) {
                    return false;
                }
            }
            hasData3_ = true;
            a3_ = {data.timedData.timePoint, std::move(std::get<3>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 3;
            break;
        case 4:
            if (StateT::CheckTime) {
                if (hasData4_ && data.timedData.timePoint < a4_.timePoint) {
                    return false;
                }
            }
            hasData4_ = true;
            a4_ = {data.timedData.timePoint, std::move(std::get<4>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 4;
            break;
        case 5:
            if (StateT::CheckTime) {
                if (hasData5_ && data.timedData.timePoint < a5_.timePoint) {
                    return false;
                }
            }
            hasData5_ = true;
            a5_ = {data.timedData.timePoint, std::move(std::get<5>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 5;
            break;
        case 6:
            if (StateT::CheckTime) {
                if (hasData6_ && data.timedData.timePoint < a6_.timePoint) {
                    return false;
                }
            }
            hasData6_ = true;
            a6_ = {data.timedData.timePoint, std::move(std::get<6>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 6;
            break;
        case 7:
            if (StateT::CheckTime) {
                if (hasData7_ && data.timedData.timePoint < a7_.timePoint) {
                    return false;
                }
            }
            hasData7_ = true;
            a7_ = {data.timedData.timePoint, std::move(std::get<7>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 7;
            break;
        case 8:
            if (StateT::CheckTime) {
                if (hasData8_ && data.timedData.timePoint < a8_.timePoint) {
                    return false;
                }
            }
            hasData8_ = true;
            a8_ = {data.timedData.timePoint, std::move(std::get<8>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 8;
            break;
        }
        return true;
    }
    inline int lastIdx() const {
        return lastIdx_;
    }
    inline bool good() const {
        return (
            (!requireMask_[0] || hasData0_) && 
            (!requireMask_[1] || hasData1_) && 
            (!requireMask_[2] || hasData2_) && 
            (!requireMask_[3] || hasData3_) && 
            (!requireMask_[4] || hasData4_) && 
            (!requireMask_[5] || hasData5_) && 
            (!requireMask_[6] || hasData6_) && 
            (!requireMask_[7] || hasData7_) && 
            (!requireMask_[8] || hasData8_)
        );
    }
    inline WithTime<A0, typename StateT::TimePointType> const &get0() const {
        return a0_;
    }
    inline WithTime<A1, typename StateT::TimePointType> const &get1() const {
        return a1_;
    }
    inline WithTime<A2, typename StateT::TimePointType> const &get2() const {
        return a2_;
    }
    inline WithTime<A3, typename StateT::TimePointType> const &get3() const {
        return a3_;
    }
    inline WithTime<A4, typename StateT::TimePointType> const &get4() const {
        return a4_;
    }
    inline WithTime<A5, typename StateT::TimePointType> const &get5() const {
        return a5_;
    }
    inline WithTime<A6, typename StateT::TimePointType> const &get6() const {
        return a6_;
    }
    inline WithTime<A7, typename StateT::TimePointType> const &get7() const {
        return a7_;
    }
    inline WithTime<A8, typename StateT::TimePointType> const &get8() const {
        return a8_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
private:
    FanInParamMask requireMask_;
    bool hasData0_;
    WithTime<A0, typename StateT::TimePointType> a0_;
    bool hasData1_;
    WithTime<A1, typename StateT::TimePointType> a1_;
    bool hasData2_;
    WithTime<A2, typename StateT::TimePointType> a2_;
    bool hasData3_;
    WithTime<A3, typename StateT::TimePointType> a3_;
    bool hasData4_;
    WithTime<A4, typename StateT::TimePointType> a4_;
    bool hasData5_;
    WithTime<A5, typename StateT::TimePointType> a5_;
    bool hasData6_;
    WithTime<A6, typename StateT::TimePointType> a6_;
    bool hasData7_;
    WithTime<A7, typename StateT::TimePointType> a7_;
    bool hasData8_;
    WithTime<A8, typename StateT::TimePointType> a8_;
    bool hasData9_;
    WithTime<A9, typename StateT::TimePointType> a9_;
    int lastIdx_;
public:
    TimeChecker(FanInParamMask const &requireMask=FanInParamMask()) :
        requireMask_(requireMask), hasData0_(false), a0_(), hasData1_(false), a1_(), hasData2_(false), a2_(), hasData3_(false), a3_(), hasData4_(false), a4_(), hasData5_(false), a5_(), hasData6_(false), a6_(), hasData7_(false), a7_(), hasData8_(false), a8_(), hasData9_(false), a9_(), lastIdx_(-1)
    {}
    inline bool operator()(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> &&data) {
        switch (data.timedData.value.index()) {
        case 0:
            if (StateT::CheckTime) {
                if (hasData0_ && data.timedData.timePoint < a0_.timePoint) {
                    return false;
                }
            }
            hasData0_ = true;
            a0_ = {data.timedData.timePoint, std::move(std::get<0>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 0;
            break;
        case 1:
            if (StateT::CheckTime) {
                if (hasData1_ && data.timedData.timePoint < a1_.timePoint) {
                    return false;
                }
            }
            hasData1_ = true;
            a1_ = {data.timedData.timePoint, std::move(std::get<1>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 1;
            break;
        case 2:
            if (StateT::CheckTime) {
                if (hasData2_ && data.timedData.timePoint < a2_.timePoint) {
                    return false;
                }
            }
            hasData2_ = true;
            a2_ = {data.timedData.timePoint, std::move(std::get<2>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 2;
            break;
        case 3:
            if (StateT::CheckTime) {
                if (hasData3_ && data.timedData.timePoint < a3_.timePoint) {
                    return false;
                }
            }
            hasData3_ = true;
            a3_ = {data.timedData.timePoint, std::move(std::get<3>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 3;
            break;
        case 4:
            if (StateT::CheckTime) {
                if (hasData4_ && data.timedData.timePoint < a4_.timePoint) {
                    return false;
                }
            }
            hasData4_ = true;
            a4_ = {data.timedData.timePoint, std::move(std::get<4>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 4;
            break;
        case 5:
            if (StateT::CheckTime) {
                if (hasData5_ && data.timedData.timePoint < a5_.timePoint) {
                    return false;
                }
            }
            hasData5_ = true;
            a5_ = {data.timedData.timePoint, std::move(std::get<5>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 5;
            break;
        case 6:
            if (StateT::CheckTime) {
                if (hasData6_ && data.timedData.timePoint < a6_.timePoint) {
                    return false;
                }
            }
            hasData6_ = true;
            a6_ = {data.timedData.timePoint, std::move(std::get<6>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 6;
            break;
        case 7:
            if (StateT::CheckTime) {
                if (hasData7_ && data.timedData.timePoint < a7_.timePoint) {
                    return false;
                }
            }
            hasData7_ = true;
            a7_ = {data.timedData.timePoint, std::move(std::get<7>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 7;
            break;
        case 8:
            if (StateT::CheckTime) {
                if (hasData8_ && data.timedData.timePoint < a8_.timePoint) {
                    return false;
                }
            }
            hasData8_ = true;
            a8_ = {data.timedData.timePoint, std::move(std::get<8>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 8;
            break;
        case 9:
            if (StateT::CheckTime) {
                if (hasData9_ && data.timedData.timePoint < a9_.timePoint) {
                    return false;
                }
            }
            hasData9_ = true;
            a9_ = {data.timedData.timePoint, std::move(std::get<9>(data.timedData.value)), data.timedData.finalFlag};
            lastIdx_ = 9;
            break;
        }
        return true;
    }
    inline int lastIdx() const {
        return lastIdx_;
    }
    inline bool good() const {
        return (
            (!requireMask_[0] || hasData0_) && 
            (!requireMask_[1] || hasData1_) && 
            (!requireMask_[2] || hasData2_) && 
            (!requireMask_[3] || hasData3_) && 
            (!requireMask_[4] || hasData4_) && 
            (!requireMask_[5] || hasData5_) && 
            (!requireMask_[6] || hasData6_) && 
            (!requireMask_[7] || hasData7_) && 
            (!requireMask_[8] || hasData8_) && 
            (!requireMask_[9] || hasData9_)
        );
    }
    inline WithTime<A0, typename StateT::TimePointType> const &get0() const {
        return a0_;
    }
    inline WithTime<A1, typename StateT::TimePointType> const &get1() const {
        return a1_;
    }
    inline WithTime<A2, typename StateT::TimePointType> const &get2() const {
        return a2_;
    }
    inline WithTime<A3, typename StateT::TimePointType> const &get3() const {
        return a3_;
    }
    inline WithTime<A4, typename StateT::TimePointType> const &get4() const {
        return a4_;
    }
    inline WithTime<A5, typename StateT::TimePointType> const &get5() const {
        return a5_;
    }
    inline WithTime<A6, typename StateT::TimePointType> const &get6() const {
        return a6_;
    }
    inline WithTime<A7, typename StateT::TimePointType> const &get7() const {
        return a7_;
    }
    inline WithTime<A8, typename StateT::TimePointType> const &get8() const {
        return a8_;
    }
    inline WithTime<A9, typename StateT::TimePointType> const &get9() const {
        return a9_;
    }
};