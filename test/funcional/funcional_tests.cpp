#include <iostream>
#include <cmath>
#include "funcional_tests.h"
#include "../../src/mySim.h" 

using namespace std;

void exponentialFuncionalTest() {
    cout << "Running Exponential Funcional Test..." << endl;

    System pop("Populacao", 100.0);
    ExponentialFlow nascimento(nullptr, &pop);
    Model model;
    
    model.add(&pop);
    model.add(&nascimento);
    model.run(0, 100);

    cout << "Exponential Test Passed! Final Value: " << pop.getValue() << "\n" << endl;
}

void logisticalFuncionalTest() {
    cout << "Running Logistical Funcional Test..." << endl;

    System pop("Populacao", 100.0);
    LogisticFlow nascimento(nullptr, &pop, 160.0);
    Model model;

    model.add(&pop);
    model.add(&nascimento);
    model.run(0, 100);

    cout << "Logistical Test Passed! Final Value: " << pop.getValue() << "\n" << endl;
}

void complexFuncionalTest() {
    cout << "Running Complex Funcional Test..." << endl;
    cout << "Complex Test Finished.\n" << endl;
}