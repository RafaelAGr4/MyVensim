#include <iostream>
#include <cmath>
#include <cassert>
#include "funcional_tests.hpp"

#include "../../src/system.hpp"
#include "../../src/flow.hpp"
#include "../../src/model.hpp"

#include "../../src/systemImpl.hpp"
#include "../../src/modelImpl.hpp"
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

    System* pop1 = new SystemImpl("pop1", 100.0);
    System* pop2 = new SystemImpl("pop2", 0.0);
    

    Flow* exponencial = new ExponentialFlow("Exponencial", pop1, pop2);
    

    Model* model = new ModelImpl();
    

    model->add(pop1);
    model->add(pop2);
    model->add(exponencial);
    
    model->run(0, 100);

    cout << "Valor final de pop1: " << pop1->getValue() << " (Esperado: ~36.6032)" << endl;
    cout << "Valor final de pop2: " << pop2->getValue() << " (Esperado: ~63.3968)" << endl;


    assert(compareRounded(pop1->getValue(), 36.6032));
    assert(compareRounded(pop2->getValue(), 63.3968));


    delete model;
    delete exponencial;
    delete pop1;
    delete pop2;

    cout << "Teste Exponencial SUCEDIDO!" << endl << endl;
}

void logisticalFuncionalTest() {
    cout << "A rodar teste da funcao logistica..." << endl;

    System* p1 = new SystemImpl("p1", 100.0);
    System* p2 = new SystemImpl("p2", 10.0);
    

    Flow* logistica = new LogisticFlow("Logistico", p1, p2, 70.0);
    
    Model* model = new ModelImpl();

    model->add(p1);
    model->add(p2);
    model->add(logistica);
    
    model->run(0, 100);

    cout << "Valor final de p1: " << p1->getValue() << " (Esperado: ~88.2167)" << endl;
    cout << "Valor final de p2: " << p2->getValue() << " (Esperado: ~21.7833)" << endl;

    assert(compareRounded(p1->getValue(), 88.2167));
    assert(compareRounded(p2->getValue(), 21.7833));

    delete model;
    delete logistica;
    delete p1;
    delete p2;

    cout << "Teste Logistico SUCEDIDO!" << endl << endl;
}

void complexFuncionalTest() {
    cout << "A rodar teste funcional complexo..." << endl;

    System* q1 = new SystemImpl("Q1", 100.0);
    System* q2 = new SystemImpl("Q2", 0.0);
    System* q3 = new SystemImpl("Q3", 100.0);
    System* q4 = new SystemImpl("Q4", 0.0);
    System* q5 = new SystemImpl("Q5", 0.0);

    Flow* f = new ExponentialFlow("f", q1, q2);
    Flow* g = new ExponentialFlow("g", q1, q3);
    Flow* r = new ExponentialFlow("r", q2, q5);
    Flow* t = new ExponentialFlow("t", q2, q3);
    Flow* u = new ExponentialFlow("u", q3, q4);
    Flow* v = new ExponentialFlow("v", q4, q1);

    Model* model = new ModelImpl();
    model->add(q1); model->add(q2); model->add(q3); model->add(q4); model->add(q5);
    model->add(f); model->add(g); model->add(r); model->add(t); model->add(u); model->add(v);

    model->run(0, 100);

    cout << "Valor final de Q1: " << q1->getValue() << " (Esperado: ~31.8513)" << endl;
    cout << "Valor final de Q2: " << q2->getValue() << " (Esperado: ~18.4003)" << endl;
    cout << "Valor final de Q3: " << q3->getValue() << " (Esperado: ~77.1143)" << endl;
    cout << "Valor final de Q4: " << q4->getValue() << " (Esperado: ~56.1728)" << endl;
    cout << "Valor final de Q5: " << q5->getValue() << " (Esperado: ~16.4612)" << endl;

    assert(compareRounded(q1->getValue(), 31.8513));
    assert(compareRounded(q2->getValue(), 18.4003));
    assert(compareRounded(q3->getValue(), 77.1143));
    assert(compareRounded(q4->getValue(), 56.1728));
    assert(compareRounded(q5->getValue(), 16.4612));

    delete model;
    delete f; delete g; delete r; delete t; delete u; delete v;
    delete q1; delete q2; delete q3; delete q4; delete q5;

    cout << "Teste Complexo SUCEDIDO!" << endl << endl;
}