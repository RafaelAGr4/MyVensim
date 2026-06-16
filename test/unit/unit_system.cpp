#include "unit_system.h"
#include "../../src/factory.hpp"
#include <cassert>

void unit_System_constructor(void) {
    System* s1 = createSystem();
    assert(s1->getValue() == 0.0);
    assert(s1->getName() == "");

    System* s2 = createSystem("Test", 10.0);
    assert(s2->getValue() == 10.0);
    assert(s2->getName() == "Test");

    delete s1;
    delete s2;
}

void unit_System_destructor(void) {}

void unit_System_getName(void) {
    System* s = createSystem("SystemName", 0.0);
    assert(s->getName() == "SystemName");
    delete s;
}

void unit_System_getValue(void) {
    System* s = createSystem("Test", 10.5);
    assert(s->getValue() == 10.5);
    delete s;
}

void unit_System_setValue(void) {
    System* s = createSystem();
    s->setValue(100.0);
    assert(s->getValue() == 100.0);
    delete s;
}

void run_unit_tests_System(void) {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_getName();
    unit_System_getValue();
    unit_System_setValue();
}