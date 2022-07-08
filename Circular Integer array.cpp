#include <iostream>
#include<stack>
#include<vector>
using namespace std;
int getLarge(int a[],int n){
    int arr[2 * n];
    for (int i = 0; i < 2 * n; i++)
        arr[i] = a[i % n];
    int next, i, j;
    for (i = 0; i < n-1; i++) {
        next = -1;
        for (j = i + 1; j < 2 * n ; j++) {
            if (arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
        }
        cout << next << "\t";
    }
    return 0;
}
int main()
{
    int n,i,max,first;
    cout<<"Enter total number of elements:";
    cin >> n;
    int arr[n];
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << getLarge(arr,n);
    return 0;
}
