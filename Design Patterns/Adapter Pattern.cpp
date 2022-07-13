
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Target
{
public:
    virtual ~Target() = default;

    virtual string Request() const
    {
        return "Inside Request Block";
    }

};


class Adaptee
{
public:
    string NeedtoModified()
    {
        string s = "gnirtS desreveR ma I";
        return s;
    }
};


class Adapter : public Target
{
private:
    Adaptee* adaptee_;
public:
    Adapter(Adaptee* a) : adaptee_(a)
    {

    }

    string Request() const override
    {
        string needtomodified = this->adaptee_->NeedtoModified();
        string result;
        stack<int> stk;

        for (char ch : needtomodified)
        {
            stk.push(ch);
        }

        for (int i = 0; i < needtomodified.size(); i++)
        {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;

    }
};
void Client(const Target* target)
{
    cout << target->Request();
}
int main()
{
    Adaptee* adaptee = new Adaptee;
    Adapter* adapter = new Adapter(adaptee);
    Client(adapter);
}