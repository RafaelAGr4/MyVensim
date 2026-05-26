#ifndef FLOW_HPP
#define FLOW_HPP
#include "system.hpp"
#include <string>

/**
 * @brief Classe abstrata (Interface) que representa um Fluxo entre dois Sistemas.
 * @details Define o comportamento base para a transferência de valores de um sistema de origem para um de destino.
 */
class Flow {
private:
    std::string name;     ///< Nome identificador do fluxo.
    System* origin;       ///< Ponteiro para o sistema de origem do fluxo.
    System* destination;  ///< Ponteiro para o sistema de destino do fluxo.

public:
    /**
     * @brief Construtor padrão e parametrizado da classe Flow.
     * @param name Nome do fluxo.
     * @param origin Ponteiro para o sistema de origem (padrão é nullptr).
     * @param destination Ponteiro para o sistema de destino (padrão é nullptr).
     */
    Flow(std::string name = "", System* origin = nullptr, System* destination = nullptr);

    /**
     * @brief Destrutor virtual da classe Flow.
     */
    virtual ~Flow();

    /**
     * @brief Construtor de cópia da classe Flow.
     * @param other Objeto Flow a ser copiado.
     */
    Flow(const Flow& other);

    /**
     * @brief Operador de atribuição sobrecarregado da classe Flow.
     * @param other Objeto Flow de onde os dados serão copiados.
     * @return Referência para o próprio objeto Flow atualizado.
     */
    Flow& operator=(const Flow& other);

    /**
     * @brief Define o sistema de origem do fluxo.
     * @param s Ponteiro para o sistema de origem.
     */
    void setOrigin(System* s);

    /**
     * @brief Retorna o sistema de origem do fluxo.
     * @return System* Ponteiro para o sistema de origem.
     */
    System* getOrigin() const;
    
    /**
     * @brief Define o sistema de destino do fluxo.
     * @param s Ponteiro para o sistema de destino.
     */
    void setDestination(System* s);

    /**
     * @brief Retorna o sistema de destino do fluxo.
     * @return System* Ponteiro para o sistema de destino.
     */
    System* getDestination() const;

    /**
     * @brief Retorna o nome do fluxo.
     * @return std::string Nome do fluxo.
     */
    std::string getName() const;

    /**
     * @brief Método puramente virtual para calcular a equação matemática do fluxo.
     * @note Deve ser implementado pelas classes filhas.
     * @return double O valor gerado pela equação do fluxo a ser transferido.
     */
    virtual double execute() = 0; 
};
#endif