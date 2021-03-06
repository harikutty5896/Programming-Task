#include "pch.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;

class Car
{
protected:
    string name;
    int speed;
    int power;
    string color;

public:
    Car()
    {}
    Car(string n, int s, int p)
        :name(n), speed(s), power(p)
    {}
    ~Car()
    {}
    virtual unique_ptr<Car> clone() = 0;
    void carDetails(string c)
    {
        color = c;

        cout << "Car Name :" << name << endl;
        cout << "Car Speed:" << speed << endl;
        cout << "Car Power:" << power << endl;
        cout << "Car Color:" << color << endl;
        cout << "______________________________" << endl;

    }
};

class simpleCar : public Car
{
public:
    simpleCar(string n, int s, int p)
        :Car(n, s, p)
    {}
    unique_ptr<Car> clone()
    {
        return make_unique<simpleCar>(*this);
        
    }
};

class RaceCar : public Car
{
public:
    RaceCar(string n, int s, int p)
        :Car(n, s, p)
    {}
    unique_ptr<Car> clone()
    {
        return make_unique<RaceCar>(*this);
    }
};

enum CarType { racecar, simplecar };

class CarFactory
{
private:
    unordered_map<CarType, unique_ptr<Car>, hash<int>> m_cars;
public:
    CarFactory()
    {
        m_cars[simplecar] = make_unique<simpleCar>("Simple Car", 60, 200);
        m_cars[racecar] = make_unique<RaceCar>("Race Car", 120, 400);
    }

    unique_ptr<Car> createCar(CarType cartype)
    {
        return m_cars[cartype]->clone();
    }
};

int main()
{
    CarFactory carfactory;
    auto Car = carfactory.createCar(simplecar);
    Car->carDetails("Green");

    Car = carfactory.createCar(simplecar);
    Car->carDetails("Red");


   /* Car = carfactory.createCar(racecar);
    Car->carDetails("Blue");
    Car = carfactory.createCar(racecar);
    Car->carDetails("Violet");*/
}