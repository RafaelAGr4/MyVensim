#ifndef MODEL_HPP
#define MODEL_HPP
#include "system.hpp"
#include "flow.hpp"

/**
 * @brief Interface pura (API) que representa o Modelo/Contentor principal da simulação.
 */
class Model {
public:
    virtual ~Model() {}
    
    virtual void add(System* s) = 0;
    virtual void add(Flow* f) = 0;
    
    virtual double getTime() const = 0;
    virtual void setTime(double time) = 0;
    
    virtual void run(double start, double end) = 0;
};

#endif