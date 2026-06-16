#include "unit_flow.h"
#include "../../src/factory.hpp"
#include <cassert>
#include <cmath>

void unit_Flow_constructor(void) {
    System* s1 = createSystem("S1", 10.0);
    System* s2 = createSystem("S2", 0.0);
    
    Flow* f = createExponentialFlow("F1", s1, s2);
    assert(f->getName() == "F1");
    assert(f->getOrigin() == s1);
    assert(f->getDestination() == s2);
    
    delete f;
    delete s1;
    delete s2;
}

void unit_Flow_destructor(void) {}

void unit_Flow_getName(void) {
    Flow* f = createExponentialFlow("FluxoTeste", nullptr, nullptr);
    assert(f->getName() == "FluxoTeste");
    delete f;
}

void unit_Flow_setName(void) {
    Flow* f = createExponentialFlow();
    f->setName("NovoNome");
    assert(f->getName() == "NovoNome");
    delete f;
}

void unit_Flow_getOrigin(void) {
    System* s = createSystem("S1", 10.0);
    Flow* f = createExponentialFlow("F", s, nullptr);
    assert(f->getOrigin() == s);
    delete f;
    delete s;
}

void unit_Flow_setOrigin(void) {
    System* s = createSystem("S1", 10.0);
    Flow* f = createExponentialFlow();
    f->setOrigin(s);
    assert(f->getOrigin() == s);
    delete f;
    delete s;
}

void unit_Flow_getDestination(void) {
    System* s = createSystem("S2", 5.0);
    Flow* f = createExponentialFlow("F", nullptr, s);
    assert(f->getDestination() == s);
    delete f;
    delete s;
}

void unit_Flow_setDestination(void) {
    System* s = createSystem("S2", 5.0);
    Flow* f = createExponentialFlow();
    f->setDestination(s);
    assert(f->getDestination() == s);
    delete f;
    delete s;
}

void unit_Flow_execute(void) {
    System* s1 = createSystem("S1", 100.0);
    System* s2 = createSystem("S2", 10.0);
    
    Flow* expF = createExponentialFlow("Exp", s1, s2);
    
    // Validacao com std::trunc (igual aos testes funcionais)
    // Esperado: 1.0 (1.0 * 10000 = 10000)
    assert(std::trunc(expF->execute() * 10000 + 0.5) == 10000); 
    
    Flow* logF = createLogisticFlow("Log", s1, s2, 100.0);
    
    // Validacao com std::trunc (igual aos testes funcionais)
    // Esperado: 0.09 (0.09 * 10000 = 900)
    assert(std::trunc(logF->execute() * 10000 + 0.5) == 900); 
    
    delete expF;
    delete logF;
    delete s1;
    delete s2;
}

void run_unit_tests_Flow(void) {
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_getName();
    unit_Flow_setName();
    unit_Flow_getOrigin();
    unit_Flow_setOrigin();
    unit_Flow_getDestination();
    unit_Flow_setDestination();
    unit_Flow_execute();
}