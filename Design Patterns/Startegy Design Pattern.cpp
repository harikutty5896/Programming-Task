#include <iostream>
#include <string>
using namespace std;


class VehicleStrategy
{
public:
    virtual ~VehicleStrategy() = default;
    virtual int ChooseVehicle() const = 0;
};


class BikeStartegy : public VehicleStrategy
{
private:
    VehicleStrategy* v;
public:
    int ChooseVehicle() const override
    {

        cout << "You are Travelling through Bike" << endl;
        return 10;

    }
};

class BusStartegy : public VehicleStrategy
{
    int ChooseVehicle() const override
    {
        cout << "You are  Travelling through Bus" << endl;
        return 100;
    }
};


class Travel
{
private:
    VehicleStrategy* vehiclestrategy;

public:
    Travel(VehicleStrategy* v) :vehiclestrategy(v)
    {

    }

    void TravelLogic()
    {
        cout << "Based on the Vehicle Startegy" << endl;
        int amount = this->vehiclestrategy->ChooseVehicle();
        cout << "Amount :" << amount << endl;
    }
};

void Client(Travel* travel)
{
    travel->TravelLogic();
}
int main()
{
    Travel* biketravel = new Travel(new BikeStartegy());
    Travel* bustravel = new Travel(new BusStartegy());
    int num;
    cout << "Enter 1 for Bike \nEnter 2 for Bus " << endl;
    cin >> num;
    if (num == 1)
    {
        Client(biketravel);
    }
    else if (num == 2)
    {
        Client(bustravel);
    }
}