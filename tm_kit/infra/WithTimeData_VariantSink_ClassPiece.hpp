template <std::size_t N, std::size_t K>
class ActionAsSink {};
template <>
class ActionAsSink<1, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<A> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink<A, B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<A> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink<A, B>(action);
    }
};
template <>
class ActionAsSink<2, 0> {
public:
    template <class R, class A0, class A1, class B>
    static typename R::template Sink<A0> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1>,B> const &action) {
        return r.template actionAsSink_2_0<A0,A1,B>(name, action);
    }
    template <class R, class A0, class A1, class B>
    static typename R::template Sink<A0> call(R &r, typename R::template ActionPtr<std::variant<A0,A1>,B> const &action) {
        return r.template actionAsSink_2_0<A0,A1,B>(action);
    }
};
template <>
class ActionAsSink<2, 1> {
public:
    template <class R, class A0, class A1, class B>
    static typename R::template Sink<A1> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1>,B> const &action) {
        return r.template actionAsSink_2_1<A0,A1,B>(name, action);
    }
    template <class R, class A0, class A1, class B>
    static typename R::template Sink<A1> call(R &r, typename R::template ActionPtr<std::variant<A0,A1>,B> const &action) {
        return r.template actionAsSink_2_1<A0,A1,B>(action);
    }
};
template <>
class ActionAsSink<3, 0> {
public:
    template <class R, class A0, class A1, class A2, class B>
    static typename R::template Sink<A0> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
        return r.template actionAsSink_3_0<A0,A1,A2,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class B>
    static typename R::template Sink<A0> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
        return r.template actionAsSink_3_0<A0,A1,A2,B>(action);
    }
};
template <>
class ActionAsSink<3, 1> {
public:
    template <class R, class A0, class A1, class A2, class B>
    static typename R::template Sink<A1> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
        return r.template actionAsSink_3_1<A0,A1,A2,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class B>
    static typename R::template Sink<A1> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
        return r.template actionAsSink_3_1<A0,A1,A2,B>(action);
    }
};
template <>
class ActionAsSink<3, 2> {
public:
    template <class R, class A0, class A1, class A2, class B>
    static typename R::template Sink<A2> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
        return r.template actionAsSink_3_2<A0,A1,A2,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class B>
    static typename R::template Sink<A2> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
        return r.template actionAsSink_3_2<A0,A1,A2,B>(action);
    }
};
template <>
class ActionAsSink<4, 0> {
public:
    template <class R, class A0, class A1, class A2, class A3, class B>
    static typename R::template Sink<A0> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
        return r.template actionAsSink_4_0<A0,A1,A2,A3,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class B>
    static typename R::template Sink<A0> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
        return r.template actionAsSink_4_0<A0,A1,A2,A3,B>(action);
    }
};
template <>
class ActionAsSink<4, 1> {
public:
    template <class R, class A0, class A1, class A2, class A3, class B>
    static typename R::template Sink<A1> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
        return r.template actionAsSink_4_1<A0,A1,A2,A3,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class B>
    static typename R::template Sink<A1> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
        return r.template actionAsSink_4_1<A0,A1,A2,A3,B>(action);
    }
};
template <>
class ActionAsSink<4, 2> {
public:
    template <class R, class A0, class A1, class A2, class A3, class B>
    static typename R::template Sink<A2> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
        return r.template actionAsSink_4_2<A0,A1,A2,A3,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class B>
    static typename R::template Sink<A2> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
        return r.template actionAsSink_4_2<A0,A1,A2,A3,B>(action);
    }
};
template <>
class ActionAsSink<4, 3> {
public:
    template <class R, class A0, class A1, class A2, class A3, class B>
    static typename R::template Sink<A3> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
        return r.template actionAsSink_4_3<A0,A1,A2,A3,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class B>
    static typename R::template Sink<A3> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
        return r.template actionAsSink_4_3<A0,A1,A2,A3,B>(action);
    }
};
template <>
class ActionAsSink<5, 0> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class B>
    static typename R::template Sink<A0> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
        return r.template actionAsSink_5_0<A0,A1,A2,A3,A4,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class B>
    static typename R::template Sink<A0> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
        return r.template actionAsSink_5_0<A0,A1,A2,A3,A4,B>(action);
    }
};
template <>
class ActionAsSink<5, 1> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class B>
    static typename R::template Sink<A1> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
        return r.template actionAsSink_5_1<A0,A1,A2,A3,A4,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class B>
    static typename R::template Sink<A1> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
        return r.template actionAsSink_5_1<A0,A1,A2,A3,A4,B>(action);
    }
};
template <>
class ActionAsSink<5, 2> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class B>
    static typename R::template Sink<A2> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
        return r.template actionAsSink_5_2<A0,A1,A2,A3,A4,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class B>
    static typename R::template Sink<A2> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
        return r.template actionAsSink_5_2<A0,A1,A2,A3,A4,B>(action);
    }
};
template <>
class ActionAsSink<5, 3> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class B>
    static typename R::template Sink<A3> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
        return r.template actionAsSink_5_3<A0,A1,A2,A3,A4,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class B>
    static typename R::template Sink<A3> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
        return r.template actionAsSink_5_3<A0,A1,A2,A3,A4,B>(action);
    }
};
template <>
class ActionAsSink<5, 4> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class B>
    static typename R::template Sink<A4> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
        return r.template actionAsSink_5_4<A0,A1,A2,A3,A4,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class B>
    static typename R::template Sink<A4> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
        return r.template actionAsSink_5_4<A0,A1,A2,A3,A4,B>(action);
    }
};
template <>
class ActionAsSink<6, 0> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A0> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_0<A0,A1,A2,A3,A4,A5,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A0> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_0<A0,A1,A2,A3,A4,A5,B>(action);
    }
};
template <>
class ActionAsSink<6, 1> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A1> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_1<A0,A1,A2,A3,A4,A5,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A1> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_1<A0,A1,A2,A3,A4,A5,B>(action);
    }
};
template <>
class ActionAsSink<6, 2> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A2> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_2<A0,A1,A2,A3,A4,A5,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A2> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_2<A0,A1,A2,A3,A4,A5,B>(action);
    }
};
template <>
class ActionAsSink<6, 3> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A3> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_3<A0,A1,A2,A3,A4,A5,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A3> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_3<A0,A1,A2,A3,A4,A5,B>(action);
    }
};
template <>
class ActionAsSink<6, 4> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A4> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_4<A0,A1,A2,A3,A4,A5,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A4> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_4<A0,A1,A2,A3,A4,A5,B>(action);
    }
};
template <>
class ActionAsSink<6, 5> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A5> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_5<A0,A1,A2,A3,A4,A5,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class B>
    static typename R::template Sink<A5> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
        return r.template actionAsSink_6_5<A0,A1,A2,A3,A4,A5,B>(action);
    }
};
template <>
class ActionAsSink<7, 0> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A0> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_0<A0,A1,A2,A3,A4,A5,A6,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A0> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_0<A0,A1,A2,A3,A4,A5,A6,B>(action);
    }
};
template <>
class ActionAsSink<7, 1> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A1> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_1<A0,A1,A2,A3,A4,A5,A6,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A1> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_1<A0,A1,A2,A3,A4,A5,A6,B>(action);
    }
};
template <>
class ActionAsSink<7, 2> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A2> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_2<A0,A1,A2,A3,A4,A5,A6,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A2> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_2<A0,A1,A2,A3,A4,A5,A6,B>(action);
    }
};
template <>
class ActionAsSink<7, 3> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A3> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_3<A0,A1,A2,A3,A4,A5,A6,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A3> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_3<A0,A1,A2,A3,A4,A5,A6,B>(action);
    }
};
template <>
class ActionAsSink<7, 4> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A4> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_4<A0,A1,A2,A3,A4,A5,A6,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A4> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_4<A0,A1,A2,A3,A4,A5,A6,B>(action);
    }
};
template <>
class ActionAsSink<7, 5> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A5> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_5<A0,A1,A2,A3,A4,A5,A6,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A5> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_5<A0,A1,A2,A3,A4,A5,A6,B>(action);
    }
};
template <>
class ActionAsSink<7, 6> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A6> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_6<A0,A1,A2,A3,A4,A5,A6,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
    static typename R::template Sink<A6> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
        return r.template actionAsSink_7_6<A0,A1,A2,A3,A4,A5,A6,B>(action);
    }
};
template <>
class ActionAsSink<8, 0> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A0> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_0<A0,A1,A2,A3,A4,A5,A6,A7,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A0> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_0<A0,A1,A2,A3,A4,A5,A6,A7,B>(action);
    }
};
template <>
class ActionAsSink<8, 1> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A1> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_1<A0,A1,A2,A3,A4,A5,A6,A7,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A1> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_1<A0,A1,A2,A3,A4,A5,A6,A7,B>(action);
    }
};
template <>
class ActionAsSink<8, 2> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A2> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_2<A0,A1,A2,A3,A4,A5,A6,A7,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A2> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_2<A0,A1,A2,A3,A4,A5,A6,A7,B>(action);
    }
};
template <>
class ActionAsSink<8, 3> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A3> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_3<A0,A1,A2,A3,A4,A5,A6,A7,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A3> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_3<A0,A1,A2,A3,A4,A5,A6,A7,B>(action);
    }
};
template <>
class ActionAsSink<8, 4> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A4> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_4<A0,A1,A2,A3,A4,A5,A6,A7,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A4> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_4<A0,A1,A2,A3,A4,A5,A6,A7,B>(action);
    }
};
template <>
class ActionAsSink<8, 5> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A5> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_5<A0,A1,A2,A3,A4,A5,A6,A7,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A5> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_5<A0,A1,A2,A3,A4,A5,A6,A7,B>(action);
    }
};
template <>
class ActionAsSink<8, 6> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A6> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_6<A0,A1,A2,A3,A4,A5,A6,A7,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A6> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_6<A0,A1,A2,A3,A4,A5,A6,A7,B>(action);
    }
};
template <>
class ActionAsSink<8, 7> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A7> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_7<A0,A1,A2,A3,A4,A5,A6,A7,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
    static typename R::template Sink<A7> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
        return r.template actionAsSink_8_7<A0,A1,A2,A3,A4,A5,A6,A7,B>(action);
    }
};
template <>
class ActionAsSink<9, 0> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A0> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A0> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(action);
    }
};
template <>
class ActionAsSink<9, 1> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A1> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A1> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(action);
    }
};
template <>
class ActionAsSink<9, 2> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A2> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A2> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(action);
    }
};
template <>
class ActionAsSink<9, 3> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A3> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A3> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(action);
    }
};
template <>
class ActionAsSink<9, 4> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A4> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A4> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(action);
    }
};
template <>
class ActionAsSink<9, 5> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A5> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A5> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(action);
    }
};
template <>
class ActionAsSink<9, 6> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A6> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A6> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(action);
    }
};
template <>
class ActionAsSink<9, 7> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A7> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A7> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(action);
    }
};
template <>
class ActionAsSink<9, 8> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A8> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
    static typename R::template Sink<A8> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
        return r.template actionAsSink_9_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(action);
    }
};
template <>
class ActionAsSink<10, 0> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A0> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A0> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(action);
    }
};
template <>
class ActionAsSink<10, 1> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A1> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A1> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(action);
    }
};
template <>
class ActionAsSink<10, 2> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A2> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A2> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(action);
    }
};
template <>
class ActionAsSink<10, 3> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A3> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A3> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(action);
    }
};
template <>
class ActionAsSink<10, 4> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A4> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A4> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(action);
    }
};
template <>
class ActionAsSink<10, 5> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A5> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A5> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(action);
    }
};
template <>
class ActionAsSink<10, 6> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A6> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A6> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(action);
    }
};
template <>
class ActionAsSink<10, 7> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A7> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A7> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(action);
    }
};
template <>
class ActionAsSink<10, 8> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A8> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A8> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(action);
    }
};
template <>
class ActionAsSink<10, 9> {
public:
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A9> call(R &r, std::string const &name, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(name, action);
    }
    template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
    static typename R::template Sink<A9> call(R &r, typename R::template ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
        return r.template actionAsSink_10_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(action);
    }
};