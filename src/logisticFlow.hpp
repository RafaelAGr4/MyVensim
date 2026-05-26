#ifndef LOGISTICFLOW_HPP
#define LOGISTICFLOW_HPP
#include "flow.hpp"
#include "system.hpp"

class LogisticFlow : public Flow {
private:
    double pMax; 

public:
    LogisticFlow(System* origin = nullptr, System* destination = nullptr, double pMax = 0.0);
    virtual ~LogisticFlow();

    LogisticFlow(const LogisticFlow& other);
    LogisticFlow& operator=(const LogisticFlow& other);

    virtual double execute() override;
};

#endif