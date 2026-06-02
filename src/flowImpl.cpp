#include "flowImpl.hpp"

FlowImpl::FlowImpl(std::string name, System* origin, System* destination) 
    : name(name), origin(origin), destination(destination) {}

FlowImpl::~FlowImpl() {}

FlowImpl::FlowImpl(const FlowImpl& other) {
    this->name = other.name;
    this->origin = other.origin;
    this->destination = other.destination;
}

FlowImpl& FlowImpl::operator=(const FlowImpl& other) {
    if (this == &other) return *this;
    this->name = other.name;
    this->origin = other.origin;
    this->destination = other.destination;
    return *this;
}

void FlowImpl::setOrigin(System* s) { origin = s; }
System* FlowImpl::getOrigin() const { return origin; }

void FlowImpl::setDestination(System* s) { destination = s; }
System* FlowImpl::getDestination() const { return destination; }

std::string FlowImpl::getName() const { return name; }
void FlowImpl::setName(std::string n) { name = n; }