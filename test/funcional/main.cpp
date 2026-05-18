#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"
#include "../../src/mySim.h" 
#include <iostream>

int main() {
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();

<<<<<<< HEAD
    std::cout << "Os testes tiveram sucesso " << std::endl;
=======
    std::cout << "All functional tests executed successfully!" << std::endl;
>>>>>>> b3ba545dba7ced8fa45a1470ac11d8147dd86ff1
    return true; 
}

#endif