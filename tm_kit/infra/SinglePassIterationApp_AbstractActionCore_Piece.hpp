template <class A0, class A1, class B>
class AbstractActionCore<std::variant<A0,A1>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual Provider<B> {
public:
    virtual bool isOneTimeOnly() const = 0;
};
template <class A0, class A1, class A2, class B>
class AbstractActionCore<std::variant<A0,A1,A2>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual Provider<B> {
public:
    virtual bool isOneTimeOnly() const = 0;
};
template <class A0, class A1, class A2, class A3, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual Provider<B> {
public:
    virtual bool isOneTimeOnly() const = 0;
};
template <class A0, class A1, class A2, class A3, class A4, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual Provider<B> {
public:
    virtual bool isOneTimeOnly() const = 0;
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual Provider<B> {
public:
    virtual bool isOneTimeOnly() const = 0;
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual Provider<B> {
public:
    virtual bool isOneTimeOnly() const = 0;
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual Provider<B> {
public:
    virtual bool isOneTimeOnly() const = 0;
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual Provider<B> {
public:
    virtual bool isOneTimeOnly() const = 0;
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual Provider<B> {
public:
    virtual bool isOneTimeOnly() const = 0;
};