#include <iostream>
using namespace std;

int main()
{
    int arr[2][2]={
        {1,5},
        {7,4}
    };
    int (*ptr)[2][2];
    ptr=&arr;
    
    cout << ptr << endl;
    cout << (*ptr) << endl;
    cout << ***ptr << endl;
    
}