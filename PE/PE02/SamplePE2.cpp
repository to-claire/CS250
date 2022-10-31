// #include "AnyList.h"
// #include "AnyList.cpp"
// #include "DoublyList.h"
// #include "DoublyList.cpp"

// #include "Pair.h"
// #include "Pair.cpp"
#include "DArray.h"
#include "DArray.cpp"

#include <iostream>
#include <vector>
#include <list>
#include <set> // +multiset
#include <map> // +multimap
#include <stack>
#include <queue>
#include <algorithm>
// #include <utility>

using namespace std;

// Create a member function of DArray that passes two parameters, an STL list of type int and an STL set of type int. 
// Use an STL function to search container 1 for a specific value (or range of values). 
// If it is found, insert that element in container 2 (where will depend on the container) and at the end of the calling object. 
// If it is not found, insert that element in container 2 and double the value of the last element in the calling object 
// (assume capacity is large enough to accommodate one more element). 
// The function should return a Boolean, indicating whether the value was found or not.

bool DArray::function2(const std::list<int>& aList, std::set<int>& aSet, int elem)
{
    if (find(aList.begin(), aList.end(), elem) != aList.end())
    {
        aSet.insert(elem);
        a[numOfElements] = elem;
        ++numOfElements;
        return true;
    }
    else
    {
        aSet.insert(elem);
        a[numOfElements - 1] = a[numOfElements - 1] * 2;
        return false;
    }
}

// Create a function that passes three parameters, an STL multimap of type <int,int>, 
// an STL vector of type int, and an STL stack of type int. 
// Use an STL function to check if the multimap contains a key that is equal to the last element of the vector. 
// If that key is found, insert into the stack all the values associated with that key, 
// in the order they are from the first occurrence of the key. 
// If there is no key that is equal to the last element of the vector, 
// insert the value of the last element of the vector into the stack.

void function3(const map<int, int>& aMap, const vector<int>& aVector, stack<int>& aStack)
{
    int elem = aVector.back();
    auto itr = aMap.find(elem);
    if (itr != aMap.end())
    {
        while (itr->first == elem)
        {
            aStack.push(itr->second);
            ++itr;
        }
    }
    else
    {
        aStack.push(elem);
    }
}


int main()
{
    return 0;
}