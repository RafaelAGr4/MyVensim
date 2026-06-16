#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>

/**
 * @brief Interface da classe System.
 * Define o contrato que toda implementacao de System deve cumprir.
 * Nao possui atributos nem implementacoes — apenas metodos virtuais puros.
 */
class System {
public:
    /**
     * @brief Destrutor virtual puro da interface System.
     */
    virtual ~System() {}

    /**
     * @brief Obtem o nome do sistema.
     * @return string com o nome do sistema.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Define o nome do sistema.
     * @param name Novo nome do sistema.
     */
    virtual void setName(const std::string name) = 0;

    /**
     * @brief Obtem o valor armazenado no sistema.
     * @return double correspondente ao valor atual do estoque.
     */
    virtual double getValue() const = 0;

    /**
     * @brief Define o valor do sistema.
     * @param v Novo valor do sistema.
     */
    virtual void setValue(double v) = 0;
};

#endif // SYSTEM_HPP