// Fig. 10.18: HugeInteger.cpp
// HugeInteger member-function and friend-function definitions.
#include <cctype> // isdigit function prototype
#include "HugeInteger.h" // HugeInteger class definition
using namespace std;
// default constructor; conversion constructor that converts
// a long integer into a HugeInteger object
HugeInteger::HugeInteger(long value) {
 // place digits of argument into array
    for (int j{digits - 1}; value != 0 && j >= 0; j--) {
        integer[j] = value % 10;
        value /= 10;
    }
}

 // conversion constructor that converts a character string
 // representing a large integer into a HugeInteger object
HugeInteger::HugeInteger(const string& number) {
 // place digits of argument into array
    int length= number.size();

    for (int j{digits - length}, k{0}; j < digits; ++j, ++k) {
        if (isdigit(number[k])) { // ensure that character is a digit
            integer[j] = number[k] - '0';
        }
    }
} 
 // addition operator; HugeInteger + HugeInteger
HugeInteger HugeInteger::operator+(const HugeInteger& op2) const {
    HugeInteger temp; // temporary result
    int carry = 0;

    for (int i{digits - 1}; i >= 0; i--) {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;

 // determine whether to carry a 1
        if (temp.integer[i] > 9) {
        temp.integer[i] %= 10; // reduce to 0-9
        carry = 1;
        }else { // no carry
        carry = 0;
        }
    }

    return temp; // return copy of temporary object
}
bool HugeInteger::isEmpty() const{
    int sum{0};
    for (int i{digits - 1}; i >= 0; i--)
    {   
        if(integer[i])
            sum += integer[i];
    }
    return sum > 0 ? false : true;
}

 // addition operator; HugeInteger + int
HugeInteger HugeInteger::operator+(int op2) const {
 // convert op2 to a HugeInteger, then invoke
 // operator+ for two HugeInteger objects
    return *this + HugeInteger(op2);
}

 // addition operator;
 // HugeInteger + string that represents large integer value
HugeInteger HugeInteger::operator+(const string& op2) const {
 // convert op2 to a HugeInteger, then invoke
 // operator+ for two HugeInteger objects
    return *this + HugeInteger(op2);
}

 // overloaded output operator
ostream& operator<<(ostream& output, const HugeInteger& num) {
    int i;

 // skip leading zeros
    for (i = 0; (i < HugeInteger::digits) && (0 == num.integer[i]); ++i) { }

    if (i == HugeInteger::digits) {
        output << 0;
    }else {
        for (; i < HugeInteger::digits; ++i) {
        output << num.integer[i];
        }
    }
    return output;
} 

HugeInteger HugeInteger::operator*(const HugeInteger& op2) const {
    
    int tempRes{0}, temp{0}, carryInSorM{1}, result{0};

    for (int i{digits - 1}; i >= 0; i--){
        int carryInM{0}, decUnit{1};
        tempRes = 0;
        for (int j{digits - 1}; j >= 0; j--){
            temp = ((integer[i] * op2.integer[j]) + carryInM);

            if (temp>9){
                carryInM = temp / 10;
                temp %= 10;
            }else{
                carryInM = 0;
            }
            tempRes += (temp * decUnit);
            decUnit *= 10;
        }
        result += (tempRes * carryInSorM);
        carryInSorM *= 10;
    }

    HugeInteger resultado{result};
    
    return resultado; 
}

HugeInteger HugeInteger::operator*(int op2) const {
    return *this * HugeInteger(op2);
}

HugeInteger HugeInteger::operator*(const string& op2) const {
    return *this * HugeInteger(op2);
}

HugeInteger HugeInteger::operator/(const HugeInteger& op2) const {

    int dividen{0}, divisor{0}, decUnit{1};

    int division = 0;
    for (int i{digits - 1}; i >= 0; i--)
    {
        if (integer[i] || op2.integer[i]){
            dividen += integer[i] * decUnit;
            divisor += op2.integer[i] * decUnit;
            decUnit *= 10;
        }
    }
    if (divisor){
        division = dividen / divisor;
            HugeInteger temp{division};
            return temp;
    }else{
        cout << "Error: ";
        HugeInteger temp;
        return temp;
    }
}

HugeInteger HugeInteger::operator/(int op2) const {
    return *this / HugeInteger(op2);
}

HugeInteger HugeInteger::operator/(const string& op2) const {
    return *this / HugeInteger(op2);
}

bool operator==(const HugeInteger& op1, const HugeInteger& op2){
    //hI1 (HugeInteger1)
    bool result = false;
    if(op1.isEmpty() && op2.isEmpty()){
        result = true;
    }else{
    for (int i{op1.integer.size() -1}; i >= 0; i--){
        if (op1.integer[i] || op2.integer[i] ){
            if (op1.integer[i] == op2.integer[i]){
                result = true;
            }else{
                result = false;
                break;
            }
        }
    }
    }
    return result;
}
bool operator==(const HugeInteger& op1, int op2){
    return op1 == HugeInteger(op2);
}
bool operator==(const HugeInteger& op1, const std::string op2){
    return op1 == HugeInteger(op2);
}


bool operator!=(const HugeInteger& op1, const HugeInteger& op2){
    return !(op1 == op2);
}
bool operator!=(const HugeInteger& op1, int op2){
    return !(op1 == HugeInteger(op2));
}
bool operator!=(const HugeInteger& op1, const std::string op2){
    return !(op1 == HugeInteger(op2));
}


bool operator>(const HugeInteger& op1, const HugeInteger& op2){
    
    int number{0}, number2{0}, decimalUnit{1};
    for (int i{op1.digits - 1}; i >= 0; i--)
    {
        if (op1.integer[i] || op2.integer[i]){
            number += op1.integer[i] * decimalUnit;
            number2 += op2.integer[i] * decimalUnit;
            decimalUnit *= 10;
        }
    }
    return number > number2;
}
bool operator>(const HugeInteger& op1, int op2){
    return op1 > HugeInteger(op2);
}
bool operator>(const HugeInteger& op1, const std::string op2){
    return op1 > HugeInteger(op2);
}


bool operator<(const HugeInteger& op1, const HugeInteger& op2){
    return op2 > op1;
}
bool operator<(const HugeInteger& op1, int op2){
    return HugeInteger(op2) > op1;
}
bool operator<(const HugeInteger& op1, const std::string op2){
    return HugeInteger(op2) > op1;
}


bool operator>=(const HugeInteger& op1, const HugeInteger& op2){
    
    return !(op1 < op2);
}
bool operator>=(const HugeInteger& op1, int op2){
    return !(op1 < HugeInteger(op2));
}
bool operator>=(const HugeInteger& op1, const std::string op2){
    return !(op1 < HugeInteger(op2));
}


bool operator<=(const HugeInteger& op1, const HugeInteger& op2){
    return !(op1 > op2);
}
bool operator<=(const HugeInteger& op1, int op2){
    return !(op1 > HugeInteger(op2));
}
bool operator<=(const HugeInteger& op1, const std::string op2){
    return !(op1 > HugeInteger(op2));
}