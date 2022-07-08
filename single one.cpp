#include <iostream>
#include<unordered_map>
using namespace std;
int SingleOne(int a[], int n)
{
    unordered_map<int,int>fmap;
    for(int i = 0; i < n;i++)
    {
        fmap[a[i]]++;
    }
 
    for(auto it:fmap)
    {
        if(it.second == 1)
        {
            return it.first;
        }
    }
}

int main()
{
    int n,i;
    cout << "Enter total number of elements:";
    cin >> n;
	int arr[n];
	for(i=0;i<n;i++){
	    cin >> arr[i];
	}
	cout <<	SingleOne(arr, n);
	return 0;
}
