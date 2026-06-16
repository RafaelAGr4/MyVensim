#ifndef EXPONENTIAL_FLOW_HPP
#define EXPONENTIAL_FLOW_HPP
#include "flowImpl.hpp"

/**
 * @brief Implementacao do fluxo Exponencial.
 * Herda de FlowImpl e calcula a taxa de transferencia baseada em um percentual do valor da origem.
 */
class ExponentialFlow : public FlowImpl {
public:
    ExponentialFlow(std::string name = "", System* origin = nullptr, System* destination = nullptr);
    virtual ~ExponentialFlow();
    double execute() override;
};

#endif