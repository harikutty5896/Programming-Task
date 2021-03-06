#include "pch.h"
#include <iostream>
#include <memory>
using namespace std;

class ConstructHouse  //template Class
{
public:
    void MakeHouse()  //template Method
    {
        this->SetWall();
        this->SetRoof();
        this->SetWindow();
        this->SetDoors();
        this->SetDecoration();
        this->MakeCompound();

    }
protected:

    void SetWall() //Basic Operation
    {
        cout << "House Wall Added" << endl;
    }
    void SetRoof() //Basic Operation
    {
        cout << "House Roof Added" << endl;
    }

    virtual void SetWindow() = 0;
    virtual void SetDoors() = 0;

    virtual void SetDecoration()
    {
    }
    virtual void MakeCompound()
    {
    }


};

class ConstructWoodenHouse : public ConstructHouse
{
    void SetWindow() //required operation
    {
        cout << "Wooden Window Added" << endl;
    }
    void SetDoors() //required operation
    {
        cout << "Wooden Doors Added" << endl;
    }

    void MakeCompound()
    {
        cout << "Compound Wall Added " << endl;
    }
};

class ConstructSteelHouse : public ConstructHouse
{
    void SetWindow() //required operation
    {
        cout << "Steel Window Added" << endl;
    }
    void SetDoors() //required operation
    {
        cout << "Steel Doors Added" << endl;
    }

    void SetDecoration()
    {
        cout << "House Decoration Added" << endl;
    }
};


int main()
{
    int x;
    cout << "Enter 1 for Wooden House \nEnter 2 for Steel House" << endl;
    cin >> x;

    if (x == 1)
    {
        shared_ptr<ConstructWoodenHouse> woodenhouse = make_shared<ConstructWoodenHouse>();
        woodenhouse->MakeHouse();
    }
    else if (x == 2)
    {
        shared_ptr<ConstructSteelHouse> steelhouse = make_shared<ConstructSteelHouse>();
        steelhouse->MakeHouse();
    }

}
