#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include <string>

/**
 * @brief Interface que representa um Sistema (variável de estado) na simulação.
 */
class System {
public:
    virtual ~System() {}
    virtual std::string getName() const = 0;
    virtual void setName(const std::string& name) = 0;
    virtual double getValue() const = 0;
    virtual void setValue(double value) = 0;
};

#endif