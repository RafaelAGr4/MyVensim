#ifndef LOGISTICFLOW_HPP
#define LOGISTICFLOW_HPP
#include "flow.hpp"
#include "system.hpp"

/**
 * @brief Classe que implementa o fluxo com comportamento logístico (crescimento com limite).
 * @details Utiliza a capacidade de carga máxima (pMax) do ambiente para limitar o crescimento.
 */
class LogisticFlow : public Flow {
private:
    double pMax; ///< Capacidade máxima de carga (limite assintótico).

public:
    /**
     * @brief Construtor parametrizado para LogisticFlow.
     * @param origin Ponteiro para o sistema de origem.
     * @param destination Ponteiro para o sistema de destino.
     * @param pMax Valor limite para o crescimento logístico.
     */
    LogisticFlow(System* origin = nullptr, System* destination = nullptr, double pMax = 0.0);

    /**
     * @brief Destrutor da classe LogisticFlow.
     */
    virtual ~LogisticFlow();

    /**
     * @brief Construtor de cópia para LogisticFlow.
     * @param other Objeto a ser copiado.
     */
    LogisticFlow(const LogisticFlow& other);

    /**
     * @brief Operador de atribuição para LogisticFlow.
     * @param other Objeto de onde os dados serão copiados.
     * @return Referência para o próprio objeto atualizado.
     */
    LogisticFlow& operator=(const LogisticFlow& other);

    /**
     * @brief Calcula e executa a equação logística.
     * @return double Resultado do cálculo considerando o pMax e o sistema de destino.
     */
    virtual double execute() override;
};
#endif