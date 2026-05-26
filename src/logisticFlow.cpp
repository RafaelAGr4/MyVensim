#include "logisticFlow.hpp"
LogisticFlow::LogisticFlow(System* origin, System* destination, double pMax)
    : Flow("Logistico", origin, destination) {
    this->pMax = pMax;
}
LogisticFlow::~LogisticFlow() {}

LogisticFlow::LogisticFlow(const LogisticFlow& other) : Flow(other) {
    this->pMax = other.pMax;
}
LogisticFlow& LogisticFlow::operator=(const LogisticFlow& other) {
    if (this == &other) return *this;
    Flow::operator=(other);
    this->pMax = other.pMax;
    return *this;
}
double LogisticFlow::execute() {
    if (getDestination() != nullptr) {
        double v = getDestination()->getValue();
        return 0.01 * v * (1.0 - (v / pMax));
    }
    return 0.0;
}
