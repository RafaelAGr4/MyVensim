#include "system.hpp"

System::System(std::string name, double value) {
    this->name = name;
    this->value = value;
}
System::~System() {}

System::System(const System& other) {
    this->name = other.name;
    this->value = other.value;
}
System& System::operator=(const System& other) {
    if (this == &other) return *this;
    this->name = other.name;
    this->value = other.value;
    return *this;
}
std::string System::getName() const { return name; }
double System::getValue() const { return value; }
void System::setValue(double v) { value = v; }