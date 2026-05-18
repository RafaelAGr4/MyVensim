#include <iostream>
#include <cmath>
#include <cassert>
#include "funcional_tests.h"
#include "../../src/mySim.h" 

using namespace std;

void exponentialFuncionalTest() {
    cout << "A rodar teste da funcao exponencial..." << endl;

    System pop1("pop1", 100.0);
    System pop2("pop2", 0.0);
    
    ExponentialFlow exponencial(&pop1, &pop2);
    Model model;
    
    model.add(&pop1);
    model.add(&pop2);
    model.add(&exponencial);
    
    model.run(0, 100);

    assert(abs(pop1.getValue() - 36.6032) < 0.0001);
    assert(abs(pop2.getValue() - 63.3968) < 0.0001);

    cout << "Teste Exponencial SUCEDIDO!" << endl << endl;
}

void logisticalFuncionalTest() {
    cout << "A rodar teste da funcao logistica..." << endl;

    System p1("p1", 100.0);
    System p2("p2", 10.0);
    
    LogisticFlow logistica(&p1, &p2, 70.0);
    Model model;

    model.add(&p1);
    model.add(&p2);
    model.add(&logistica);
    
    model.run(0, 100);

    assert(abs(p1.getValue() - 88.2167) < 0.0001);
    assert(abs(p2.getValue() - 21.7833) < 0.0001);

    cout << "Teste Logistico SUCEDIDO!" << endl << endl;
}

void complexFuncionalTest() {
    cout << "A rodar teste funcional complexo..." << endl;

    System q1("Q1", 100.0);
    System q2("Q2", 0.0);
    System q3("Q3", 100.0);
    System q4("Q4", 0.0);
    System q5("Q5", 0.0);

    ExponentialFlow f(&q1, &q2);
    ExponentialFlow g(&q1, &q3);
    ExponentialFlow r(&q2, &q5);
    ExponentialFlow t(&q2, &q3);
    ExponentialFlow u(&q3, &q4);
    ExponentialFlow v(&q4, &q1);

    Model model;
    model.add(&q1); model.add(&q2); model.add(&q3); model.add(&q4); model.add(&q5);
    model.add(&f); model.add(&g); model.add(&r); model.add(&t); model.add(&u); model.add(&v);

    model.run(0, 100);

    assert(abs(q1.getValue() - 31.8513) < 0.0001);
    assert(abs(q2.getValue() - 18.4003) < 0.0001);
    assert(abs(q3.getValue() - 77.1143) < 0.0001);
    assert(abs(q4.getValue() - 56.1728) < 0.0001);
    assert(abs(q5.getValue() - 16.4612) < 0.0001);

    cout << "Teste Complexo SUCEDIDO!" << endl << endl;
}
