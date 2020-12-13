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