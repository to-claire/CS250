#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void searchElement(const set<int>& aSet, int element)
{
    if (binary_search(aSet.begin(), aSet.end(), element))
        cout << "Element " << element << " was found." << "\n";
    else 
        cout << "Element " << element << " was not found." << "\n";
}

int main()
{
    set<int> aSet = { 78, 32, 41, 74, 93, 12, 67, 53, 88, 72, 33 };
    searchElement(aSet, 12);    // first element
    searchElement(aSet, 93);    // last element
    searchElement(aSet, 41);    // element somewhere in the middle
    searchElement(aSet, 999);   // element not in the set

    cout << "\n";
    return 0;
}