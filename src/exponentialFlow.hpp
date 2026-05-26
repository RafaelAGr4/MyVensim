#ifndef EXPONENTIAL_FLOW
#define EXPONENTIAL_FLOW
#include "flow.hpp"
#include "system.hpp"

class ExponentialFlow : public Flow {
public:

    ExponentialFlow(System* origin = nullptr, System* destination = nullptr);
    virtual ~ExponentialFlow();

    ExponentialFlow(const ExponentialFlow& other);
    ExponentialFlow& operator=(const ExponentialFlow& other);

    virtual double execute() override;
};

#endif