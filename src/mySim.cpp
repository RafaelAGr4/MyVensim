#include "mySim.h"



//Construtor
System::System(std::string name, double value) {
    this->name = name;
    this->value = value;
}

//Destrutor
System::~System() {}

std::string System::getName() const {
    return name;
}

double System::getValue() const {
    return value;
}

void System::setValue(double v) {
    value = v;
}

//Construtor
Flow::Flow(std::string name, System* origin, System* destination) {
    this->name = name;
    this->origin = origin;
    this->destination = destination;
}
//Destrutor
Flow::~Flow() {}

void Flow::setOrigin(System* s) {
    origin = s;
}

System* Flow::getOrigin() const {
    return origin;
}

void Flow::setDestination(System* s) {
    destination = s;
}

System* Flow::getDestination() const {
    return destination;
}

std::string Flow::getName() const {
    return name;
}

//Construtor: inicializa o tempo do modelo
Model::Model(double time) {
    this->time = time;
}

//Destrutor
Model::~Model() {
    systems.clear();
    flows.clear();
}

void Model::add(System* s) {
    systems.push_back(s);
}

void Model::add(Flow* f) {
    flows.push_back(f);
}

double Model::getTime() const {
    return time;
}

void Model::run(double start, double end) {
    for (time = start; time < end; time += 1.0) {

    }
}