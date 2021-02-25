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