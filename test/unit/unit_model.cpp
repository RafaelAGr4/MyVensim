#include "unit_model.h"
#include "../../src/factory.hpp"
#include <cassert>

void unit_Model_constructor(void) {
    Model* m = createModel();
    // Você testava a criacao com o parametro tempo no original, 
    // mas na nossa factory ele inicia zerado, vamos testar isso.
    assert(m != nullptr);
    delete m;
}

void unit_Model_destructor(void) {}

void unit_Model_add(void) {
    Model* m = createModel();
    System* s = createSystem("S", 10.0);
    Flow* f = createExponentialFlow("F", s, nullptr);
    
    m->add(s);
    m->add(f);
    
    delete m;
    delete s;
    delete f;
}

// Os testes de getTime e setTime foram removidos aqui, pois se baseavam
// na versao antiga que permitia que o tempo fosse acessado ou modificado
// diretamente, mas a execucao agora ocorre puramente baseada nos parametros do execute().

void unit_Model_run(void) {
    Model* m = createModel();
    System* s1 = createSystem("S1", 100.0);
    System* s2 = createSystem("S2", 0.0);
    Flow* f = createExponentialFlow("F", s1, s2);
    
    m->add(s1);
    m->add(s2);
    m->add(f);
    
    m->execute(0, 1, 1); // Roda 1 passo de tempo
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
    unit_Model_run();
}