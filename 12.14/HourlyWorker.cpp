#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "HourlyWorker.h" // SalariedEmployee class definition

using namespace std;

HourlyWorker::HourlyWorker(const string& first, const string& last,
    const string& ssn, double wage, double hours) 
    : Employee(first, last, ssn){
    setWage(wage);
    setHours(hours);
}
void HourlyWorker::setWage(double w) {

    if (w < 0.0) {
        throw invalid_argument("Wage must be >= 0.0");
    }
    wage = w;
}

double HourlyWorker::getWage() const{
    return wage;
}

void HourlyWorker::setHours(double h) { 
    if(h < 0.0) {
        throw invalid_argument("Hours must be >= 0.0");
    }
    hours = h;
}

double HourlyWorker::getHours() const{
    return hours;
}
double HourlyWorker::earnings() const{
    int earnings{0};

    if(hours > 40){

        earnings = (getWage() * 40) + (getWage() * 1.5 * (getHours() - 40));
        return earnings;
    }
    else{
        return getWage() * getHours();
    }
}
string HourlyWorker::toString() const {
    ostringstream output;
    output << fixed << setprecision(2);
    output << "Hourly Worker: " << Employee::toString()
        << "\nWage per hour: " << getWage()
        << "; Hours Worked: " << getHours();
    return output.str();
}

