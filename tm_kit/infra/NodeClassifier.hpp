#ifndef TM_KIT_INFRA_NODE_CLASSIFIER_HPP_
#define TM_KIT_INFRA_NODE_CLASSIFIER_HPP_

#if defined(_MSC_VER)
    #define TM_KIT_INFRA_NODE_CLASSIFIER_SIMPLIFIED 0
#elif defined(__llvm__)
    #if defined(__clang_major__)
        #if __clang_major__ >= 12
            #define TM_KIT_INFRA_NODE_CLASSIFIER_SIMPLIFIED 1
        #else
            #define TM_KIT_INFRA_NODE_CLASSIFIER_SIMPLIFIED 0
        #endif
    #else
        #define TM_KIT_INFRA_NODE_CLASSIFIER_SIMPLIFIED 0
    #endif
#elif defined(__GNUC__)
    #if __GNUC__ >= 11
        #define TM_KIT_INFRA_NODE_CLASSIFIER_SIMPLIFIED 1
    #else
        #define TM_KIT_INFRA_NODE_CLASSIFIER_SIMPLIFIED 0
    #endif
#else
    #define TM_KIT_INFRA_NODE_CLASSIFIER_SIMPLIFIED 0
#endif

namespace dev { namespace cd606 { namespace tm { namespace infra {
    template <class M>
    class NodeClassifier {
#if TM_KIT_INFRA_NODE_CLASSIFIER_SIMPLIFIED == 1
    public:
        template <class X>
        struct IsImporter {
            static constexpr bool Value = false;
        };
        template <class T>
        struct IsImporter<typename M::template Importer<T>> {
            static constexpr bool Value = true;
        };
        template <class X>
        struct IsExporter {
            static constexpr bool Value = false;
        };
        template <class T>
        struct IsExporter<typename M::template Exporter<T>> {
            static constexpr bool Value = true;
        };
        template <class X>
        struct IsAction {
            static constexpr bool Value = false;
        };
        template <class A, class B>
        struct IsAction<typename M::template Action<A,B>> {
            static constexpr bool Value = true;
        };
        template <class X>
        struct IsOnOrderFacility {
            static constexpr bool Value = false;
        };
        template <class A, class B>
        struct IsOnOrderFacility<typename M::template OnOrderFacility<A,B>> {
            static constexpr bool Value = true;
        };
        template <class X>
        struct IsLocalOnOrderFacility {
            static constexpr bool Value = false;
        };
        template <class A, class B, class C>
        struct IsLocalOnOrderFacility<typename M::template LocalOnOrderFacility<A,B,C>> {
            static constexpr bool Value = true;
        };
        template <class X>
        struct IsOnOrderFacilityWithExternalEffects {
            static constexpr bool Value = false;
        };
        template <class A, class B, class C>
        struct IsOnOrderFacilityWithExternalEffects<typename M::template OnOrderFacilityWithExternalEffects<A,B,C>> {
            static constexpr bool Value = true;
        };
        template <class X>
        struct IsVIEOnOrderFacility {
            static constexpr bool Value = false;
        };
        template <class A, class B, class C, class D>
        struct IsVIEOnOrderFacility<typename M::template VIEOnOrderFacility<A,B,C,D>> {
            static constexpr bool Value = true;
        };
#else
    private:
        template <class T>
        struct TrueType : std::true_type {};

        template <class T>
        static auto hasDataType(int) -> TrueType<typename T::DataType>;
        template <class T>
        static auto hasDataType(long) -> std::false_type;

        template <class T>
        static auto hasInputType(int) -> TrueType<typename T::InputType>;
        template <class T>
        static auto hasInputType(long) -> std::false_type;
        
        template <class T>
        static auto hasOutputType(int) -> TrueType<typename T::OutputType>;
        template <class T>
        static auto hasOutputType(long) -> std::false_type;

        template <class T>
        static auto hasExtraInputType(int) -> TrueType<typename T::ExtraInputType>;
        template <class T>
        static auto hasExtraInputType(long) -> std::false_type;

        template <class T>
        static auto hasExtraOutputType(int) -> TrueType<typename T::ExtraOutputType>;
        template <class T>
        static auto hasExtraOutputType(long) -> std::false_type;

