#ifndef MODEL_HPP
#define MODEL_HPP
#include <vector>
#include "system.hpp"
#include "flow.hpp"
class Model {
private:
    double time;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:
    
    Model(double time = 0.0);
    virtual ~Model();

    Model& operator=(const Model& other);
    Model(const Model& other);
    

    void add(System* s);
    void add(Flow* f);
    void run(double start, double end);

    double getTime() const;
};
#endif