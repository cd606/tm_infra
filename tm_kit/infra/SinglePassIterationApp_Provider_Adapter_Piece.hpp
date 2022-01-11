template <class A0, class A1>
class ProviderAdapter_2_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1>> *underlying_;
public:
    ProviderAdapter_2_0(Provider<std::variant<A0,A1>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_2_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1>
class ProviderAdapter_2_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1>> *underlying_;
public:
    ProviderAdapter_2_1(Provider<std::variant<A0,A1>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_2_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2>
class ProviderAdapter_3_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2>> *underlying_;
public:
    ProviderAdapter_3_0(Provider<std::variant<A0,A1,A2>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_3_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2>
class ProviderAdapter_3_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2>> *underlying_;
public:
    ProviderAdapter_3_1(Provider<std::variant<A0,A1,A2>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_3_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2>
class ProviderAdapter_3_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2>> *underlying_;
public:
    ProviderAdapter_3_2(Provider<std::variant<A0,A1,A2>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_3_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3>
class ProviderAdapter_4_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3>> *underlying_;
public:
    ProviderAdapter_4_0(Provider<std::variant<A0,A1,A2,A3>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_4_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3>
class ProviderAdapter_4_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3>> *underlying_;
public:
    ProviderAdapter_4_1(Provider<std::variant<A0,A1,A2,A3>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_4_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3>
class ProviderAdapter_4_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3>> *underlying_;
public:
    ProviderAdapter_4_2(Provider<std::variant<A0,A1,A2,A3>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_4_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3>
class ProviderAdapter_4_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3>> *underlying_;
public:
    ProviderAdapter_4_3(Provider<std::variant<A0,A1,A2,A3>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_4_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4>
class ProviderAdapter_5_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4>> *underlying_;
public:
    ProviderAdapter_5_0(Provider<std::variant<A0,A1,A2,A3,A4>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_5_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4>
class ProviderAdapter_5_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4>> *underlying_;
public:
    ProviderAdapter_5_1(Provider<std::variant<A0,A1,A2,A3,A4>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_5_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4>
class ProviderAdapter_5_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4>> *underlying_;
public:
    ProviderAdapter_5_2(Provider<std::variant<A0,A1,A2,A3,A4>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_5_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4>
class ProviderAdapter_5_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4>> *underlying_;
public:
    ProviderAdapter_5_3(Provider<std::variant<A0,A1,A2,A3,A4>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_5_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4>
class ProviderAdapter_5_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4>> *underlying_;
public:
    ProviderAdapter_5_4(Provider<std::variant<A0,A1,A2,A3,A4>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_5_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
class ProviderAdapter_6_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying_;
public:
    ProviderAdapter_6_0(Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_6_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
class ProviderAdapter_6_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying_;
public:
    ProviderAdapter_6_1(Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_6_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
class ProviderAdapter_6_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying_;
public:
    ProviderAdapter_6_2(Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_6_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
class ProviderAdapter_6_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying_;
public:
    ProviderAdapter_6_3(Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_6_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
class ProviderAdapter_6_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying_;
public:
    ProviderAdapter_6_4(Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_6_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
class ProviderAdapter_6_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying_;
public:
    ProviderAdapter_6_5(Provider<std::variant<A0,A1,A2,A3,A4,A5>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_6_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class ProviderAdapter_7_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying_;
public:
    ProviderAdapter_7_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_7_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class ProviderAdapter_7_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying_;
public:
    ProviderAdapter_7_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_7_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class ProviderAdapter_7_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying_;
public:
    ProviderAdapter_7_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_7_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class ProviderAdapter_7_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying_;
public:
    ProviderAdapter_7_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_7_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class ProviderAdapter_7_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying_;
public:
    ProviderAdapter_7_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_7_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class ProviderAdapter_7_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying_;
public:
    ProviderAdapter_7_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_7_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class ProviderAdapter_7_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying_;
public:
    ProviderAdapter_7_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_7_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class ProviderAdapter_8_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying_;
public:
    ProviderAdapter_8_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_8_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class ProviderAdapter_8_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying_;
public:
    ProviderAdapter_8_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_8_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class ProviderAdapter_8_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying_;
public:
    ProviderAdapter_8_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_8_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class ProviderAdapter_8_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying_;
public:
    ProviderAdapter_8_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_8_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class ProviderAdapter_8_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying_;
public:
    ProviderAdapter_8_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_8_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class ProviderAdapter_8_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying_;
public:
    ProviderAdapter_8_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_8_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class ProviderAdapter_8_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying_;
public:
    ProviderAdapter_8_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_8_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class ProviderAdapter_8_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying_;
public:
    ProviderAdapter_8_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_8_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class ProviderAdapter_9_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying_;
public:
    ProviderAdapter_9_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_9_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class ProviderAdapter_9_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying_;
public:
    ProviderAdapter_9_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_9_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class ProviderAdapter_9_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying_;
public:
    ProviderAdapter_9_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_9_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class ProviderAdapter_9_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying_;
public:
    ProviderAdapter_9_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_9_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class ProviderAdapter_9_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying_;
public:
    ProviderAdapter_9_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_9_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class ProviderAdapter_9_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying_;
public:
    ProviderAdapter_9_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_9_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class ProviderAdapter_9_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying_;
public:
    ProviderAdapter_9_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_9_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class ProviderAdapter_9_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying_;
public:
    ProviderAdapter_9_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_9_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class ProviderAdapter_9_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying_;
public:
    ProviderAdapter_9_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_9_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ProviderAdapter_10_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying_;
public:
    ProviderAdapter_10_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_10_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ProviderAdapter_10_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying_;
public:
    ProviderAdapter_10_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_10_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ProviderAdapter_10_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying_;
public:
    ProviderAdapter_10_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_10_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ProviderAdapter_10_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying_;
public:
    ProviderAdapter_10_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_10_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ProviderAdapter_10_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying_;
public:
    ProviderAdapter_10_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_10_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ProviderAdapter_10_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying_;
public:
    ProviderAdapter_10_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_10_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ProviderAdapter_10_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying_;
public:
    ProviderAdapter_10_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_10_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ProviderAdapter_10_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying_;
public:
    ProviderAdapter_10_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_10_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ProviderAdapter_10_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying_;
public:
    ProviderAdapter_10_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_10_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ProviderAdapter_10_9 : public Provider<A9> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying_;
public:
    ProviderAdapter_10_9(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *underlying) : Provider<A9>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_10_9() = default;
    virtual Certificate<A9> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A9>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(cert));
        } else {
            return Certificate<A9>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr);
        }
    }
    virtual Data<A9> next(Certificate<A9> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 9) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) -> A9 {return std::get<9>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProviderAdapter_11_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying_;
public:
    ProviderAdapter_11_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_11_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProviderAdapter_11_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying_;
public:
    ProviderAdapter_11_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_11_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProviderAdapter_11_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying_;
public:
    ProviderAdapter_11_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_11_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProviderAdapter_11_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying_;
public:
    ProviderAdapter_11_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_11_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProviderAdapter_11_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying_;
public:
    ProviderAdapter_11_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_11_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProviderAdapter_11_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying_;
public:
    ProviderAdapter_11_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_11_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProviderAdapter_11_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying_;
public:
    ProviderAdapter_11_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_11_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProviderAdapter_11_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying_;
public:
    ProviderAdapter_11_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_11_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProviderAdapter_11_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying_;
public:
    ProviderAdapter_11_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_11_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProviderAdapter_11_9 : public Provider<A9> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying_;
public:
    ProviderAdapter_11_9(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying) : Provider<A9>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_11_9() = default;
    virtual Certificate<A9> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A9>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>(cert));
        } else {
            return Certificate<A9>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr);
        }
    }
    virtual Data<A9> next(Certificate<A9> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 9) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) -> A9 {return std::get<9>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProviderAdapter_11_10 : public Provider<A10> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying_;
public:
    ProviderAdapter_11_10(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *underlying) : Provider<A10>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_11_10() = default;
    virtual Certificate<A10> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A10>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>(cert));
        } else {
            return Certificate<A10>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr);
        }
    }
    virtual Data<A10> next(Certificate<A10> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 10) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) -> A10 {return std::get<10>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_9 : public Provider<A9> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_9(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A9>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_9() = default;
    virtual Certificate<A9> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A9>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A9>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A9> next(Certificate<A9> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 9) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A9 {return std::get<9>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_10 : public Provider<A10> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_10(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A10>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_10() = default;
    virtual Certificate<A10> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A10>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A10>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A10> next(Certificate<A10> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 10) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A10 {return std::get<10>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProviderAdapter_12_11 : public Provider<A11> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying_;
public:
    ProviderAdapter_12_11(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *underlying) : Provider<A11>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_12_11() = default;
    virtual Certificate<A11> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A11>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>(cert));
        } else {
            return Certificate<A11>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr);
        }
    }
    virtual Data<A11> next(Certificate<A11> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 11) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) -> A11 {return std::get<11>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_9 : public Provider<A9> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_9(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A9>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_9() = default;
    virtual Certificate<A9> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A9>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A9>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A9> next(Certificate<A9> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 9) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A9 {return std::get<9>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_10 : public Provider<A10> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_10(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A10>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_10() = default;
    virtual Certificate<A10> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A10>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A10>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A10> next(Certificate<A10> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 10) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A10 {return std::get<10>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_11 : public Provider<A11> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_11(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A11>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_11() = default;
    virtual Certificate<A11> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A11>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A11>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A11> next(Certificate<A11> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 11) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A11 {return std::get<11>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProviderAdapter_13_12 : public Provider<A12> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying_;
public:
    ProviderAdapter_13_12(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *underlying) : Provider<A12>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_13_12() = default;
    virtual Certificate<A12> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A12>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>(cert));
        } else {
            return Certificate<A12>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr);
        }
    }
    virtual Data<A12> next(Certificate<A12> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 12) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) -> A12 {return std::get<12>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_9 : public Provider<A9> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_9(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A9>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_9() = default;
    virtual Certificate<A9> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A9>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A9>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A9> next(Certificate<A9> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 9) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A9 {return std::get<9>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_10 : public Provider<A10> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_10(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A10>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_10() = default;
    virtual Certificate<A10> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A10>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A10>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A10> next(Certificate<A10> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 10) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A10 {return std::get<10>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_11 : public Provider<A11> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_11(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A11>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_11() = default;
    virtual Certificate<A11> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A11>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A11>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A11> next(Certificate<A11> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 11) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A11 {return std::get<11>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_12 : public Provider<A12> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_12(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A12>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_12() = default;
    virtual Certificate<A12> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A12>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A12>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A12> next(Certificate<A12> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 12) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A12 {return std::get<12>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProviderAdapter_14_13 : public Provider<A13> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying_;
public:
    ProviderAdapter_14_13(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *underlying) : Provider<A13>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_14_13() = default;
    virtual Certificate<A13> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A13>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>(cert));
        } else {
            return Certificate<A13>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr);
        }
    }
    virtual Data<A13> next(Certificate<A13> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 13) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) -> A13 {return std::get<13>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_9 : public Provider<A9> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_9(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A9>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_9() = default;
    virtual Certificate<A9> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A9>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A9>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A9> next(Certificate<A9> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 9) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A9 {return std::get<9>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_10 : public Provider<A10> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_10(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A10>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_10() = default;
    virtual Certificate<A10> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A10>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A10>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A10> next(Certificate<A10> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 10) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A10 {return std::get<10>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_11 : public Provider<A11> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_11(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A11>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_11() = default;
    virtual Certificate<A11> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A11>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A11>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A11> next(Certificate<A11> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 11) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A11 {return std::get<11>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_12 : public Provider<A12> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_12(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A12>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_12() = default;
    virtual Certificate<A12> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A12>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A12>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A12> next(Certificate<A12> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 12) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A12 {return std::get<12>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_13 : public Provider<A13> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_13(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A13>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_13() = default;
    virtual Certificate<A13> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A13>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A13>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A13> next(Certificate<A13> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 13) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A13 {return std::get<13>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProviderAdapter_15_14 : public Provider<A14> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying_;
public:
    ProviderAdapter_15_14(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *underlying) : Provider<A14>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_15_14() = default;
    virtual Certificate<A14> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A14>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>(cert));
        } else {
            return Certificate<A14>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr);
        }
    }
    virtual Data<A14> next(Certificate<A14> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 14) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) -> A14 {return std::get<14>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_9 : public Provider<A9> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_9(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A9>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_9() = default;
    virtual Certificate<A9> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A9>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A9>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A9> next(Certificate<A9> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 9) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A9 {return std::get<9>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_10 : public Provider<A10> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_10(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A10>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_10() = default;
    virtual Certificate<A10> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A10>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A10>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A10> next(Certificate<A10> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 10) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A10 {return std::get<10>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_11 : public Provider<A11> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_11(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A11>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_11() = default;
    virtual Certificate<A11> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A11>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A11>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A11> next(Certificate<A11> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 11) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A11 {return std::get<11>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_12 : public Provider<A12> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_12(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A12>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_12() = default;
    virtual Certificate<A12> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A12>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A12>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A12> next(Certificate<A12> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 12) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A12 {return std::get<12>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_13 : public Provider<A13> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_13(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A13>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_13() = default;
    virtual Certificate<A13> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A13>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A13>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A13> next(Certificate<A13> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 13) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A13 {return std::get<13>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_14 : public Provider<A14> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_14(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A14>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_14() = default;
    virtual Certificate<A14> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A14>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A14>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A14> next(Certificate<A14> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 14) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A14 {return std::get<14>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProviderAdapter_16_15 : public Provider<A15> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying_;
public:
    ProviderAdapter_16_15(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *underlying) : Provider<A15>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_16_15() = default;
    virtual Certificate<A15> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A15>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>(cert));
        } else {
            return Certificate<A15>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr);
        }
    }
    virtual Data<A15> next(Certificate<A15> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 15) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) -> A15 {return std::get<15>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_9 : public Provider<A9> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_9(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A9>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_9() = default;
    virtual Certificate<A9> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A9>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A9>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A9> next(Certificate<A9> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 9) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A9 {return std::get<9>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_10 : public Provider<A10> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_10(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A10>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_10() = default;
    virtual Certificate<A10> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A10>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A10>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A10> next(Certificate<A10> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 10) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A10 {return std::get<10>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_11 : public Provider<A11> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_11(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A11>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_11() = default;
    virtual Certificate<A11> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A11>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A11>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A11> next(Certificate<A11> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 11) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A11 {return std::get<11>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_12 : public Provider<A12> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_12(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A12>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_12() = default;
    virtual Certificate<A12> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A12>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A12>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A12> next(Certificate<A12> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 12) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A12 {return std::get<12>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_13 : public Provider<A13> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_13(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A13>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_13() = default;
    virtual Certificate<A13> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A13>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A13>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A13> next(Certificate<A13> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 13) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A13 {return std::get<13>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_14 : public Provider<A14> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_14(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A14>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_14() = default;
    virtual Certificate<A14> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A14>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A14>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A14> next(Certificate<A14> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 14) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A14 {return std::get<14>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_15 : public Provider<A15> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_15(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A15>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_15() = default;
    virtual Certificate<A15> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A15>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A15>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A15> next(Certificate<A15> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 15) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A15 {return std::get<15>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProviderAdapter_17_16 : public Provider<A16> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying_;
public:
    ProviderAdapter_17_16(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *underlying) : Provider<A16>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_17_16() = default;
    virtual Certificate<A16> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A16>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>(cert));
        } else {
            return Certificate<A16>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr);
        }
    }
    virtual Data<A16> next(Certificate<A16> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 16) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) -> A16 {return std::get<16>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_9 : public Provider<A9> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_9(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A9>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_9() = default;
    virtual Certificate<A9> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A9>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A9>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A9> next(Certificate<A9> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 9) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A9 {return std::get<9>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_10 : public Provider<A10> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_10(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A10>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_10() = default;
    virtual Certificate<A10> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A10>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A10>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A10> next(Certificate<A10> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 10) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A10 {return std::get<10>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_11 : public Provider<A11> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_11(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A11>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_11() = default;
    virtual Certificate<A11> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A11>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A11>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A11> next(Certificate<A11> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 11) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A11 {return std::get<11>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_12 : public Provider<A12> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_12(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A12>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_12() = default;
    virtual Certificate<A12> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A12>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A12>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A12> next(Certificate<A12> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 12) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A12 {return std::get<12>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_13 : public Provider<A13> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_13(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A13>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_13() = default;
    virtual Certificate<A13> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A13>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A13>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A13> next(Certificate<A13> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 13) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A13 {return std::get<13>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_14 : public Provider<A14> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_14(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A14>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_14() = default;
    virtual Certificate<A14> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A14>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A14>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A14> next(Certificate<A14> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 14) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A14 {return std::get<14>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_15 : public Provider<A15> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_15(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A15>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_15() = default;
    virtual Certificate<A15> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A15>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A15>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A15> next(Certificate<A15> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 15) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A15 {return std::get<15>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_16 : public Provider<A16> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_16(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A16>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_16() = default;
    virtual Certificate<A16> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A16>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A16>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A16> next(Certificate<A16> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 16) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A16 {return std::get<16>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProviderAdapter_18_17 : public Provider<A17> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying_;
public:
    ProviderAdapter_18_17(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *underlying) : Provider<A17>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_18_17() = default;
    virtual Certificate<A17> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A17>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>(cert));
        } else {
            return Certificate<A17>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr);
        }
    }
    virtual Data<A17> next(Certificate<A17> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 17) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) -> A17 {return std::get<17>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_9 : public Provider<A9> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_9(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A9>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_9() = default;
    virtual Certificate<A9> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A9>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A9>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A9> next(Certificate<A9> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 9) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A9 {return std::get<9>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_10 : public Provider<A10> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_10(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A10>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_10() = default;
    virtual Certificate<A10> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A10>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A10>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A10> next(Certificate<A10> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 10) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A10 {return std::get<10>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_11 : public Provider<A11> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_11(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A11>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_11() = default;
    virtual Certificate<A11> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A11>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A11>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A11> next(Certificate<A11> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 11) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A11 {return std::get<11>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_12 : public Provider<A12> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_12(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A12>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_12() = default;
    virtual Certificate<A12> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A12>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A12>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A12> next(Certificate<A12> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 12) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A12 {return std::get<12>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_13 : public Provider<A13> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_13(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A13>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_13() = default;
    virtual Certificate<A13> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A13>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A13>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A13> next(Certificate<A13> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 13) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A13 {return std::get<13>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_14 : public Provider<A14> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_14(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A14>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_14() = default;
    virtual Certificate<A14> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A14>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A14>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A14> next(Certificate<A14> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 14) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A14 {return std::get<14>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_15 : public Provider<A15> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_15(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A15>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_15() = default;
    virtual Certificate<A15> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A15>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A15>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A15> next(Certificate<A15> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 15) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A15 {return std::get<15>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_16 : public Provider<A16> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_16(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A16>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_16() = default;
    virtual Certificate<A16> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A16>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A16>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A16> next(Certificate<A16> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 16) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A16 {return std::get<16>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_17 : public Provider<A17> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_17(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A17>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_17() = default;
    virtual Certificate<A17> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A17>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A17>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A17> next(Certificate<A17> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 17) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A17 {return std::get<17>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProviderAdapter_19_18 : public Provider<A18> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying_;
public:
    ProviderAdapter_19_18(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *underlying) : Provider<A18>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_19_18() = default;
    virtual Certificate<A18> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A18>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>(cert));
        } else {
            return Certificate<A18>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr);
        }
    }
    virtual Data<A18> next(Certificate<A18> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 18) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) -> A18 {return std::get<18>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_0 : public Provider<A0> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_0(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A0>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_0() = default;
    virtual Certificate<A0> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A0>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A0>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A0> next(Certificate<A0> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 0) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A0 {return std::get<0>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_1 : public Provider<A1> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_1(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A1>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_1() = default;
    virtual Certificate<A1> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A1>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A1>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A1> next(Certificate<A1> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 1) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A1 {return std::get<1>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_2 : public Provider<A2> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_2(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A2>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_2() = default;
    virtual Certificate<A2> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A2>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A2>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A2> next(Certificate<A2> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 2) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A2 {return std::get<2>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_3 : public Provider<A3> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_3(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A3>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_3() = default;
    virtual Certificate<A3> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A3>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A3>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A3> next(Certificate<A3> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 3) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A3 {return std::get<3>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_4 : public Provider<A4> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_4(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A4>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_4() = default;
    virtual Certificate<A4> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A4>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A4>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A4> next(Certificate<A4> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 4) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A4 {return std::get<4>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_5 : public Provider<A5> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_5(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A5>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_5() = default;
    virtual Certificate<A5> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A5>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A5>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A5> next(Certificate<A5> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 5) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A5 {return std::get<5>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_6 : public Provider<A6> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_6(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A6>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_6() = default;
    virtual Certificate<A6> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A6>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A6>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A6> next(Certificate<A6> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 6) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A6 {return std::get<6>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_7 : public Provider<A7> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_7(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A7>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_7() = default;
    virtual Certificate<A7> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A7>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A7>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A7> next(Certificate<A7> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 7) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A7 {return std::get<7>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_8 : public Provider<A8> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_8(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A8>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_8() = default;
    virtual Certificate<A8> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A8>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A8>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A8> next(Certificate<A8> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 8) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A8 {return std::get<8>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_9 : public Provider<A9> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_9(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A9>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_9() = default;
    virtual Certificate<A9> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A9>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A9>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A9> next(Certificate<A9> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 9) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A9 {return std::get<9>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_10 : public Provider<A10> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_10(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A10>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_10() = default;
    virtual Certificate<A10> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A10>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A10>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A10> next(Certificate<A10> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 10) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A10 {return std::get<10>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_11 : public Provider<A11> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_11(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A11>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_11() = default;
    virtual Certificate<A11> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A11>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A11>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A11> next(Certificate<A11> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 11) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A11 {return std::get<11>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_12 : public Provider<A12> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_12(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A12>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_12() = default;
    virtual Certificate<A12> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A12>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A12>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A12> next(Certificate<A12> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 12) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A12 {return std::get<12>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_13 : public Provider<A13> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_13(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A13>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_13() = default;
    virtual Certificate<A13> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A13>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A13>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A13> next(Certificate<A13> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 13) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A13 {return std::get<13>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_14 : public Provider<A14> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_14(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A14>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_14() = default;
    virtual Certificate<A14> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A14>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A14>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A14> next(Certificate<A14> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 14) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A14 {return std::get<14>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_15 : public Provider<A15> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_15(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A15>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_15() = default;
    virtual Certificate<A15> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A15>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A15>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A15> next(Certificate<A15> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 15) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A15 {return std::get<15>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_16 : public Provider<A16> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_16(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A16>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_16() = default;
    virtual Certificate<A16> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A16>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A16>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A16> next(Certificate<A16> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 16) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A16 {return std::get<16>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_17 : public Provider<A17> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_17(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A17>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_17() = default;
    virtual Certificate<A17> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A17>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A17>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A17> next(Certificate<A17> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 17) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A17 {return std::get<17>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_18 : public Provider<A18> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_18(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A18>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_18() = default;
    virtual Certificate<A18> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A18>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A18>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A18> next(Certificate<A18> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 18) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A18 {return std::get<18>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProviderAdapter_20_19 : public Provider<A19> {
private:
    Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying_;
public:
    ProviderAdapter_20_19(Provider<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *underlying) : Provider<A19>(), underlying_(underlying) {}
    virtual ~ProviderAdapter_20_19() = default;
    virtual Certificate<A19> poll() override final {
        auto cert = underlying_->poll();
        if (cert.check()) {
            return Certificate<A19>(cert.timePoint(), this, new Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>(cert));
        } else {
            return Certificate<A19>(std::nullopt, this, (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr);
        }
    }
    virtual Data<A19> next(Certificate<A19> &&cert) override final {
        if (cert.check()) {
            auto *c = (Certificate<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) cert.additionalInfo();
            if (c == nullptr) {
                return std::nullopt;
            }
            if (!c->check()) {
                return std::nullopt;
            }
            auto d = underlying_->next(std::move(*c));
            delete c;
            if (!d) {
                return std::nullopt;
            }
            if (d->timedData.value.index() != 19) {
                return std::nullopt;
            }
            return std::move(*d).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) -> A19 {return std::get<19>(std::move(x));}, true);
        } else {
            return std::nullopt;
        }
    }
};