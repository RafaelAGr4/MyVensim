#include "logisticFlow.hpp"

LogisticFlow::LogisticFlow(std::string name, System* origin, System* destination, double pMax)
    : FlowImpl(name, origin, destination), pMax(pMax) {}

LogisticFlow::~LogisticFlow() {}

double LogisticFlow::execute() {
    if (getDestination() != nullptr) {
        double v = getDestination()->getValue();
        return 0.01 * v * (1.0 - (v / pMax));
    }
    return 0.0;
}

double LogisticFlow::getPMax() const { return pMax; }
void LogisticFlow::setPMax(double p) { pMax = p; }