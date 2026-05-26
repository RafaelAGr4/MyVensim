#ifndef FUNCIONAL_TESTS_HPP
#define FUNCIONAL_TESTS_HPP

/**
 * @file funcional_tests.h
 * @brief Declaração dos testes funcionais para validação do simulador MyVensim.
 * @details Este arquivo contém os testes de cenários reais (exponencial, logístico e complexo)
 * para garantir a precisão matemática dos fluxos e sistemas ao longo do tempo.
 */

/**
 * @brief Executa o teste funcional para o cenário de fluxo exponencial.
 * @details Valida a transferência de valores entre duas populações (pop1 e pop2) 
 * simulando um crescimento/decaimento exponencial de 0 a 100 iterações.
 */
void exponentialFuncionalTest();

/**
 * @brief Executa o teste funcional para o cenário de fluxo logístico.
 * @details Valida o comportamento do fluxo logístico limitado pela capacidade máxima (pMax)
 * de 0 a 100 iterações.
 */
void logisticalFuncionalTest();

/**
 * @brief Executa o teste funcional complexo envolvendo múltiplos sistemas e fluxos intercalados.
 * @details Conecta 5 sistemas (Q1 a Q5) através de 6 fluxos exponenciais para validar
 * a estabilidade e a corretude do simulador em cenários de alta interdependência.
 */
void complexFuncionalTest();

#endif // FUNCIONAL_TESTS_H