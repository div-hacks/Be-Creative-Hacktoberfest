#include<iostream>

using namespace std;


int main()
{
    int arr[5] = {3,1,4,5,2};

    for(int i=1;i<6;i++)
    {
        for(int j=1;j<6;j++)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = i;
        }
    }

    for(int k=1;k<6;k++)
        cout<<arr[k]<<" ";

    return 0;
}
