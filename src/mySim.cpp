#include "mySim.h"

System::System(std::string name, double value) {
    this->name = name;
    this->value = value;
}

System::~System() {}

std::string System::getName() const {
    return name;
}

double System::getValue() const {
    return value;
}

void System::setValue(double v) {
    value = v;
}

Flow::Flow(std::string name, System* origin, System* destination) {
    this->name = name;
    this->origin = origin;
    this->destination = destination;
}

Flow::~Flow() {}

void Flow::setOrigin(System* s) {
    origin = s;
}

System* Flow::getOrigin() const {
    return origin;
}

void Flow::setDestination(System* s) {
    destination = s;
}

System* Flow::getDestination() const {
    return destination;
}

std::string Flow::getName() const {
    return name;
}

ExponentialFlow::ExponentialFlow(System* origin, System* destination)
    : Flow("Exponencial", origin, destination) {}

ExponentialFlow::~ExponentialFlow() {}

double ExponentialFlow::execute() {
    if (getDestination() != nullptr) {
        return 0.01 * getDestination()->getValue();
    }
    return 0.0;
}

LogisticFlow::LogisticFlow(System* origin, System* destination, double pMax)
    : Flow("Logistico", origin, destination) {
    this->pMax = pMax;
}

LogisticFlow::~LogisticFlow() {}

double LogisticFlow::execute() {
    if (getDestination() != nullptr) {
        double v = getDestination()->getValue();
        return 0.01 * v * (1.0 - (v / pMax));
    }
    return 0.0;
}

Model::Model(double time) {
    this->time = time;
}

Model::~Model() {
    systems.clear();
    flows.clear();
}

void Model::add(System* s) {
    systems.push_back(s);
}

void Model::add(Flow* f) {
    flows.push_back(f);
}

double Model::getTime() const {
    return time;
}

void Model::run(double start, double end) {
    for (time = start; time < end; time += 1.0) {
        
        std::vector<double> results;
        for (size_t i = 0; i < flows.size(); ++i) {
            results.push_back(flows[i]->execute());
        }

        for (size_t i = 0; i < flows.size(); ++i) {
            System* origin = flows[i]->getOrigin();
            System* destination = flows[i]->getDestination();

            if (origin != nullptr) {
                origin->setValue(origin->getValue() - results[i]);
            }
            if (destination != nullptr) {
                destination->setValue(destination->getValue() + results[i]);
            }
        }
    }
}