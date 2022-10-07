#include "DoublyList.h"
#include "DoublyList.cpp"

#include <iostream>

using namespace std;

void runTest(int num);

int main()
{
    // test cases
	runTest(0);
	runTest(1);
	runTest(2);
	runTest(3);
	runTest(4);
	runTest(5);
	runTest(6);
	runTest(7);

	return 0;
}


void runTest(int num)
{
	DoublyList list1;
	// DoublyList list2;
	
	int i = 0;
	while (i++ < num)
	{
		list1.insertBack(rand() % 10);
		// list2.insertBack(rand() % 10);
	}
	
	// cout << "Calling: " << endl;
	list1.printForward();
	cout << endl;
	list1.printReverse();
	cout << endl;
	// cout << "Param: " << endl;
	// list2.printForward();
	// cout << endl;
	// list2.printReverse();
	cout << endl << endl;

	// call function
	list1.deleteFourth();

	// cout << "Calling: " << endl;
	list1.printForward();
	cout << endl;
	list1.printReverse();
	cout << endl;
	// cout << "Param: " << endl;
	// list2.printForward();
	// cout << endl;
	// list2.printReverse();
	cout << "\n-----------------\n";

	list1.clearList();
	// list2.clearList();
}
