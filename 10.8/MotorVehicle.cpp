#include "MotorVehicle.h"
#include <iostream>
#include <string>
using namespace std;

MotorVehicle::MotorVehicle(string make, string fuelType, int yearOfManufacture, string color, int engineCapacity){ //contructor 1

    this->make = make;
    this->fuelType = fuelType;
    this->yearOfManufacture = yearOfManufacture;
    this->color = color;
    this->engineCapacity = engineCapacity;
    cout << "Objeto creado" << endl;
}
MotorVehicle::MotorVehicle(){
    this->make = " ";
    this->fuelType = " ";
    this->yearOfManufacture = 0;
    this->color = " ";
    this->engineCapacity = 0;
    cout << "Objeto creado" << endl;
}
void MotorVehicle::displayCarDetails(){

    cout << "make: " << this->make << endl;
    cout << "fuelType: " << this->fuelType << endl;
    cout << "yearOfManufacture: " << this->yearOfManufacture << endl;
    cout << "color: " << this->color << endl;
    cout << "engineCapacity: " << this->engineCapacity << endl;

}

//sobrecarga de operadores
bool MotorVehicle::operator ==(const MotorVehicle &p) const{
    if(this->make == p.make && 
        this->fuelType == p.fuelType && 
        this->yearOfManufacture == p.yearOfManufacture && 
        this->color == p.color && 
        this->engineCapacity == p.engineCapacity){
        return true;
    }
    return false;
}
bool MotorVehicle::operator !=(const MotorVehicle &p) const{
    if(this->make == p.make && 
        this->fuelType == p.fuelType && 
        this->yearOfManufacture == p.yearOfManufacture && 
        this->color == p.color &&  
        this->engineCapacity == p.engineCapacity){
        return false;
    }
    return true;
}
bool MotorVehicle::operator >(const MotorVehicle &p) const{
    return this->yearOfManufacture > p.yearOfManufacture;
}

ostream& operator << (ostream &o,const MotorVehicle &p){
    o << "make: " << p.make << endl << 
    "fuelType: " << p.fuelType << endl <<
    "yearOfManufacture: " << p.yearOfManufacture << endl <<
    "color: " << p.color << endl <<
    "engineCapacity: " << p.engineCapacity << endl;

    return o;
}

//setters y getters
void MotorVehicle::setMake(string make){
    this->make = make;
}
string MotorVehicle::getMake(){
    return this->make;
}
void MotorVehicle::setFuelType(string fuelType){
    this->fuelType = fuelType;
}
string MotorVehicle::getFuelType(){
    return this->fuelType;
}
void MotorVehicle::setYear(int year){
    this->yearOfManufacture = year;
}
int MotorVehicle::getYear(){
    return this->yearOfManufacture;
}
void MotorVehicle::setColor(string color){
    this->color = color;
}
string MotorVehicle::getColor(){
    return this->color;
}
void MotorVehicle::setEngine(int engine){
    this->engineCapacity = engine;
}
int MotorVehicle::getEngine(){
    return this->engineCapacity;
}