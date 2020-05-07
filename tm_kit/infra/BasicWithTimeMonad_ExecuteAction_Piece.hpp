template <class A0, class A1, class B>
Source<B> execute(Action<std::variant<A0,A1>,B> &action, Source<A0> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A0>(
                [](A0 &&a) -> std::variant<A0,A1> {
                    return std::variant<A0,A1> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class B>
Source<B> execute(Action<std::variant<A0,A1>,B> &action, Source<A1> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A1>(
                [](A1 &&a) -> std::variant<A0,A1> {
                    return std::variant<A0,A1> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class B>
Source<B> execute(Action<std::variant<A0,A1,A2>,B> &action, Source<A0> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A0>(
                [](A0 &&a) -> std::variant<A0,A1,A2> {
                    return std::variant<A0,A1,A2> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class B>
Source<B> execute(Action<std::variant<A0,A1,A2>,B> &action, Source<A1> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A1>(
                [](A1 &&a) -> std::variant<A0,A1,A2> {
                    return std::variant<A0,A1,A2> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class B>
Source<B> execute(Action<std::variant<A0,A1,A2>,B> &action, Source<A2> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A2>(
                [](A2 &&a) -> std::variant<A0,A1,A2> {
                    return std::variant<A0,A1,A2> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A0> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A0>(
                [](A0 &&a) -> std::variant<A0,A1,A2,A3> {
                    return std::variant<A0,A1,A2,A3> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A1> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A1>(
                [](A1 &&a) -> std::variant<A0,A1,A2,A3> {
                    return std::variant<A0,A1,A2,A3> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A2> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A2>(
                [](A2 &&a) -> std::variant<A0,A1,A2,A3> {
                    return std::variant<A0,A1,A2,A3> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A3> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A3>(
                [](A3 &&a) -> std::variant<A0,A1,A2,A3> {
                    return std::variant<A0,A1,A2,A3> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A0> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A0>(
                [](A0 &&a) -> std::variant<A0,A1,A2,A3,A4> {
                    return std::variant<A0,A1,A2,A3,A4> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A1> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A1>(
                [](A1 &&a) -> std::variant<A0,A1,A2,A3,A4> {
                    return std::variant<A0,A1,A2,A3,A4> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A2> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A2>(
                [](A2 &&a) -> std::variant<A0,A1,A2,A3,A4> {
                    return std::variant<A0,A1,A2,A3,A4> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A3> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A3>(
                [](A3 &&a) -> std::variant<A0,A1,A2,A3,A4> {
                    return std::variant<A0,A1,A2,A3,A4> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A4> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A4>(
                [](A4 &&a) -> std::variant<A0,A1,A2,A3,A4> {
                    return std::variant<A0,A1,A2,A3,A4> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A0> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A0>(
                [](A0 &&a) -> std::variant<A0,A1,A2,A3,A4,A5> {
                    return std::variant<A0,A1,A2,A3,A4,A5> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A1> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A1>(
                [](A1 &&a) -> std::variant<A0,A1,A2,A3,A4,A5> {
                    return std::variant<A0,A1,A2,A3,A4,A5> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A2> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A2>(
                [](A2 &&a) -> std::variant<A0,A1,A2,A3,A4,A5> {
                    return std::variant<A0,A1,A2,A3,A4,A5> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A3> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A3>(
                [](A3 &&a) -> std::variant<A0,A1,A2,A3,A4,A5> {
                    return std::variant<A0,A1,A2,A3,A4,A5> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A4> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A4>(
                [](A4 &&a) -> std::variant<A0,A1,A2,A3,A4,A5> {
                    return std::variant<A0,A1,A2,A3,A4,A5> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A5> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A5>(
                [](A5 &&a) -> std::variant<A0,A1,A2,A3,A4,A5> {
                    return std::variant<A0,A1,A2,A3,A4,A5> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A0> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A0>(
                [](A0 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A1> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A1>(
                [](A1 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A2> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A2>(
                [](A2 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A3> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A3>(
                [](A3 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A4> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A4>(
                [](A4 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A5> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A5>(
                [](A5 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A6> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A6>(
                [](A6 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A0> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A0>(
                [](A0 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A1> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A1>(
                [](A1 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A2> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A2>(
                [](A2 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A3> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A3>(
                [](A3 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A4> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A4>(
                [](A4 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A5> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A5>(
                [](A5 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A6> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A6>(
                [](A6 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A7> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A7>(
                [](A7 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A0> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A0>(
                [](A0 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A1> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A1>(
                [](A1 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A2> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A2>(
                [](A2 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A3> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A3>(
                [](A3 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A4> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A4>(
                [](A4 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A5> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A5>(
                [](A5 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A6> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A6>(
                [](A6 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A7> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A7>(
                [](A7 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A8> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A8>(
                [](A8 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A0> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A0>(
                [](A0 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A1> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A1>(
                [](A1 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A2> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A2>(
                [](A2 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A3> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A3>(
                [](A3 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A4> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A4>(
                [](A4 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A5> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A5>(
                [](A5 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A6> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A6>(
                [](A6 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A7> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A7>(
                [](A7 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A8> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A8>(
                [](A8 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A9> &&variable) {
    switch (RunMode) {
    case BasicWithTimeMonadRunMode::TypeCheckOnly:
        return {};
    case BasicWithTimeMonadRunMode::MinimalTestRun:
        {
            auto v = apply(*(liftPure<A9>(
                [](A9 &&a) -> std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {
                    return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a)};
                }))
                , std::move(variable.data));
            return {apply(action, std::move(v))};
        }
        break;
    default:
        return {};
    }
}