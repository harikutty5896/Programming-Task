#include "pch.h"
#include <iostream>

using namespace std;

class Subject
{

public:
    virtual void Request() = 0;

};

class RealSubject : public Subject
{
public:
    void Request()
    {
        cout << "Inside Real Subject Block" << endl;
    }
};

class Proxy : public Subject
{
private:
    RealSubject* realsubject;

public:
    Proxy()
    {
        realsubject = new RealSubject();
    }
    void Request()
    {
        cout << "Inside Proxy Block before sending request to Real Subject" << endl;
        realsubject->Request();
    }
};


int main()
{
    Proxy* proxy = new Proxy();
    proxy->Request();
}
