#include "pch.h"
#include <iostream>

using namespace std;

class ServiceInterface
{

public:
    virtual void Request(string pass)
    {

    }
};

class RealService : public ServiceInterface
{
public:
    void Request()
    {
        cout << "Finally request reached inside Real Service Block" << endl;
    }
};

class Proxy : public ServiceInterface
{
private:
    RealService* realservice;

public:
    Proxy()
    {
        realservice = new RealService();
    }
    bool BeforeProcessing(string p)
    {
        int num_count = 0;
        int u_str_count = 0;
        int l_str_count = 0;
        for (char ch : p)
        {
            if (isdigit(ch))
            {
                num_count++;
            }
            else
            {
                if (isupper(ch))
                {
                    u_str_count++;
                }
                else
                {
                    l_str_count++;
                }
            }
        }
        if (p.size() > 6)
        {
            if (num_count >= 2)
            {
                if (u_str_count >= 2)
                {
                    if (l_str_count >= 2)
                    {
                        return true;
                    }
                    else
                    {
                        cout << "Must Contain 2 Lowercase" << endl;
                        return false;
                    }
                }
                else
                {
                    cout << "Must Contain 2 Uppercase" << endl;
                    return false;
                }
            }
            else
            {
                cout << "Must Contain 2 Numbers" << endl;
                return false;
            }

        }
        else
        {
            cout << "Length Must be Greater than 6" << endl;
            return false;
        }

    }
    void Request(string p)
    {
        if (this->BeforeProcessing(p))
        {
            cout << "Validation Sucessful" << endl;
            realservice->Request();
        }
        else
        {
            cout << "Validation failed !! Proxy Blocked the Request" << endl;
        }

    }
};

void Client(Proxy* proxy, string p)
{
    proxy->Request(p);
}

int main()
{
    string password;
    cout << "Enter Password:" << endl;
    cin >> password;
    Proxy* proxy = new Proxy();
    Client(proxy, password);
}
