#include <bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int W, int wt[], int val[], int idx)
{
	if (idx == 0) {
		return (W / wt[0]) * val[0];
	}
	int notTake
		= 0 + unboundedKnapsack(W, wt, val, idx - 1);
	int take = INT_MIN;
	if (wt[idx] <= W) {
		take = val[idx]
			+ unboundedKnapsack(W - wt[idx], wt, val,
								idx);
	}
	return max(take, notTake);
}
int main()
{
	int W = 100;
	int val[] = { 10, 30, 20 };
	int wt[] = { 5, 10, 15 };
	int n = sizeof(val) / sizeof(val[0]);

	cout << unboundedKnapsack(W, wt, val, n - 1);
	return 0;
}
