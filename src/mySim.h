// src/mySim.h
#ifndef MYSIM_H
#define MYSIM_H

#include <string>
#include <vector>

// Forward Declaration
class System;
class Flow;

class System {
private:
    std::string name;
    double value;

public:
    // Construtor e Destrutor
    System(std::string name = "", double value = 0.0);
    virtual ~System();

    std::string getName() const;
    double getValue() const;
    void setValue(double v);
};

class Flow {// Classe abstrata
private:
    std::string name;
    System* origin;
    System* destination;

public:
    // Construtor e Destrutor
    Flow(std::string name = "", System* origin = nullptr, System* destination = nullptr);
    virtual ~Flow();

    void setOrigin(System* s);
    System* getOrigin() const;
    
    void setDestination(System* s);
    System* getDestination() const;

    std::string getName() const;

    virtual double execute() = 0; 
};

class Model {
private:
    double time;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:
    // Construtor e Destrutor
    Model(double time = 0.0);
    virtual ~Model();

    void add(System* s);
    void add(Flow* f);
    void run(double start, double end);

    double getTime() const;
};

#endif // MYSIM_H