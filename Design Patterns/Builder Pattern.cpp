#include <iostream>
using namespace std;

class Car
{
private:
    string type;
    string body;
    string engine;
public:
    Car(string t)
        :type(t)
    {
    }
    //Setters
    void setBody(string b)
    {
        body = b;
    }
    void setEngine(string e)
    {
        engine = e;
    }

    //Getters
    string getBody()
    {
        return body;
    }
    string getEngine()
    {
        return engine;
    }

    void showCarDetails()
    {
        cout << "Car Type :" << type << endl;
        cout << "Car Body :" << body << endl;
        cout << "Car Engine :" << engine << endl;
    }
};

class CarBuilder
{
protected:
    Car* car;

public:
    virtual void getParts() = 0;
    virtual void createBody() = 0;
    virtual void createEngine() = 0;

    Car* getCar()
    {
        return car;
    }

};

class RaceCarBuilder : public CarBuilder
{
    void getParts()
    {
        car = new Car("Racecar");
    }

    void createBody()
    {
        car->setBody("Racecar Body");
    }

    void createEngine()
    {
        car->setEngine("Racecar Engine");
    }
};

class NormalCarBuilder : public CarBuilder
{
    void getParts()
    {
        car = new Car("NormalCar");
    }
    void createBody()
    {
        car->setBody("NormalCar Body");
    }
    void createEngine()
    {
        car->setEngine("NormalCar Engine");
    }
};

class Director
{
public:
    Car* createCar(CarBuilder* carbuilder)
    {
        carbuilder->getParts();
        carbuilder->createBody();
        carbuilder->createEngine();

        return carbuilder->getCar();
    }
};
int main()
{
    Director* dr;
    RaceCarBuilder rcb;
    NormalCarBuilder ncb;

    Car* rcar = dr->createCar(&rcb);
    Car* ncar = dr->createCar(&ncb);

    rcar->showCarDetails();
    ncar->showCarDetails();

}
