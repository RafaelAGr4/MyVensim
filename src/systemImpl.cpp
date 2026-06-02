#include "systemImpl.hpp"

SystemImpl::SystemImpl(std::string name, double value) : name(name), value(value) {}

SystemImpl::~SystemImpl() {}

SystemImpl::SystemImpl(const SystemImpl& other) {
    this->name = other.name;
    this->value = other.value;
}

SystemImpl& SystemImpl::operator=(const SystemImpl& other) {
    if (this == &other) return *this;
    this->name = other.name;
    this->value = other.value;
    return *this;
}

std::string SystemImpl::getName() const { return name; }
void SystemImpl::setName(const std::string& name) { this->name = name; }
double SystemImpl::getValue() const { return value; }
void SystemImpl::setValue(double v) { value = v; }