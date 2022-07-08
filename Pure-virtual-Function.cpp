#include <iostream>
using namespace std;

class Animal
{
  public:
    virtual void MakeNoise() =0;
};

class dog : public Animal
{
    public:
         void MakeNoise()
         {
             cout << "I am Dog" << endl;
         }
};

class cat : public Animal
{
    public:
        void MakeNoise()
        {
            cout << "I am cat" << endl;
        }
};

int main()
{
    Animal *d= new dog();
    d->MakeNoise();
    
    Animal *c= new cat();
    c->MakeNoise();
    
    return 0;
}
