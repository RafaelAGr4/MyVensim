#include "unit_Flow.h"
#include "../../src/systemImpl.hpp"
#include "../../src/exponentialFlow.hpp"
#include "../../src/logisticFlow.hpp"
#include <cassert>

void unit_Flow_constructor(void) {
    System* s1 = new SystemImpl("S1", 10.0);
    System* s2 = new SystemImpl("S2", 0.0);
    
    Flow* f = new ExponentialFlow("F1", s1, s2);
    assert(f->getName() == "F1");
    assert(f->getOrigin() == s1);
    assert(f->getDestination() == s2);
    
    delete f;
    delete s1;
    delete s2;
}

void unit_Flow_destructor(void) {}

void unit_Flow_getName(void) {
    Flow* f = new ExponentialFlow("FluxoTeste", nullptr, nullptr);
    assert(f->getName() == "FluxoTeste");
    delete f;
}

void unit_Flow_setName(void) {
    Flow* f = new ExponentialFlow();
    f->setName("NovoNome");
    assert(f->getName() == "NovoNome");
    delete f;
}

void unit_Flow_getOrigin(void) {
    System* s = new SystemImpl("S1", 10.0);
    Flow* f = new ExponentialFlow("F", s, nullptr);
    assert(f->getOrigin() == s);
    delete f;
    delete s;
}

void unit_Flow_setOrigin(void) {
    System* s = new SystemImpl("S1", 10.0);
    Flow* f = new ExponentialFlow();
    f->setOrigin(s);
    assert(f->getOrigin() == s);
    delete f;
    delete s;
}

void unit_Flow_getDestination(void) {
    System* s = new SystemImpl("S2", 5.0);
    Flow* f = new ExponentialFlow("F", nullptr, s);
    assert(f->getDestination() == s);
    delete f;
    delete s;
}

void unit_Flow_setDestination(void) {
    System* s = new SystemImpl("S2", 5.0);
    Flow* f = new ExponentialFlow();
    f->setDestination(s);
    assert(f->getDestination() == s);
    delete f;
    delete s;
}

void unit_Flow_execute(void) {
    System* s1 = new SystemImpl("S1", 100.0);
    System* s2 = new SystemImpl("S2", 10.0);
    
    Flow* expF = new ExponentialFlow("Exp", s1, s2);
    assert(expF->execute() == 1.0); // 0.01 * 100.0 = 1.0
    
    Flow* logF = new LogisticFlow("Log", s1, s2, 100.0);
    // 0.01 * 10.0 * (1.0 - (10.0 / 100.0)) = 0.1 * 0.9 = 0.09
    assert(logF->execute() - 0.09 < 0.0001); 
    
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