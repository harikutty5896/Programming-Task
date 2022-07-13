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
    simpleCar(string n,int s,int p)
        :Car (n,s,p)
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

enum CarType{Racecar,SimpleCar};

class Client
{
private:
    unordered_map<CarType,unique_ptr<Car>, hash<int>> m_cars;
public:
    Client()
    {
        m_cars[SimpleCar] = make_unique<simpleCar>("Simple Car", 60, 200);
        m_cars[Racecar] = make_unique<RaceCar>("Race Car", 120, 400);
    }

    unique_ptr<Car> createCar(CarType CarType)
    {
        return m_cars[CarType]->clone();
    }
};

int main()
{
    Client client;
    auto Car = client.createCar(SimpleCar);
    Car->carDetails("Green");
    Car = client.createCar(SimpleCar);
    Car->carDetails("Red");


    Car = client.createCar(Racecar);
    Car->carDetails("Blue");
    Car = client.createCar(Racecar);
    Car->carDetails("Violet");
}