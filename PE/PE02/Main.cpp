#include "DArray.h"
#include "DArray.cpp"
// + AnyList and DoublyList class

#include <iostream>
#include <vector>
#include <list>
#include <set> // + multiset
#include <map> // + multimap
#include <stack>
#include <queue>
#include <algorithm>
#include <utility> // pair class

using namespace std;

void printVector(const vector<int>& aVector);
void printList(const list<int>& aList);
void printSet(const set<int>& aSet);
void printMultiSet(const multiset<int>& aSet);
void printMap(const map<int, int>& aMap);
void printMultiMap(const multimap<int, int>& aMap);
void printStack(stack<int>& aStack);
void printQueue(queue<int>& aQueue);

// Functions that you need to know how to use without a description:
// STL vector/list/set/multiset/map/multimap
    // Constructors
    // begin, end, rbegin, rend, clear, empty, operator=, size
// STL vector
    // at, back, operator[], pop_back, push_back, reserve, resize
// STL list
    // front, pop_back, pop_front, push_back, push_front
// STL map/multimap
    // operator[]
// STL stack
    // empty, pop, push, size, top
// STL queue
    // empty, pop, push, size, front, back

// multiple choice: insert elements from param darray and param queue/stack/list into calling darray
// fill in: splice on list, fill_n on vector, reverse/rotate
// codecheck: params map and list, insert key back of list and values front of list, return number of negatives in map using count_if 
// codecheck: remove_if and erase on multimaps

int func(const map<int, int>& m, list<int>& l)
{
    for (const auto& e : m)
    {
        l.push_front(e.first);
        l.push_back(e.second);
    }
    return count_if(l.begin(), l.end(), 
        [] (int e) { return e < 0; });
}


// void DArray::func(queue<int>& q, const DArray& arr)
// {
//     int i = 0;
//     int idx = arr.numOfElements - 1;
//     while (i < arr.numOfElements)
//     {
//         a[i] = arr.a[i]
//         a[idx] = arr.a[idx];
//         q.push_back(q.front());
//         q.pop();
//         ++i;
//         --idx;
//     }
// }

int main()
{
    vector<int> v1 = {2, 3, 7, 2, 9, 0, 5};
    vector<int> v2 = {3, 2, 1, 4};

    list<int> l1 = {2, 1, 9, 2, 6, 3};
    list<int> l2 = {6, 7, 8, 9, 0};

    set<int> s1 = {5, 4, 1, 3, 7, 2};
    multiset<int> s2 = {5, 4, 1, 2, 5, 2, 2, 0, 0, 5};

    map<int, int> m1 = {
        {1, -100},
        {2, 200},
        {4, 400},
        {3, 300},
    };
    multimap<int, int> m2 = {
        {1, 100},
        {2, 200},
        {4, 400},
        {3, 300},
        {2, 250},
	};

    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);

    stack<int> st2;
    st2.push(0);
    st2.push(0);

    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    queue<int> q2;
    q2.push(0);
    q2.push(0);


    // STL vector
        // assign, erase, front, insert, swap
    v1.assign(3, 0);
    v1.assign(l1.begin(), l1.end());
    v1.assign({1, 2, 3, 4});
    // cout << v1.front() << ' ' << v1.back() << endl;
    v1.insert(v1.begin() + 3, 2, 0);
    v1.insert(v1.begin() + 3, l1.begin(), l1.end());
    v1.insert(v1.begin() + 6, {0, 0, 0});
    v1.swap(v2);

    // STL list
        // assign, erase, insert, merge, remove, remove_if, sort, splice, swap, unique
    l1.assign(10, 0);
    l1.assign(v2.begin(), v2.end());
    l1.assign({0, 0});
    l2.erase(++l2.begin());
    l2.erase(++l2.begin(), l2.end());
    l2.insert(l2.begin(), 4, 9);
    l2.insert(l2.begin(), s1.begin(), s1.end());
    l2.insert(l2.begin(), {0, 0, 0});
    l1.merge(l2);
    l2.remove(9);
    l2.remove_if([] (int e) { return e % 2 == 0;});
    l2.sort([] (int a, int b) { return a > b; });
    l1.splice(++l1.begin(), l2, ++l2.begin(), l2.end());
    l1.swap(l2);
    l1.assign({1, 2, 2, 3, 4});
    l1.unique();

    // STL set/multiset/map/multimap
        // count, erase, insert, find, swap
    // cout << s2.count(0) << endl;
    s2.erase(2);
    s2.insert(s1.begin(), s1.end());
    // cout << m2.count(2) << endl;
    // m2.erase(++m2.begin(), m2.end());
    m2.erase(2);
    m2.insert({2, 200});
    
    // STL stack/queue
        // swap (both member and non-member)
    st1.swap(st2);
    swap(st1, st2);
    q1.swap(q2);
    swap(q1, q2);

    // cout << v1.front();

    // STL ALGORITHM
    // adjacent_find
    // copy, copy_backward, copy_if, copy_n
    v1.resize(v1.size() + 3);
    copy_backward(v1.begin(), v1.begin()+3, v1.end());
    v1.resize(v1.size() + 3);
    copy_if(v1.begin(), v1.begin()+6, v1.begin(), [] (int e) { return e % 2 == 0; });
    copy_n(v1.begin()+7, 3, v1.begin());
    // count, count_if
    // cout << count_if(v1.begin(), v1.end(), [] (int e) { return e == 0; }) << endl;
    // fill, fill_n
    fill_n(v1.begin(), 4, 0);
    // find, find_if
    // cout << *(find_if(v1.begin(), v1.end(), [] (int e) { return e == 4; }));
    // for_each
    for_each(v1.begin(), v1.end(), [] (int& e) { return e *= 2; });
    // is_sorted
    // merge
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v1.begin());
    // move
    // remove, remove_if
    l1.erase(remove_if(l1.begin(), l1.end(), [] (int e) { return e % 2 == 0; }), l1.end());
    // replace, replace_if
    // reverse
    // rotate
    rotate(l2.begin(), ++l2.begin(), l2.end());
    // sort
    // swap
    // unique

    // printVector(v1);
    // printList(l1);
    // printList(l2);
    // printSet(s1);
    // printMap(m1);
    // printMultiSet(s2);
    // printMultiMap(m2);
    // printStack(st1);
    // printQueue(q1);
    
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

void printSet(const set<int>& aSet)
{
	for (const int& elem : aSet)
		cout << elem << " ";
	cout << endl;
}

void printMap(const map<int, int>& aMap)
{
	for (const auto& elem : aMap)
	{
		cout << "(" << elem.first << ", " << elem.second << ")";
	}
	cout << endl;
}

void printMultiSet(const multiset<int>& aSet)
{
	for (const int& elem : aSet)
		cout << elem << " ";
	cout << endl;
}

void printMultiMap(const multimap<int, int>& aMap)
{
	for (const auto& elem : aMap)
	{
		cout << "(" << elem.first << ", " << elem.second << ")";
	}
	cout << endl;
}

void printStack(stack<int>& aStack)
{
    while (!aStack.empty())
    {
        cout << aStack.top() << ' ';
        aStack.pop();
    }
    cout << endl;
}

void printQueue(queue<int>& aQueue)
{
    while (!aQueue.empty())
    {
        cout << aQueue.front() << ' ';
        aQueue.pop();
    }
    cout << endl;
}