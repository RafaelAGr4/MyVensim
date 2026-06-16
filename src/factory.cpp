/**
 * @file factory.cpp
 * @brief Implementacao das funcoes de fabrica.
 *
 * Este e o unico arquivo do sistema que possui visibilidade sobre as classes de 
 * implementacao real, encapsulando-as dentro do componente compilado.
 */

#include "factory.hpp"
#include "systemImpl.hpp"
#include "modelImpl.hpp"
#include "exponentialFlow.hpp"
#include "logisticFlow.hpp"

System* createSystem(std::string name, double value) {
    return new SystemImpl(name, value);
}

Model* createModel() {
    return new ModelImpl();
}

Flow* createExponentialFlow(std::string name, System* origin, System* destination) {
    return new ExponentialFlow(name, origin, destination);
}

Flow* createLogisticFlow(std::string name, System* origin, System* destination, double pMax) {
    return new LogisticFlow(name, origin, destination, pMax);
}