// C++ program to demonstrate function
// declaration outside class

#include <bits/stdc++.h>
using namespace std;
class Geeks
{
	public:
	string geekname;
	int id;
	
	// printname is not defined inside class definition
	void printname();
	
	// printid is defined inside class definition
	void printid()
	{
		cout << "Geek id is: " << id;
	}
};

// Definition of printname using scope resolution operator ::
void Geeks::printname()
{
	cout << "Geekname is: " << geekname;
}
int main() {
	
	Geeks obj1;
	obj1.geekname = "xyz";
	obj1.id=15;
	
	// call printname()
	obj1.printname();
	cout << endl;
	
	// call printid()
	obj1.printid();
	return 0;
}
