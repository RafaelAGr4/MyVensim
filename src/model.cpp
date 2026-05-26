#include "model.hpp"

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