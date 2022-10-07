#include "AnyList.h"
#include "AnyList.cpp"

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
	runTest(8);

	// int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// AnyList aList;
	// aList.arrayToEmptyCalling(arr, 10);
	// aList.print();

	return 0;
}


void runTest(int num)
{
	AnyList list1;
	AnyList list2;
	
	int i = 0;
	while (i++ < num)
	{
		list1.insertBack(rand() % 10);
		list1.insertBack(rand() % 10);
		list2.insertBack(rand() % 10);
	}

	list1.print();
	cout << endl;
	list2.print();
	cout << endl << endl;

	// call functions
	// list1.sumCallingToEndParamater(list2);
	list1.swapLastParamFirstCalling(list2);

	list1.print();
	cout << endl;
	list2.print();
	cout << "\n-----------------\n";

	list1.clearList();
	list2.clearList();
}