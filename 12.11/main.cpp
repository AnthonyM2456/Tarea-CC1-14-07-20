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


using namespace std;

void virtualViaPointer(const Employee* const); // prototype
void virtualViaReference(const Employee&); // prototype
Date fecha(11,11,2007);

int main() {

    cout << fixed << setprecision(2); // set floating-point formatting
    // create derived-class objects
    
    SalariedEmployee salariedEmployee{"John", "Smith", "111-11-1111", Date(11,29,1977), 800};
    CommissionEmployee commissionEmployee{"Sue", "Jones", "333-33-3333", Date(7,25, 1990), 20000, .05};
    BasePlusCommissionEmployee basePlusCommissionEmployee{"Bob", "Lewis", "444-44-4444", Date(2,12,1985), 5000, .04, 300};
    
    vector<Employee *> employees{&salariedEmployee, &commissionEmployee, &basePlusCommissionEmployee};

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
    if (baseClassPtr->BD.getMonth()==fecha.getMonth()){
        cout <<baseClassPtr->toString() << "\nearned $" <<baseClassPtr->earnings() + 100 << "\n\n";
    }
    else{
        cout <<baseClassPtr->toString() << "\nearned $" <<baseClassPtr->earnings() << "\n\n";
    }
}
// call Employee virtual functions toString and earnings off a
// base-class reference using dynamic binding
void virtualViaReference(const Employee& baseClassRef) {
    if(baseClassRef.BD.getMonth()==fecha.getMonth()){
        cout <<baseClassRef.toString() << "\nearned $" <<baseClassRef.earnings()+100.0 << "\n\n";
    }
    else{
        cout <<baseClassRef.toString() << "\nearned $" << baseClassRef.earnings()<< "\n\n";
    }
}