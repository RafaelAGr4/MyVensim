#ifndef LOGISTIC_FLOW_HPP
#define LOGISTIC_FLOW_HPP
#include "flowImpl.hpp"

/**
 * @brief Implementacao do fluxo Logistico.
 * Herda de FlowImpl e calcula a taxa baseada em um crescimento logistico focado no limite do destino.
 */
class LogisticFlow : public FlowImpl {
private:
    double pMax;

public:
    LogisticFlow(std::string name = "", System* origin = nullptr, System* destination = nullptr, double pMax = 0.0);
    virtual ~LogisticFlow();
    double execute() override;
    
    double getPMax() const;
    void setPMax(double pMax);
};

#endif