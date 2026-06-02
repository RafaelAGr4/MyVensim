#ifndef MODEL_IMPL_HPP
#define MODEL_IMPL_HPP
#include "model.hpp"
#include <vector>

class ModelImpl : public Model {
private:
    double time;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:
    ModelImpl(double time = 0.0);
    virtual ~ModelImpl();
    ModelImpl(const ModelImpl& other);
    ModelImpl& operator=(const ModelImpl& other);

    void add(System* s) override;
    void add(Flow* f) override;
    
    double getTime() const override;
    void setTime(double time) override;
    
    void run(double start, double end) override;
};

#endif