#include "exponentialflow.hpp"
ExponentialFlow::ExponentialFlow(System* origin, System* destination)
    : Flow("Exponencial", origin, destination) {}
ExponentialFlow::~ExponentialFlow() {}

ExponentialFlow::ExponentialFlow(const ExponentialFlow& other) : Flow(other) {}
ExponentialFlow& ExponentialFlow::operator=(const ExponentialFlow& other) {
    if (this == &other) return *this;
    Flow::operator=(other);
    return *this;
}
double ExponentialFlow::execute() {
    if (getOrigin() != nullptr) return 0.01 * getOrigin()->getValue();
    return 0.0;
}