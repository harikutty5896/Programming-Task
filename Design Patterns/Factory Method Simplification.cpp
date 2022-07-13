#include"pch.h"
#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Product
{
public:
    virtual ~Product()
    {
    }
    virtual string ProductDetails() = 0;
};


class Chair : public Product
{
public:
    string ProductDetails() override
    {
        return "I am Product : Chair";
    }
};

class Table : public Product
{
public:
    string ProductDetails() override
    {
        return "I am Product : Table";
    }
};

class Factory
{
public:
    Factory() {}
    Product* FactoryMethod(int i)
    {
        if (i == 1)
        {
            return new Chair();
        }
        else if (i == 2)
        {
            return new Table();
        }
        else
        {
            cout << " Invalid Type";
        }
        return 0;
    }
    ~Factory() {}
};

int main()
{
    int x;
    cout << "Enter 1 for Chair \nEnter 2 for table" << endl;
    cin >> x;
    if (x == 1)
    {
        unique_ptr<Factory> factory = make_unique<Factory>();
        Product* p = factory->FactoryMethod(1);
        cout << p->ProductDetails();
        delete p;
    }
    else if (x == 2)
    {
        Factory* factory = new Factory();
        Product* p = factory->FactoryMethod(2);
        cout << p->ProductDetails();
        delete factory;
        delete p;
    }
    else
    {
        cout << "Not a Valid Choice" << endl;
    }
    return 0;
}
