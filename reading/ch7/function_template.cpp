//Program to demonstrate a function template.
#include <iostream>
using namespace std;

//Interchanges the values of variable1 and variable2.
//The assignment operator must work for the type T.
template<typename T>
void swapValues(T& variable1, T& variable2);

int main( )
{
	cout << "Process integers...\n\n";
	int integer1 = 1, 
		integer2 = 2;

	cout << "Original integer values: "
         << integer1 << " " << integer2 << endl;

	//Calling the function --> as usual
	swapValues(integer1, integer2);

	cout << "Swapped integer values: "
         << integer1 << " " << integer2 << endl;

	cout << "\n------------------------------------------\n\n";
	cout << "Process characters...\n\n";
	char symbol1 = 'A', symbol2 = 'B';

	cout << "Original character values: "
         << symbol1 << " " << symbol2 << endl;

	swapValues(symbol1, symbol2);

	cout << "Swapped character values: "
         << symbol1 << " " << symbol2 << endl;
    
	cout << endl;
	system("Pause");
	return 0;
}

//Need to re-write the template definition
template<typename T>
void swapValues(T& variable1, T& variable2)
{
	T temp = variable1;
	variable1 = variable2;
	variable2 = temp;
}