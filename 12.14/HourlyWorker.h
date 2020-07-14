#ifndef HOURLY_H
#define HOURLY_H
#include "Employee.h"
#include <string>

using namespace std;

class HourlyWorker : public Employee {

    private:
        double wage;
        double hours;
    public:
        HourlyWorker(const string&, const string&, const string&, double = 0.0, double = 0.0);
        virtual ~HourlyWorker() = default;

        void setWage(double);
        double getWage() const;

        void setHours(double);
        double getHours() const;

        virtual double earnings() const override;
        virtual std::string toString() const override;
};
#endif