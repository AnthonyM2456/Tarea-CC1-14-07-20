#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include <string>
#include <iostream>

using namespace std;

class MotorVehicle{

    private: //metodos

    string make;
    string fuelType;
    int yearOfManufacture;
    string color;
    int engineCapacity;

    public: //atributos

    MotorVehicle(); //constructor sin argumentos
    MotorVehicle(string, string, int, string, int); //contructor con argumentos
    MotorVehicle(const MotorVehicle&); //constructor copia
    
    void displayCarDetails(); //print

    //sobrecarga de operadores
    bool operator ==(const MotorVehicle &p) const; 
    bool operator !=(const MotorVehicle &p) const;
    bool operator >(const MotorVehicle &p) const;
    friend ostream& operator << (ostream &o,const MotorVehicle &p);

    //setters y getters
    void setMake(string);
    string getMake();

    void setFuelType(string);
    string getFuelType();

    void setYear(int);
    int getYear();

    void setColor(string);
    string getColor();

    void setEngine(int);
    int getEngine();

};

#endif