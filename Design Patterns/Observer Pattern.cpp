#include "pch.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;


class InterfaceObserver {
public:
    virtual ~InterfaceObserver() {};
    virtual void Update(const string& message_from_subject) = 0;
};

class InterfaceSubject {
public:
    virtual ~InterfaceSubject() {};
    virtual void Attach(InterfaceObserver* observer) = 0;
    virtual void Detach(InterfaceObserver* observer) = 0;
    virtual void Notify() = 0;
};


class Subject : public InterfaceSubject
{
private:
    list<InterfaceObserver*> Observer_list;
    string Message = "Low Power";

public:
    void Attach(InterfaceObserver* observer) override
    {
        Observer_list.push_back(observer);
        cout << "Observer Added" << endl;
    }

    void Detach(InterfaceObserver* observer) override
    {
        Observer_list.remove(observer);
        cout << "Observer Removed" << endl;
    }

    void Notify() override
    {
        for (auto itr = Observer_list.begin(); itr != Observer_list.end(); itr++)
        {
            (*itr)->Update(Message);
        }
    }

    void BatteryLevel(int val)
    {
        int Battery_limit = 30;
        cout << "Battery Level :" << val << endl;
        if (val <= Battery_limit)
        {
            Notify();
        }
    }
};

class Observer : public InterfaceObserver
{
private:
    string message;

public:
    void Update(const string& message)
    {
        cout << message << endl;
    }
};

int main()
{
    Subject* subject = new Subject();
    Observer* observer = new Observer();
    subject->Attach(observer);
    subject->BatteryLevel(60);
    subject->BatteryLevel(50);
    subject->BatteryLevel(40);
    subject->BatteryLevel(30);
    subject->BatteryLevel(20);
    subject->Detach(observer);
}