template <class A0, class A1, class B>
Sink<A0> actionAsSink_2_0(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_2_0<A0,A1,B>(*action), name, 0 };
}
template <class A0, class A1, class B>
Sink<A1> actionAsSink_2_1(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_2_1<A0,A1,B>(*action), name, 1 };
}
template <class A0, class A1, class B>
Sink<A0> actionAsSink_2_0(ActionPtr<std::variant<A0,A1>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_2_0<A0,A1,B>(*action), name, 0 };
}
template <class A0, class A1, class B>
Sink<A1> actionAsSink_2_1(ActionPtr<std::variant<A0,A1>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_2_1<A0,A1,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class B>
Sink<A0> actionAsSink_3_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_3_0<A0,A1,A2,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class B>
Sink<A1> actionAsSink_3_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_3_1<A0,A1,A2,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class B>
Sink<A2> actionAsSink_3_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_3_2<A0,A1,A2,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class B>
Sink<A0> actionAsSink_3_0(ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_3_0<A0,A1,A2,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class B>
Sink<A1> actionAsSink_3_1(ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_3_1<A0,A1,A2,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class B>
Sink<A2> actionAsSink_3_2(ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_3_2<A0,A1,A2,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A0> actionAsSink_4_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_4_0<A0,A1,A2,A3,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A1> actionAsSink_4_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_4_1<A0,A1,A2,A3,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A2> actionAsSink_4_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_4_2<A0,A1,A2,A3,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A3> actionAsSink_4_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_4_3<A0,A1,A2,A3,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A0> actionAsSink_4_0(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_4_0<A0,A1,A2,A3,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A1> actionAsSink_4_1(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_4_1<A0,A1,A2,A3,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A2> actionAsSink_4_2(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_4_2<A0,A1,A2,A3,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A3> actionAsSink_4_3(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_4_3<A0,A1,A2,A3,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A0> actionAsSink_5_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_5_0<A0,A1,A2,A3,A4,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A1> actionAsSink_5_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_5_1<A0,A1,A2,A3,A4,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A2> actionAsSink_5_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_5_2<A0,A1,A2,A3,A4,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A3> actionAsSink_5_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_5_3<A0,A1,A2,A3,A4,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A4> actionAsSink_5_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_5_4<A0,A1,A2,A3,A4,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A0> actionAsSink_5_0(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_5_0<A0,A1,A2,A3,A4,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A1> actionAsSink_5_1(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_5_1<A0,A1,A2,A3,A4,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A2> actionAsSink_5_2(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_5_2<A0,A1,A2,A3,A4,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A3> actionAsSink_5_3(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_5_3<A0,A1,A2,A3,A4,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A4> actionAsSink_5_4(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_5_4<A0,A1,A2,A3,A4,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A0> actionAsSink_6_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_6_0<A0,A1,A2,A3,A4,A5,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A1> actionAsSink_6_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_6_1<A0,A1,A2,A3,A4,A5,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A2> actionAsSink_6_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_6_2<A0,A1,A2,A3,A4,A5,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A3> actionAsSink_6_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_6_3<A0,A1,A2,A3,A4,A5,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A4> actionAsSink_6_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_6_4<A0,A1,A2,A3,A4,A5,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A5> actionAsSink_6_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_6_5<A0,A1,A2,A3,A4,A5,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A0> actionAsSink_6_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_6_0<A0,A1,A2,A3,A4,A5,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A1> actionAsSink_6_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_6_1<A0,A1,A2,A3,A4,A5,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A2> actionAsSink_6_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_6_2<A0,A1,A2,A3,A4,A5,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A3> actionAsSink_6_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_6_3<A0,A1,A2,A3,A4,A5,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A4> actionAsSink_6_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_6_4<A0,A1,A2,A3,A4,A5,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A5> actionAsSink_6_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_6_5<A0,A1,A2,A3,A4,A5,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A0> actionAsSink_7_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_7_0<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A1> actionAsSink_7_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_7_1<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A2> actionAsSink_7_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_7_2<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A3> actionAsSink_7_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_7_3<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A4> actionAsSink_7_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_7_4<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A5> actionAsSink_7_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_7_5<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A6> actionAsSink_7_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_7_6<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A0> actionAsSink_7_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_7_0<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A1> actionAsSink_7_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_7_1<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A2> actionAsSink_7_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_7_2<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A3> actionAsSink_7_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_7_3<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A4> actionAsSink_7_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_7_4<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A5> actionAsSink_7_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_7_5<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A6> actionAsSink_7_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_7_6<A0,A1,A2,A3,A4,A5,A6,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A0> actionAsSink_8_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_8_0<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A1> actionAsSink_8_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_8_1<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A2> actionAsSink_8_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_8_2<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A3> actionAsSink_8_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_8_3<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A4> actionAsSink_8_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_8_4<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A5> actionAsSink_8_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_8_5<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A6> actionAsSink_8_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_8_6<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A7> actionAsSink_8_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_8_7<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A0> actionAsSink_8_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_8_0<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A1> actionAsSink_8_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_8_1<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A2> actionAsSink_8_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_8_2<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A3> actionAsSink_8_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_8_3<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A4> actionAsSink_8_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_8_4<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A5> actionAsSink_8_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_8_5<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A6> actionAsSink_8_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_8_6<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A7> actionAsSink_8_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_8_7<A0,A1,A2,A3,A4,A5,A6,A7,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A0> actionAsSink_9_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_9_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A1> actionAsSink_9_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_9_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A2> actionAsSink_9_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_9_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A3> actionAsSink_9_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_9_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A4> actionAsSink_9_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_9_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A5> actionAsSink_9_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_9_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A6> actionAsSink_9_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_9_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A7> actionAsSink_9_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_9_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A8> actionAsSink_9_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_9_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A0> actionAsSink_9_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_9_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A1> actionAsSink_9_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_9_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A2> actionAsSink_9_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_9_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A3> actionAsSink_9_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_9_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A4> actionAsSink_9_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_9_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A5> actionAsSink_9_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_9_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A6> actionAsSink_9_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_9_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A7> actionAsSink_9_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_9_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A8> actionAsSink_9_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_9_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A0> actionAsSink_10_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_10_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A1> actionAsSink_10_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_10_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A2> actionAsSink_10_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_10_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A3> actionAsSink_10_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_10_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A4> actionAsSink_10_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_10_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A5> actionAsSink_10_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_10_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A6> actionAsSink_10_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_10_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A7> actionAsSink_10_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_10_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A8> actionAsSink_10_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_10_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A9> actionAsSink_10_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_10_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A0> actionAsSink_10_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_10_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A1> actionAsSink_10_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_10_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A2> actionAsSink_10_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_10_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A3> actionAsSink_10_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_10_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A4> actionAsSink_10_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_10_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A5> actionAsSink_10_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_10_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A6> actionAsSink_10_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_10_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A7> actionAsSink_10_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_10_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A8> actionAsSink_10_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_10_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A9> actionAsSink_10_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_10_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A0> actionAsSink_11_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_11_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A1> actionAsSink_11_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_11_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A2> actionAsSink_11_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_11_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A3> actionAsSink_11_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_11_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A4> actionAsSink_11_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_11_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A5> actionAsSink_11_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_11_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A6> actionAsSink_11_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_11_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A7> actionAsSink_11_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_11_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A8> actionAsSink_11_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_11_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A9> actionAsSink_11_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_11_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A10> actionAsSink_11_10(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_11_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A0> actionAsSink_11_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_11_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A1> actionAsSink_11_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_11_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A2> actionAsSink_11_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_11_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A3> actionAsSink_11_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_11_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A4> actionAsSink_11_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_11_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A5> actionAsSink_11_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_11_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A6> actionAsSink_11_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_11_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A7> actionAsSink_11_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_11_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A8> actionAsSink_11_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_11_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A9> actionAsSink_11_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_11_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Sink<A10> actionAsSink_11_10(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_11_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A0> actionAsSink_12_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A1> actionAsSink_12_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A2> actionAsSink_12_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A3> actionAsSink_12_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A4> actionAsSink_12_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A5> actionAsSink_12_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A6> actionAsSink_12_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A7> actionAsSink_12_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A8> actionAsSink_12_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A9> actionAsSink_12_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A10> actionAsSink_12_10(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A11> actionAsSink_12_11(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_12_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A0> actionAsSink_12_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A1> actionAsSink_12_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A2> actionAsSink_12_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A3> actionAsSink_12_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A4> actionAsSink_12_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A5> actionAsSink_12_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A6> actionAsSink_12_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A7> actionAsSink_12_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A8> actionAsSink_12_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A9> actionAsSink_12_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A10> actionAsSink_12_10(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Sink<A11> actionAsSink_12_11(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_12_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A0> actionAsSink_13_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A1> actionAsSink_13_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A2> actionAsSink_13_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A3> actionAsSink_13_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A4> actionAsSink_13_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A5> actionAsSink_13_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A6> actionAsSink_13_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A7> actionAsSink_13_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A8> actionAsSink_13_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A9> actionAsSink_13_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A10> actionAsSink_13_10(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A11> actionAsSink_13_11(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A12> actionAsSink_13_12(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_13_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A0> actionAsSink_13_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A1> actionAsSink_13_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A2> actionAsSink_13_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A3> actionAsSink_13_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A4> actionAsSink_13_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A5> actionAsSink_13_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A6> actionAsSink_13_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A7> actionAsSink_13_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A8> actionAsSink_13_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A9> actionAsSink_13_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A10> actionAsSink_13_10(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A11> actionAsSink_13_11(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Sink<A12> actionAsSink_13_12(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_13_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A0> actionAsSink_14_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A1> actionAsSink_14_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A2> actionAsSink_14_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A3> actionAsSink_14_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A4> actionAsSink_14_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A5> actionAsSink_14_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A6> actionAsSink_14_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A7> actionAsSink_14_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A8> actionAsSink_14_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A9> actionAsSink_14_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A10> actionAsSink_14_10(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A11> actionAsSink_14_11(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A12> actionAsSink_14_12(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A13> actionAsSink_14_13(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_14_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A0> actionAsSink_14_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A1> actionAsSink_14_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A2> actionAsSink_14_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A3> actionAsSink_14_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A4> actionAsSink_14_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A5> actionAsSink_14_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A6> actionAsSink_14_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A7> actionAsSink_14_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A8> actionAsSink_14_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A9> actionAsSink_14_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A10> actionAsSink_14_10(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A11> actionAsSink_14_11(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A12> actionAsSink_14_12(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Sink<A13> actionAsSink_14_13(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_14_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A0> actionAsSink_15_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A1> actionAsSink_15_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A2> actionAsSink_15_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A3> actionAsSink_15_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A4> actionAsSink_15_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A5> actionAsSink_15_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A6> actionAsSink_15_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A7> actionAsSink_15_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A8> actionAsSink_15_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A9> actionAsSink_15_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A10> actionAsSink_15_10(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A11> actionAsSink_15_11(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A12> actionAsSink_15_12(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A13> actionAsSink_15_13(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A14> actionAsSink_15_14(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_15_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A0> actionAsSink_15_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A1> actionAsSink_15_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A2> actionAsSink_15_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A3> actionAsSink_15_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A4> actionAsSink_15_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A5> actionAsSink_15_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A6> actionAsSink_15_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A7> actionAsSink_15_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A8> actionAsSink_15_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A9> actionAsSink_15_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A10> actionAsSink_15_10(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A11> actionAsSink_15_11(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A12> actionAsSink_15_12(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A13> actionAsSink_15_13(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Sink<A14> actionAsSink_15_14(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_15_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A0> actionAsSink_16_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A1> actionAsSink_16_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A2> actionAsSink_16_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A3> actionAsSink_16_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A4> actionAsSink_16_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A5> actionAsSink_16_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A6> actionAsSink_16_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A7> actionAsSink_16_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A8> actionAsSink_16_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A9> actionAsSink_16_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A10> actionAsSink_16_10(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A11> actionAsSink_16_11(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A12> actionAsSink_16_12(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A13> actionAsSink_16_13(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A14> actionAsSink_16_14(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A15> actionAsSink_16_15(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_16_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 15 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A0> actionAsSink_16_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A1> actionAsSink_16_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A2> actionAsSink_16_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A3> actionAsSink_16_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A4> actionAsSink_16_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A5> actionAsSink_16_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A6> actionAsSink_16_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A7> actionAsSink_16_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A8> actionAsSink_16_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A9> actionAsSink_16_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A10> actionAsSink_16_10(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A11> actionAsSink_16_11(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A12> actionAsSink_16_12(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A13> actionAsSink_16_13(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A14> actionAsSink_16_14(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Sink<A15> actionAsSink_16_15(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_16_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B>(*action), name, 15 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A0> actionAsSink_17_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A1> actionAsSink_17_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A2> actionAsSink_17_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A3> actionAsSink_17_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A4> actionAsSink_17_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A5> actionAsSink_17_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A6> actionAsSink_17_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A7> actionAsSink_17_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A8> actionAsSink_17_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A9> actionAsSink_17_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A10> actionAsSink_17_10(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A11> actionAsSink_17_11(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A12> actionAsSink_17_12(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A13> actionAsSink_17_13(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A14> actionAsSink_17_14(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A15> actionAsSink_17_15(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 15 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A16> actionAsSink_17_16(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_17_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 16 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A0> actionAsSink_17_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A1> actionAsSink_17_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A2> actionAsSink_17_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A3> actionAsSink_17_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A4> actionAsSink_17_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A5> actionAsSink_17_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A6> actionAsSink_17_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A7> actionAsSink_17_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A8> actionAsSink_17_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A9> actionAsSink_17_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A10> actionAsSink_17_10(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A11> actionAsSink_17_11(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A12> actionAsSink_17_12(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A13> actionAsSink_17_13(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A14> actionAsSink_17_14(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A15> actionAsSink_17_15(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 15 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Sink<A16> actionAsSink_17_16(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_17_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B>(*action), name, 16 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A0> actionAsSink_18_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A1> actionAsSink_18_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A2> actionAsSink_18_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A3> actionAsSink_18_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A4> actionAsSink_18_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A5> actionAsSink_18_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A6> actionAsSink_18_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A7> actionAsSink_18_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A8> actionAsSink_18_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A9> actionAsSink_18_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A10> actionAsSink_18_10(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A11> actionAsSink_18_11(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A12> actionAsSink_18_12(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A13> actionAsSink_18_13(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A14> actionAsSink_18_14(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A15> actionAsSink_18_15(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 15 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A16> actionAsSink_18_16(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 16 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A17> actionAsSink_18_17(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_18_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 17 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A0> actionAsSink_18_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A1> actionAsSink_18_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A2> actionAsSink_18_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A3> actionAsSink_18_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A4> actionAsSink_18_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A5> actionAsSink_18_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A6> actionAsSink_18_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A7> actionAsSink_18_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A8> actionAsSink_18_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A9> actionAsSink_18_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A10> actionAsSink_18_10(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A11> actionAsSink_18_11(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A12> actionAsSink_18_12(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A13> actionAsSink_18_13(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A14> actionAsSink_18_14(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A15> actionAsSink_18_15(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 15 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A16> actionAsSink_18_16(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 16 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Sink<A17> actionAsSink_18_17(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_18_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B>(*action), name, 17 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A0> actionAsSink_19_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A1> actionAsSink_19_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A2> actionAsSink_19_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A3> actionAsSink_19_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A4> actionAsSink_19_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A5> actionAsSink_19_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A6> actionAsSink_19_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A7> actionAsSink_19_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A8> actionAsSink_19_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A9> actionAsSink_19_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A10> actionAsSink_19_10(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A11> actionAsSink_19_11(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A12> actionAsSink_19_12(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A13> actionAsSink_19_13(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A14> actionAsSink_19_14(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A15> actionAsSink_19_15(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 15 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A16> actionAsSink_19_16(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 16 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A17> actionAsSink_19_17(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 17 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A18> actionAsSink_19_18(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_19_18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 18 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A0> actionAsSink_19_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A1> actionAsSink_19_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A2> actionAsSink_19_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A3> actionAsSink_19_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A4> actionAsSink_19_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A5> actionAsSink_19_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A6> actionAsSink_19_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A7> actionAsSink_19_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A8> actionAsSink_19_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A9> actionAsSink_19_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A10> actionAsSink_19_10(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A11> actionAsSink_19_11(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A12> actionAsSink_19_12(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A13> actionAsSink_19_13(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A14> actionAsSink_19_14(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A15> actionAsSink_19_15(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 15 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A16> actionAsSink_19_16(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 16 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A17> actionAsSink_19_17(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 17 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Sink<A18> actionAsSink_19_18(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_19_18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B>(*action), name, 18 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A0> actionAsSink_20_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A1> actionAsSink_20_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A2> actionAsSink_20_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A3> actionAsSink_20_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A4> actionAsSink_20_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A5> actionAsSink_20_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A6> actionAsSink_20_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A7> actionAsSink_20_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A8> actionAsSink_20_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A9> actionAsSink_20_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A10> actionAsSink_20_10(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A11> actionAsSink_20_11(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A12> actionAsSink_20_12(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A13> actionAsSink_20_13(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A14> actionAsSink_20_14(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A15> actionAsSink_20_15(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 15 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A16> actionAsSink_20_16(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 16 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A17> actionAsSink_20_17(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 17 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A18> actionAsSink_20_18(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 18 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A19> actionAsSink_20_19(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.template actionAsSink_20_19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 19 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A0> actionAsSink_20_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A1> actionAsSink_20_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 1 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A2> actionAsSink_20_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 2 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A3> actionAsSink_20_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 3 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A4> actionAsSink_20_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 4 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A5> actionAsSink_20_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 5 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A6> actionAsSink_20_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 6 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A7> actionAsSink_20_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 7 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A8> actionAsSink_20_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 8 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A9> actionAsSink_20_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 9 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A10> actionAsSink_20_10(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 10 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A11> actionAsSink_20_11(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 11 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A12> actionAsSink_20_12(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 12 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A13> actionAsSink_20_13(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 13 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A14> actionAsSink_20_14(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 14 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A15> actionAsSink_20_15(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 15 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A16> actionAsSink_20_16(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 16 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A17> actionAsSink_20_17(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 17 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A18> actionAsSink_20_18(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 18 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Sink<A19> actionAsSink_20_19(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::recursive_mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.template actionAsSink_20_19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B>(*action), name, 19 };
}