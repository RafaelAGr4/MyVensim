// src/mySim.cpp
#include "mySim.h"

// --- SYSTEM ---
System::System(std::string name, double value) {
    this->name = name;
    this->value = value;
}
System::~System() {}

System::System(const System& other) {
    this->name = other.name;
    this->value = other.value;
}
System& System::operator=(const System& other) {
    if (this == &other) return *this;
    this->name = other.name;
    this->value = other.value;
    return *this;
}
std::string System::getName() const { return name; }
double System::getValue() const { return value; }
void System::setValue(double v) { value = v; }

// --- FLOW ---
Flow::Flow(std::string name, System* origin, System* destination) {
    this->name = name;
    this->origin = origin;
    this->destination = destination;
}
Flow::~Flow() {}

Flow::Flow(const Flow& other) {
    this->name = other.name;
    this->origin = other.origin;
    this->destination = other.destination;
}
Flow& Flow::operator=(const Flow& other) {
    if (this == &other) return *this;
    this->name = other.name;
    this->origin = other.origin;
    this->destination = other.destination;
    return *this;
}
void Flow::setOrigin(System* s) { origin = s; }
System* Flow::getOrigin() const { return origin; }
void Flow::setDestination(System* s) { destination = s; }
System* Flow::getDestination() const { return destination; }
std::string Flow::getName() const { return name; }

// --- EXPONENTIAL FLOW ---
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

// --- LOGISTIC FLOW ---
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

// --- MODEL ---
Model::Model(double time) { this->time = time; }
Model::~Model() {
    systems.clear();
    flows.clear();
}
Model::Model(const Model& other) {
    this->time = other.time;
    this->systems = other.systems;
    this->flows = other.flows;
}
Model& Model::operator=(const Model& other) {
    if (this == &other) return *this;
    this->time = other.time;
    this->systems = other.systems;
    this->flows = other.flows;
    return *this;
}
void Model::add(System* s) { systems.push_back(s); }
void Model::add(Flow* f) { flows.push_back(f); }
double Model::getTime() const { return time; }

void Model::run(double start, double end) {
    for (time = start; time < end; time += 1.0) {
        std::vector<double> results;
        for (size_t i = 0; i < flows.size(); ++i) {
            results.push_back(flows[i]->execute());
        }
        for (size_t i = 0; i < flows.size(); ++i) {
            System* origin = flows[i]->getOrigin();
            System* destination = flows[i]->getDestination();
            if (origin != nullptr) origin->setValue(origin->getValue() - results[i]);
            if (destination != nullptr) destination->setValue(destination->getValue() + results[i]);
        }
    }
}
