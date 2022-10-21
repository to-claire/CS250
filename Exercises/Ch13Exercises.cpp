#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

// To complete the exercises below, you will need to refer to the algorithm section on cplusplus.com
// Note that for the exercises, labs and exams:
// You are not required to use the constant iterators cbegin, cend, crbegin and crend. 
// You may use auto for ONLY iterators, unless otherwise indicated.

void printVector(const vector<int>& aVector);
void printList(const list<int>& aList);

// Exercise 7
bool lessOrEqualTo50(int n) // Unary Predicate
    { return (n <= 50); }

// Exercise 9
bool lessThan10(int n)
    { return (n < 10); }

int main()
{
    // Exercise 1
    // Implement the following:
    // Create an STL vector using the default constructor.
    vector<int> v1;
    // Size the vector to have 5 number of elements, all 0s. Which function should you use?
    v1.resize(5);
    // Use algorithm std::fill to overwrite the last three elements with 9
    //  so that the vector becomes: 0 0 9 9 9
    fill(v1.begin() + 2, v1.end(), 9);
    // Use algorithm std::fill to overwrite the second and third element with 5, 
    // so that the vector becomes: 0 5 5 9 9
    fill(v1.begin() + 1, v1.begin() + 3, 5);
    // printVector(v1);

    // Exercise 2
    // Implement the following:
    // Create an STL list using the default constructor.
    list<int> l2;
    // Size the list to have six number of elements, all 0s. Which function should you use?
    l2.resize(6);
    // Use algorithm std::fill to overwrite all the elements with 4, 
    // so that the list becomes: 4 4 4 4 4 4
    fill(l2.begin(), l2.end(), 4);
    // Using algorithm std::fill again to overwrite the last three elements with 200, 
    // so that the list becomes: 4 4 4 200 200 200
    auto itr2 = l2.begin();
    for (int i = 0; i < 3; ++i) ++itr2;
    fill(itr2, l2.end(), 200);
    // printList(l2);

    // Exercise 3
    // Implement the following:
    // Create an STL vector with elements: 45 95 76 21 35 62 85
    vector<int> v3 = { 45, 95, 76, 21, 35, 62, 85 };
    // Use algorithm std::find to search for 62; 
    // save the return value in an iterator--you may declare the iterator using auto.
    auto itr3 = find(v3.begin(), v3.end(), 62);
    // If the element is found, print the index where the element is located; 
    // otherwise, print a message that the element was not found. 
    // How can you do this? Try and reason on this to figure it out, before looking at the solution.
    // if (itr3 != v3.end())
    //     cout << (itr3 - v3.begin()) << endl;
    // else
    //     cout << "Element was not found.\n";

    // Exercise 4
    // Implement the following:
    // Create an STL vector with elements: 30 20 10 90 50 80 70 40
    vector<int> v4 = { 30, 20, 10, 90, 50, 80, 70, 40 };
    // Use algorithm std::find to search for 50, but only between 10 and 70 inclusive; 
    // save the return value in an iterator--you may declare the iterator using auto.
    auto itr4 = find(v4.begin() + 2, v4.begin() + 7, 50);
    // If the element is found, print the index where the element is located; otherwise, 
    // print a message that the element was not found.
    // if (itr4 != v4.begin() + 7)
    //     cout << (itr4 - v4.begin()) << endl;
    // else 
    //     cout << "Element was not found.\n";

    // Exercise 5
    // Implement the following:
    // Create an STL list with elements: 8 7 6 1 3
    list<int> l5 = { 8, 7, 6, 1, 3 };
    // Use algorithm std::find to search for 1; 
    // save the return value in an iterator--you may declare the iterator using auto.
    auto itr5 = find(l5.begin(), l5.end(), 1);
    // If the element is found, use the function list::insert to insert 100 before 1.
    if (itr5 != l5.end())
        l5.insert(itr5, 100);
    // printList(l5);

    // Exercise 6
    // Implement the following:
    // Create an STL vector with elements: 1 2 3 2 4 5 2 6 7
    vector<int> v6 = { 1, 2, 3, 2, 4, 5, 2, 6, 7 };
    // Use algorithm std::remove to delete all occurrences of 2; 
    // save the return value in an iterator to use later--you may declare the iterator using auto.
    // Print the vector. What do you see?
    auto itr6 = remove(v6.begin(), v6.end(), 2);
    // 1 3 4 5 6 7 2 6 7 
    // std::remove cannot alter the size of an array or a container
    v6.resize(itr6 - v6.begin());
    // 1 3 4 5 6 7

    // Exercise 7
    // Implement the following:
    // A unary predicate function named lessOrEqualTo50() that returns true when the int parameter is <= 50.
    // In the main function:
    // Create an STL vector with elements: 45 89 12 63 35 10 28 95 67 22
    vector<int> v7 = { 45, 89, 12, 63, 35, 10, 28, 95, 67, 22 };
    // Try and use both vector::erase and algorithm 
    // std::remove_if to delete all elements <= to 50 and resize the vector in one statement.
    v7.erase(remove_if(v7.begin(), v7.end(), lessOrEqualTo50), v7.end()); 
    // remove() returns past-the-end itr
    // .erase() resizes by deleting from itr to end
    // printVector(v7);

    // Exercise 8
    // Implement the following:
    // Create an STL vector with elements: -1 2 3 -2 4 -7 -5 1 6
    // Use algorithm std::remove_if to delete all negative integers 
    // by using a lambda expression as the third parameter.
    // Resize the vector using function vector::resize.
    vector<int> v8 = { -1, 2, 3, -2, 4, -7, -5, 1, 6 };
    auto itr8 = remove_if(v8.begin(), v8.end(), 
        [] (int e) { return e < 0; });
    v8.resize(itr8 - v8.begin());
    // printVector(v8);

    // Exercise 9
    // Implement the following:
    // Create an STL vector with elements: 10 10 62 19 31 10 24 79 10 72
    // Use algorithm std::replace to overwrite all occurrences of 10 with 1000.
    vector<int> v9 = { 10, 10, 62, 19, 31, 10, 24, 79, 10, 72 };
    replace(v9.begin(), v9.end(), 10, 1000);
    // printVector(v9);

    // Exercise 10
    // Implement the following:
    // A unary predicate function named lessThan10() that returns true when the int parameter < 10.
    // In the main function:
    // Create an STL vector with elements: 10 10 2 19 31 10 4 9 10 2
    // Use algorithm std::replace_if to overwrite all elements that are less than 10 with 2000.
    vector<int> v10 = { 10, 10, 2, 19, 31, 10, 4, 9, 10, 2 };
    replace_if(v10.begin(), v10.end(), lessThan10, 2000);
    // printVector(v10);

    // Exercise 11
    // Rewrite the call to function std::replace_if in exercise 10 by calling a lambda expression.
    vector<int> v11 = { 10, 10, 2, 19, 31, 10, 4, 9, 10, 2 };
    replace_if(v11.begin(), v11.end(), 
        [] (int n) { return n < 10; }, 2000);
    // printVector(v11);

    // Exercise 12
    // Implement the following:
    // Create an STL vector with elements: 1 2 3 4 5
    // Use algorithm std::reverse to reverse the order of elements in the vector.
    vector<int> v12 = { 1, 2, 3, 4, 5 };
    reverse(v12.begin(), v12.end());
    // printVector(v12);

    // Exercise 13
    // Implement the following:
    // Create an STL vector with elements: 1 2 3 4 5 6 7 8 9 10
    // Use algorithm std::reverse to reverse the range: 3 4 5 6 7 8 9
    vector<int> v13 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    reverse(v13.begin() + 2, v13.begin() + (v13.size() - 1));
    // printVector(v13);

    // Exercise 14
    // Implement the following:
    // Create an STL vector with elements: 1 2 3 4 5 6
    // Use algorithm std::rotate to rotate the vector to 3 4 5 6 1 2
    vector<int> v14 = { 1, 2, 3, 4, 5, 6 };
    rotate(v14.begin(), v14.begin() + 2, v14.end());
    // printVector(v14);

    // Exercise 15
    // Implement the following: 
    // Create an STL vector with elements 1 2 3 4 5 6 7 8 9 10
    // Use algorithm std::rotate to rotate the vector 
    // so that it becomes: 1 2 3 4 7 5 6 8 9 10
    vector<int> v15 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    rotate(v15.begin() + 4, v15.begin() + 6, v15.begin() + 7);
    // printVector(v15);

    // Exercise 16
    // Implement the following:
    // Create an STL vector with elements: 9 8 7 6 5 4 3 2 1
    // Use algorithm std::sort to sort a specific range of the vector 
    // so that it becomes: 9 8 2 3 4 5 6 7 1
    vector<int> v16 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    sort(v16.begin() + 2, v16.end() + (v16.size() - 1));
    // printVector(v16);

    return 0;
}


void printVector(const vector<int>& aVector)
{
	for (const auto& element : aVector)
		cout << element << " ";
	cout << endl;
}

void printList(const list<int>& aList)
{
	for (const auto& element : aList)
		cout << element << " ";
	cout << endl;
}

