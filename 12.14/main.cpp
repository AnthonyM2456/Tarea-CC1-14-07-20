// Fig. 12.17: fig12_17.cpp
// Processing Employee derived-class objects with static binding
// then polymorphically using dynamic binding.
#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "PieceWorker.h"
#include "HourlyWorker.h"

using namespace std;

void virtualViaPointer(const Employee* const); // prototype
void virtualViaReference(const Employee&); // prototype

int main() {

    cout << fixed << setprecision(2); // set floating-point formatting
    // create derived-class objects
    SalariedEmployee salariedEmployee{"John", "Smith", "111-11-1111", 800};
    CommissionEmployee commissionEmployee{"Sue", "Jones", "333-33-3333", 10000, .06};
    BasePlusCommissionEmployee basePlusCommissionEmployee{"Bob", "Lewis", "444-44-4444", 5000, .04, 300};
    PieceWorker pieceworker{"George", "Zue", "222-22-2222", 50, 50}; // salario por objeto -- objetos
    HourlyWorker hourlyworker1{"Kyle", "Mizu", "123-45-678", 80, 24}; //salario por hora -- horas trabajadas
    HourlyWorker hourlyworker2{"Vanessa", "Nury", "987-65-432", 100, 48}; //salario por hora -- horas trabajadas

    
    vector<Employee *> employees{&salariedEmployee, &commissionEmployee, &basePlusCommissionEmployee, &pieceworker, &hourlyworker1, &hourlyworker2};

    cout << "\nEMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNAMIC BINDING\n\n";

    // call virtualViaPointer to print each Employee's information
    // and earnings using dynamic binding
    cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS POINTERS\n\n";

    for (const Employee* employeePtr : employees) {
        virtualViaPointer(employeePtr);
    }

    // call virtualViaReference to print each Employee's information
    // and earnings using dynamic binding
    cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCES\n\n";

    for (const Employee* employeePtr : employees) {
        virtualViaReference(*employeePtr); // note dereferencing
    }
}

// call Employee virtual functions toString and earnings off a
// base-class pointer using dynamic binding
void virtualViaPointer(const Employee* const baseClassPtr) {
    cout << baseClassPtr->toString() << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}

// call Employee virtual functions toString and earnings off a
// base-class reference using dynamic binding
void virtualViaReference(const Employee& baseClassRef) {
    cout << baseClassRef.toString() << "\nearned $" << baseClassRef.earnings() << "\n\n";
}