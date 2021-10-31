// Minimize subarray increments / decrements required to reduce all array elements to 0



#include <bits/stdc++.h>
using namespace std;

// Function to count the minimum
// number of operations required
int minOperation(int arr[], int N)
{
    int minOp = INT_MIN;
    int minNeg = 0, maxPos = 0;

    // Traverse the array
    for (int i = 0; i < N; i++)
    {
        // If array element
        // is negative
        if (arr[i] < 0)
        {
            if (arr[i] < minNeg)

                // Update minimum negative
                minNeg = arr[i];
        }
        else
        {
            if (arr[i] > maxPos)

                // Update maximum positive
                maxPos = arr[i];
        }
    }

    // Return minOp
    return abs(minNeg) + maxPos;
}

// Driver Code
int main()
{
    int arr[] = {1, 3, 4, 1};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << minOperation(arr, N);
}
