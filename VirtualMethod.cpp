#include<iostream>
using namespace std;

class VirtualExample
{
    public:
    virtual void display()
    {
        cout << "Virtual Method Inside Base Class" << endl;
    }
};

class VirtualDerived : public VirtualExample
{
    public:
    void display()
    {
        cout << "Virtual Method Inside Sub class " << endl;
    }
};

class Derived : public VirtualExample
{
    public:
    Derived()
    {
        cout << "Non Virtual Class Constructor Invoked" << endl;
    }
};

int main()
{
    VirtualExample *ptr = new VirtualDerived();
    ptr->display();
    
    VirtualExample  *ptr2 = new Derived();
    ptr2->display();
    
}