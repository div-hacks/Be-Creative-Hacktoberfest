#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str = "GeeksforGeeks";

	for (int i = 0; i < str.size(); i++)
	{
		int flag = 0;
		for (int j = 0; j < str.size(); j++)
		{
			// checking if two characters are equal
			if (str[i] == str[j] and i != j)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << str[i];
	}

	return 0;
}

// This code is contributed by umadevi9616
