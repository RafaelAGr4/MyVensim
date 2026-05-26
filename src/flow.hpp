#ifndef FLOW_HPP
#define FLOW_HPP
#include "system.hpp"
#include <string>
class Flow {
private:
    std::string name;
    System* origin;
    System* destination;

public:
    
    Flow(std::string name = "", System* origin = nullptr, System* destination = nullptr);
    virtual ~Flow();

    Flow(const Flow& other);
    Flow& operator=(const Flow& other);

    void setOrigin(System* s);
    System* getOrigin() const;
    
    void setDestination(System* s);
    System* getDestination() const;

    std::string getName() const;

    virtual double execute() = 0; 
};
#endif