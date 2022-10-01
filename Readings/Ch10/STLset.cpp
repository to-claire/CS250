#include <iostream>
#include <set>
using namespace std;

void printSet(const set<int>& aSet);

int main()
{
	// (1) Using the default constructor
	set<int> set1;
	
	// pair<iterator,bool> insert (const value_type& val);
	/*
	  Function insert returns a pair which we will not be 
	  using; therefore, we have two choices:
	  (1) Treat the function as a void function => set1.insert(value); 
	  (2) Use "auto" to create the variable that will store the 
	      return value (simpler than declaring a pair or, in some 
		  cases, an iterator).
	
		Since we do not need the return value, you can ignore it.
	*/	
		
	set1.insert(6);		
	set1.insert(2);		
	set1.insert(4);		

	cout << "set1 = ";
	printSet(set1);

	// =================================================
	// (2) Using the copy constructor

	set<int> set2(set1);

	cout << "set2 = ";
	printSet(set2);

	// =================================================
	// (3) Using the initializer list constructor

	set<int> set3{ 10, 20, 30, 40 };	
	// If not in order, they will be sorted automatically.
	set<int> set3a = { 5, 3, 1, 2, 4 };

	cout << "set3 = ";
	printSet(set3);
	cout << "set3a = ";
	printSet(set3a);

	// =================================================
	// (4) Using the range constructor

	set<int>::iterator iter = set3.begin();
	++iter;
	set<int> set4(iter, set3.end());

	cout << "set4 = ";
	printSet(set4);

	// =================================================
	// (5) Another example with function insert
	//  Declaration: pair<iterator,bool> insert (const value_type& val);
	//  Note that this overloaded insert function returns a pair, but 
	//  because we do not need the return value, we can ignore it.

	set<int> set5;
	for (int i = 1; i < 11; ++i)
		set5.insert(i);

	cout << "set5 = ";
	printSet(set5);

	return 0;
}

void printSet(const set<int>& aSet)
{
	for (auto elem : aSet)
		cout << elem << " ";

	cout << endl;
}