// Fig. 10.19: fig10_19.cpp
// HugeInteger test program.
#include <iostream>
#include "HugeInteger.h"
using namespace std;
int main() {
    HugeInteger n1{7654321};
    HugeInteger n2{7891234};
    HugeInteger n3{"99999999999999999999999999999"};
    HugeInteger n4{"1"};
    HugeInteger n5;
    HugeInteger n6{24};
    HugeInteger n7{12};
    HugeInteger n8{"12"};
    
    
    cout << n6 << " * " << n7 << " = " << (n6 * n7) << endl; 
    cout << n6 << " * " << 10 << " = " << (n6 * 10) << endl; 
    cout << n7 << " * " << "20" << " = " << (n6 * "20") << endl; 
    
    cout << n6 << " / " << n7 << " = " << (n6 / n7) << endl; 
    cout << n6 << " / " << 2 << " = " << (n6 / 2) << endl; 
    cout << n6 << " / " << "6" << " = " << (n6 / "6") << endl; 

    cout << "\n\nComparando: " << boolalpha
        << "\nn6 > n7? " << ((n6 > n7)? "Si" : "No")
        << "\nn7 > n6? " << ((n7 > n6)? "Si" : "No")
        << "\nn7 == n8? " << ((n7 == n8)? "Si" : "No")
        << "\nn6 == n7? " << ((n6 == n7)? "Si" : "No")
        << "\nn8 < n6? " << ((n8 < n6)? "Si" : "No")
        << "\nn7 < n6? " << ((n7 < n6)? "Si" : "No")
        << "\nn7 >= n8? " << ((n7 >= n8)? "Si" : "No")
        << "\nn6 <= n7? " << ((n6 <= n7)? "Si" : "No") << endl;

}