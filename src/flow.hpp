#ifndef FLOW_HPP
#define FLOW_HPP

#include "system.hpp"
#include <string>

/**
 * @brief Interface da classe Flow.
 * Define o contrato de um fluxo: conectar dois Systems (origem e destino), 
 * possuir um nome e calcular a taxa de transferencia. 
 * Todos os metodos sao virtuais puros.
 */
class Flow {
public:
    /**
     * @brief Destrutor virtual puro da interface Flow.
     */
    virtual ~Flow() {}

    /**
     * @brief Obtem o nome do fluxo.
     * @return string com o nome do fluxo.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Define o nome do fluxo.
     * @param name Novo nome do fluxo.
     */
    virtual void setName(const std::string name) = 0;

    /**
     * @brief Define o sistema de origem do fluxo.
     * @param s Ponteiro para o sistema de origem.
     */
    virtual void setOrigin(System* s) = 0;

    /**
     * @brief Define o sistema de destino do fluxo.
     * @param s Ponteiro para o sistema de destino.
     */
    virtual void setDestination(System* s) = 0;

    /**
     * @brief Obtem o sistema de origem do fluxo.
     * @return Ponteiro para a interface System correspondente a origem.
     */
    virtual System* getOrigin() const = 0;

    /**
     * @brief Obtem o sistema de destino do fluxo.
     * @return Ponteiro para a interface System correspondente ao destino.
     */
    virtual System* getDestination() const = 0;

    /**
     * @brief Desconecta (limpa) o sistema de origem do fluxo.
     */
    virtual void clearOrigin() = 0;

    /**
     * @brief Desconecta (limpa) o sistema de destino do fluxo.
     */
    virtual void clearDestination() = 0;

    /**
     * @brief Metodo puramente virtual que calcula a equacao do fluxo.
     * @return double correspondente ao valor calculado para a transferencia.
     */
    virtual double execute() = 0;
};

#endif // FLOW_HPP