template <class A0, class A1, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &f, Source<A0> &&x0, Source<A1> &&x1) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1>,B> const &f, Source<A0> &&x0, Source<A1> &&x1) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(x5.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(x5.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(x5.mSource));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(x6.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(x5.mSource));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(x6.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(x5.mSource));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(x6.mSource));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(x7.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(x5.mSource));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(x6.mSource));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(x7.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(x5.mSource));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(x6.mSource));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(x7.mSource));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(x8.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(x5.mSource));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(x6.mSource));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(x7.mSource));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(x8.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(x5.mSource));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(x6.mSource));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(x7.mSource));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(x8.mSource));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(x9.mSource));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(x.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(x0.mSource));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(x1.mSource));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(x2.mSource));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(x3.mSource));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(x4.mSource));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(x5.mSource));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(x6.mSource));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(x7.mSource));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(x8.mSource));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(x9.mSource));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}