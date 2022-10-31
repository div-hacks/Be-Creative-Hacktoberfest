#include<iostream>
using namespace std;
int maxSum( int arr[], int n) 
    {
       int tempMax = arr[0];
       int cMax = tempMax;
       for (int i = 1; i < n; i++ ) 
       { 
          cMax = max(arr[i], cMax+arr[i]);
          tempMax = max(tempMax, cMax);
       }
       return tempMax;
    }
int main() 
{
       int n;
       cout<<"enter no";
    cin>>n;
    int a [n];
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
       cout << "Maximum Sum of the Sub-array is: "<< maxSum( a, n );
}