#include "exponentialFlow.hpp"

ExponentialFlow::ExponentialFlow(std::string name, System* origin, System* destination)
    : FlowImpl(name, origin, destination) {}

ExponentialFlow::~ExponentialFlow() {}

double ExponentialFlow::execute() {
    if (getOrigin() != nullptr) {
        return 0.01 * getOrigin()->getValue();
    }
    return 0.0;
}