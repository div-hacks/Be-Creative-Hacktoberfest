#include<iostream>

using namespace std;

int main()
{
    int arr[5], i, k=0, c1=0, c2=0, c3=0;
    
    for(i=0;i<5;i++)
        cin>>arr[i];

    for (i = 0; i < 5; i++)
    {
        if(arr[i]==0)
            c1++;
        else if (arr[i]==1)
            c2++;
        else
            c3++;
    }
    
    for(i=0;i<c1;i++)
    {
        arr[k] = 0;
        k++;
    }
    for(i=0;i<c2;i++)
    {
        arr[k] = 1;
        k++;
    }
    for(i=0;i<c3;i++)
    {
        arr[k] = 2;
        k++;
    }

    for (i = 0; i < 5; i++)
    {
        cout<<arr[i];
    }
    

    return 0;
}
