#include "flow.hpp"
Flow::Flow(std::string name, System* origin, System* destination) {
    this->name = name;
    this->origin = origin;
    this->destination = destination;
}
Flow::~Flow() {}

Flow::Flow(const Flow& other) {
    this->name = other.name;
    this->origin = other.origin;
    this->destination = other.destination;
}
Flow& Flow::operator=(const Flow& other) {
    if (this == &other) return *this;
    this->name = other.name;
    this->origin = other.origin;
    this->destination = other.destination;
    return *this;
}
void Flow::setOrigin(System* s) { origin = s; }
System* Flow::getOrigin() const { return origin; }
void Flow::setDestination(System* s) { destination = s; }
System* Flow::getDestination() const { return destination; }
std::string Flow::getName() const { return name; }