template <std::size_t N, std::size_t K>
class Connect {};
template <std::size_t N, std::size_t K>
class ConnectAny {};
template <>
class Connect<1, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<T> const &sink) {
        r.template connect<T>(std::move(source), sink);
    }
};
template <>
class ConnectAny<1, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        r.template connectAny<T>(std::move(source), sink);
    }
};
template <>
class Connect<2, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_2_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<2, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_2_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>>(std::move(source), sink);
    }
};
template <>
class Connect<2, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_2_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<2, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_2_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>>(std::move(source), sink);
    }
};
template <>
class Connect<3, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_3_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<3, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_3_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>>(std::move(source), sink);
    }
};
template <>
class Connect<3, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_3_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<3, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_3_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>>(std::move(source), sink);
    }
};
template <>
class Connect<3, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_3_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<3, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_3_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>>(std::move(source), sink);
    }
};
template <>
class Connect<4, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_4_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<4, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_4_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>>(std::move(source), sink);
    }
};
template <>
class Connect<4, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_4_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<4, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_4_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>>(std::move(source), sink);
    }
};
template <>
class Connect<4, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_4_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<4, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_4_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>>(std::move(source), sink);
    }
};
template <>
class Connect<4, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_4_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<4, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_4_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>>(std::move(source), sink);
    }
};
template <>
class Connect<5, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_5_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<5, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_5_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
    }
};
template <>
class Connect<5, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_5_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<5, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_5_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
    }
};
template <>
class Connect<5, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_5_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<5, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_5_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
    }
};
template <>
class Connect<5, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_5_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<5, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_5_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
    }
};
template <>
class Connect<5, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_5_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<5, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_5_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
    }
};
template <>
class Connect<6, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_6_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<6, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_6_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class Connect<6, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_6_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<6, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_6_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class Connect<6, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_6_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<6, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_6_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class Connect<6, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_6_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<6, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_6_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class Connect<6, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_6_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<6, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_6_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class Connect<6, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_6_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<6, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_6_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
    }
};
template <>
class Connect<7, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_7_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<7, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_7_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class Connect<7, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_7_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<7, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_7_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class Connect<7, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_7_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<7, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_7_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class Connect<7, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_7_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<7, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_7_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class Connect<7, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_7_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<7, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_7_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class Connect<7, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_7_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<7, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_7_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class Connect<7, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_7_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<7, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_7_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
    }
};
template <>
class Connect<8, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_8_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<8, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_8_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class Connect<8, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_8_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<8, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_8_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class Connect<8, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_8_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<8, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_8_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class Connect<8, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_8_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<8, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_8_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class Connect<8, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_8_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<8, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_8_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class Connect<8, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_8_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<8, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_8_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class Connect<8, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_8_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<8, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_8_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class Connect<8, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_8_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<8, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_8_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
    }
};
template <>
class Connect<9, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_9_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<9, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_9_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class Connect<9, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_9_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<9, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_9_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class Connect<9, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_9_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<9, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_9_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class Connect<9, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_9_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<9, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_9_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class Connect<9, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_9_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<9, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_9_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class Connect<9, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_9_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<9, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_9_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class Connect<9, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_9_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<9, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_9_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class Connect<9, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_9_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<9, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_9_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class Connect<9, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_9_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<9, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_9_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
    }
};
template <>
class Connect<10, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_10_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<10, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_10_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class Connect<10, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_10_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<10, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_10_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class Connect<10, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_10_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<10, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_10_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class Connect<10, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_10_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<10, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_10_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class Connect<10, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_10_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<10, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_10_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class Connect<10, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_10_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<10, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_10_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class Connect<10, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_10_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<10, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_10_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class Connect<10, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_10_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<10, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_10_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class Connect<10, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_10_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<10, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_10_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class Connect<10, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_10_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<10, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_10_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};
template <>
class Connect<11, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_11_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<11, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_11_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class Connect<11, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_11_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<11, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_11_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class Connect<11, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_11_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<11, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_11_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class Connect<11, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_11_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<11, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_11_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class Connect<11, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_11_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<11, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_11_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class Connect<11, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_11_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<11, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_11_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class Connect<11, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_11_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<11, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_11_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class Connect<11, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_11_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<11, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_11_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class Connect<11, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_11_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<11, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_11_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class Connect<11, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_11_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<11, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_11_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class Connect<11, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<10, T>> const &sink) {
        return r.template connect_11_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<11, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_11_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_12_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_12_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_12_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_12_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_12_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_12_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_12_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_12_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_12_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_12_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<10, T>> const &sink) {
        return r.template connect_12_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<12, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<11, T>> const &sink) {
        return r.template connect_12_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<12, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_12_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_13_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_13_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_13_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_13_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_13_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_13_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_13_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_13_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_13_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_13_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<10, T>> const &sink) {
        return r.template connect_13_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<11, T>> const &sink) {
        return r.template connect_13_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<13, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<12, T>> const &sink) {
        return r.template connect_13_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<13, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_13_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_14_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_14_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_14_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_14_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_14_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_14_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_14_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_14_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_14_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_14_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<10, T>> const &sink) {
        return r.template connect_14_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<11, T>> const &sink) {
        return r.template connect_14_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<12, T>> const &sink) {
        return r.template connect_14_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<14, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<13, T>> const &sink) {
        return r.template connect_14_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<14, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_14_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_15_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_15_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_15_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_15_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_15_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_15_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_15_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_15_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_15_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_15_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<10, T>> const &sink) {
        return r.template connect_15_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<11, T>> const &sink) {
        return r.template connect_15_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<12, T>> const &sink) {
        return r.template connect_15_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<13, T>> const &sink) {
        return r.template connect_15_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<15, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<14, T>> const &sink) {
        return r.template connect_15_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<15, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_15_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_16_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_16_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_16_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_16_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_16_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_16_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_16_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_16_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_16_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_16_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<10, T>> const &sink) {
        return r.template connect_16_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<11, T>> const &sink) {
        return r.template connect_16_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<12, T>> const &sink) {
        return r.template connect_16_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<13, T>> const &sink) {
        return r.template connect_16_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<14, T>> const &sink) {
        return r.template connect_16_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<16, 15> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<15, T>> const &sink) {
        return r.template connect_16_15<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<16, 15> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_16_15<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_17_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_17_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_17_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_17_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_17_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_17_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_17_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_17_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_17_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_17_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<10, T>> const &sink) {
        return r.template connect_17_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<11, T>> const &sink) {
        return r.template connect_17_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<12, T>> const &sink) {
        return r.template connect_17_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<13, T>> const &sink) {
        return r.template connect_17_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<14, T>> const &sink) {
        return r.template connect_17_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 15> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<15, T>> const &sink) {
        return r.template connect_17_15<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 15> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_15<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<17, 16> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<16, T>> const &sink) {
        return r.template connect_17_16<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<17, 16> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_17_16<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_18_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_18_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_18_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_18_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_18_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_18_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_18_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_18_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_18_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_18_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<10, T>> const &sink) {
        return r.template connect_18_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<11, T>> const &sink) {
        return r.template connect_18_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<12, T>> const &sink) {
        return r.template connect_18_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<13, T>> const &sink) {
        return r.template connect_18_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<14, T>> const &sink) {
        return r.template connect_18_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 15> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<15, T>> const &sink) {
        return r.template connect_18_15<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 15> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_15<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 16> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<16, T>> const &sink) {
        return r.template connect_18_16<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 16> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_16<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<18, 17> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<17, T>> const &sink) {
        return r.template connect_18_17<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<18, 17> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_18_17<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_19_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_19_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_19_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_19_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_19_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_19_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_19_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_19_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_19_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_19_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<10, T>> const &sink) {
        return r.template connect_19_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<11, T>> const &sink) {
        return r.template connect_19_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<12, T>> const &sink) {
        return r.template connect_19_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<13, T>> const &sink) {
        return r.template connect_19_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<14, T>> const &sink) {
        return r.template connect_19_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 15> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<15, T>> const &sink) {
        return r.template connect_19_15<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 15> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_15<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 16> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<16, T>> const &sink) {
        return r.template connect_19_16<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 16> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_16<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 17> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<17, T>> const &sink) {
        return r.template connect_19_17<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 17> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_17<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<19, 18> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<18, T>> const &sink) {
        return r.template connect_19_18<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<19, 18> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_19_18<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_20_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_20_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_20_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_20_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_20_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_20_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_20_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_20_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_20_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_20_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<10, T>> const &sink) {
        return r.template connect_20_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 10> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_10<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<11, T>> const &sink) {
        return r.template connect_20_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 11> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_11<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<12, T>> const &sink) {
        return r.template connect_20_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 12> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_12<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<13, T>> const &sink) {
        return r.template connect_20_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 13> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_13<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<14, T>> const &sink) {
        return r.template connect_20_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 14> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_14<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 15> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<15, T>> const &sink) {
        return r.template connect_20_15<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 15> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_15<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 16> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<16, T>> const &sink) {
        return r.template connect_20_16<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 16> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_16<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 17> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<17, T>> const &sink) {
        return r.template connect_20_17<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 17> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_17<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 18> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<18, T>> const &sink) {
        return r.template connect_20_18<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 18> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_18<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class Connect<20, 19> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<19, T>> const &sink) {
        return r.template connect_20_19<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};
template <>
class ConnectAny<20, 19> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::any> const &sink) {
        return r.template connectAny_20_19<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>,std::variant_alternative_t<10,T>,std::variant_alternative_t<11,T>,std::variant_alternative_t<12,T>,std::variant_alternative_t<13,T>,std::variant_alternative_t<14,T>,std::variant_alternative_t<15,T>,std::variant_alternative_t<16,T>,std::variant_alternative_t<17,T>,std::variant_alternative_t<18,T>,std::variant_alternative_t<19,T>>(std::move(source), sink);
    }
};