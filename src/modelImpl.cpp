#include "modelImpl.hpp"

ModelImpl::ModelImpl(double time) : time(time) {}

ModelImpl::~ModelImpl() {
    systems.clear();
    flows.clear();
}

ModelImpl::ModelImpl(const ModelImpl& other) {
    this->time = other.time;
    this->systems = other.systems;
    this->flows = other.flows;
}

ModelImpl& ModelImpl::operator=(const ModelImpl& other) {
    if (this == &other) return *this;
    this->time = other.time;
    this->systems = other.systems;
    this->flows = other.flows;
    return *this;
}

void ModelImpl::add(System* s) { systems.push_back(s); }
void ModelImpl::add(Flow* f) { flows.push_back(f); }

double ModelImpl::getTime() const { return time; }
void ModelImpl::setTime(double t) { time = t; }

void ModelImpl::run(double start, double end) {
    for (time = start; time < end; time += 1.0) {
        std::vector<double> results;
        
        // 1. Calcula o resultado de todos os fluxos
        for (size_t i = 0; i < flows.size(); ++i) {
            results.push_back(flows[i]->execute());
        }
        
        // 2. Atualiza os valores dos sistemas afetados pelos fluxos
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