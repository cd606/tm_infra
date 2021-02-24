template <std::size_t N, std::size_t K>
class Connect {};
template <>
class Connect<1, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<T> const &sink) {
        r.template connect<T>(std::move(source), sink);
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
class Connect<2, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_2_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>>(std::move(source), sink);
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
class Connect<3, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_3_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>>(std::move(source), sink);
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
class Connect<4, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_4_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>>(std::move(source), sink);
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
class Connect<4, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_4_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>>(std::move(source), sink);
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
class Connect<5, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_5_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
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
class Connect<5, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_5_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
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
class Connect<5, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_5_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>>(std::move(source), sink);
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
class Connect<6, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_6_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
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
class Connect<6, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_6_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
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
class Connect<6, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_6_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>>(std::move(source), sink);
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
class Connect<7, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_7_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
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
class Connect<7, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_7_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
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
class Connect<7, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_7_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>>(std::move(source), sink);
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
class Connect<8, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_8_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
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
class Connect<8, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_8_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
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
class Connect<8, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_8_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
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
class Connect<8, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_8_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>>(std::move(source), sink);
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
class Connect<9, 0> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<0, T>> const &sink) {
        return r.template connect_9_0<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
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
class Connect<9, 2> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<2, T>> const &sink) {
        return r.template connect_9_2<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
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
class Connect<9, 4> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<4, T>> const &sink) {
        return r.template connect_9_4<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
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
class Connect<9, 6> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<6, T>> const &sink) {
        return r.template connect_9_6<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
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
class Connect<9, 8> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<8, T>> const &sink) {
        return r.template connect_9_8<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>>(std::move(source), sink);
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
class Connect<10, 1> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<1, T>> const &sink) {
        return r.template connect_10_1<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
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
class Connect<10, 3> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<3, T>> const &sink) {
        return r.template connect_10_3<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
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
class Connect<10, 5> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<5, T>> const &sink) {
        return r.template connect_10_5<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
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
class Connect<10, 7> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<7, T>> const &sink) {
        return r.template connect_10_7<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
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
class Connect<10, 9> {
public:
    template <class R, class T>
    static void call(R &r, typename R::template Source<T> &&source, typename R::template Sink<std::variant_alternative_t<9, T>> const &sink) {
        return r.template connect_10_9<std::variant_alternative_t<0,T>,std::variant_alternative_t<1,T>,std::variant_alternative_t<2,T>,std::variant_alternative_t<3,T>,std::variant_alternative_t<4,T>,std::variant_alternative_t<5,T>,std::variant_alternative_t<6,T>,std::variant_alternative_t<7,T>,std::variant_alternative_t<8,T>,std::variant_alternative_t<9,T>>(std::move(source), sink);
    }
};