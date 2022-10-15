#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> aVector = { 1, 2, 6, 3, 2, 4, 2, 5, 2 };
    list<int> aList = { 1, 2, 6, 3, 2, 4, 2, 5, 2 };
    multiset<int> aMultiSet = { 1, 2, 6, 3, 2, 4, 2, 5, 2 };
    multimap<int, char> aMultiMap = {
        { 1, 'B' },
        { 2, 'A' },
        { 6, 'M' },
        { 3, 'X' },
        { 2, 'F' },
        { 4, 'L' },
        { 2, 'B' },
        { 5, 'B' },
        { 2, 'A' },
    };

    /* 
        Note that the multiset will store all the elements in order.
        Also note that the mutimap will do the same, but it will
        keep what is called a "stable order", which means that duplicate
        keys will be stored according the order in which they came:
        ... {2,'A'},{2,'F'},{2,'B'},{2,'A'}...
    */

    // The return type is a "signed integral type";
    // therefore, it can be stored in an int.
    int countAll2s = count(aVector.begin(), aVector.end(), 2);
    cout << countAll2s << "\n";

    cout << count(aVector.begin(), aVector.begin() + 6, 2) << "\n"; 
    // The output for this one will not be 3, but 2, because
    // aVector.begin() + 6 will point to the third 2 in the vector,
    // which will not be included in the half-open interval. 

    cout << count(aList.begin(), aList.end(), 2) << "\n";

    cout << count(aMultiSet.begin(), aMultiSet.end(), 2) << "\n";

    // Could you use (aList.begin() + 6) or (aSet.begin() + 6)? 
    // No, because lists and sets do not have random access.
    // The algorithm count does not work for a multimap. That is 
    // why the multimap has its own member function count.
    cout << aMultiMap.count(2) << "\n";
    // If you need to find how many times 2 is repeated in a specific
    // range in the multimap, then you would need to create a loop and 
    // simply keep count. 
    
    cout << "\n";
    return 0;
}