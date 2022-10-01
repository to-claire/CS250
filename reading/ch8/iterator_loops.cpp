#include <iostream>
#include <vector>
#include <iterator>  // need to be included for the ostream iterator

using namespace std;

void example1();
void example2();
void example3();

int main()
{
	example1();		// vector iterator
	cout << "\n----------------------------------\n";
	example2();		// reverse iterator
	cout << "\n----------------------------------\n";
	example3();		// ostream iterator
	cout << "\n----------------------------------\n";

	cout << endl;
	system("Pause");
	return 0;
}

	// vector iterator
void example1()		
{	
	cout << "EXAMPLE 1: Vector Iterator\n\n";

	vector<char> container = { 'A','B','C','D','E' };

	cout << "Print vector using an iterator: ";
	vector<char>::iterator iter = container.begin();	//Why this is not const?
	vector<char>::const_iterator iterEnd = container.end();
	while (iter != iterEnd)
	{
		cout << *iter << " ";
		++iter;
	}
	cout << endl;					// OUTPUT: A B C D E		

	cout << "Overwrite all elements with X and print again: ";
	for (iter = container.begin(); iter != iterEnd; ++iter)
		*iter = 'X';
	for (iter = container.begin(); iter != iterEnd; ++iter)
		cout << *iter << " ";
	cout << endl;					// OUTPUT: X X X X X
}

	// reverse iterator
void example2()		
{
	cout << "EXAMPLE 2: Reverse Iterator\n\n";

	vector<int> v = { 10, 11, 12, 13, 14 };

	cout << "Print backwards: ";
	vector<int>::const_reverse_iterator revIter = v.rbegin();
	vector<int>::const_reverse_iterator revIterEnd = v.rend();
	while (revIter != revIterEnd)
	{
		cout << *revIter << " ";
		++revIter;
	}
	cout << endl;					// OUTPUT: 14 13 12 11 10
}

	// ostream iterator
void example3()
{
	cout << "EXAMPLE 3: Ostream Iterator\n\n"; 
	
	vector<int> v;

	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);

	ostream_iterator<int> screen1(cout);

	cout << "Vector contains (no delimiter): ";
	copy(v.begin(), v.end(), screen1);  
	cout << endl;					// OUTPUT:1011121314

	ostream_iterator<int> screen2(cout, " ");

	cout << "\nVector contains (with delimiter): ";
	copy(v.begin(), v.end(), screen2);  
	cout << endl;					// OUTPUT: 10 11 12 13 14
}