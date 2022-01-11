template <class A0, class A1>
void connect_2_0(Source<std::variant<A0,A1>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/2")) {
        return;
    }
    m_.template connect_2_0<A0,A1>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1>
void connectAny_2_0(Source<std::variant<A0,A1>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/2")) {
        return;
    }
    m_.template connectAny_2_0<A0,A1>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1>
void connect_2_1(Source<std::variant<A0,A1>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/2")) {
        return;
    }
    m_.template connect_2_1<A0,A1>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1>
void connectAny_2_1(Source<std::variant<A0,A1>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/2")) {
        return;
    }
    m_.template connectAny_2_1<A0,A1>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2>
void connect_3_0(Source<std::variant<A0,A1,A2>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/3")) {
        return;
    }
    m_.template connect_3_0<A0,A1,A2>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2>
void connectAny_3_0(Source<std::variant<A0,A1,A2>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/3")) {
        return;
    }
    m_.template connectAny_3_0<A0,A1,A2>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2>
void connect_3_1(Source<std::variant<A0,A1,A2>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/3")) {
        return;
    }
    m_.template connect_3_1<A0,A1,A2>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2>
void connectAny_3_1(Source<std::variant<A0,A1,A2>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/3")) {
        return;
    }
    m_.template connectAny_3_1<A0,A1,A2>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2>
void connect_3_2(Source<std::variant<A0,A1,A2>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/3")) {
        return;
    }
    m_.template connect_3_2<A0,A1,A2>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2>
void connectAny_3_2(Source<std::variant<A0,A1,A2>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/3")) {
        return;
    }
    m_.template connectAny_3_2<A0,A1,A2>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connect_4_0(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/4")) {
        return;
    }
    m_.template connect_4_0<A0,A1,A2,A3>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connectAny_4_0(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/4")) {
        return;
    }
    m_.template connectAny_4_0<A0,A1,A2,A3>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connect_4_1(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/4")) {
        return;
    }
    m_.template connect_4_1<A0,A1,A2,A3>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connectAny_4_1(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/4")) {
        return;
    }
    m_.template connectAny_4_1<A0,A1,A2,A3>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connect_4_2(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/4")) {
        return;
    }
    m_.template connect_4_2<A0,A1,A2,A3>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connectAny_4_2(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/4")) {
        return;
    }
    m_.template connectAny_4_2<A0,A1,A2,A3>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connect_4_3(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/4")) {
        return;
    }
    m_.template connect_4_3<A0,A1,A2,A3>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3>
void connectAny_4_3(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/4")) {
        return;
    }
    m_.template connectAny_4_3<A0,A1,A2,A3>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_0(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/5")) {
        return;
    }
    m_.template connect_5_0<A0,A1,A2,A3,A4>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connectAny_5_0(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/5")) {
        return;
    }
    m_.template connectAny_5_0<A0,A1,A2,A3,A4>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_1(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/5")) {
        return;
    }
    m_.template connect_5_1<A0,A1,A2,A3,A4>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connectAny_5_1(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/5")) {
        return;
    }
    m_.template connectAny_5_1<A0,A1,A2,A3,A4>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_2(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/5")) {
        return;
    }
    m_.template connect_5_2<A0,A1,A2,A3,A4>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connectAny_5_2(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/5")) {
        return;
    }
    m_.template connectAny_5_2<A0,A1,A2,A3,A4>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_3(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/5")) {
        return;
    }
    m_.template connect_5_3<A0,A1,A2,A3,A4>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connectAny_5_3(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/5")) {
        return;
    }
    m_.template connectAny_5_3<A0,A1,A2,A3,A4>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_4(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/5")) {
        return;
    }
    m_.template connect_5_4<A0,A1,A2,A3,A4>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4>
