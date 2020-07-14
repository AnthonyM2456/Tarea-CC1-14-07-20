#include "MotorVehicle.h"

using namespace std;

int main(){
    
    MotorVehicle a("Kia", "Gas 90", 2017, "Red", 1600);
    MotorVehicle b("Mercedes-Benz", "Gas 98", 2020, "Gold", 2000);
    MotorVehicle c("Mercedes-Benz", "Gas 98", 2020, "Gold", 2000);
    MotorVehicle d("Kia", "Gas 90", 2018, "Red",  1800);

    cout << "Details Car a: " << endl;
    a.displayCarDetails();
    cout << "*************************" << endl;
    cout << "Details Car b: " << endl;
    b.displayCarDetails();
    cout << "*************************" << endl;
    cout << "Details Car c: " << endl;
    c.displayCarDetails();
    cout << "*************************" << endl;
    cout << "Details Car d: " << endl;
    d.displayCarDetails();
    cout << "*************************" << endl;

    //uso de sobrecarga de operadores == != >
    cout << "A == B?: " << ( (a==b) ? "Si": "No" ) << endl;
    cout << "B == C?: " << ( (b==c) ? "Si": "No" ) << endl;
    cout << "A != B?: " << ( (a!=b) ? "Si": "No" ) << endl;
    cout << "B != C?: " << ( (b!=c) ? "Si": "No" ) << endl;
    cout << "Year(A) > Year(D)?: " << ( (a>d) ? "Si": "No" ) << endl;

    //uso sobrecarga operador <<
    cout << a;
    cout << "*************************" << endl;
    cout << b;
    cout << "*************************" << endl;
    cout << c;
    cout << "*************************" << endl;
    cout << d;
    
    

    return 0;
}
