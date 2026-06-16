#include "funcional_tests.hpp"
#include "../../src/factory.hpp"
#include <cassert>
#include <cmath>

void exponentialFuncionalTest(void) {
    System* pop1 = createSystem("Pop1", 100.0);
    System* pop2 = createSystem("Pop2", 0.0);
    Flow* f1 = createExponentialFlow("F1", pop1, pop2);
    
    Model* sim = createModel();
    sim->add(pop1); 
    sim->add(pop2); 
    sim->add(f1);
    
    sim->execute(0, 100, 1);
    
    assert(std::trunc(pop1->getValue() * 10000 + 0.5) == 366032);
    assert(std::trunc(pop2->getValue() * 10000 + 0.5) == 633968);

    delete sim;
    delete pop1;
    delete pop2;
    delete f1;
}

void logisticalFuncionalTest(void) {
    System* p1 = createSystem("P1", 100.0);
    System* p2 = createSystem("P2", 10.0);
    Flow* f1 = createLogisticFlow("F1", p1, p2, 70.0); // pMax definido como 70.0
    
    Model* sim = createModel();
    sim->add(p1); 
    sim->add(p2); 
    sim->add(f1);
    
    sim->execute(0, 100, 1);
    
    assert(std::trunc(p1->getValue() * 10000 + 0.5) == 882167);
    assert(std::trunc(p2->getValue() * 10000 + 0.5) == 217833);

    delete sim;
    delete p1;
    delete p2;
    delete f1;
}

void complexFuncionalTest(void) {
    System* q1 = createSystem("Q1", 100.0);
    System* q2 = createSystem("Q2", 0.0);
    System* q3 = createSystem("Q3", 100.0);
    System* q4 = createSystem("Q4", 0.0);
    System* q5 = createSystem("Q5", 0.0);
    
    // A matematica do ComplexFlow e identica ao ExponentialFlow
    Flow* f = createExponentialFlow("f", q1, q2);
    Flow* g = createExponentialFlow("g", q1, q3);
    Flow* r = createExponentialFlow("r", q2, q5);
    Flow* t = createExponentialFlow("t", q2, q3);
    Flow* u = createExponentialFlow("u", q3, q4);
    Flow* v = createExponentialFlow("v", q4, q1);
    
    Model* sim = createModel();
    sim->add(q1); sim->add(q2); sim->add(q3); sim->add(q4); sim->add(q5);
    sim->add(f);  sim->add(g);  sim->add(r);  sim->add(t);  sim->add(u);  sim->add(v);
    
    sim->execute(0, 100, 1);
    
    assert(std::trunc(q1->getValue() * 10000 + 0.5) == 318513);
    assert(std::trunc(q2->getValue() * 10000 + 0.5) == 184003);
    assert(std::trunc(q3->getValue() * 10000 + 0.5) == 771143);
    assert(std::trunc(q4->getValue() * 10000 + 0.5) == 561728);
    assert(std::trunc(q5->getValue() * 10000 + 0.5) == 164612);

    delete sim;
    delete q1; delete q2; delete q3; delete q4; delete q5;
    delete f; delete g; delete r; delete t; delete u; delete v;
}