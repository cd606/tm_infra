#ifndef TM_KIT_INFRA_INT_ID_COMPONENT_HPP_
#define TM_KIT_INFRA_INT_ID_COMPONENT_HPP_

namespace dev { namespace cd606 { namespace tm { namespace infra {

template <class IntType = uint64_t>
class IntIDComponent {
private:
    static IntType id;
public:
    using IDType = IntType;
    using IDHash = std::hash<IntType>;
    static IDType new_id() {
        return (id++);
    }
    static std::string id_to_string(IDType const &id) {
        return std::to_string(id);
    }
    static IDType id_from_string(std::string const &s) {
        return std::stoi(s);
    }
    static std::string id_to_bytes(IDType const &id) {
        char buf[sizeof(IntType)];
        std::memcpy(buf, &id, sizeof(IntType));
        return std::string(buf, buf+sizeof(IntType));
    }
    static bool less_comparison_id(IDType const &a, IDType const &b) {
        return std::less<IntType>()(a,b);
    }
};

template <class IntType>
IntType IntIDComponent<IntType>::id = 0;

} } } }

#endif