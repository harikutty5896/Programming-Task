#include <iostream>
#include <string>
using namespace std;

class Chair
{
    public:
      virtual ~Chair(){}
      virtual string Details() const =0;
};

class PlasticChair : public Chair
{
    public:
    string Details() const override
    {
      return "I am Chair : Plastic Chair \n" ;
    }
};

class SteelChair : public Chair
{
    public:
    string Details() const override
    {
      return "I am Chair : Steel Chair \n" ;
    }
};

class Table
{
    public:
    virtual ~Table(){}
    virtual string Details() const =0;
};

class PlasticTable : public Table
{
    public:
    string Details() const override
    {
        return "I am Table : Plastic Table \n" ;
    }
};

class SteelTable : public Table
{
    public:
    string Details() const override
    {
        return "I am Table : Steel Table \n" ;
    }
};


class FurnitureFactory
{
    public:
    virtual Chair* createChair() const =0;
    virtual Table* createTable() const =0;
};

class PlasticFactory : public FurnitureFactory
{
    public:
    Chair* createChair() const override
    {
        return new PlasticChair();
    }
    Table* createTable() const override
    {
        return new PlasticTable();
    }
    
};

class SteelFactory : public FurnitureFactory
{
    public:
    Chair* createChair() const override
    {
        return new SteelChair();
    }
    Table* createTable() const override
    {
        return new SteelTable();
    }
    
};

void clientcode(const FurnitureFactory &factory,int id)
{
    if(id==1)
    {
        const Chair *c_product_plastic = factory.createChair();
        cout << c_product_plastic->Details();
        delete c_product_plastic;
    }
    else if(id==2)
    {
        const Table *t_product_plastic = factory.createTable();
        cout << t_product_plastic->Details();
        delete t_product_plastic;
    }
    else
    {
        cout << "Invalid Option" << endl;
    }
}

int main()
{
    int x;
    int y;
    cout << "Enter 1 for Plastic Products \nEnter 2 for Steel products" << endl;
    cin >> x;
    if(x==1)
    {
        cout << "Enter 1 for Chair \nEnter 2 for Table" << endl;
        cin >> y;
        if(y==1)
        {
            PlasticFactory *p = new PlasticFactory();
            clientcode(*p,1);
            delete p;
        }
        else if(y=2)
        {
            PlasticFactory *p = new PlasticFactory();
            clientcode(*p,2);
            delete p;
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }
    }
    else if(x==2)
    {
        cout << "Enter 1 for Chair \nEnter 2 for Table" << endl;
        cin >> y;
        if(y==1)
        {
           SteelFactory *s = new SteelFactory();
           clientcode(*s,1);
           delete s; 
        }
        else if(y=2)
        {
            SteelFactory *s = new SteelFactory();
            clientcode(*s,2);
            delete s; 
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }
       
    }
    else
    {
        cout << "Invalid Option" << endl;
    }
    return 0;
}