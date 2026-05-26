#ifndef EXPONENTIAL_FLOW
#define EXPONENTIAL_FLOW
#include "flow.hpp"
#include "system.hpp"

/**
 * @brief Classe que implementa o fluxo com comportamento exponencial.
 * @details Representa um fluxo onde a taxa de variação é proporcional ao valor presente no sistema de origem.
 */
class ExponentialFlow : public Flow {
public:
    /**
     * @brief Construtor parametrizado para ExponentialFlow.
     * @param origin Ponteiro para o sistema de origem.
     * @param destination Ponteiro para o sistema de destino.
     */
    ExponentialFlow(System* origin = nullptr, System* destination = nullptr);

    /**
     * @brief Destrutor da classe ExponentialFlow.
     */
    virtual ~ExponentialFlow();

    /**
     * @brief Construtor de cópia para ExponentialFlow.
     * @param other Objeto a ser copiado.
     */
    ExponentialFlow(const ExponentialFlow& other);

    /**
     * @brief Operador de atribuição para ExponentialFlow.
     * @param other Objeto de onde os dados serão copiados.
     * @return Referência para o próprio objeto atualizado.
     */
    ExponentialFlow& operator=(const ExponentialFlow& other);

    /**
     * @brief Calcula e executa a equação do fluxo exponencial.
     * @return double Resultado do cálculo (ex: 0.01 * valor do sistema de origem).
     */
    virtual double execute() override;
};
#endif