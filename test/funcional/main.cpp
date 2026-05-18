#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"
#include "../../src/mySim.h" 
#include <iostream>

int main() {
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();

    std::cout << "Os testes tiveram sucesso " << std::endl;
    
    std::cout << "All functional tests executed successfully!" << std::endl;
    return 0; 
}

#endif
