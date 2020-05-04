template <class A0, class A1, class B>
Sink<A0> actionAsSink_2_0(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_2_0(*action), name, 0 };
}
template <class A0, class A1, class B>
Sink<A1> actionAsSink_2_1(std::string const &name, ActionPtr<std::variant<A0,A1>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_2_1(*action), name, 0 };
}
template <class A0, class A1, class B>
Sink<A0> actionAsSink_2_0(ActionPtr<std::variant<A0,A1>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_2_0(*action), name, 0 };
}
template <class A0, class A1, class B>
Sink<A1> actionAsSink_2_1(ActionPtr<std::variant<A0,A1>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_2_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class B>
Sink<A0> actionAsSink_3_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_3_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class B>
Sink<A1> actionAsSink_3_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_3_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class B>
Sink<A2> actionAsSink_3_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_3_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class B>
Sink<A0> actionAsSink_3_0(ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_3_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class B>
Sink<A1> actionAsSink_3_1(ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_3_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class B>
Sink<A2> actionAsSink_3_2(ActionPtr<std::variant<A0,A1,A2>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_3_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A0> actionAsSink_4_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_4_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A1> actionAsSink_4_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_4_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A2> actionAsSink_4_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_4_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A3> actionAsSink_4_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_4_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A0> actionAsSink_4_0(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_4_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A1> actionAsSink_4_1(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_4_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A2> actionAsSink_4_2(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_4_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A3> actionAsSink_4_3(ActionPtr<std::variant<A0,A1,A2,A3>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_4_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A0> actionAsSink_5_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_5_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A1> actionAsSink_5_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_5_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A2> actionAsSink_5_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_5_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A3> actionAsSink_5_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_5_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A4> actionAsSink_5_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_5_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A0> actionAsSink_5_0(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_5_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A1> actionAsSink_5_1(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_5_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A2> actionAsSink_5_2(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_5_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A3> actionAsSink_5_3(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_5_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A4> actionAsSink_5_4(ActionPtr<std::variant<A0,A1,A2,A3,A4>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_5_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A0> actionAsSink_6_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_6_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A1> actionAsSink_6_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_6_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A2> actionAsSink_6_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_6_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A3> actionAsSink_6_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_6_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A4> actionAsSink_6_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_6_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A5> actionAsSink_6_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_6_5(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A0> actionAsSink_6_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_6_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A1> actionAsSink_6_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_6_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A2> actionAsSink_6_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_6_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A3> actionAsSink_6_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_6_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A4> actionAsSink_6_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_6_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A5> actionAsSink_6_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_6_5(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A0> actionAsSink_7_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_7_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A1> actionAsSink_7_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_7_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A2> actionAsSink_7_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_7_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A3> actionAsSink_7_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_7_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A4> actionAsSink_7_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_7_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A5> actionAsSink_7_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_7_5(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A6> actionAsSink_7_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_7_6(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A0> actionAsSink_7_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_7_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A1> actionAsSink_7_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_7_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A2> actionAsSink_7_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_7_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A3> actionAsSink_7_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_7_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A4> actionAsSink_7_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_7_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A5> actionAsSink_7_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_7_5(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A6> actionAsSink_7_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_7_6(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A0> actionAsSink_8_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_8_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A1> actionAsSink_8_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_8_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A2> actionAsSink_8_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_8_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A3> actionAsSink_8_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_8_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A4> actionAsSink_8_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_8_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A5> actionAsSink_8_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_8_5(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A6> actionAsSink_8_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_8_6(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A7> actionAsSink_8_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_8_7(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A0> actionAsSink_8_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_8_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A1> actionAsSink_8_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_8_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A2> actionAsSink_8_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_8_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A3> actionAsSink_8_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_8_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A4> actionAsSink_8_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_8_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A5> actionAsSink_8_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_8_5(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A6> actionAsSink_8_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_8_6(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A7> actionAsSink_8_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_8_7(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A0> actionAsSink_9_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_9_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A1> actionAsSink_9_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_9_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A2> actionAsSink_9_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_9_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A3> actionAsSink_9_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_9_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A4> actionAsSink_9_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_9_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A5> actionAsSink_9_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_9_5(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A6> actionAsSink_9_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_9_6(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A7> actionAsSink_9_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_9_7(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A8> actionAsSink_9_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_9_8(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A0> actionAsSink_9_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_9_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A1> actionAsSink_9_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_9_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A2> actionAsSink_9_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_9_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A3> actionAsSink_9_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_9_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A4> actionAsSink_9_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_9_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A5> actionAsSink_9_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_9_5(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A6> actionAsSink_9_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_9_6(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A7> actionAsSink_9_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_9_7(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A8> actionAsSink_9_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_9_8(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A0> actionAsSink_10_0(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_10_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A1> actionAsSink_10_1(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_10_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A2> actionAsSink_10_2(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_10_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A3> actionAsSink_10_3(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_10_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A4> actionAsSink_10_4(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_10_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A5> actionAsSink_10_5(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_10_5(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A6> actionAsSink_10_6(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_10_6(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A7> actionAsSink_10_7(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_10_7(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A8> actionAsSink_10_8(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_10_8(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A9> actionAsSink_10_9(std::string const &name, ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    {
        std::lock_guard<std::mutex> _(mutex_);
        registerAction_(action, name);
    }
    return { m_.actionAsSink_10_9(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A0> actionAsSink_10_0(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_10_0(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A1> actionAsSink_10_1(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_10_1(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A2> actionAsSink_10_2(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_10_2(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A3> actionAsSink_10_3(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_10_3(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A4> actionAsSink_10_4(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_10_4(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A5> actionAsSink_10_5(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_10_5(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A6> actionAsSink_10_6(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_10_6(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A7> actionAsSink_10_7(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_10_7(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A8> actionAsSink_10_8(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_10_8(*action), name, 0 };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A9> actionAsSink_10_9(ActionPtr<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> const &action) {
    std::string name;
    {
        std::lock_guard<std::mutex> _(mutex_);
        name = checkName_((void *) action.get());
    }
    return { m_.actionAsSink_10_9(*action), name, 0 };
}