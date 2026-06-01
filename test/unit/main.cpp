/// Arquivo main.cpp"
#include "unit_tests.h"
#include "unit_System.h"
#include <iostream>
using namespace std;

int main(){

    run_unit_tests_System();
    cout << "System [OK]" << endl;
    run_unit_tests_Flow();
    cout << "Flow [OK]" << endl;
    run_unit_tests_FlowTypes();
    cout << "FlowType [OK]" << endl;
    run_unit_tests_Model();
    cout << "Model [OK]" << endl;
    cout << "All test [OK]!" << endl;
    return 0;

}