#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

// RESTRICTIONS:
// CANNOT use any numbers (0, 1, 2, etc.).
    // Example:
    // Given a vector named aVector that contains { 2, 5, 7, 1 }, replace 7 with 4.
    // Solution:  aVector[*aVector.begin()] = (*aVector.begin()) * (*aVector.begin());
// CANNOT create additional variables.
// CANNOT create additional containers.
// Each function requires a SINGLE statement.
// Some function will require to use specific member functions.

// ALLOWED:
// Can use iterators.
// Can use the following arithmetic operators: +, -, *, /

// WARNING: 
// - Do NOT use ++++ or ---- (or any longer combination).
// - Do NOT use end() to get the last element (think of end() as a nullptr).


// (functionVectorOne) ---------------------------------------
// vectorOne is: 5 2 9 8 4 1 6 
// Function runs...
// Expected output: 5 1 1 1 1 1 2 9 8 4 1 6 
void functionVectorOne(vector<int>& vectorOne)
{
    vectorOne.insert(++vectorOne.begin(), *vectorOne.begin(), 
	   (*vectorOne.begin() / *vectorOne.begin()));
}

// (functionVectorTwo) ---------------------------------------
// vectorTwoA is: 1 2 3 4 5 6 
// vectorTwoB is empty.
// Function runs...
// Expected output vectorTwoA: 6 5 4 3 2 1
// Expected output vectorTwoB: 1 2 3 4 5 6
void functionVectorTwo(vector<int>& vectorTwoA, 
    vector<int>& vectorTwoB)
{
    vectorTwoA.swap(vectorTwoB);
} // incorrect

// (functionVectorThree) --------------------------------------
// vectorThree is: 2 14 3 67 8 75 
// Function runs...
// Expected output: 2 6 14 3 67 8 75
void functionVectorThree(vector<int>& vectorThree)
{
    vectorThree.insert(++vectorThree.begin(), *vectorThree.begin() + 
	   *vectorThree.begin() + *vectorThree.begin());
}

// (functionVectorFour) ---------------------------------------
// vectorFour is: 6 5 4 3 2 9 
// Function runs...
// Expected output: 6 5 4 3 2
void functionVectorFour(vector<int>& vectorFour)
{
    vectorFour.pop_back();
}

// (functionVectorFive) ---------------------------------------
// vectorFive is: 5 2 9 3 8 6 
// Function runs...
// Expected output: 9 5 2 9 3 8 6
void functionVectorFive(vector<int>& vectorFive)
{
    vectorFive.insert(vectorFive.begin(), *vectorFive.begin() +
	   *(++vectorFive.begin()) + *(++vectorFive.begin()));
}

// (functionListOne) ------------------------------------------
// listOne is: 1 3 4 5 6 7 2 
// Function runs...
// Expected output: 1 2 3 4 5 6 7
void functionListOne(list<int>& listOne)
{
    listOne.sort();
}

// (functionListTwo) ------------------------------------------
// listTwo is: 9 1 2 6 8 
// Function runs...
// Expected output: 9 1 2 6 8 0 0 0 0
void functionListTwo(list<int>& listTwo)
{
    listTwo.resize(*listTwo.begin());
}

// (functionListThree) ----------------------------------------
// listThreeA is: 34 67 89 12 34 56 
// listThreeB is: 1 2 3 4 5 
// Function runs...
// Expected output listThreeA: 67 89 12 34 56
// Expected output listThreeB: 1 34 2 3 4 5
void functionListThree(list<int>& listThreeA,
    list<int>& listThreeB)
{
    listThreeB.splice(++listThreeB.begin(), listThreeA, 
        listThreeA.begin());
}

// (functionMultisetOne) ---------------------------------------
// multisetOne is: 2 12 22 34 62 73 90 
// Function runs...
// Expected output: 2 12 22 34 45 62 73 90
void functionMultisetOne(multiset<int>& multisetOne)
{
    multisetOne.insert(multisetOne.begin(), 
        *multisetOne.rbegin() / *multisetOne.begin());
}

// (functionMapOne) -------------------------------------------
// mapOne is: {2,6}{4,3}{5,22}{6,12}{7,4}{9,1}
// Function runs...
// Expected output: {2,6}{4,3}{5,22}{7,4}{9,1}
void functionMapOne(map<int, int>& mapOne)
{
    mapOne.erase(mapOne.begin()->second);
}

// (functionMultimapOne) --------------------------------------
// multimapA is empty.
// multimapB is: {3,14}{4,35}{4,48}{6,52}{6,12}
// Function runs...
// Expected output multimapA: {3,14}{4,35}{4,48}{6,52}{6,12}
// Expected output multimapB: {3,14}{4,35}{4,48}{6,52}{6,12}
void functionMultimapOne(multimap<int, int>& multimapA,
    const multimap<int, int>& multimapB)
{
    multimapA = multimapB;
}


