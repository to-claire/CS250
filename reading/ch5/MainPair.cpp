#include "Pair.h"
#include "Pair.cpp"
#include <iostream>
using namespace std;

// Declaration of overloaded subtraction operator
// as a non-member function.
Pair operator-(const Pair& p1, const Pair& p2);

int main()
{
	{
		// TEST CASE 1
		Pair p1(4, 3);
		Pair p2(10, 20);

		cout << "TEST: Insertion operator <<\n";
		cout << "\n\tP1: " << p1;
		cout << "\n\tP2: " << p2;

		cout << "\n\nTEST: Addition operator\n";
		Pair p3 = p1 + p2;
		cout << "\n\tP3 = P1 + P2";
		cout << "\n\tP3: " << p3;

		cout << "\n\nTEST: Multiplication operator\n";
		Pair p4 = p1 * p2;
		cout << "\n\tP4 = P1 * P2";
		cout << "\n\tP4: " << p4;

		cout << "\n\nTEST: Subtraction operator\n";
		Pair p5 = p1 - p2;
		cout << "\n\tP5 = P1 - P2";
		cout << "\n\tP5: " << p5;
	}

	{
		// TEST CASE 2
		Pair p1(1, 2);
		Pair p2(2, 3);

		cout << "\n\nTEST: Comparison operator\n";
		if (p1 == p2)
		{
			cout << "\n\tPair 1: " << p1;
			cout << "\n\tPair 2: " << p2;
			cout << "\n\tFirst try: Equal --> This is incorrect.\n";
		}
		else
		{
			cout << "\n\tPair 1: " << p1;
			cout << "\n\tPair 2: " << p2;
			cout << "\n\tFirst try: Not equal --> "
				<< "This is correct.\n";
		}

		cout << "\n\nTEST: Prefix increment and comparison operator\n";

		if (++p1 == p2)  //increment before evaluating if statement
		// p1(2,3) and p2(2,3)
		{
			cout << "\n\tPair 1: " << p1;
			cout << "\n\tPair 2: " << p2;
			cout << "\n\tSecond try: Equal --> "
				<< "This is correct.\n";
		}
		else
		{
			cout << "\n\tPair 1: " << p1;
			cout << "\n\tPair 2: " << p2;
			cout << "\n\tSecond try: Not equal --> "
				<< "his is incorrect.\n";
		}

		cout << "\n\nTEST: Postfix increment and comparison operator\n";

		if (p1++ == p2)  //increment after evaluating if statement
			//p1(2,3) and p2(2,3)
		{
			cout << "\n\tPair 1: " << p1;
			cout << "\n\tPair 2: " << p2;
			cout << "\n\tThird try: Equal --> "
				<< "This is correct.\n";
		}
		else
		{
			cout << "\n\tPair 1: " << p1;
			cout << "\n\tPair 2: " << p2;
			cout << "\n\tThird try: Not equal --> "
				<< "This is incorrect.\n";
		}
	}
	std::cout << "\n";
	return 0;
}

// Definition of overloaded comparison operator.
Pair operator-(const Pair& p1, const Pair& p2)
{
	// Need to construct a temporary object.
	Pair tempPair ( (p1.getFirst() - p2.getFirst()),
		(p1.getSecond() - p2.getSecond()));
	return tempPair;
}