// Check if all the pairs of an array are coprime with each other

#include <bits/stdc++.h>
using namespace std;

// Function to check if all the
// pairs of the array are coprime
// with each other or not
bool allCoprime(int A[], int n)
{
    bool all_coprime = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            // Check if GCD of the
            // pair is not equal to 1
            if (__gcd(A[i], A[j]) != 1)
            {

                // All pairs are non-coprime
                // Return false
                all_coprime = false;
                break;
            }
        }
    }
    return all_coprime;
}

// Driver Code
int main()
{
    int A[] = {3, 5, 11, 7, 19};
    int arr_size = sizeof(A) / sizeof(A[0]);
    if (allCoprime(A, arr_size))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}
