#include "pch.h"
#include <iostream>
#include <mutex>  
#include <chrono>
#include <thread>
#include <string>
using namespace std;
class Singleton
{
private:
    static mutex mtx;
    static Singleton* instance;

protected:
    string value;
    Singleton(string v) :value(v)
    {
    }

public:
    Singleton(Singleton& other) = delete;
    void operator=(const Singleton&) = delete;
    static Singleton* GetInstance(const string& value);
    string getValue() const
    {
        return value;
    }
};

Singleton* Singleton::instance{ nullptr };
mutex Singleton::mtx;

Singleton* Singleton::GetInstance(const string& value)
{
    lock_guard<mutex> lock(mtx);
    if (instance == nullptr)
    {
        instance = new Singleton(value);
    }
    return instance;
}

void Threadone()
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("one");
    cout << singleton->getValue() << endl;

}

void Threadtwo()
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("two");
    cout << singleton->getValue() << endl;
}

int main()
{
    thread t1(Threadone);
    thread t2(Threadtwo);
    t1.join();
    t2.join();
    return 0;
}


