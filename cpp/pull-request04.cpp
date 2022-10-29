// C++ program for implementation of falling matrix.
#include<iostream>
#include<string>
#include<thread>
#include<cstdlib>
#include<ctime>
#include<chrono>

// Width of the matrix line
const int width = 70;

// Defines the number of flips in Boolean Array 'switches'
const int flipsPerLine =5;

// Delay between two successive line print
const int sleepTime = 100;

using namespace std;

int main()
{
	int i=0, x=0;

	// srand initialized with time function
	// to get distinct rand values at runtime
	srand(time(NULL));

	// Used to decide whether to print
	// the character in that particular iteration
	bool switches[width] = {0};

	// Set of characters to print from
	const string ch = "1234567890qwertyuiopasdfghjkl"
					"zxcvbnm,./';[]!@#$%^&*()-=_+";
	const int l = ch.size();

	// Green font over black console, duh!
	system("Color 0A");

	// Indefinite Loop
	while (true)
	{
		// Loop over the width
		// Increment by 2 gives better effect
		for (i=0;i<width;i+=2)
		{
			// Print character if switches[i] is 1
			// Else print a blank character
			if (switches[i])
				cout << ch[rand() % l] << " ";
			else
				cout<<" ";
		}

		// Flip the defined amount of Boolean values
		// after each line
		for (i=0; i!=flipsPerLine; ++i)
		{
			x = rand() % width;
			switches[x] = !switches[x];
		}

		// New Line
		cout << endl;

		// Using sleep_for function to delay,
		// chrono milliseconds function to convert to milliseconds
		this_thread::sleep_for(chrono::milliseconds(sleepTime));
	}
	return 0;
}
