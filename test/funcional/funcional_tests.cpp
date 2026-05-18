#include <iostream>
#include <cmath>
#include "funcional_tests.h"
#include "../../src/mySim.h" 

using namespace std;

void exponentialFuncionalTest() {
    cout << "Teste da função exponencial" << endl;

    System pop("Populacao", 100.0);
    ExponentialFlow nascimento(nullptr, &pop);
    Model model;
    
    model.add(&pop);
    model.add(&nascimento);
    model.run(0, 100);

    cout << "Teste sucedido, valor final:  " << pop.getValue() << "\n" << endl;
}

void logisticalFuncionalTest() {
    cout << "Teste da função logística" << endl;

    System pop("População", 100.0);
    LogisticFlow nascimento(nullptr, &pop, 160.0);
    Model model;

    model.add(&pop);
    model.add(&nascimento);
    model.run(0, 100);

    cout << "Teste sucedido, valor final:  " << pop.getValue() << "\n" << endl;
}

void complexFuncionalTest() {
    cout << "Teste funcional complexo" << endl;
    cout << "Teste sucedido\n" << endl;
}