#ifndef SYSTEM_IMPL_HPP
#define SYSTEM_IMPL_HPP

#include "system.hpp"

/**
 * @brief Implementacao concreta da interface System.
 * Armazena o nome e o valor em atributos privados e implementa
 * todos os metodos definidos na interface.
 */
class SystemImpl : public System {
private:
    std::string name; /**< Nome descritivo do sistema (estoque) */
    double value;     /**< Valor numerico armazenado no sistema */

public:
    /**
     * @brief Construtor padrao e parametrizado da classe SystemImpl.
     * @param name Nome inicial do sistema (padrao: "").
     * @param v Valor inicial do sistema (padrao: 0.0).
     */
    SystemImpl(std::string name = "", double v = 0.0);

    /**
     * @brief Construtor de copia de SystemImpl.
     * @param obj Objeto a ser copiado.
     */
    SystemImpl(const SystemImpl& obj);

    /**
     * @brief Destrutor da classe SystemImpl.
     */
    virtual ~SystemImpl();

    /**
     * @brief Operador de atribuicao por copia para SystemImpl.
     * @param obj Objeto do qual os dados serao copiados.
     * @return Referencia para o proprio objeto alterado.
     */
    SystemImpl& operator=(const SystemImpl& obj);

    /**
     * @brief Obtem o nome do sistema.
     * @return string com o nome do sistema.
     */
    std::string getName() const override;

    /**
     * @brief Define o nome do sistema.
     * @param name Novo nome do sistema.
     */
    void setName(const std::string name) override;

    /**
     * @brief Obtem o valor armazenado no sistema.
     * @return double correspondente ao valor atual.
     */
    double getValue() const override;

    /**
     * @brief Define o valor do sistema.
     * @param v Novo valor a ser atribuido.
     */
    void setValue(double v) override;
};

#endif // SYSTEM_IMPL_HPP