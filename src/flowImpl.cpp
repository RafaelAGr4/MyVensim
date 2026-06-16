#include "flowImpl.hpp"

FlowImpl::FlowImpl(std::string name, System* origin, System* destination)
    : name(name), origin(origin), destination(destination) {}

FlowImpl::FlowImpl(const FlowImpl& obj)
    : name(obj.name), origin(obj.origin), destination(obj.destination) {}

FlowImpl::~FlowImpl() {}

FlowImpl& FlowImpl::operator=(const FlowImpl& obj) {
    if (this == &obj) return *this;
    name = obj.name;
    origin = obj.origin;
    destination = obj.destination;
    return *this;
}

std::string FlowImpl::getName() const { return name; }
void FlowImpl::setName(const std::string name) { this->name = name; }
void FlowImpl::setOrigin(System* s) { origin = s; }
void FlowImpl::setDestination(System* s) { destination = s; }
System* FlowImpl::getOrigin() const { return origin; }
System* FlowImpl::getDestination() const { return destination; }
void FlowImpl::clearOrigin() { origin = nullptr; }
void FlowImpl::clearDestination() { destination = nullptr; }