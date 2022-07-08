#include <iostream>
using namespace std;

int main()
{
    char arr[]="Helloworld";
    char *chrptr;
    chrptr = &arr[0];
    cout << chrptr;

}
//Output :: Helloworld -- Identify why cout behave different when char array
//Answer - cout cant able to identify it as a pointer (%p)..instead of it act as a string(%s) so its printing char until it reach '\0'