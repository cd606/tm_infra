#ifndef TM_KIT_INFRA_STOPPABLE_PRODUCER_HPP_
#define TM_KIT_INFRA_STOPPABLE_PRODUCER_HPP_

namespace dev { namespace cd606 { namespace tm { namespace infra {
    template <uint8_t N>
    class IStoppableProducer {
    private:
        std::atomic<uint32_t> stoppedFlag_ = 0;
    public:
        void stopProducer() {
            stoppedFlag_ = (uint32_t) 0xffffffff;
        }
        void restartProducer() {
            stoppedFlag_ = 0;
        }
        void stopProducer(uint8_t which) {
            if (which < N) {
                stoppedFlag_ = (stoppedFlag_ | (((uint32_t) 1) << which));
            }
        }
        void restartProducer(uint8_t which) {
            if (which < N) {
                stoppedFlag_ = (stoppedFlag_ & ~(((uint32_t) 1) << which));
            }
        }
        bool producerIsStopped(uint8_t which) const {
            if (which < N) {
                return ((stoppedFlag_ & (((uint32_t) 1) << which)) != 0);
            } else {
                return false;
            }
        }
        std::vector<std::string> producerStoppedStatus() const {
            std::vector<std::string> ret;
            for (uint8_t which=0; which < N; ++which) {
                if ((stoppedFlag_ & (((uint32_t) 1) << which)) != 0) {
                    ret.push_back(std::to_string((int) which)+" stopped");
                }
            }
            return ret;
        }
    };

    template <>
    class IStoppableProducer<1> {
    private:
        std::atomic<bool> producerIsStopped_ = false;
    public:
        void stopProducer() {
            producerIsStopped_ = true;
        }
        void stopProducer(uint8_t which) {
            if (which == 0) {
                producerIsStopped_ = true;
            }
        }
        void restartProducer() {
            producerIsStopped_ = false;
        }
        void restartProducer(uint8_t which) {
            if (which == 0) {
                producerIsStopped_ = false;
            }
        }
        bool producerIsStopped() const {
            return producerIsStopped_;
        }
        bool producerIsStopped(uint8_t which) const {
            if (which == 0) {
                return producerIsStopped_;
            } else {
                return false;
            }
        }
        std::vector<std::string> producerStoppedStatus() const {
            std::vector<std::string> ret;
            if (producerIsStopped_) {
                ret.push_back("stopped");
            }
            return ret;
        }
    };

    template <>
    class IStoppableProducer<0> {
    public:
        void stopProducer() {
        }
        void stopProducer(uint8_t which) {
        }
        void restartProducer() {
        }
        void restartProducer(uint8_t which) {
        }
        bool producerIsStopped() const {
            return false;
        }
        bool producerIsStopped(uint8_t which) const {
            return false;
        }
        std::vector<std::string> producerStoppedStatus() const {
            return {};
        }
    };
} } } }

#endif