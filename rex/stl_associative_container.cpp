#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

// Declaration function printSet.
// The function passes a list and prints all
// the elements on one line, separated by a space.
// Use a range-based FOR loop. If you do not know
// what this means, search the Web.
void printSet(const set<int>& l);

int main()
{
	/**************************************************************
				SETS
	***************************************************************/
	cout << "  ***  STL SET CLASS  ***  \n\n";
	
	// Create a set of ints named set1 using the initializer list 
	// to insert the following integers in this order: 
	// 2, 7, 5, 6, 9, 1 and 3.
    set<int> set1;
	set1.insert(2);
	set1.insert(7);
	set1.insert(5);
	set1.insert(6);
	set1.insert(9);
	set1.insert(1);
	set1.insert(3);

	// Print the set using the printSet function you implemented.
	// What do you notice in the printout?
    // elements are sorted in assending order
	printSet(set1);

	// size_type  erase (const value_type& val);
	// Use the function erase integer 9 from set1.
	// Print out set1.
	set1.erase(9);
	printSet(set1);
	
	// size_type  erase (const value_type& val);
	// Use the function erase integer 2 from set1, but
	// this time use cout to print the return value.
	// What is the return value? 2
    cout << set1.erase(2);
    
	// If you do not know what the return value is, then
	// check set::erase in cplusplus.com
	cout << endl;
	
	// Print set1.
	printSet(set1);

	// iterator  erase (const_iterator position);
	// This function is different from the previous one,
	// because instead of passing a value, it passes a 
	// position indicated by an iterator.
	// Delete the second element in the set without creating
	// an iterator variable and using the prefix increment
	// operator.
	set1.erase(++set1.begin());

	// Print set1.
	printSet(set1);
	
	// pair<iterator,bool> insert (const value_type& val);
	// Use the function insert to insert 4 and 8 in set1.
	set1.insert(4);
	set1.insert(8);

	// Print set1.
	printSet(set1);
	
	set<int>::iterator first = set1.begin();
	set<int>::iterator second = ++set1.begin();
	// iterator erase(const_iterator first, const_iterator last);
	// Use function erase to delete the first and second element
	// in set1. Use the given iterators created above.
	// Note that you should write one statement only.
	set1.erase(first, ++second);

	// Print set1.
	printSet(set1);
	
	// Your output should be: 5 6 7 8
	// If it is not, you need to carefully read about function erase
	// to understand how it works.

	cout << "\n\n--------------------------------------------------";
	cout << "\n\nThe output for the next sections depends "
		<< "on your implementation.";

	/**************************************************************
				MAPS
	***************************************************************/
	cout << "\n\n--------------------------------------------------";
	cout << "\n  ***  STL MAP CLASS  ***  \n\n";

	// Create a few maps using the different constructors shown in 
	// the slides. 
	map<int, string> map1;
	map1[97] = "Jungkook";
	//map1[95] = "Taehyung";
	map1[93] = "Yoongi";
	map1[92] = "Jin";
	//map1[95] = "Jimin";
	//map1[94] = "Hobi";
	map1[94] = "Namjoon";

	multimap<int, string> map2 = {
		{99, "Yeonjun"},
		{00, "Soobin"},
		{01, "Beomgyu"},
		{01, "Taehyun"},
		{02, "Kai"},
	};

	// Use the following functions to manipulate the maps:
	// pair<iterator,bool> insert (const value_type& val);
	map1.insert(make_pair(95, "Jimin"));

	// void insert (InputIterator first, InputIterator last);


	// iterator  erase(const_iterator position);


	// size_type erase(const key_type& k);


	// iterator  erase(const_iterator first, const_iterator last);


	// Print each map without creating a print function, but 
	// by using a range-based loop.
	for (auto elem : map1)
	{
		cout << "(" << elem.first << ", " << elem.second << ")";
	}
	cout << '\n';

	for (auto elem : map2)
	{
		cout << "(" << elem.first << ", " << elem.second << ")";
	}

	cout << "\n\n----------------------------------------------------";

	cout  <<  endl;
	system("Pause");
	return 0;
}

// Definition function printSet
void printSet(const set<int>& aSet)
{
	for (const int& elem : aSet)
		cout << elem << " ";
	cout << endl;
}
