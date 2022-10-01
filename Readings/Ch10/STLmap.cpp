#include <iostream>
#include <string>
#include <map>

// We will use the namespace std
// to make the code less cluttered.
using namespace std; 

void printMap(const map<int, string>& aMap);

int main()
{
	// (1) Using the default constructor
	// The assignment operator will 
	// assign a value to each key.

	map<int, string> map1;
	map1[129] = "Jane";
	map1[245] = "Amy";
	map1[391] = "Tad";

	cout << "map1 = ";
	printMap(map1);

	// =================================================
	// (2) Using the copy constructor

	map<int, string> map2(map1);

	cout << "\nmap2 = ";
	printMap(map2);

	// =================================================
	// (3) Using the initializer list constructor
	// Note how to display each pair to make the 
	// code more readable.

	map<int, string> map3{
		{ 329, "Jeff" },
		{ 713, "Karl" },
		{ 258, "Mary" },
		{ 736, "Karl" },
		{ 412, "Burt" }
	};

	cout << "\nmap3 = ";
	printMap(map3);

	// =================================================
	// (4) Using the range constructor

	map<int, string>::iterator iter = ++map3.begin();
	// Note that iter is incremented by 1 to 
	// start from the second pair.
	map<int, string> map4(iter, map3.end());		

	cout << "\nmap4 = ";
	printMap(map4);

	// =================================================
	// (5) Using the make_pair function
	// The make_pair function belongs 
	// to the STL pair.

	map<int, double> map5;

	for (int i = 1; i < 6; ++i)
		map5.insert(make_pair(i, (i / 10.0)));

	cout << "\nmap5 = ";
	for (auto i : map5)
		cout << "(" << i.first << ", " << i.second << ") ";

	cout << endl;

	return 0;
}

void printMap(const map<int, string>& aMap)
{
	for (auto elem : aMap)
		cout << "(" << elem.first << ", " << elem.second << ")";

	cout << endl;
}

