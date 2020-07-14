#ifndef PIECE_H
#define PIECE_H

#include "Employee.h"
#include <string>

using namespace std;

class PieceWorker : public Employee{
    private:
        double wage;
        double pieces;
    public:
        PieceWorker(const string&, const string&, const string&, double = 0.0, double = 0.0);

        virtual ~PieceWorker() = default;

        void setWage(double);
        double getWage() const;
        void setPieces(double);
        double getPieces() const;

        virtual double earnings() const override;
        virtual std::string toString() const override; 
};
#endif 