#include "modelImpl.hpp"

// Inicializacao do vetor estatico de controle de instancias
std::vector<Model*> ModelImpl::models;

ModelImpl::ModelImpl() : time(0.0) {
    // Registra o modelo recem-criado no vetor global de controle
    models.push_back(this);
}

ModelImpl::ModelImpl(const ModelImpl& obj)
    : time(obj.time), systems(obj.systems), flows(obj.flows) {
    models.push_back(this);
}

ModelImpl::~ModelImpl() {
    // Logica de remocao segura via iterador elogiada pelo professor
    for (auto it = models.begin(); it != models.end(); ++it) {
        if (*it == this) {
            models.erase(it);
            break;
        }
    }
    systems.clear();
    flows.clear();
}

ModelImpl& ModelImpl::operator=(const ModelImpl& obj) {
    if (this == &obj) return *this;
    time    = obj.time;
    systems = obj.systems;
    flows   = obj.flows;
    return *this;
}

Model::systemIterator ModelImpl::beginSystems() { return systems.begin(); }
Model::systemIterator ModelImpl::endSystems()   { return systems.end();   }
Model::flowIterator   ModelImpl::beginFlows()   { return flows.begin();   }
Model::flowIterator   ModelImpl::endFlows()     { return flows.end();     }

void ModelImpl::add(System* s) { systems.push_back(s); }
void ModelImpl::add(Flow* f)   { flows.push_back(f);   }

void ModelImpl::remove(System* s) {
    for (auto it = systems.begin(); it != systems.end(); )
        if (*it == s) it = systems.erase(it);
        else ++it;
}

void ModelImpl::remove(Flow* f) {
    for (auto it = flows.begin(); it != flows.end(); )
        if (*it == f) it = flows.erase(it);
        else ++it;
}

void ModelImpl::execute(double start, double final_time, double inc) {
    time = start;
    while (time < final_time) {
        std::vector<double> results;
        // Calcula todas as taxas simultaneamente com base no estado atual
        for (Flow* f : flows)
            results.push_back(f->execute());

        // Aplica as taxas atualizando os estoques de origem e destino correspondentes
        for (std::size_t i = 0; i < flows.size(); ++i) {
            System* origem  = flows[i]->getOrigin();
            System* destino = flows[i]->getDestination();
            if (origem  != nullptr) origem->setValue(origem->getValue()   - results[i]);
            if (destino != nullptr) destino->setValue(destino->getValue() + results[i]);
        }
        time += inc;
    }
}