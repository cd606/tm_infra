template <class A0, class A1, class B>
static ActionCheckData create(Action<std::variant<A0,A1>,B> *f, std::string const &n)
{
    ActionCheckData d {n, 2};
    d.isImporter = false;
    d.isExporter = false;
    return d;
}
template <class A0, class A1, class A2, class B>
static ActionCheckData create(Action<std::variant<A0,A1,A2>,B> *f, std::string const &n)
{
    ActionCheckData d {n, 3};
    d.isImporter = false;
    d.isExporter = false;
    return d;
}
template <class A0, class A1, class A2, class A3, class B>
static ActionCheckData create(Action<std::variant<A0,A1,A2,A3>,B> *f, std::string const &n)
{
    ActionCheckData d {n, 4};
    d.isImporter = false;
    d.isExporter = false;
    return d;
}
template <class A0, class A1, class A2, class A3, class A4, class B>
static ActionCheckData create(Action<std::variant<A0,A1,A2,A3,A4>,B> *f, std::string const &n)
{
    ActionCheckData d {n, 5};
    d.isImporter = false;
    d.isExporter = false;
    return d;
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
static ActionCheckData create(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> *f, std::string const &n)
{
    ActionCheckData d {n, 6};
    d.isImporter = false;
    d.isExporter = false;
    return d;
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
static ActionCheckData create(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> *f, std::string const &n)
{
    ActionCheckData d {n, 7};
    d.isImporter = false;
    d.isExporter = false;
    return d;
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
static ActionCheckData create(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> *f, std::string const &n)
{
    ActionCheckData d {n, 8};
    d.isImporter = false;
    d.isExporter = false;
    return d;
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
static ActionCheckData create(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> *f, std::string const &n)
{
    ActionCheckData d {n, 9};
    d.isImporter = false;
    d.isExporter = false;
    return d;
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
static ActionCheckData create(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> *f, std::string const &n)
{
    ActionCheckData d {n, 10};
    d.isImporter = false;
    d.isExporter = false;
    return d;
}