        template <class X>
        struct IsOneWayHolder {
            static constexpr bool Value = (
                decltype(hasDataType<X>(0))::value
                && !decltype(hasInputType<X>(0))::value
                && !decltype(hasOutputType<X>(0))::value
                && !decltype(hasExtraInputType<X>(0))::value
                && !decltype(hasExtraOutputType<X>(0))::value
            );
        };
        template <class X>
        struct IsTwoWayHolder {
            static constexpr bool Value = (
                !decltype(hasDataType<X>(0))::value
                && decltype(hasInputType<X>(0))::value
                && decltype(hasOutputType<X>(0))::value
                && !decltype(hasExtraInputType<X>(0))::value
                && !decltype(hasExtraOutputType<X>(0))::value
            );
        };
        template <class X>
        struct IsThreeWayHolder {
            static constexpr bool Value = (
                decltype(hasDataType<X>(0))::value
                && decltype(hasInputType<X>(0))::value
                && decltype(hasOutputType<X>(0))::value
                && !decltype(hasExtraInputType<X>(0))::value
                && !decltype(hasExtraOutputType<X>(0))::value
            );
        };
        template <class X>
        struct IsFourWayHolder {
            static constexpr bool Value = (
                !decltype(hasDataType<X>(0))::value
                && decltype(hasInputType<X>(0))::value
                && decltype(hasOutputType<X>(0))::value
                && decltype(hasExtraInputType<X>(0))::value
                && decltype(hasExtraOutputType<X>(0))::value
            );
        };
    private:
        template <class X, bool B>
        struct IsImporterImpl2 {
        };
        template <class X>
        struct IsImporterImpl2<X, true> {
            static constexpr bool Value = std::is_same_v<
                X, typename M::template Importer<typename X::DataType>
            >;
        };
        template <class X>
        struct IsImporterImpl2<X, false> {
            static constexpr bool Value = false;
        };
        template <class X, bool B>
        struct IsImporterImpl {
        };
        template <class X>
        struct IsImporterImpl<X, true> {
            static constexpr bool Value = IsImporterImpl2<X, (!is_keyed_data_v<typename X::DataType> || is_monostate_keyed_data_v<typename X::DataType>)>::Value;
        };
        template <class X>
        struct IsImporterImpl<X, false> {
            static constexpr bool Value = false;
        };
    public:
        template <class X>
        struct IsImporter {
            static constexpr bool Value = IsImporterImpl<X, IsOneWayHolder<X>::Value>::Value;
        };
    private:
        template <class X, bool B>
        struct IsExporterImpl2 {
        };
        template <class X>
        struct IsExporterImpl2<X, true> {
            static constexpr bool Value = std::is_same_v<
                X, typename M::template Exporter<typename X::DataType>
            >;
        };
        template <class X>
        struct IsExporterImpl2<X, false> {
            static constexpr bool Value = false;
        };
        template <class X, bool B>
        struct IsExporterImpl {
        };
        template <class X>
        struct IsExporterImpl<X, true> {
            static constexpr bool Value = IsExporterImpl2<X, !withtime_utils::IsVariant<typename X::DataType>::Value>::Value;
        };
        template <class X>
        struct IsExporterImpl<X, false> {
            static constexpr bool Value = false;
        };
    public:
        template <class X>
        struct IsExporter {
            static constexpr bool Value = IsExporterImpl<X, IsOneWayHolder<X>::Value>::Value;
        };
    private:
        template <class X, bool B>
        struct IsActionImpl2 {
        };
        template <class X>
        struct IsActionImpl2<X, true> {
            static constexpr bool Value = std::is_same_v<
                X, typename M::template Action<typename X::InputType, typename X::OutputType>
            >;
        };
        template <class X>
        struct IsActionImpl2<X, false> {
            static constexpr bool Value = false;
        };
        template <class X, bool B>
        struct IsActionImpl {
        };
        template <class X>
        struct IsActionImpl<X, true> {
            static constexpr bool Value = IsActionImpl2<
                X, 
                !(
                    is_key_v<typename X::InputType> && is_keyed_data_v<typename X::OutputType> && !is_monostate_keyed_data_v<typename X::OutputType>
                )
            >::Value;
        };
        template <class X>
        struct IsActionImpl<X, false> {
            static constexpr bool Value = false;
        };
    public:
        template <class X>
        struct IsAction {
            static constexpr bool Value = IsActionImpl<X, IsTwoWayHolder<X>::Value>::Value;
        };
    private:
        template <class X, bool B>
        struct IsOnOrderFacilityImpl {
        };
        template <class X>
        struct IsOnOrderFacilityImpl<X, true> {
            static constexpr bool Value = std::is_same_v<
                X, typename M::template OnOrderFacility<typename X::InputType, typename X::OutputType>
            >;
        };
        template <class X>
        struct IsOnOrderFacilityImpl<X, false> {
            static constexpr bool Value = false;
        };
    public:
        template <class X>
        struct IsOnOrderFacility {
            static constexpr bool Value = IsOnOrderFacilityImpl<X, IsTwoWayHolder<X>::Value>::Value;
        };
    private:
        template <class X, bool B>
        struct IsLocalOnOrderFacilityImpl2 {
        };
        template <class X>
        struct IsLocalOnOrderFacilityImpl2<X, true> {
            static constexpr bool Value = std::is_same_v<
                X, typename M::template LocalOnOrderFacility<typename X::InputType, typename X::OutputType, typename X::DataType>
            >;
        };
        template <class X>
        struct IsLocalOnOrderFacilityImpl2<X, false> {
            static constexpr bool Value = false;
        };
        template <class X, bool B>
        struct IsLocalOnOrderFacilityImpl {
        };
        template <class X>
        struct IsLocalOnOrderFacilityImpl<X, true> {
            static constexpr bool Value = IsLocalOnOrderFacilityImpl2<
                X, 
                !withtime_utils::IsVariant<typename X::DataType>::Value
            >::Value;
        };
        template <class X>
        struct IsLocalOnOrderFacilityImpl<X, false> {
            static constexpr bool Value = false;
        };
    public:
        template <class X>
        struct IsLocalOnOrderFacility {
            static constexpr bool Value = IsLocalOnOrderFacilityImpl<X, IsThreeWayHolder<X>::Value>::Value;
        };
    private:
        template <class X, bool B>
        struct IsOnOrderFacilityWithExternalEffectsImpl2 {
        };
        template <class X>
        struct IsOnOrderFacilityWithExternalEffectsImpl2<X, true> {
            static constexpr bool Value = std::is_same_v<
                X, typename M::template OnOrderFacilityWithExternalEffects<typename X::InputType, typename X::OutputType, typename X::DataType>
            >;
        };
        template <class X>
        struct IsOnOrderFacilityWithExternalEffectsImpl2<X, false> {
            static constexpr bool Value = false;
        };
        template <class X, bool B>
        struct IsOnOrderFacilityWithExternalEffectsImpl {
        };
        template <class X>
        struct IsOnOrderFacilityWithExternalEffectsImpl<X, true> {
            static constexpr bool Value = IsOnOrderFacilityWithExternalEffectsImpl2<
                X, 
                (!is_keyed_data_v<typename X::DataType> || is_monostate_keyed_data_v<typename X::DataType>)
            >::Value;
        };
        template <class X>
        struct IsOnOrderFacilityWithExternalEffectsImpl<X, false> {
            static constexpr bool Value = false;
        };
    public:
        template <class X>
        struct IsOnOrderFacilityWithExternalEffects {
            static constexpr bool Value = IsOnOrderFacilityWithExternalEffectsImpl<X, IsThreeWayHolder<X>::Value>::Value;
        };
    private:
        template <class X, bool B>
        struct IsVIEOnOrderFacilityImpl2 {
        };
        template <class X>
        struct IsVIEOnOrderFacilityImpl2<X, true> {
            static constexpr bool Value = std::is_same_v<
                X, typename M::template VIEOnOrderFacility<typename X::InputType, typename X::OutputType, typename X::ExtraInputType, typename X::ExtraOutputType>
            >;
        };
        template <class X>
        struct IsVIEOnOrderFacilityImpl2<X, false> {
            static constexpr bool Value = false;
        };
        template <class X, bool B>
        struct IsVIEOnOrderFacilityImpl {
        };
        template <class X>
        struct IsVIEOnOrderFacilityImpl<X, true> {
            static constexpr bool Value = IsVIEOnOrderFacilityImpl2<
                X, 
                (
                    !withtime_utils::IsVariant<typename X::ExtraInputType>::Value
                    && (!is_keyed_data_v<typename X::ExtraOutputType> || is_monostate_keyed_data_v<typename X::ExtraOutputType>)
                )
            >::Value;
        };
        template <class X>
        struct IsVIEOnOrderFacilityImpl<X, false> {
            static constexpr bool Value = false;
        };
    public:
        template <class X>
        struct IsVIEOnOrderFacility {
            static constexpr bool Value = IsVIEOnOrderFacilityImpl<X, IsFourWayHolder<X>::Value>::Value;
        };
#endif
    };
} } } }

#undef TM_KIT_INFRA_NODE_CLASSIFIER_SIMPLIFIED

#endif