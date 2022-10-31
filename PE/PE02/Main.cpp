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

int main()
{
    vector<int> v1 = {1, 3, 7, 2, 9, 0};

    return 0;
}

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

// Functions that you need to know how to use with a given description:
// STL vector
    // assign, erase, front, insert, swap
// STL list
    // assign, erase, insert, merge, remove, remove_if, sort, splice, swap, unique
// STL set/multiset/map/multimap
    // count, erase, insert, find, swap
// STL stack/queue
    // swap (both member and non-member)
// STL algorithms
    // adjacent_find
    // copy, copy_backward, copy_if, copy_n
    // count, count_if
    // fill, fill_n
    // find, find_if
    // for_each
    // is_sorted
    // merge
    // move
    // remove, remove_if
    // replace, replace_if
    // reverse
    // rotate
    // sort
    // swap
    // unique