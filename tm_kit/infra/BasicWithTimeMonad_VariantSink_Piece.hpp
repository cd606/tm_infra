template <class A0, class A1, class B>
Sink<A0> actionAsSink_2_0(Action<std::variant<A0,A1>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A0> {
            [this,&action](Source<A0> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class B>
Sink<A1> actionAsSink_2_1(Action<std::variant<A0,A1>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A1> {
            [this,&action](Source<A1> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class B>
Sink<A0> actionAsSink_3_0(Action<std::variant<A0,A1,A2>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A0> {
            [this,&action](Source<A0> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class B>
Sink<A1> actionAsSink_3_1(Action<std::variant<A0,A1,A2>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A1> {
            [this,&action](Source<A1> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class B>
Sink<A2> actionAsSink_3_2(Action<std::variant<A0,A1,A2>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A2> {
            [this,&action](Source<A2> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A0> actionAsSink_4_0(Action<std::variant<A0,A1,A2,A3>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A0> {
            [this,&action](Source<A0> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A1> actionAsSink_4_1(Action<std::variant<A0,A1,A2,A3>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A1> {
            [this,&action](Source<A1> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A2> actionAsSink_4_2(Action<std::variant<A0,A1,A2,A3>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A2> {
            [this,&action](Source<A2> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class B>
Sink<A3> actionAsSink_4_3(Action<std::variant<A0,A1,A2,A3>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A3> {
            [this,&action](Source<A3> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A0> actionAsSink_5_0(Action<std::variant<A0,A1,A2,A3,A4>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A0> {
            [this,&action](Source<A0> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A1> actionAsSink_5_1(Action<std::variant<A0,A1,A2,A3,A4>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A1> {
            [this,&action](Source<A1> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A2> actionAsSink_5_2(Action<std::variant<A0,A1,A2,A3,A4>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A2> {
            [this,&action](Source<A2> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A3> actionAsSink_5_3(Action<std::variant<A0,A1,A2,A3,A4>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A3> {
            [this,&action](Source<A3> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Sink<A4> actionAsSink_5_4(Action<std::variant<A0,A1,A2,A3,A4>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A4> {
            [this,&action](Source<A4> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A0> actionAsSink_6_0(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A0> {
            [this,&action](Source<A0> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A1> actionAsSink_6_1(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A1> {
            [this,&action](Source<A1> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A2> actionAsSink_6_2(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A2> {
            [this,&action](Source<A2> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A3> actionAsSink_6_3(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A3> {
            [this,&action](Source<A3> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A4> actionAsSink_6_4(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A4> {
            [this,&action](Source<A4> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Sink<A5> actionAsSink_6_5(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A5> {
            [this,&action](Source<A5> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A0> actionAsSink_7_0(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A0> {
            [this,&action](Source<A0> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A1> actionAsSink_7_1(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A1> {
            [this,&action](Source<A1> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A2> actionAsSink_7_2(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A2> {
            [this,&action](Source<A2> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A3> actionAsSink_7_3(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A3> {
            [this,&action](Source<A3> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A4> actionAsSink_7_4(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A4> {
            [this,&action](Source<A4> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A5> actionAsSink_7_5(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A5> {
            [this,&action](Source<A5> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Sink<A6> actionAsSink_7_6(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A6> {
            [this,&action](Source<A6> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A0> actionAsSink_8_0(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A0> {
            [this,&action](Source<A0> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A1> actionAsSink_8_1(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A1> {
            [this,&action](Source<A1> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A2> actionAsSink_8_2(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A2> {
            [this,&action](Source<A2> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A3> actionAsSink_8_3(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A3> {
            [this,&action](Source<A3> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A4> actionAsSink_8_4(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A4> {
            [this,&action](Source<A4> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A5> actionAsSink_8_5(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A5> {
            [this,&action](Source<A5> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A6> actionAsSink_8_6(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A6> {
            [this,&action](Source<A6> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Sink<A7> actionAsSink_8_7(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A7> {
            [this,&action](Source<A7> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A0> actionAsSink_9_0(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A0> {
            [this,&action](Source<A0> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A1> actionAsSink_9_1(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A1> {
            [this,&action](Source<A1> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A2> actionAsSink_9_2(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A2> {
            [this,&action](Source<A2> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A3> actionAsSink_9_3(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A3> {
            [this,&action](Source<A3> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A4> actionAsSink_9_4(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A4> {
            [this,&action](Source<A4> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A5> actionAsSink_9_5(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A5> {
            [this,&action](Source<A5> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A6> actionAsSink_9_6(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A6> {
            [this,&action](Source<A6> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A7> actionAsSink_9_7(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A7> {
            [this,&action](Source<A7> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Sink<A8> actionAsSink_9_8(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A8> {
            [this,&action](Source<A8> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A0> actionAsSink_10_0(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A0> {
            [this,&action](Source<A0> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A1> actionAsSink_10_1(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A1> {
            [this,&action](Source<A1> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A2> actionAsSink_10_2(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A2> {
            [this,&action](Source<A2> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A3> actionAsSink_10_3(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A3> {
            [this,&action](Source<A3> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A4> actionAsSink_10_4(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A4> {
            [this,&action](Source<A4> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A5> actionAsSink_10_5(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A5> {
            [this,&action](Source<A5> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A6> actionAsSink_10_6(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A6> {
            [this,&action](Source<A6> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A7> actionAsSink_10_7(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A7> {
            [this,&action](Source<A7> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A8> actionAsSink_10_8(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A8> {
            [this,&action](Source<A8> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Sink<A9> actionAsSink_10_9(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        return Sink<A9> {
            [this,&action](Source<A9> &&src) {
                execute(action, std::move(src));
            }
        };
    default:
        return {};
    }
}