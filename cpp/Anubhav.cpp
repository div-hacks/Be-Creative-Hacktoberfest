/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fact(int n){
    if(n==0||n==1)
    return 1;
    
    else
    return n*fact(n-1);
}

int main()
{
    int n;
    cout << "Enter the number to find fact : \n";
    cin >> n;
    auto start = high_resolution_clock::now();
    cout <<fact(n) <<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}
