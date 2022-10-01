/*
	The Big Three
*/

#include "DArray.h"
#include "DArray.cpp"

#include <iostream>
using namespace std;

int main( )
{
	//Ask the user to enter the capacity
	cout << "Enter the capacity of the array: ";
	int cap = 0;
	cin >> cap;

	//Create the new array
	DArray a1(cap);

	//Ask the user to enter values for the array
	cout << "\nEnter positive numbers "
		<< "(enter -1 to quit)" << endl;
	int n = 0;
	cin >> n;
	while(n != -1)
	{
		a1.addElement(n);
		cin >> n;
	}

	cout << "\n\nArray 1: " << a1;

	//test copy constructor
	DArray a2(a1);
	cout << "\nArray 2: " << a2;

	//test overloaded assignment operator
	DArray a3;
	a3 = a1;
	cout << "\nArray 3: " << a3 << endl;

	// Will this statement call the copy constructor or the assignment operator?
	// Use the debugger to check where it goes.
	DArray a4 = a1;  

	//destroy first array to see if other arrays are still there
	a1.~DArray();
	// cout << "\nArray 1: " << a1 << endl; // this is destroyed and program will crash
	cout << "\nArray 2: " << a2;
	cout << "\nArray 3: " << a3;

	cout << endl;
	system("Pause");
    return 0;
}

