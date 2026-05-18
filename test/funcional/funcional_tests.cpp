#include <iostream>
#include <cmath>
#include "funcional_tests.h"
#include "../../src/mySim.h" 

using namespace std;

void exponentialFuncionalTest() {
<<<<<<< HEAD
    cout << "Teste da função exponencial" << endl;
=======
    cout << "Running Exponential Funcional Test..." << endl;
>>>>>>> b3ba545dba7ced8fa45a1470ac11d8147dd86ff1

    System pop("Populacao", 100.0);
    ExponentialFlow nascimento(nullptr, &pop);
    Model model;
    
    model.add(&pop);
    model.add(&nascimento);
    model.run(0, 100);

<<<<<<< HEAD
    cout << "Teste sucedido, valor final:  " << pop.getValue() << "\n" << endl;
}

void logisticalFuncionalTest() {
    cout << "Teste da função logística" << endl;

    System pop("População", 100.0);
=======
    cout << "Exponential Test Passed! Final Value: " << pop.getValue() << "\n" << endl;
}

void logisticalFuncionalTest() {
    cout << "Running Logistical Funcional Test..." << endl;

    System pop("Populacao", 100.0);
>>>>>>> b3ba545dba7ced8fa45a1470ac11d8147dd86ff1
    LogisticFlow nascimento(nullptr, &pop, 160.0);
    Model model;

    model.add(&pop);
    model.add(&nascimento);
    model.run(0, 100);

<<<<<<< HEAD
    cout << "Teste sucedido, valor final:  " << pop.getValue() << "\n" << endl;
}

void complexFuncionalTest() {
    cout << "Teste funcional complexo" << endl;
    cout << "Teste sucedido\n" << endl;
=======
    cout << "Logistical Test Passed! Final Value: " << pop.getValue() << "\n" << endl;
}

void complexFuncionalTest() {
    cout << "Running Complex Funcional Test..." << endl;
    cout << "Complex Test Finished.\n" << endl;
>>>>>>> b3ba545dba7ced8fa45a1470ac11d8147dd86ff1
}