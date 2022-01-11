template <std::size_t N, std::size_t K>
class ActionAsSink {};
template <>
class ActionAsSink<1, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<A> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink<typename R::template Action<A, B>>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<A> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink<typename R::template Action<A, B>>(action);
    }
};
template <>
class ActionAsSink<2, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_2_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_2_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,B>(action);
    }
};
template <>
class ActionAsSink<2, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_2_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_2_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,B>(action);
    }
};
template <>
class ActionAsSink<3, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_3_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_3_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,B>(action);
    }
};
template <>
class ActionAsSink<3, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_3_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_3_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,B>(action);
    }
};
template <>
class ActionAsSink<3, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_3_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_3_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,B>(action);
    }
};
template <>
class ActionAsSink<4, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_4_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_4_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,B>(action);
    }
};
template <>
class ActionAsSink<4, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_4_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_4_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,B>(action);
    }
};
template <>
class ActionAsSink<4, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_4_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_4_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,B>(action);
    }
};
template <>
class ActionAsSink<4, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_4_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_4_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,B>(action);
    }
};
template <>
class ActionAsSink<5, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_5_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_5_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,B>(action);
    }
};
template <>
class ActionAsSink<5, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_5_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_5_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,B>(action);
    }
};
template <>
class ActionAsSink<5, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_5_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_5_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,B>(action);
    }
};
template <>
class ActionAsSink<5, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_5_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_5_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,B>(action);
    }
};
template <>
class ActionAsSink<5, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_5_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_5_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,B>(action);
    }
};
template <>
class ActionAsSink<6, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(action);
    }
};
template <>
class ActionAsSink<6, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(action);
    }
};
template <>
class ActionAsSink<6, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(action);
    }
};
template <>
class ActionAsSink<6, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(action);
    }
};
template <>
class ActionAsSink<6, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(action);
    }
};
template <>
class ActionAsSink<6, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_6_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,B>(action);
    }
};
template <>
class ActionAsSink<7, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(action);
    }
};
template <>
class ActionAsSink<7, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(action);
    }
};
template <>
class ActionAsSink<7, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(action);
    }
};
template <>
class ActionAsSink<7, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(action);
    }
};
template <>
class ActionAsSink<7, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(action);
    }
};
template <>
class ActionAsSink<7, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(action);
    }
};
template <>
class ActionAsSink<7, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_7_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,B>(action);
    }
};
template <>
class ActionAsSink<8, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(action);
    }
};
template <>
class ActionAsSink<8, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(action);
    }
};
template <>
class ActionAsSink<8, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(action);
    }
};
template <>
class ActionAsSink<8, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(action);
    }
};
template <>
class ActionAsSink<8, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(action);
    }
};
template <>
class ActionAsSink<8, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(action);
    }
};
template <>
class ActionAsSink<8, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(action);
    }
};
template <>
class ActionAsSink<8, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_8_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,B>(action);
    }
};
template <>
class ActionAsSink<9, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(action);
    }
};
template <>
class ActionAsSink<9, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(action);
    }
};
template <>
class ActionAsSink<9, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(action);
    }
};
template <>
class ActionAsSink<9, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(action);
    }
};
template <>
class ActionAsSink<9, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(action);
    }
};
template <>
class ActionAsSink<9, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(action);
    }
};
template <>
class ActionAsSink<9, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(action);
    }
};
template <>
class ActionAsSink<9, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(action);
    }
};
template <>
class ActionAsSink<9, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_9_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,B>(action);
    }
};
template <>
class ActionAsSink<10, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(action);
    }
};
template <>
class ActionAsSink<10, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(action);
    }
};
template <>
class ActionAsSink<10, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(action);
    }
};
template <>
class ActionAsSink<10, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(action);
    }
};
template <>
class ActionAsSink<10, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(action);
    }
};
template <>
class ActionAsSink<10, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(action);
    }
};
template <>
class ActionAsSink<10, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(action);
    }
};
template <>
class ActionAsSink<10, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(action);
    }
};
template <>
class ActionAsSink<10, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(action);
    }
};
template <>
class ActionAsSink<10, 9> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_10_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,B>(action);
    }
};
template <>
class ActionAsSink<11, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(action);
    }
};
template <>
class ActionAsSink<11, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(action);
    }
};
template <>
class ActionAsSink<11, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(action);
    }
};
template <>
class ActionAsSink<11, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(action);
    }
};
template <>
class ActionAsSink<11, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(action);
    }
};
template <>
class ActionAsSink<11, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(action);
    }
};
template <>
class ActionAsSink<11, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(action);
    }
};
template <>
class ActionAsSink<11, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(action);
    }
};
template <>
class ActionAsSink<11, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(action);
    }
};
template <>
class ActionAsSink<11, 9> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(action);
    }
};
template <>
class ActionAsSink<11, 10> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_11_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 9> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 10> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<12, 11> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_12_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 9> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 10> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 11> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<13, 12> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_13_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 9> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 10> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 11> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 12> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<14, 13> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_14_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 9> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 10> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 11> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 12> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 13> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<15, 14> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_15_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 9> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 10> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 11> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 12> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 13> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 14> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<16, 15> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<15,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_15<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<15,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_16_15<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 9> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 10> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 11> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 12> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 13> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 14> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 15> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<15,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_15<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<15,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_15<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<17, 16> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<16,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_16<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<16,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_17_16<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 9> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 10> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 11> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 12> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 13> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 14> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 15> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<15,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_15<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<15,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_15<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 16> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<16,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_16<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<16,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_16<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<18, 17> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<17,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_17<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<17,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_18_17<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 9> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 10> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 11> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 12> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 13> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 14> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 15> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<15,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_15<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<15,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_15<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 16> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<16,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_16<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<16,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_16<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 17> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<17,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_17<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<17,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_17<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<19, 18> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<18,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_18<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<18,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_19_18<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 0> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<0,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_0<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 1> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<1,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_1<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 2> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<2,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_2<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 3> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<3,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_3<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 4> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<4,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_4<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 5> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<5,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_5<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 6> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<6,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_6<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 7> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<7,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_7<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 8> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<8,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_8<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 9> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<9,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_9<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 10> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<10,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_10<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 11> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<11,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_11<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 12> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<12,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_12<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 13> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<13,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_13<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 14> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<14,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_14<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 15> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<15,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_15<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<15,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_15<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 16> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<16,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_16<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<16,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_16<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 17> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<17,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_17<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<17,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_17<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 18> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<18,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_18<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<18,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_18<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};
template <>
class ActionAsSink<20, 19> {
public:
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<19,A>> call(R &r, std::string const &name, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_19<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(name, action);
    }
    template <class R, class A, class B>
    static typename R::template Sink<std::variant_alternative_t<19,A>> call(R &r, typename R::template ActionPtr<A,B> const &action) {
        return r.template actionAsSink_20_19<std::variant_alternative_t<0,A>,std::variant_alternative_t<1,A>,std::variant_alternative_t<2,A>,std::variant_alternative_t<3,A>,std::variant_alternative_t<4,A>,std::variant_alternative_t<5,A>,std::variant_alternative_t<6,A>,std::variant_alternative_t<7,A>,std::variant_alternative_t<8,A>,std::variant_alternative_t<9,A>,std::variant_alternative_t<10,A>,std::variant_alternative_t<11,A>,std::variant_alternative_t<12,A>,std::variant_alternative_t<13,A>,std::variant_alternative_t<14,A>,std::variant_alternative_t<15,A>,std::variant_alternative_t<16,A>,std::variant_alternative_t<17,A>,std::variant_alternative_t<18,A>,std::variant_alternative_t<19,A>,B>(action);
    }
};