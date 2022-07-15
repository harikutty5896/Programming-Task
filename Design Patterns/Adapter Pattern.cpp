
#include <iostream>
#include <string>
#include <stack>
using namespace std;

enum Types { Number };

class ClientInterface
{
public:
    virtual ~ClientInterface() = default;

    virtual string Request() const
    {
        return "";
    }

    virtual int Request(Types t) const
    {
        return 0;
    }

};


class Adaptee
{
private:
    string password;
public:
    Adaptee(string p) : password(p)
    {

    }
    string NeedtoModified()
    {
        return password;
    }
    int NumNeedtoModified()
    {
        return 100;
    }
};


class Adapter : public ClientInterface
{
private:
    Adaptee* adapte;
public:
    Adapter(Adaptee* a) : adapte(a)
    {

    }

    string Request() const override
    {
        string needtomodified = this->adapte->NeedtoModified();
        string result;
        for (char ch : needtomodified)
        {
            result.push_back(ch + 1);
        }
        return result;

    }
};

class NumberAdapter : public ClientInterface
{
private:
    Adaptee* adaptee;
public:
    NumberAdapter(Adaptee* a) : adaptee(a)
    {

    }
    int Request(Types t) const override
    {
        int numneedtomodified = this->adaptee->NumNeedtoModified();
        return (numneedtomodified * 100);
    }
};

void Client(const ClientInterface* target, Types t)
{
    cout << target->Request();
    cout << endl;
    cout << target->Request(t);
}

int main()
{
    string password;
    cout << "Enter Password :" << endl;
    cin >> password;

    Types types = Number;

    Adaptee* adaptee = new Adaptee(password);

    //String Adapter
    Adapter* adapter = new Adapter(adaptee);
    Client(adapter, types);

    //Number Adapter
    NumberAdapter* adapter2 = new NumberAdapter(adaptee);
    Client(adapter2, types);
}