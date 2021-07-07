#ifndef TM_KIT_INFRA_KLEISLI_SEQUENCE_HPP_
#define TM_KIT_INFRA_KLEISLI_SEQUENCE_HPP_

#include <tm_kit/infra/GenericLift.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    
    template <class M>
    class KleisliSequence {
    public:
        template <class FirstF, class... Fs>
        static auto seq(FirstF &&firstF, Fs &&... fs) {
            if constexpr (sizeof...(Fs) == 0) {
                return GenericLift<M>::liftKU(std::move(firstF));
            } else {
                return KleisliUtils<M>::compose(
                    GenericLift<M>::liftKU(std::move(firstF))
                    , seq<Fs...>(std::forward<Fs>(fs)...)
                );
            }
        }
    };
    
} } } }

#endif