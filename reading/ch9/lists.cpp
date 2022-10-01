// Include the header file of the vector class.
#include <list>
#include <iostream>

using namespace std;

void printList(const list<int>& aList);

int main()
{
	// An empty list that will store ints.
	list<int> numbers;

	// Create a list using an initializer list.
	list<int> scores = { 98, 76, 99, 87 };

	printList(scores);

	// Add a new element to the front.
	scores.push_front(75);

	printList(scores);

	// Remove the front element.
	scores.pop_front();

	printList(scores);

	// Reverse the order of elements.
	scores.reverse();

	printList(scores);

	// Sort the elements.
	scores.sort();

	printList(scores);

	// Delete an element in the list.
	scores.remove(87);

	printList(scores);
	cout << endl;

	// There are 6 overloaded splice functions. 
	// We will look at two of them here.
	// IMPORTANT: Do look at cplusplus.com and 
	// read about these functions. You need to 
	// familiarize yourself to the wording used,
	// because your programming exam 2 and the 
	// final will have references to it.

	// Create two new lists.
	list<int> nums1 = { 1, 2, 3, 4, 5 };
	list<int> nums2 = { 9, 10 };

	// Declaration of function list::splice from cplusplus.com
	// that transfers the elements in the list before
	// the element pointer by position.

	// void splice(const_iterator position, list & x);
	nums1.splice(++nums1.begin(), nums2);

	// What do you think the print out will be?
	printList(nums1);
	printList(nums2);
	cout << endl;

	// What if the expression had a postfix increment 
	// operator instead? Like this one:
	// nums1.splice(nums1.begin()++, nums3);

	// Declaration of function list::splice from cplusplus.com
	// that transfers the elements in the list in 
	// interval [first, last) before the element pointed
	// to by positions. Note the parenthesis in [first, last).
	// A square bracket includes the element, while a 
    // parenthesis does not.

	// Create two new lists.
	list<int> nums3 = { 1, 2, 3, 4, 5 };
	list<int> nums4 = { 6, 7, 8, 9 };

	// void splice (const_iterator position, list& x,
	//            const_iterator first, const_iterator last);
	nums3.splice(nums3.begin(), nums4, ++nums4.begin(), nums4.end());

	// What do you think the print out will be?
	printList(nums3);
	printList(nums4);
	cout << endl;

	// Function list::merge merges two SORTED lists.
	// You should sort both lists before merging them.

	// Create two new lists.
	list<int> nums5 = { 6, 3, 1, 9 };
	list<int> nums6 = { 4, 5, 2, 7, 8 };

	// Declaration function list::merge from cplusplus.com
	// void merge (list& x)
	nums5.sort();
	nums6.sort();
	nums5.merge(nums6);

	// What do you think the print out will be?
	printList(nums5);
	printList(nums6);
	cout << endl;

	cout << endl;
	return 0;
}

void printList(const list<int>& aList)
{
	// Print the list.
	for (const auto& i : aList)
		cout << i << " ";
	cout << endl;
}