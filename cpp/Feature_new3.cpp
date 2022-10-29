#include <vector>

// Function to find the sum of elements
// in a vector
inline int findSum(vector<int>& arr, int N)
{
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}
	return sum;
}

struct GfG {

	// Declare vector arr
	std::vector<int> arr;

	// Function
	int execute() const
	{
		return findSum(arr, arr.size());
	}
};
