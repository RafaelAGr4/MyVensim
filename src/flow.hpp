#ifndef FLOW_HPP
#define FLOW_HPP
#include "system.hpp"
#include <string>

/**
 * @brief Interface pura (API) que representa um Fluxo entre dois Sistemas.
 */
class Flow {
public:
    virtual ~Flow() {}
    
    virtual void setOrigin(System* s) = 0;
    virtual System* getOrigin() const = 0;
    
    virtual void setDestination(System* s) = 0;
    virtual System* getDestination() const = 0;
    
    virtual std::string getName() const = 0;
    virtual void setName(std::string name) = 0;
    
    virtual double execute() = 0;
};

#endif