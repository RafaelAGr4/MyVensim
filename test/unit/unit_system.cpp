/// Arquivo unit_System.cpp"
#include "unit_System.h"
#include "..\..\src\system.h"

  void unit_System_constructor( void){
        System s1();
        assert( s1.getValue() == 0 );
        System s2(10);
        assert( s2.getValue() == 10 );
  }

void unit_System_destructor( void){ };

void unit_System_getValue( void){
        System s(10);
        assert( s.getValue() == 10 );
}

void unit_System_setValue( void ) {
        System s();
        s.setValue(100);
        assert( s.getValue() == 100 );
}

void run_unit_tests_System( void ){
        unit_System_constructor();
        unit_System_destructor();
        unit_System_getValue();
        unit_System_setValue();
}