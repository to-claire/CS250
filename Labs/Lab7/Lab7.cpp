#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

// part 1
void displayScores(vector<int>& scores)
{
    /*************************************
        Do NOT use endl or \n
    **************************************/
    // Use std::sort to sort scores in descending order.
    // You will need a lambda expression.
    // Your code here...
    sort(scores.begin(), scores.end(), 
        [] (int a, int b) { return a > b; });

    cout << "\nHighest score: ";

    // Display highest score.
    // Use std::max_element to find the highest score.
    // Your code here...
    for_each(scores.begin(), scores.end(), 
        [] (int e) { cout << e << ' '; });

    cout << "\nLowest score: ";
    // Display lowest score.
    // Use std::min_element to find the lowest score. 
    // Your code here...
    cout << *min_element(scores.begin(), scores.end());

    cout << "\nPerfect scores: ";
    // Display number of scores equal to 100.
    // Use std::count
    // Your code here...
    cout << count(scores.begin(), scores.end(), 100);

    cout << "\nScore count: ";
    // Display the total number of scores.
    // Use vector::size
    // Your code here...
    cout << scores.size();
}

// part 2
void workingWithLists(list<int>& firstList,
    list<int>& secondList, int value1, int value2, int value3)
{
    /*******************************************
        Do NOT use endl or \n
    ********************************************/

    ostream_iterator<int> screen(cout, " ");

    cout << "First list: ";
    copy(firstList.begin(), firstList.end(), screen);

    cout << "\nSearch " << value1 << ": ";
    // If found, print "Found." otherwise print "Not found."
    // Use std::find on firstList.
    if (find(firstList.begin(), firstList.end(), value1) != firstList.end())
    {
        cout << "Found.";
    }
    else
    {
        cout << "Not found.";
    }

    cout << "\nReplace " << value2 << " with " << value3 << ": ";
    // Use std::replace on firstList.
    replace(firstList.begin(), firstList.end(), value2, value3);

    copy(firstList.begin(), firstList.end(), screen);

    cout << "\nDelete " << value3 << ": ";
    // Use std::find and list::erase on firstList.
    firstList.erase(find(firstList.begin(), firstList.end(), value3));

    copy(firstList.begin(), firstList.end(), screen);
    cout << "\nSort the list: ";
    // Use list::sort on firstList.
    firstList.sort();

    copy(firstList.begin(), firstList.end(), screen);

    cout << "\nReverse the list starting from the 3rd element: ";
    // Use std::reverse on firstList
    auto itr = firstList.begin();
    advance(itr, 2);
    reverse(itr, firstList.end());

    copy(firstList.begin(), firstList.end(), screen);

    cout << "\nSecond list: ";
    copy(secondList.begin(), secondList.end(), screen);

    cout << "\nMove last three elements of the second list "
        << "into the first list at position fourth.\n";

    // Use list::splice and std::advance
    auto itr1 = firstList.begin();
    advance(itr1, 3);
    auto itr2 = secondList.begin();
    advance(itr2, secondList.size() - 3);
    firstList.splice(itr1, secondList, itr2, secondList.end());

    cout << "First list: ";
    copy(firstList.begin(), firstList.end(), screen);
    cout << "\nSecond list: ";
    copy(secondList.begin(), secondList.end(), screen);
    cout << endl;
}

// part 3
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

extern void print(const vector<int>& vector1, const vector<int>& vector2);

void workingWithVectors(vector<int>& vector1, vector<int>& vector2)
{
    /****************************************
        Do NOT use endl or \n.
        vector1 contains elements.
        vector2 contains all 0 with size 20.
    *****************************************/
    cout << "Initial data:\n";
    print(vector1, vector2);

    // Use std::copy_if to copy all the positive
    // integers of vector1 into vector2.
    // You will need a lambda expression and
    // readjust the size of the vector.
    // Your code here...
    auto itr = copy_if(vector1.begin(), vector1.end(), vector2.begin(),
        [] (int e) { return e > 0; });
    vector2.resize(itr - vector2.begin());
    
    cout << "\nAll positive elements have been copied...\n";
    print(vector1, vector2);

    int sumOfOdds = 0;

    // Use std::for_each to sum all elements in vector2,
    // storing the result in variable sumOfOdds.
    // You will need a lambda expression.
    // Your code here...
    for_each(vector2.begin(), vector2.end(),
        [&sumOfOdds] (int e) { if (e % 2 == 1) sumOfOdds += e; });
    
    cout << "\nSum of all odds elements in vector1: " << sumOfOdds << endl;

    // Use std::for_each to double all elements in vector2.
    // You will need a lambda expression.
    // How should you pass the parameter in the lambda
    // expression so that the original elements are modified?
    // Your code here...
    for_each(vector2.begin(), vector2.end(),
        [] (int& e) { e *= 2; });
    
    cout << "\nAll elements in vector2 have been doubled...\n";
    print(vector1, vector2);
}