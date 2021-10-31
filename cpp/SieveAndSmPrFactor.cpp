#include<iostream>

using namespace std;

//-------------------------------------------------------------

void sieveOfEratosthenes(int n) {
    int arr[n+1] = {0};

    for(int i = 2; i <= n; i++) {
        if(arr[i] == 0) {
            for (int j = i*i; j <= n; j += i)
            {
                arr[j] = 1;
            }
        }
        
    }
    
    for(int i=2; i<=n; i++) {
        if(arr[i] == 0) cout<<i<<" ";
    }
    cout<<endl;
}

//-----------------------------------------------------------------

void prFactUsingSieve(int n) {
    int arr[n+1] = {0};
    for (int i = 0; i <= n; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if(arr[i] == i) {
            for(int j=i*i; j<=n; j+=i) {
                if(arr[j] == j) {
                    arr[j] = i;
                }
            }
        }
    }
    
    while(n != 1) {
        cout<<arr[n]<<" ";
        n /= arr[n];
    }
    
}

//----------------------------------------------------------------

int main() {
    int n;
    cin>>n;
    // sieveOfEratosthenes(n);

    prFactUsingSieve(n);

    return 0;
}