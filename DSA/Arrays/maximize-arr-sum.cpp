// Maximize array sum by replacing equal adjacent pairs by their sum and X respectively


#include <bits/stdc++.h>
using namespace std;

// Function to calculate x ^ y
int power(int x, int y)
{
    int temp;

    // Base Case
    if (y == 0)
        return 1;

    // Find the value in temp
    temp = power(x, y / 2);

    // If y is even
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

// Function that find the maximum
// possible sum of the array
void maximumPossibleSum(int N, int X)
{

    // Print the result using
    // the formula
    cout << (X * (power(2, N) - 1)) << endl;
}

// Driver code
int main()
{
    int N = 3, X = 5;

    // Function call
    maximumPossibleSum(N, X);
}
