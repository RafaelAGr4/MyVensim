#ifndef FLOW_IMPL_HPP
#define FLOW_IMPL_HPP

#include "flow.hpp"
#include <string>

/**
 * @brief Implementacao concreta base da interface Flow.
 * Gerencia o nome, os ponteiros de origem e destino, e implementa todos os metodos
 * da interface, exceto execute() — que permanece abstrato para que
 * cada tipo de fluxo defina sua propria equacao matematica.
 */
class FlowImpl : public Flow {
protected:
    std::string name;    /**< Nome do fluxo */
    System* origin;      /**< Ponteiro para o sistema de origem */
    System* destination; /**< Ponteiro para o sistema de destino */

public:
    /**
     * @brief Construtor padrao e parametrizado da classe FlowImpl.
     */
    FlowImpl(std::string name = "", System* origin = nullptr, System* destination = nullptr);
    
    /**
     * @brief Construtor de copia de FlowImpl.
     */
    FlowImpl(const FlowImpl& obj);
    
    /**
     * @brief Destrutor da classe FlowImpl.
     */
    virtual ~FlowImpl();
    
    /**
     * @brief Operador de atribuicao por copia.
     */
    FlowImpl& operator=(const FlowImpl& obj);

    std::string getName() const override;
    void setName(const std::string name) override;
    void setOrigin(System* s) override;
    void setDestination(System* s) override;
    System* getOrigin() const override;
    System* getDestination() const override;
    void clearOrigin() override;
    void clearDestination() override;

    /**
     * @brief Metodo abstrato mantido para as subclasses implementarem a logica matematica.
     */
    virtual double execute() = 0; 
};

#endif // FLOW_IMPL_HPP