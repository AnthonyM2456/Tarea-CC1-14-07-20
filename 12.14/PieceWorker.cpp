#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "PieceWorker.h"

using namespace std;

PieceWorker::PieceWorker(const string& first, const string& last,
    const string& ssn, double wage, double pieces) 
    : Employee(first, last, ssn) {
    setWage(wage);
    setPieces(pieces);
}
void PieceWorker::setWage(double w) {

    if (w < 0.0) {
        throw invalid_argument("Wage must be >= 0.0");
    }

    wage = w;
}

double PieceWorker::getWage() const{
    return wage;
}

void PieceWorker::setPieces(double p) { 
    if(p < 0.0) {
        throw invalid_argument("Pieces must be >= 0.0");
    }

    pieces = p;
}

double PieceWorker::getPieces() const{
    return pieces;
}

double PieceWorker::earnings() const {
    return getWage() * getPieces();
}
string PieceWorker::toString() const {
    ostringstream output;
    output << fixed << setprecision(2);
    output << "Piece Worker: " << Employee::toString()
        << "\nWage per piece: " << getWage()
        << "; Pieces produced: " << getPieces();
    return output.str();
}