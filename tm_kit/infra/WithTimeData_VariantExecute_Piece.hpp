template <class A0, class A1, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(0, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(1, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(0, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(1, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(0, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(1, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(2, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(0, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(1, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(2, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(0, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(1, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(2, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(3, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(0, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(1, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(2, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(3, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(0, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(1, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(2, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(3, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(4, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(0, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(1, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(2, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(3, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(4, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(0, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(1, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(2, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(3, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(4, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(5, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(0, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(1, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(2, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(3, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(4, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(5, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(0, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(1, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(2, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(3, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(4, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(5, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(6, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(0, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(1, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(2, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(3, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(4, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(5, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(6, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(0, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(1, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(2, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(3, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(4, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(5, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(6, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(7, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(0, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(1, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(2, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(3, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(4, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(5, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(6, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(7, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(0, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(1, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(2, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(3, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(4, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(5, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(6, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(7, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(8, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(0, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(1, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(2, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(3, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(4, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(5, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(6, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(7, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(8, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(0, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(1, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(2, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(3, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(4, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(5, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(6, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(7, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(8, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        connectAndCheck_(9, (void *) f.get(), x.producer);
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(0, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(1, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(2, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(3, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(4, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(5, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(6, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(7, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(8, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        connectAndCheck_(9, (void *) f.get(), x.producer);
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.execute(*f, std::move(x.mSource)), name };
}