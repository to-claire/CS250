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


// (functionVectorOne) -------------------------------------------
// vectorOne is: 5 2 9 8 4 1 6 
// Function runs...
// Expected output: 1 1 5 2 9 8 4 1 6
void functionVectorOne(vector<int>& vectorOne)
{
    vectorOne.insert(vectorOne.begin(), 
	   *(++vectorOne.begin()),
	   *vectorOne.begin() / *vectorOne.begin());
}

// (functionVectorTwo) -------------------------------------------
// vectorTwoA is: 1 2 3 4 5 6 
// vectorTwoB is: 10 20 30 40 
// Function runs...
// Expected output vectorTwoA: 1 2 3 4 5 6
// Expected output vectorTwoB: 2 10 20 30 40
void functionVectorTwo(vector<int>& vectorTwoA, 
    vector<int>& vectorTwoB)
{
    vectorTwoB.insert(vectorTwoB.begin(), *(++vectorTwoA.begin()));
}

// (functionVectorThree) -------------------------------------------
// vectorThree is: 2 14 3 67 8 75 
// Function runs...
// Expected output: 5 2 14 3 67 8 75 
void functionVectorThree(vector<int>& vectorThree)
{
    vectorThree.insert(vectorThree.begin(), 
	   *(++vectorThree.begin()) / *vectorThree.begin() -
	   *vectorThree.begin());
}

// (functionVectorFour) -------------------------------------------
// vectorFour is: 6 5 4 3 2 9 
// Function runs...
// Expected output: 6 6 6 6 6
void functionVectorFour(vector<int>& vectorFour)
{
    vectorFour.assign(*(++vectorFour.begin()), *vectorFour.begin());
}

// (functionVectorFive) -------------------------------------------
// vectorFive is: 3 5 9 7 8 6 
// Function runs...
// Expected output: 3 9 7 8 6
void functionVectorFive(vector<int>& vectorFive)
{
    vectorFive.erase(++vectorFive.begin());
}

// (functionListOne) -------------------------------------------
// listOne is: 1 3 4 4 5 1 1 6 7 1 2 
// Function runs...
// Expected output: 3 4 4 5 6 7 2
void functionListOne(list<int>& listOne)
{
    listOne.remove(*listOne.begin());
}

// (functionListTwo) -------------------------------------------
// listTwo is: 3 2 1 
// Function runs...
// Expected output: 3 2 1 0 0 0 0 0 0
void functionListTwo(list<int>& listTwo)
{
    listTwo.resize(*listTwo.begin() * *listTwo.begin());
}

// (functionListThree) -------------------------------------------
// listThreeA is: 1 2 3 4 5 
// listThreeB is: 6 7 8 9 
// Function runs...
// Expected output listThreeA: 
// Expected output listThreeB: 1 2 3 4 5 6 7 8 9
void functionListThree(list<int>& listThreeA,
    list<int>& listThreeB)
{
    listThreeB.splice(listThreeB.begin(), listThreeA);
}

// (functionMultisetOne) -------------------------------------------
// multisetOne is: 12 22 34 54 62 73 90 
// Function runs...
// Expected output: 7 12 22 34 54 62 73 90
void functionMultisetOne(multiset<int>& multisetOne)
{
    multisetOne.insert(*multisetOne.rbegin() /
         *multisetOne.begin());
}

// (functionMapOne) -------------------------------------------
// mapOne is: {2,8}{4,7}{5,22}{6,12}{7,4}{9,1}
// Function runs...
// Expected output: {2,8}{4,7}{5,22}{6,12}{9,1}
void functionMapOne(map<int, int>& mapOne)
{
    mapOne.erase((++mapOne.begin())->second);
}

// (functionMultimapOne) -------------------------------------------
// multimapA is: {178,3}{567,9}
// multimapB is: {3,14}{4,35}{4,48}{6,52}{6,12}
// Function runs...
// Expected output multimapA: {3,14}{4,35}{4,48}{6,52}{6,12}
// Expected output multimapB: {178,3}{567,9}
void functionMultimapOne(multimap<int, int>& multimapA,
    multimap<int, int>& multimapB)
{
    multimapA.swap(multimapB);
}
