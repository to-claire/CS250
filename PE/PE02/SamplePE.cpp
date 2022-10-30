// #include "AnyList.h"
// #include "AnyList.cpp"
#include "DoublyList.h"
#include "DoublyList.cpp"

#include "Pair.h"
#include "Pair.cpp"
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
#include <utility>

using namespace std;

// Function identifier: function1
// Member function of the DArray class
   // Member variables of the DArray class (as seen in the lessons)
      // int* a, int cap, int numOfElements
// Parameters: An STL vector of type int
// Return value: Boolean

// The function returns true if the sequence of integers 
// in the DArray object is the same (same order as well) 
// as the one in the vector object; if not the same, it returns false.

// You may use auto for iterators.
// Assumptions: none
// Restrictions: none

bool DArray::function1(const vector<int>& aVector)
{
   if (numOfElements == 0)
      return false;
   else if (numOfElements != static_cast<int>(aVector.size()))
      return false;
   else
   {
      int idx = 0;
      while (idx < numOfElements)
      {
         if (a[idx] != aVector[idx])
            return false;
         else
            ++idx;
      }
      return true;
   }
}

// Function identifier: function2
// Non-member function
// Parameters (in this order):
   // An STL map of type int/int
   // An STL list of type int
   // An STL set of type int
   // An int storing an element to search
// Return value: none

// The function searches the list for a given element. 
// If the element is found, all the elements in the list will be inserted into the set, 
// and then all the elements of the list and the set will be inserted into the map so that 
// the set elements are the keys of the map pairs and the list elements are the values of the map pairs. 
// The function does nothing if the element is not found.
// You may use auto for iterators.
// Assumptions: 
   // Map is empty.
   // List has at least one element and no duplicates.
   // Set is empty.
// Restrictions: 
   // Use STL algorithm std::find to search the STL list.
   // Use STL function set::insert.
   // Cannot create any objects.

// Example 1:
   // Map is: (empty); List is: 2 4 9 1 3; Set is: (empty); Element is: 9
   // Map is: {1,2}{2,4}{3,9}{4,1}{9,3}; List is: 2 4 9 1 3; Set is: 1 2 3 4 9
// Example 2:
   // Map is: (empty); List is: 23 87 46 51 29 16 33 90; Set is: (empty); Element is: 100
   // Map is: (empty); List is: 23 87 46 51 29 16 33 90; Set is: (empty)
// Example 3:
   // Map is: (empty); List is: 34; Set is: (empty); Element is: 34
   // Map is: {34,34}; List is: 34; Set is: 34

void function2(map<int, int>& aMap, const list<int>& aList, set<int>& aSet, int element)
{
   // the function searches the list for a given element
   if (find(aList.begin(), aList.end(), element) != aList.end())
   {
      // if found, all list elements will be inserted into the set
      for (int e : aList)
      {
         aSet.insert(e);
      }
      
      // insert all list and set elements into a map of pair(set, list)
      auto itrSet = aSet.begin();
      for (const auto& elem : aList)
      {
         aMap[*itrSet] = elem;
         ++itrSet;
      }
      // or aMap.insert(itrMap, { *itrSet, *itrList });
   }
}


// Extra-credit Question (3 pts.)
// Function identifier: function3
// Member function of the DoublyList class (definition shown below)
// Parameters:
   // An STL queue of type int
// The function pushes into the queue the first element of the list, the last element of the list, 
// the second element of the list, the before-last element of the list, and so on.
// Return type: none

// Assumptions:  
   // The list has at least one element.
   // The queue is empty.
// Restrictions: 
   // Cannot create any objects.

// Example 1:
   // List is: 3 8 6 4 5 1 7 2; Queue is: (empty) 
   // List is: 3 8 6 4 5 1 7 2; Queue is: 3 2 8 7 6 1 4 5
// Example 2:
   // List is: 45 87 12 94 73 60 22; Queue is: (empty) 
   // List is: 45 87 12 94 73 60 22; Queue is: 45 22 87 60 12 73 94
// Example 3:
   // List is: 56; Queue is: (empty) 
   // List is: 56; Queue is: 56

void DoublyList::function3(queue<int>& aQueue) const
{
   Node* ptrFront = first;
   Node* ptrBack = last;
   for (int i = 0; i < count / 2; ++i)
   {
      aQueue.push(ptrFront->getData());
      aQueue.push(ptrBack->getData());
      ptrFront = ptrFront->getNext();
      ptrBack = ptrBack->getPrev();
   }
   if (count % 2 == 1) 
   {
      aQueue.push(ptrFront->getData());
   }
}

int main()
{
   return 0;
}