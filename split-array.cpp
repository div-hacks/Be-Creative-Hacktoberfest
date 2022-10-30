// Split Array into K non-overlapping subset such that maximum among all subset sum is minimum

#include <bits/stdc++.h>
using namespace std;
 
// Function to split the array into M
// groups such that maximum of the sum
// of all elements of all the groups
// is minimized
int findMinimumValue(int arr[], int N,
                     int M)
{
    // Sort the array in decreasing order
    sort(arr, arr + N, greater<int>());
 
    // Initialize priority queue (Min heap)
    priority_queue<int, vector<int>,
                   greater<int> >
        pq;
 
    // Push 0 for all the M groups
    for (int i = 1; i <= M; ++i) {
        pq.push(0);
    }
 
    // Traverse the array, arr[]
    for (int i = 0; i < N; ++i) {
 
        // Pop the group having the
        // minimum sum
        int val = pq.top();
        pq.pop();
 
        // Increment val by arr[i]
        val += arr[i];
 
        // Push the new sum of the
        // group into the pq
        pq.push(val);
    }
 
    // Iterate while size of the pq
    // is greater than 1
    while (pq.size() > 1) {
        pq.pop();
    }
 
    // Return result
    return pq.top();
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 7, 9, 2, 12, 3, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;
    cout << findMinimumValue(arr, N, K);
 
    return 0;
}