void connectAny_5_4(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/5")) {
        return;
    }
    m_.template connectAny_5_4<A0,A1,A2,A3,A4>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_0(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/6")) {
        return;
    }
    m_.template connect_6_0<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_0(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/6")) {
        return;
    }
    m_.template connectAny_6_0<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_1(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/6")) {
        return;
    }
    m_.template connect_6_1<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_1(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/6")) {
        return;
    }
    m_.template connectAny_6_1<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_2(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/6")) {
        return;
    }
    m_.template connect_6_2<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_2(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/6")) {
        return;
    }
    m_.template connectAny_6_2<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_3(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/6")) {
        return;
    }
    m_.template connect_6_3<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_3(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/6")) {
        return;
    }
    m_.template connectAny_6_3<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_4(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/6")) {
        return;
    }
    m_.template connect_6_4<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_4(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/6")) {
        return;
    }
    m_.template connectAny_6_4<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_5(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/6")) {
        return;
    }
    m_.template connect_6_5<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_5(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/6")) {
        return;
    }
    m_.template connectAny_6_5<A0,A1,A2,A3,A4,A5>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/7")) {
        return;
    }
    m_.template connect_7_0<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/7")) {
        return;
    }
    m_.template connectAny_7_0<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/7")) {
        return;
    }
    m_.template connect_7_1<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/7")) {
        return;
    }
    m_.template connectAny_7_1<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/7")) {
        return;
    }
    m_.template connect_7_2<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/7")) {
        return;
    }
    m_.template connectAny_7_2<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/7")) {
        return;
    }
    m_.template connect_7_3<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/7")) {
        return;
    }
    m_.template connectAny_7_3<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/7")) {
        return;
    }
    m_.template connect_7_4<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/7")) {
        return;
    }
    m_.template connectAny_7_4<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/7")) {
        return;
    }
    m_.template connect_7_5<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/7")) {
        return;
    }
    m_.template connectAny_7_5<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/7")) {
        return;
    }
    m_.template connect_7_6<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/7")) {
        return;
    }
    m_.template connectAny_7_6<A0,A1,A2,A3,A4,A5,A6>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/8")) {
        return;
    }
    m_.template connect_8_0<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/8")) {
        return;
    }
    m_.template connectAny_8_0<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/8")) {
        return;
    }
    m_.template connect_8_1<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/8")) {
        return;
    }
    m_.template connectAny_8_1<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/8")) {
        return;
    }
    m_.template connect_8_2<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/8")) {
        return;
    }
    m_.template connectAny_8_2<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/8")) {
        return;
    }
    m_.template connect_8_3<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/8")) {
        return;
    }
    m_.template connectAny_8_3<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/8")) {
        return;
    }
    m_.template connect_8_4<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/8")) {
        return;
    }
    m_.template connectAny_8_4<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/8")) {
        return;
    }
    m_.template connect_8_5<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/8")) {
        return;
    }
    m_.template connectAny_8_5<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/8")) {
        return;
    }
    m_.template connect_8_6<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/8")) {
        return;
    }
    m_.template connectAny_8_6<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/8")) {
        return;
    }
    m_.template connect_8_7<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/8")) {
        return;
    }
    m_.template connectAny_8_7<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/9")) {
        return;
    }
    m_.template connect_9_0<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/9")) {
        return;
    }
    m_.template connectAny_9_0<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/9")) {
        return;
    }
    m_.template connect_9_1<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/9")) {
        return;
    }
    m_.template connectAny_9_1<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/9")) {
        return;
    }
    m_.template connect_9_2<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/9")) {
        return;
    }
    m_.template connectAny_9_2<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/9")) {
        return;
    }
    m_.template connect_9_3<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/9")) {
        return;
    }
    m_.template connectAny_9_3<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/9")) {
        return;
    }
    m_.template connect_9_4<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/9")) {
        return;
    }
    m_.template connectAny_9_4<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/9")) {
        return;
    }
    m_.template connect_9_5<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/9")) {
        return;
    }
    m_.template connectAny_9_5<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/9")) {
        return;
    }
    m_.template connect_9_6<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/9")) {
        return;
    }
    m_.template connectAny_9_6<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/9")) {
        return;
    }
    m_.template connect_9_7<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/9")) {
        return;
    }
    m_.template connectAny_9_7<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/9")) {
        return;
    }
    m_.template connect_9_8<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/9")) {
        return;
    }
    m_.template connectAny_9_8<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/10")) {
        return;
    }
    m_.template connect_10_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/10")) {
        return;
    }
    m_.template connectAny_10_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/10")) {
        return;
    }
    m_.template connect_10_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/10")) {
        return;
    }
    m_.template connectAny_10_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/10")) {
        return;
    }
    m_.template connect_10_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/10")) {
        return;
    }
    m_.template connectAny_10_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/10")) {
        return;
    }
    m_.template connect_10_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/10")) {
        return;
    }
    m_.template connectAny_10_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/10")) {
        return;
    }
    m_.template connect_10_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/10")) {
        return;
    }
    m_.template connectAny_10_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/10")) {
        return;
    }
    m_.template connect_10_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/10")) {
        return;
    }
    m_.template connectAny_10_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/10")) {
        return;
    }
    m_.template connect_10_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/10")) {
        return;
    }
    m_.template connectAny_10_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/10")) {
        return;
    }
    m_.template connect_10_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/10")) {
        return;
    }
    m_.template connectAny_10_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/10")) {
        return;
    }
    m_.template connect_10_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/10")) {
        return;
    }
    m_.template connectAny_10_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/10")) {
        return;
    }
    m_.template connect_10_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/10")) {
        return;
    }
    m_.template connectAny_10_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/11")) {
        return;
    }
    m_.template connect_11_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/11")) {
        return;
    }
    m_.template connectAny_11_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/11")) {
        return;
    }
    m_.template connect_11_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/11")) {
        return;
    }
    m_.template connectAny_11_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/11")) {
        return;
    }
    m_.template connect_11_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/11")) {
        return;
    }
    m_.template connectAny_11_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/11")) {
        return;
    }
    m_.template connect_11_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/11")) {
        return;
    }
    m_.template connectAny_11_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/11")) {
        return;
    }
    m_.template connect_11_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/11")) {
        return;
    }
    m_.template connectAny_11_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/11")) {
        return;
    }
    m_.template connect_11_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/11")) {
        return;
    }
    m_.template connectAny_11_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/11")) {
        return;
    }
    m_.template connect_11_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/11")) {
        return;
    }
    m_.template connectAny_11_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/11")) {
        return;
    }
    m_.template connect_11_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/11")) {
        return;
    }
    m_.template connectAny_11_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/11")) {
        return;
    }
    m_.template connect_11_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/11")) {
        return;
    }
    m_.template connectAny_11_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/11")) {
        return;
    }
    m_.template connect_11_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/11")) {
        return;
    }
    m_.template connectAny_11_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A10> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/11")) {
        return;
    }
    m_.template connect_11_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/11")) {
        return;
    }
    m_.template connectAny_11_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/12")) {
        return;
    }
    m_.template connect_12_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/12")) {
        return;
    }
    m_.template connectAny_12_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/12")) {
        return;
    }
    m_.template connect_12_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/12")) {
        return;
    }
    m_.template connectAny_12_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/12")) {
        return;
    }
    m_.template connect_12_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/12")) {
        return;
    }
    m_.template connectAny_12_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/12")) {
        return;
    }
    m_.template connect_12_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/12")) {
        return;
    }
    m_.template connectAny_12_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/12")) {
        return;
    }
    m_.template connect_12_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/12")) {
        return;
    }
    m_.template connectAny_12_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/12")) {
        return;
    }
    m_.template connect_12_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/12")) {
        return;
    }
    m_.template connectAny_12_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/12")) {
        return;
    }
    m_.template connect_12_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/12")) {
        return;
    }
    m_.template connectAny_12_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/12")) {
        return;
    }
    m_.template connect_12_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/12")) {
        return;
    }
    m_.template connectAny_12_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/12")) {
        return;
    }
    m_.template connect_12_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/12")) {
        return;
    }
    m_.template connectAny_12_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/12")) {
        return;
    }
    m_.template connect_12_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/12")) {
        return;
    }
    m_.template connectAny_12_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A10> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/12")) {
        return;
    }
    m_.template connect_12_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/12")) {
        return;
    }
    m_.template connectAny_12_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A11> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/12")) {
        return;
    }
    m_.template connect_12_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/12")) {
        return;
    }
    m_.template connectAny_12_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/13")) {
        return;
    }
    m_.template connect_13_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/13")) {
        return;
    }
    m_.template connectAny_13_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/13")) {
        return;
    }
    m_.template connect_13_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/13")) {
        return;
    }
    m_.template connectAny_13_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/13")) {
        return;
    }
    m_.template connect_13_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/13")) {
        return;
    }
    m_.template connectAny_13_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/13")) {
        return;
    }
    m_.template connect_13_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/13")) {
        return;
    }
    m_.template connectAny_13_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/13")) {
        return;
    }
    m_.template connect_13_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/13")) {
        return;
    }
    m_.template connectAny_13_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/13")) {
        return;
    }
    m_.template connect_13_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/13")) {
        return;
    }
    m_.template connectAny_13_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/13")) {
        return;
    }
    m_.template connect_13_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/13")) {
        return;
    }
    m_.template connectAny_13_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/13")) {
        return;
    }
    m_.template connect_13_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/13")) {
        return;
    }
    m_.template connectAny_13_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/13")) {
        return;
    }
    m_.template connect_13_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/13")) {
        return;
    }
    m_.template connectAny_13_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/13")) {
        return;
    }
    m_.template connect_13_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/13")) {
        return;
    }
    m_.template connectAny_13_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A10> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/13")) {
        return;
    }
    m_.template connect_13_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/13")) {
        return;
    }
    m_.template connectAny_13_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A11> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/13")) {
        return;
    }
    m_.template connect_13_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/13")) {
        return;
    }
    m_.template connectAny_13_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A12> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/13")) {
        return;
    }
    m_.template connect_13_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/13")) {
        return;
    }
    m_.template connectAny_13_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/14")) {
        return;
    }
    m_.template connect_14_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/14")) {
        return;
    }
    m_.template connectAny_14_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/14")) {
        return;
    }
    m_.template connect_14_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/14")) {
        return;
    }
    m_.template connectAny_14_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/14")) {
        return;
    }
    m_.template connect_14_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/14")) {
        return;
    }
    m_.template connectAny_14_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/14")) {
        return;
    }
    m_.template connect_14_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/14")) {
        return;
    }
    m_.template connectAny_14_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/14")) {
        return;
    }
    m_.template connect_14_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/14")) {
        return;
    }
    m_.template connectAny_14_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/14")) {
        return;
    }
    m_.template connect_14_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/14")) {
        return;
    }
    m_.template connectAny_14_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/14")) {
        return;
    }
    m_.template connect_14_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/14")) {
        return;
    }
    m_.template connectAny_14_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/14")) {
        return;
    }
    m_.template connect_14_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/14")) {
        return;
    }
    m_.template connectAny_14_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/14")) {
        return;
    }
    m_.template connect_14_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/14")) {
        return;
    }
    m_.template connectAny_14_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/14")) {
        return;
    }
    m_.template connect_14_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/14")) {
        return;
    }
    m_.template connectAny_14_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A10> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/14")) {
        return;
    }
    m_.template connect_14_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/14")) {
        return;
    }
    m_.template connectAny_14_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A11> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/14")) {
        return;
    }
    m_.template connect_14_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/14")) {
        return;
    }
    m_.template connectAny_14_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A12> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/14")) {
        return;
    }
    m_.template connect_14_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/14")) {
        return;
    }
    m_.template connectAny_14_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A13> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/14")) {
        return;
    }
    m_.template connect_14_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/14")) {
        return;
    }
    m_.template connectAny_14_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/15")) {
        return;
    }
    m_.template connect_15_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/15")) {
        return;
    }
    m_.template connectAny_15_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/15")) {
        return;
    }
    m_.template connect_15_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/15")) {
        return;
    }
    m_.template connectAny_15_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/15")) {
        return;
    }
    m_.template connect_15_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/15")) {
        return;
    }
    m_.template connectAny_15_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/15")) {
        return;
    }
    m_.template connect_15_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/15")) {
        return;
    }
    m_.template connectAny_15_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/15")) {
        return;
    }
    m_.template connect_15_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/15")) {
        return;
    }
    m_.template connectAny_15_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/15")) {
        return;
    }
    m_.template connect_15_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/15")) {
        return;
    }
    m_.template connectAny_15_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/15")) {
        return;
    }
    m_.template connect_15_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/15")) {
        return;
    }
    m_.template connectAny_15_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/15")) {
        return;
    }
    m_.template connect_15_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/15")) {
        return;
    }
    m_.template connectAny_15_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/15")) {
        return;
    }
    m_.template connect_15_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/15")) {
        return;
    }
    m_.template connectAny_15_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/15")) {
        return;
    }
    m_.template connect_15_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/15")) {
        return;
    }
    m_.template connectAny_15_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A10> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/15")) {
        return;
    }
    m_.template connect_15_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/15")) {
        return;
    }
    m_.template connectAny_15_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A11> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/15")) {
        return;
    }
    m_.template connect_15_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/15")) {
        return;
    }
    m_.template connectAny_15_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A12> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/15")) {
        return;
    }
    m_.template connect_15_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/15")) {
        return;
    }
    m_.template connectAny_15_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A13> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/15")) {
        return;
    }
    m_.template connect_15_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/15")) {
        return;
    }
    m_.template connectAny_15_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A14> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/15")) {
        return;
    }
    m_.template connect_15_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/15")) {
        return;
    }
    m_.template connectAny_15_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/16")) {
        return;
    }
    m_.template connect_16_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/16")) {
        return;
    }
    m_.template connectAny_16_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/16")) {
        return;
    }
    m_.template connect_16_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/16")) {
        return;
    }
    m_.template connectAny_16_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/16")) {
        return;
    }
    m_.template connect_16_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/16")) {
        return;
    }
    m_.template connectAny_16_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/16")) {
        return;
    }
    m_.template connect_16_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/16")) {
        return;
    }
    m_.template connectAny_16_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/16")) {
        return;
    }
    m_.template connect_16_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/16")) {
        return;
    }
    m_.template connectAny_16_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/16")) {
        return;
    }
    m_.template connect_16_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/16")) {
        return;
    }
    m_.template connectAny_16_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/16")) {
        return;
    }
    m_.template connect_16_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/16")) {
        return;
    }
    m_.template connectAny_16_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/16")) {
        return;
    }
    m_.template connect_16_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/16")) {
        return;
    }
    m_.template connectAny_16_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/16")) {
        return;
    }
    m_.template connect_16_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/16")) {
        return;
    }
    m_.template connectAny_16_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/16")) {
        return;
    }
    m_.template connect_16_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/16")) {
        return;
    }
    m_.template connectAny_16_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A10> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/16")) {
        return;
    }
    m_.template connect_16_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/16")) {
        return;
    }
    m_.template connectAny_16_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A11> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/16")) {
        return;
    }
    m_.template connect_16_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/16")) {
        return;
    }
    m_.template connectAny_16_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A12> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/16")) {
        return;
    }
    m_.template connect_16_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/16")) {
        return;
    }
    m_.template connectAny_16_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A13> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/16")) {
        return;
    }
    m_.template connect_16_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/16")) {
        return;
    }
    m_.template connectAny_16_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A14> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/16")) {
        return;
    }
    m_.template connect_16_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/16")) {
        return;
    }
    m_.template connectAny_16_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A15> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "15/16")) {
        return;
    }
    m_.template connect_16_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "15/16")) {
        return;
    }
    m_.template connectAny_16_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/17")) {
        return;
    }
    m_.template connect_17_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/17")) {
        return;
    }
    m_.template connectAny_17_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/17")) {
        return;
    }
    m_.template connect_17_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/17")) {
        return;
    }
    m_.template connectAny_17_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/17")) {
        return;
    }
    m_.template connect_17_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/17")) {
        return;
    }
    m_.template connectAny_17_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/17")) {
        return;
    }
    m_.template connect_17_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/17")) {
        return;
    }
    m_.template connectAny_17_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/17")) {
        return;
    }
    m_.template connect_17_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/17")) {
        return;
    }
    m_.template connectAny_17_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/17")) {
        return;
    }
    m_.template connect_17_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/17")) {
        return;
    }
    m_.template connectAny_17_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/17")) {
        return;
    }
    m_.template connect_17_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/17")) {
        return;
    }
    m_.template connectAny_17_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/17")) {
        return;
    }
    m_.template connect_17_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/17")) {
        return;
    }
    m_.template connectAny_17_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/17")) {
        return;
    }
    m_.template connect_17_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/17")) {
        return;
    }
    m_.template connectAny_17_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/17")) {
        return;
    }
    m_.template connect_17_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/17")) {
        return;
    }
    m_.template connectAny_17_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A10> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/17")) {
        return;
    }
    m_.template connect_17_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/17")) {
        return;
    }
    m_.template connectAny_17_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A11> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/17")) {
        return;
    }
    m_.template connect_17_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/17")) {
        return;
    }
    m_.template connectAny_17_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A12> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/17")) {
        return;
    }
    m_.template connect_17_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/17")) {
        return;
    }
    m_.template connectAny_17_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A13> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/17")) {
        return;
    }
    m_.template connect_17_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/17")) {
        return;
    }
    m_.template connectAny_17_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A14> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/17")) {
        return;
    }
    m_.template connect_17_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/17")) {
        return;
    }
    m_.template connectAny_17_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A15> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "15/17")) {
        return;
    }
    m_.template connect_17_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "15/17")) {
        return;
    }
    m_.template connectAny_17_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A16> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "16/17")) {
        return;
    }
    m_.template connect_17_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "16/17")) {
        return;
    }
    m_.template connectAny_17_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/18")) {
        return;
    }
    m_.template connect_18_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/18")) {
        return;
    }
    m_.template connectAny_18_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/18")) {
        return;
    }
    m_.template connect_18_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/18")) {
        return;
    }
    m_.template connectAny_18_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/18")) {
        return;
    }
    m_.template connect_18_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/18")) {
        return;
    }
    m_.template connectAny_18_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/18")) {
        return;
    }
    m_.template connect_18_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/18")) {
        return;
    }
    m_.template connectAny_18_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/18")) {
        return;
    }
    m_.template connect_18_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/18")) {
        return;
    }
    m_.template connectAny_18_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/18")) {
        return;
    }
    m_.template connect_18_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/18")) {
        return;
    }
    m_.template connectAny_18_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/18")) {
        return;
    }
    m_.template connect_18_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/18")) {
        return;
    }
    m_.template connectAny_18_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/18")) {
        return;
    }
    m_.template connect_18_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/18")) {
        return;
    }
    m_.template connectAny_18_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/18")) {
        return;
    }
    m_.template connect_18_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/18")) {
        return;
    }
    m_.template connectAny_18_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/18")) {
        return;
    }
    m_.template connect_18_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/18")) {
        return;
    }
    m_.template connectAny_18_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A10> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/18")) {
        return;
    }
    m_.template connect_18_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/18")) {
        return;
    }
    m_.template connectAny_18_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A11> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/18")) {
        return;
    }
    m_.template connect_18_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/18")) {
        return;
    }
    m_.template connectAny_18_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A12> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/18")) {
        return;
    }
    m_.template connect_18_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/18")) {
        return;
    }
    m_.template connectAny_18_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A13> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/18")) {
        return;
    }
    m_.template connect_18_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/18")) {
        return;
    }
    m_.template connectAny_18_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A14> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/18")) {
        return;
    }
    m_.template connect_18_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/18")) {
        return;
    }
    m_.template connectAny_18_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A15> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "15/18")) {
        return;
    }
    m_.template connect_18_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "15/18")) {
        return;
    }
    m_.template connectAny_18_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A16> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "16/18")) {
        return;
    }
    m_.template connect_18_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "16/18")) {
        return;
    }
    m_.template connectAny_18_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A17> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "17/18")) {
        return;
    }
    m_.template connect_18_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "17/18")) {
        return;
    }
    m_.template connectAny_18_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/19")) {
        return;
    }
    m_.template connect_19_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/19")) {
        return;
    }
    m_.template connectAny_19_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/19")) {
        return;
    }
    m_.template connect_19_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/19")) {
        return;
    }
    m_.template connectAny_19_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/19")) {
        return;
    }
    m_.template connect_19_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/19")) {
        return;
    }
    m_.template connectAny_19_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/19")) {
        return;
    }
    m_.template connect_19_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/19")) {
        return;
    }
    m_.template connectAny_19_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/19")) {
        return;
    }
    m_.template connect_19_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/19")) {
        return;
    }
    m_.template connectAny_19_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/19")) {
        return;
    }
    m_.template connect_19_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/19")) {
        return;
    }
    m_.template connectAny_19_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/19")) {
        return;
    }
    m_.template connect_19_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/19")) {
        return;
    }
    m_.template connectAny_19_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/19")) {
        return;
    }
    m_.template connect_19_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/19")) {
        return;
    }
    m_.template connectAny_19_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/19")) {
        return;
    }
    m_.template connect_19_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/19")) {
        return;
    }
    m_.template connectAny_19_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/19")) {
        return;
    }
    m_.template connect_19_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/19")) {
        return;
    }
    m_.template connectAny_19_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A10> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/19")) {
        return;
    }
    m_.template connect_19_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/19")) {
        return;
    }
    m_.template connectAny_19_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A11> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/19")) {
        return;
    }
    m_.template connect_19_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/19")) {
        return;
    }
    m_.template connectAny_19_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A12> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/19")) {
        return;
    }
    m_.template connect_19_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/19")) {
        return;
    }
    m_.template connectAny_19_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A13> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/19")) {
        return;
    }
    m_.template connect_19_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/19")) {
        return;
    }
    m_.template connectAny_19_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A14> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/19")) {
        return;
    }
    m_.template connect_19_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/19")) {
        return;
    }
    m_.template connectAny_19_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A15> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "15/19")) {
        return;
    }
    m_.template connect_19_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "15/19")) {
        return;
    }
    m_.template connectAny_19_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A16> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "16/19")) {
        return;
    }
    m_.template connect_19_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "16/19")) {
        return;
    }
    m_.template connectAny_19_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A17> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "17/19")) {
        return;
    }
    m_.template connect_19_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "17/19")) {
        return;
    }
    m_.template connectAny_19_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_18(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A18> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "18/19")) {
        return;
    }
    m_.template connect_19_18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_18(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "18/19")) {
        return;
    }
    m_.template connectAny_19_18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A0> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/20")) {
        return;
    }
    m_.template connect_20_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "0/20")) {
        return;
    }
    m_.template connectAny_20_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A1> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/20")) {
        return;
    }
    m_.template connect_20_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "1/20")) {
        return;
    }
    m_.template connectAny_20_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A2> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/20")) {
        return;
    }
    m_.template connect_20_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "2/20")) {
        return;
    }
    m_.template connectAny_20_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A3> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/20")) {
        return;
    }
    m_.template connect_20_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "3/20")) {
        return;
    }
    m_.template connectAny_20_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A4> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/20")) {
        return;
    }
    m_.template connect_20_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "4/20")) {
        return;
    }
    m_.template connectAny_20_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A5> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/20")) {
        return;
    }
    m_.template connect_20_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "5/20")) {
        return;
    }
    m_.template connectAny_20_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A6> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/20")) {
        return;
    }
    m_.template connect_20_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "6/20")) {
        return;
    }
    m_.template connectAny_20_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A7> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/20")) {
        return;
    }
    m_.template connect_20_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "7/20")) {
        return;
    }
    m_.template connectAny_20_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A8> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/20")) {
        return;
    }
    m_.template connect_20_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "8/20")) {
        return;
    }
    m_.template connectAny_20_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A9> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/20")) {
        return;
    }
    m_.template connect_20_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "9/20")) {
        return;
    }
    m_.template connectAny_20_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A10> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/20")) {
        return;
    }
    m_.template connect_20_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "10/20")) {
        return;
    }
    m_.template connectAny_20_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A11> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/20")) {
        return;
    }
    m_.template connect_20_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "11/20")) {
        return;
    }
    m_.template connectAny_20_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A12> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/20")) {
        return;
    }
    m_.template connect_20_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "12/20")) {
        return;
    }
    m_.template connectAny_20_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A13> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/20")) {
        return;
    }
    m_.template connect_20_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "13/20")) {
        return;
    }
    m_.template connectAny_20_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A14> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/20")) {
        return;
    }
    m_.template connect_20_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "14/20")) {
        return;
    }
    m_.template connectAny_20_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A15> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "15/20")) {
        return;
    }
    m_.template connect_20_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "15/20")) {
        return;
    }
    m_.template connectAny_20_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A16> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "16/20")) {
        return;
    }
    m_.template connect_20_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "16/20")) {
        return;
    }
    m_.template connectAny_20_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A17> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "17/20")) {
        return;
    }
    m_.template connect_20_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "17/20")) {
        return;
    }
    m_.template connectAny_20_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_18(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A18> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "18/20")) {
        return;
    }
    m_.template connect_20_18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_18(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "18/20")) {
        return;
    }
    m_.template connectAny_20_18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_19(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A19> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "19/20")) {
        return;
    }
    m_.template connect_20_19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_19(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    std::lock_guard<std::recursive_mutex> _(mutex_);
    auto iter = reverseLookup_.find(sink.consumer);
    if (iter == reverseLookup_.end()) {
        throw AppRunnerException(
            "No such sink '"+sink.consumer+"'"
        );
    }
    if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput, "19/20")) {
        return;
    }
    m_.template connectAny_20_19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::move(source.mSource), sink.mSink);
};