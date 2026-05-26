#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"
#include "../../src/system.hpp"
#include "../../src/flow.hpp"
#include "../../src/model.hpp"
#include "../../src/exponentialFlow.hpp"
#include "../../src/logisticFlow.hpp"
#include <iostream>

int main() {
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();

    std::cout << "Os testes tiveram sucesso " << std::endl;
    
    std::cout << "Todos os teste concluidos com sucesso!" << std::endl;
    return 0; 
}

#endif
