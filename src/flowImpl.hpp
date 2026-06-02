#ifndef FLOW_IMPL_HPP
#define FLOW_IMPL_HPP
#include "flow.hpp"

class FlowImpl : public Flow {
protected:
    std::string name;
    System* origin;
    System* destination;

public:
    FlowImpl(std::string name = "", System* origin = nullptr, System* destination = nullptr);
    virtual ~FlowImpl();
    FlowImpl(const FlowImpl& other);
    FlowImpl& operator=(const FlowImpl& other);

    void setOrigin(System* s) override;
    System* getOrigin() const override;
    
    void setDestination(System* s) override;
    System* getDestination() const override;
    
    std::string getName() const override;
    void setName(std::string name) override;
    
    virtual double execute() = 0; // Permanece virtual puro para as subclasses implementarem
};

#endif