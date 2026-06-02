#include "unit_Model.h"
#include "../../src/modelImpl.hpp"
#include "../../src/systemImpl.hpp"
#include "../../src/exponentialFlow.hpp"
#include <cassert>

void unit_Model_constructor(void) {
    Model* m = new ModelImpl(15.0);
    assert(m->getTime() == 15.0);
    delete m;
}

void unit_Model_destructor(void) {}

void unit_Model_add(void) {
    // Verifica implicitamente adicionando elementos sem quebrar a simulação
    Model* m = new ModelImpl();
    System* s = new SystemImpl("S", 10.0);
    Flow* f = new ExponentialFlow("F", s, nullptr);
    
    m->add(s);
    m->add(f);
    
    delete m;
    delete s;
    delete f;
}

void unit_Model_getTime(void) {
    Model* m = new ModelImpl(0.0);
    assert(m->getTime() == 0.0);
    delete m;
}

void unit_Model_setTime(void) {
    Model* m = new ModelImpl();
    m->setTime(42.5);
    assert(m->getTime() == 42.5);
    delete m;
}

void unit_Model_run(void) {
    Model* m = new ModelImpl();
    System* s1 = new SystemImpl("S1", 100.0);
    System* s2 = new SystemImpl("S2", 0.0);
    Flow* f = new ExponentialFlow("F", s1, s2);
    
    m->add(s1);
    m->add(s2);
    m->add(f);
    
    m->run(0, 1); // Roda 1 passo de tempo
    // No passo 0, f->execute() = 0.01 * 100 = 1.0. S1 = 99.0, S2 = 1.0
    assert(s1->getValue() == 99.0);
    assert(s2->getValue() == 1.0);
    
    delete m;
    delete s1;
    delete s2;
    delete f;
}

void run_unit_tests_Model(void) {
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_add();
    unit_Model_getTime();
    unit_Model_setTime();
    unit_Model_run();
}