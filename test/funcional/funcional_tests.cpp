#include <iostream>
#include <cmath>
#include <cassert>
#include "funcional_tests.h"
#include "../../src/system.hpp"
#include "../../src/flow.hpp"
#include "../../src/model.hpp"
#include "../../src/exponentialFlow.hpp"
#include "../../src/logisticFlow.hpp"

using namespace std;
bool compareRounded(double result, double expected){
    int resEscalonado = round(result * 10000.0);
    int espEscalonado = round(expected * 10000.0);
    return resEscalonado == espEscalonado;
}

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

    cout << "Valor final de pop1: " << pop1.getValue() << " (Esperado: ~36.6032)" << endl;
    cout << "Valor final de pop2: " << pop2.getValue() << " (Esperado: ~63.3968)" << endl;

    assert(compareRounded(pop1->getValue(), 36.6032));
    assert(compareRounded(pop2->getValue(), 63.3968));

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

    cout << "Valor final de p1: " << p1.getValue() << " (Esperado: ~88.2167)" << endl;
    cout << "Valor final de p2: " << p2.getValue() << " (Esperado: ~21.7833)" << endl;

    assert(compareRounded(p1->getValue(), 88.2167));
    assert(compareRounded(p2->getValue(), 21.7833));

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

    cout << "Valor final de Q1: " << q1.getValue() << " (Esperado: ~31.8513)" << endl;
    cout << "Valor final de Q2: " << q2.getValue() << " (Esperado: ~18.4003)" << endl;
    cout << "Valor final de Q3: " << q3.getValue() << " (Esperado: ~77.1143)" << endl;
    cout << "Valor final de Q4: " << q4.getValue() << " (Esperado: ~56.1728)" << endl;
    cout << "Valor final de Q5: " << q5.getValue() << " (Esperado: ~16.4612)" << endl;

    assert(compareRounded(q1.getValue(), 31.8513));
    assert(compareRounded(q2.getValue(), 18.4003));
    assert(compareRounded(q3.getValue(), 77.1143));
    assert(compareRounded(q4.getValue(), 56.1728));
    assert(compareRounded(q5.getValue(), 16.4612));

    cout << "Teste Complexo SUCEDIDO!" << endl << endl;
}
