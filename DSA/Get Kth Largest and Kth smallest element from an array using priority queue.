#include <bits/stdc++.h>
using namespace std;

class Solution {

public:

    void kth_Largest_MaxHeap(vector<int>&arr, int k) {

        priority_queue<int>pq ;
        int n = arr.size()  ;

        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i])  ;
        }

        int f = k - 1 ;

        while (f > 0) {
            pq.pop()  ;
            f-- ;
        }

        cout << "Kth Largest element " << pq.top() << "\n"  ;
    }

    void kth_Smallest_MinHeap(vector<int>&arr, int k) {

        priority_queue<int, vector<int>, greater<int>>pq ;
        int n = arr.size()  ;

        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i])  ;
        }

        int f = k - 1 ;

        while (f > 0) {
            pq.pop()  ;
            f-- ;
        }

        cout << "Kth Smallest element " << pq.top() << "\n"  ;
    }
} ;
int main() {

    vector<int>arr = {1, 2, 6, 4, 5, 3}  ;

    Solution obj ;
    obj.kth_Largest_MaxHeap(arr, 3)  ;
    obj.kth_Smallest_MinHeap(arr, 3)  ;

    return 0 ;
}
