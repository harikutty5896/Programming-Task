#include <iostream>
using namespace std;

int main()
{
    int n=5;
    int arr[n] ={2,3,4,5,6};
    int *ptr[n];
    for(int i=0;i<n;i++)
    {
        {
           ptr[i]=&arr[i]; 
        }
    }

    cout << "Values and Its Address" << endl;
    for(int i=0;i<n;i++)
    {
        cout << "Value :" << *ptr[i]  << " " << "Address :" << ptr[i] << endl;
    }
}