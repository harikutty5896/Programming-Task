#include <iostream>
using namespace std;

int main()
{
    int arr[2][2][2]={
        {
            {1,2},
            {3,4}
        },
        {
            {5,8},
            {9,7}
        }
    };
    
    int (*ptr)[2][2];
    ptr=arr;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                cout << ptr[i][j][k] << endl;
            }
        }
    }
    
}