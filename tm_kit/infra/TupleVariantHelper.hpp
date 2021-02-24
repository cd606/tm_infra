#ifndef TM_KIT_INFRA_TUPLE_VARIANT_HELPER_HPP_
#define TM_KIT_INFRA_TUPLE_VARIANT_HELPER_HPP_

#include <tuple>
#include <variant>

namespace dev { namespace cd606 { namespace tm { namespace infra {

    template <class A, class B>
    class TupleConcatHelper {};
    template <class A, class... Bs>
    class TupleConcatHelper<
        A, std::tuple<Bs...>
    > {
    public:
        using TheType = std::tuple<A,Bs...>;
    };

    template <class A, class B>
    using TupleConcat = typename TupleConcatHelper<A,B>::TheType;

    template <class A, class B>
    class VariantConcatHelper {};
    template <class A, class... Bs>
    class VariantConcatHelper<
        A, std::variant<Bs...>
    > {
    public:
        using TheType = std::variant<A,Bs...>;
    };

    template <class A, class B>
    using VariantConcat = typename VariantConcatHelper<A,B>::TheType;

    template <std::size_t N, class T>
    class TupleRepeatHelper {
    public:
        using TheType = TupleConcat<T, typename TupleRepeatHelper<N-1,T>::TheType>;
    };
    template <class T>
    class TupleRepeatHelper<1,T> {
    public:
        using TheType = std::tuple<T>;
    };
    
    template <std::size_t N, class T>
    using TupleRepeat = typename TupleRepeatHelper<N,T>::TheType;

    template <std::size_t N, class T>
    class VariantRepeatHelper {
    public:
        using TheType = VariantConcat<T, typename VariantRepeatHelper<N-1,T>::TheType>;
    };
    template <class T>
    class VariantRepeatHelper<1,T> {
    public:
        using TheType = std::variant<T>;
    };
    
    template <std::size_t N, class T>
    using VariantRepeat = typename VariantRepeatHelper<N,T>::TheType;

    template <std::size_t N, std::size_t Idx, class T>
    class DispatchVariantConstructHelper {
    public:
        static VariantRepeat<N, T> construct(std::size_t idx, T &&t) {
            if constexpr (Idx<0 || Idx>=N) {
                return VariantRepeat<N, T> {};
            } else {
                if (Idx == idx) {
                    return VariantRepeat<N, T> {std::in_place_index<Idx>, std::move(t)};
                } else {
                    return DispatchVariantConstructHelper<N, Idx+1, T>::construct(idx, std::move(t));
                }
            }
        }
    };
    template <std::size_t N, class T>
    VariantRepeat<N, T> dispatchVariantConstruct(std::size_t idx, T &&t) {
        return DispatchVariantConstructHelper<N,0,T>::construct(idx, std::move(t));
    }
    template <std::size_t N, std::size_t Idx, class S, class T>
    class AugmentedDispatchVariantConstructHelper {
    public:
        static VariantConcat<S, VariantRepeat<N, T>> construct(std::size_t idx, T &&t) {
            if constexpr (Idx<0 || Idx>=N) {
                return VariantConcat<S, VariantRepeat<N, T>> {};
            } else {
                if (Idx == idx) {
                    return VariantConcat<S, VariantRepeat<N, T>> {std::in_place_index<Idx+1>, std::move(t)};
                } else {
                    return AugmentedDispatchVariantConstructHelper<N, Idx+1, S, T>::construct(idx, std::move(t));
                }
            }
        }
    };
    template <std::size_t N, class S, class T>
    VariantConcat<S, VariantRepeat<N, T>> augmentedDispatchVariantConstruct(std::size_t idx, T &&t) {
        return AugmentedDispatchVariantConstructHelper<N,0,S,T>::construct(idx, std::move(t));
    }
} } } }

#endif