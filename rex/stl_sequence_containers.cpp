#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void printVector(const vector<int>& aVector);
void printList(const list<int>& aList);

int main()
{

	/***************************************************************
			VECTORS
	****************************************************************/
	cout << "  ***  STL VECTOR CLASS  ***  \n\n";

	// Use the default constructor to declare an integer vector v1.
	vector<int> v1;

	// void push_back (const value_type& val);
	// Use function push_back to insert the following values 
	// in v1: 12, 73, 41, 38, 25, 56, an 63 in this order.
	v1.push_back(12);
	v1.push_back(73); //...
	v1.push_back(41);
	v1.push_back(38);
	v1.push_back(25);
	v1.push_back(56);
	v1.push_back(63);

	// size_type size() const noexcept;
	// Create a variable of type int named sizeV1 and store 
	// the size of the vector.
	// Use function size to retrieve the size of the vector. 
	// Make sure you cast the return value of the function 
	// size to the appropriate type.
	int sizeV1 = static_cast<int>(v1.size());

	// Use a FOR loop to print out the vector.
	// Do NOT use an iterator.
	for (int i = 0; i < sizeV1; ++i)
	{
		cout << v1[i] << ' ';
	}

	//void clear() noexcept;
	// Call the function clear on vector v1.
	v1.clear();

	// size_type size() const noexcept;
	// Call function size to print the size of v1.
	cout << '\n' << v1.size();

	// size_type capacity() const noexcept;
	// Call function capacity to output the capacity of v1.
	cout << '\n' << v1.capacity() << '\n';

	// Create an array of integers containing: 
	// 10,11,12,13,14,15,16,17,18,19
	int a[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

	// Use the default constructor to declare an integer vector v2.
	vector<int> v2;

	// void assign (InputIterator first, InputIterator last);
	// Use function assign to copy elements 12, 13, 14, 15, and 
	// 16 from the array into v2.
	// One statement only.
	cout << "help\n";
	v2.assign(a[2], a[7]); 

	// Call the function printVector to print v2.
	printVector(v2);

	// const_reference back() const;
	// Use the function back output the last element in the vector
	// (Notice that the back function returns a reference.)
	cout << v2.back() << '\n';
		
	// Use the default constructor to declare an integer vector v3.
	vector<int> v3;

	// void assign (size_type n, const value_type& val);
	// Use function assign to insert the values 7, 7, 7, 7, and 7.
	// One statement only.
	v3.assign(5, 7);

	// Call the function printVector  to print v3.
	printVector(v3);

	// const_reference at(size_type n) const;
	// Use function at to replace the middle element with 100.
	// (Notice that the at function returns a reference.)
	v3.at(v3.size() / 2) = 100;

	// Call the function printVector to print v3.
	printVector(v3);

	// vector (const vector& x);
	// Use the copy constructor to create a new vector v4 with the 
	// same elements of v3.
	vector<int> v4(v3);

	// Call the function printVector to print v4.
	printVector(v4);

	// Create an iterator iterVector4 to point to 
	// the first element of v4.
	vector<int>::iterator iterVector4 = v4.begin();

	// Create an iterator iterVector2 to point to 
	// the second element of v2.
	vector<int>::iterator iterVector2 = ++v2.begin();

	// iterator insert (const_iterator position, 
	//                    InputIterator first, InputIterator last);
	// Use function insert to insert the second, third, 
	// and fourth element of v2 as the first, second, and third 
	// element of v4. Notice that the insert function returns 
	// an iterator, but if we do not intend to use it, we can 
	// ignore it.
	cout << "how do i do this?\n";

	// Call the function printVector to print v4.


	// iterator insert (const_iterator position, 
	//                   size_type n, const value_type& val);
	// Use the function insert to insert three 0s at the end of v4.
	// (Notice that the insert function returns an iterator, 
	//  but if we do not intend to use it, we can ignore it.)


	// Call the function printVector to print v4.


	// bool empty() const noexcept;
	// const_reference back() const;
	// void pop_back();
	// Use a WHILE loop to remove and output each 
	// element of v2 backwards.
	// Use function empty for the loop condition, 
	// function back to output the last element, 
	// and function pop_back to remove elements.
	// (Notice that the back function returns a reference.)


	// void resize (size_type n, const value_type& val);
	// Use function resize to insert three times number
	// 4 into v2.


	// Call the function printVector to print v2.


	// const_reference front() const;
	// Use function front to output the first element in v4.
	// (Notice that the front function returns a reference.)


	// void swap (vector& x);
	// Use function swap to swap v2 with v4.


	// Call the function printVector to print v2.


	// Create a new vector v5;


	// Use the overloaded assignment operator to copy all 
	// the elements of v2 into v5.


	// void resize (size_type n);
	// size_type size() const noexcept;
	// Delete the last element of v5 by using the 
	// functions resize and size.


	// Call the function printVector to print v5.


	// Create an iterator iterVector5 to point to the 
	// first element of v5.


	// iterator erase (const_iterator position);
	// Call the function erase to delete the first 
	// element of the vector. (Notice that the insert function
	// returns an iterator, but if we do not intend to use it, 
	// we can ignore it.)


	// Call the function printVector to print v5 again.


	// iterator erase (const_iterator position);
	// Call the function erase to delete the first 
	// element of the vector. (Notice that the insert function
	// returns an iterator, but if we do not intend to use it, 
	// we can ignore it.)


	// Call the function printVector to print v5 again.


	// Create a vector of integers named v6 containing 
	// numbers from 100 to 105.
	// Using the copy constructor, create a vector 
	// named v7, a copy of v6.


	// iterator erase (const_iterator position);
	// iterator insert (const_iterator position, 
	//                               const value_type& val);
	// Erase element 103 from v7 and insert element 333 
	// in its place, by using an iterator.
	// Note that the function erase returns an iterator 
	// that can be used to insert 333 in the right position.


	// Using a range-based FOR loop, print the elements of v7.


	/***************************************************************
			LISTS
	****************************************************************/

	cout << "\n\n----------------------------------------------------";
	cout << "\n  ***  STL LIST CLASS  ***  \n\n";

	// Use the default constructor to create three lists 
	// of integers, intList1, intList2, and intList3.
        

	// void push_back (const value_type& val);
	// Use the function push_back to insert the following
	// values in the first list: 23 58 58 58 36 15 15 93 98 58
	

	// Call function printList to print intList1.


	// Using the overloaded assignment operator, 
	// copy elements of intList1 into intList2.


	// Call function printList to print intList2.


	// void sort();
	// Using function sort, sort all elements in the second list.


	// Call function printList to print intList2.


	// void unique();
	// Using function unique, remove all consecutive 
	// duplicates in the list.


	// Call function printList to print intList2.

			
	// void push_back (const value_type& val);
	//Insert the following elements in the third list:
	//  13 23 25 136 198


	// Call function printList to print intList3.


	// void merge (list& x);
	// Add to the second list all elements of the third list.
	// --> This is ONE statement only.


	// Call function printList to print intList2.

	/***************************************************************
	*		Create statements using the functions below.	
	*       You might need to create new containers.
	*		Is the output what you expected?
	****************************************************************/
	cout << "\n\n----------------------------------------------------";
	cout << "\n  ***  OTHER FUNCTIONS  ***  \n\n";

	// list: void assign (size_type n, const value_type& val);

	// vector: void assign (InputIterator first, InputIterator last);	

	// list: const_reference back() const;
	// (Notice that this back function returns a reference.)

	// list: void clear() noexcept;

	// list: bool empty() const noexcept;

	// vector: const_reference front() const;

	// list: iterator insert (const_iterator position, 
	//                                const value_type& val);
	// (Notice that the insert function returns an iterator.)

	// list: void pop_back();

	// list: void pop_front();

	// list: void push_front (const value_type& val);

	// list: void remove (const value_type& val);

	// list: void reverse() noexcept;

	// list: void splice (const_iterator position, list& x);

	// list: void splice (const_iterator position, list& x, 
	//                                        const_iterator i);
	
	// list: void splice (const_iterator position, list& x, 
	//                const_iterator first, const_iterator last);


	cout << "\n\n----------------------------------------------------";

	cout  <<  endl;
	return 0;
}

// Definition function printVector
void printVector(const vector<int>& aVector)
{
	for (const auto& element : aVector)
		cout << element << " ";
	cout << endl;
}

// Definition function printList
void printList(const list<int>& aList)
{
	for (const auto& element : aList)
		cout << element << " ";
	cout << endl;
}

