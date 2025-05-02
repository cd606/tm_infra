template <class A0, class A1, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &f, Source<A0> &&x0, Source<A1> &&x1) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1>,B> const &f, Source<A0> &&x0, Source<A1> &&x1) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A10> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A10> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A10> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A11> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A10> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A11> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A10> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A11> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A12> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A10> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A11> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A12> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A10> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A11> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A12> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A13> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A10> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A11> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A12> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A13> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A10> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A11> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A12> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A13> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A14> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A10> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A11> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A12> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A13> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A14> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A10> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A11> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A12> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A13> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A14> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A15> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(15, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14, Source<A15> &&x15) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
        if (connectAndCheck_(15, (void *) f.get(), x15.producer, 0, x15.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x15).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A10> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A11> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A12> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A13> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A14> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A15> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(15, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14, Source<A15> &&x15) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
        if (connectAndCheck_(15, (void *) f.get(), x15.producer, 0, x15.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x15).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A10> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A11> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A12> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A13> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A14> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A15> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(15, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A16> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(16, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14, Source<A15> &&x15, Source<A16> &&x16) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
        if (connectAndCheck_(15, (void *) f.get(), x15.producer, 0, x15.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x15).theSource()));
        }
        if (connectAndCheck_(16, (void *) f.get(), x16.producer, 0, x16.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x16).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A10> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A11> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A12> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A13> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A14> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A15> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(15, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A16> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(16, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14, Source<A15> &&x15, Source<A16> &&x16) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
        if (connectAndCheck_(15, (void *) f.get(), x15.producer, 0, x15.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x15).theSource()));
        }
        if (connectAndCheck_(16, (void *) f.get(), x16.producer, 0, x16.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x16).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A10> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A11> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A12> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A13> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A14> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A15> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(15, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A16> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(16, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A17> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(17, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14, Source<A15> &&x15, Source<A16> &&x16, Source<A17> &&x17) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
        if (connectAndCheck_(15, (void *) f.get(), x15.producer, 0, x15.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x15).theSource()));
        }
        if (connectAndCheck_(16, (void *) f.get(), x16.producer, 0, x16.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x16).theSource()));
        }
        if (connectAndCheck_(17, (void *) f.get(), x17.producer, 0, x17.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x17).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A10> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A11> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A12> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A13> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A14> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A15> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(15, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A16> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(16, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A17> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(17, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14, Source<A15> &&x15, Source<A16> &&x16, Source<A17> &&x17) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
        if (connectAndCheck_(15, (void *) f.get(), x15.producer, 0, x15.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x15).theSource()));
        }
        if (connectAndCheck_(16, (void *) f.get(), x16.producer, 0, x16.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x16).theSource()));
        }
        if (connectAndCheck_(17, (void *) f.get(), x17.producer, 0, x17.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x17).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A10> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A11> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A12> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A13> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A14> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A15> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(15, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A16> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(16, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A17> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(17, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A18> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(18, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14, Source<A15> &&x15, Source<A16> &&x16, Source<A17> &&x17, Source<A18> &&x18) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
        if (connectAndCheck_(15, (void *) f.get(), x15.producer, 0, x15.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x15).theSource()));
        }
        if (connectAndCheck_(16, (void *) f.get(), x16.producer, 0, x16.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x16).theSource()));
        }
        if (connectAndCheck_(17, (void *) f.get(), x17.producer, 0, x17.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x17).theSource()));
        }
        if (connectAndCheck_(18, (void *) f.get(), x18.producer, 0, x18.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x18).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A10> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A11> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A12> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A13> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A14> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A15> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(15, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A16> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(16, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A17> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(17, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A18> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(18, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14, Source<A15> &&x15, Source<A16> &&x16, Source<A17> &&x17, Source<A18> &&x18) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
        if (connectAndCheck_(15, (void *) f.get(), x15.producer, 0, x15.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x15).theSource()));
        }
        if (connectAndCheck_(16, (void *) f.get(), x16.producer, 0, x16.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x16).theSource()));
        }
        if (connectAndCheck_(17, (void *) f.get(), x17.producer, 0, x17.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x17).theSource()));
        }
        if (connectAndCheck_(18, (void *) f.get(), x18.producer, 0, x18.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x18).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A0> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A1> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A2> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A3> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A4> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A5> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A6> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A7> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A8> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A9> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A10> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A11> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A12> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A13> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A14> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A15> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(15, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A16> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(16, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A17> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(17, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A18> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(18, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A19> &&x) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(19, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14, Source<A15> &&x15, Source<A16> &&x16, Source<A17> &&x17, Source<A18> &&x18, Source<A19> &&x19) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(f, name);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
        if (connectAndCheck_(15, (void *) f.get(), x15.producer, 0, x15.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x15).theSource()));
        }
        if (connectAndCheck_(16, (void *) f.get(), x16.producer, 0, x16.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x16).theSource()));
        }
        if (connectAndCheck_(17, (void *) f.get(), x17.producer, 0, x17.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x17).theSource()));
        }
        if (connectAndCheck_(18, (void *) f.get(), x18.producer, 0, x18.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x18).theSource()));
        }
        if (connectAndCheck_(19, (void *) f.get(), x19.producer, 0, x19.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x19).theSource()));
        }
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A0> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A1> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(1, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A2> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(2, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A3> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(3, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A4> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(4, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A5> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(5, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A6> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(6, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A7> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(7, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A8> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(8, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A9> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(9, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A10> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(10, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A11> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(11, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A12> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(12, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A13> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(13, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A14> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(14, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A15> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(15, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A16> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(16, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A17> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(17, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A18> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(18, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A19> &&x) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(19, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &f, Source<A0> &&x0, Source<A1> &&x1, Source<A2> &&x2, Source<A3> &&x3, Source<A4> &&x4, Source<A5> &&x5, Source<A6> &&x6, Source<A7> &&x7, Source<A8> &&x8, Source<A9> &&x9, Source<A10> &&x10, Source<A11> &&x11, Source<A12> &&x12, Source<A13> &&x13, Source<A14> &&x14, Source<A15> &&x15, Source<A16> &&x16, Source<A17> &&x17, Source<A18> &&x18, Source<A19> &&x19) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        if (connectAndCheck_(0, (void *) f.get(), x0.producer, 0, x0.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x0).theSource()));
        }
        if (connectAndCheck_(1, (void *) f.get(), x1.producer, 0, x1.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x1).theSource()));
        }
        if (connectAndCheck_(2, (void *) f.get(), x2.producer, 0, x2.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x2).theSource()));
        }
        if (connectAndCheck_(3, (void *) f.get(), x3.producer, 0, x3.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x3).theSource()));
        }
        if (connectAndCheck_(4, (void *) f.get(), x4.producer, 0, x4.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x4).theSource()));
        }
        if (connectAndCheck_(5, (void *) f.get(), x5.producer, 0, x5.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x5).theSource()));
        }
        if (connectAndCheck_(6, (void *) f.get(), x6.producer, 0, x6.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x6).theSource()));
        }
        if (connectAndCheck_(7, (void *) f.get(), x7.producer, 0, x7.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x7).theSource()));
        }
        if (connectAndCheck_(8, (void *) f.get(), x8.producer, 0, x8.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x8).theSource()));
        }
        if (connectAndCheck_(9, (void *) f.get(), x9.producer, 0, x9.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x9).theSource()));
        }
        if (connectAndCheck_(10, (void *) f.get(), x10.producer, 0, x10.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x10).theSource()));
        }
        if (connectAndCheck_(11, (void *) f.get(), x11.producer, 0, x11.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x11).theSource()));
        }
        if (connectAndCheck_(12, (void *) f.get(), x12.producer, 0, x12.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x12).theSource()));
        }
        if (connectAndCheck_(13, (void *) f.get(), x13.producer, 0, x13.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x13).theSource()));
        }
        if (connectAndCheck_(14, (void *) f.get(), x14.producer, 0, x14.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x14).theSource()));
        }
        if (connectAndCheck_(15, (void *) f.get(), x15.producer, 0, x15.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x15).theSource()));
        }
        if (connectAndCheck_(16, (void *) f.get(), x16.producer, 0, x16.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x16).theSource()));
        }
        if (connectAndCheck_(17, (void *) f.get(), x17.producer, 0, x17.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x17).theSource()));
        }
        if (connectAndCheck_(18, (void *) f.get(), x18.producer, 0, x18.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x18).theSource()));
        }
        if (connectAndCheck_(19, (void *) f.get(), x19.producer, 0, x19.useAltOutput)) {
            m_.execute(*f, std::move(std::move(x19).theSource()));
        }
        name = nameMap_[(void *) f.get()].name;
    }
    return { m_.actionAsSource(env_, *f), name };
}