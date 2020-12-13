template <class A0, class A1>
void connect_2_0(Source<std::variant<A0,A1>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/2")) {
        return;
    }
    m_.connect_2_0(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1>
void connect_2_1(Source<std::variant<A0,A1>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/2")) {
        return;
    }
    m_.connect_2_1(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2>
void connect_3_0(Source<std::variant<A0,A1,A2>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/3")) {
        return;
    }
    m_.connect_3_0(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2>
void connect_3_1(Source<std::variant<A0,A1,A2>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/3")) {
        return;
    }
    m_.connect_3_1(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2>
void connect_3_2(Source<std::variant<A0,A1,A2>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/3")) {
        return;
    }
    m_.connect_3_2(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connect_4_0(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/4")) {
        return;
    }
    m_.connect_4_0(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connect_4_1(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/4")) {
        return;
    }
    m_.connect_4_1(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connect_4_2(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/4")) {
        return;
    }
    m_.connect_4_2(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connect_4_3(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/4")) {
        return;
    }
    m_.connect_4_3(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_0(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/5")) {
        return;
    }
    m_.connect_5_0(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_1(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/5")) {
        return;
    }
    m_.connect_5_1(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_2(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/5")) {
        return;
    }
    m_.connect_5_2(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_3(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/5")) {
        return;
    }
    m_.connect_5_3(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_4(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/5")) {
        return;
    }
    m_.connect_5_4(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_0(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/6")) {
        return;
    }
    m_.connect_6_0(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_1(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/6")) {
        return;
    }
    m_.connect_6_1(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_2(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/6")) {
        return;
    }
    m_.connect_6_2(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_3(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/6")) {
        return;
    }
    m_.connect_6_3(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_4(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/6")) {
        return;
    }
    m_.connect_6_4(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_5(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/6")) {
        return;
    }
    m_.connect_6_5(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/7")) {
        return;
    }
    m_.connect_7_0(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/7")) {
        return;
    }
    m_.connect_7_1(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/7")) {
        return;
    }
    m_.connect_7_2(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/7")) {
        return;
    }
    m_.connect_7_3(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/7")) {
        return;
    }
    m_.connect_7_4(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/7")) {
        return;
    }
    m_.connect_7_5(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/7")) {
        return;
    }
    m_.connect_7_6(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/8")) {
        return;
    }
    m_.connect_8_0(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/8")) {
        return;
    }
    m_.connect_8_1(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/8")) {
        return;
    }
    m_.connect_8_2(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/8")) {
        return;
    }
    m_.connect_8_3(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/8")) {
        return;
    }
    m_.connect_8_4(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/8")) {
        return;
    }
    m_.connect_8_5(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/8")) {
        return;
    }
    m_.connect_8_6(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/8")) {
        return;
    }
    m_.connect_8_7(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/9")) {
        return;
    }
    m_.connect_9_0(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/9")) {
        return;
    }
    m_.connect_9_1(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/9")) {
        return;
    }
    m_.connect_9_2(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/9")) {
        return;
    }
    m_.connect_9_3(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/9")) {
        return;
    }
    m_.connect_9_4(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/9")) {
        return;
    }
    m_.connect_9_5(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/9")) {
        return;
    }
    m_.connect_9_6(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/9")) {
        return;
    }
    m_.connect_9_7(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/9")) {
        return;
    }
    m_.connect_9_8(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/10")) {
        return;
    }
    m_.connect_10_0(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/10")) {
        return;
    }
    m_.connect_10_1(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/10")) {
        return;
    }
    m_.connect_10_2(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/10")) {
        return;
    }
    m_.connect_10_3(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/10")) {
        return;
    }
    m_.connect_10_4(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/10")) {
        return;
    }
    m_.connect_10_5(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/10")) {
        return;
    }
    m_.connect_10_6(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/10")) {
        return;
    }
    m_.connect_10_7(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/10")) {
        return;
    }
    m_.connect_10_8(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/10")) {
        return;
    }
    m_.connect_10_9(std::move(source.mSource), sink.mSink);
};