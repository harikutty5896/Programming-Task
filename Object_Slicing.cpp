#include<iostream>
#include<string>
using namespace std;
class employee
{
    public:
    string name;
    int age;

    employee(string n,int a)
    : name(n),age(a)
    {
    }
    virtual void showDetails()
    {
        cout << "Name :" << name << endl;
        cout << "Age :" << age << endl;
    }
    
};

class developer : public employee
{
    string p_lang;
    
    public:
    developer(string n,int a,string p) : employee(n,a)
    {
        p_lang=p;
    }
    virtual void showDetails()
    {
        cout << "Name :" << name << endl;
        cout << "Age :" << age << endl;
        cout << "Programming Language :" << p_lang;
    }
    
};

int main()
{
       developer d("Hari",21,"C++");
       employee e=d;
       e.showDetails();
}