#ifndef EXPONENTIAL_FLOW_HPP
#define EXPONENTIAL_FLOW_HPP
#include "flowImpl.hpp"

class ExponentialFlow : public FlowImpl {
public:
    ExponentialFlow(std::string name = "", System* origin = nullptr, System* destination = nullptr);
    virtual ~ExponentialFlow();
    double execute() override;
};

#endif