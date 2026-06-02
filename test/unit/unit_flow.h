#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

void unit_Flow_constructor(void);
void unit_Flow_destructor(void);
void unit_Flow_getName(void);
void unit_Flow_setName(void);
void unit_Flow_getOrigin(void);
void unit_Flow_setOrigin(void);
void unit_Flow_getDestination(void);
void unit_Flow_setDestination(void);
void unit_Flow_execute(void);

void run_unit_tests_Flow(void);

#endif