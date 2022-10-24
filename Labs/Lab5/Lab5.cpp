#include <iostream>
#include <vector>
#include <list>

using namespace std;

void printSuitors(const vector<int>& suitors, 
    const list<int>& eliminatedSuitors);

// In an ancient land, the beautiful princess Eve had many suitors. 
// She decided on the following procedure to determine which suitor she would marry. 
// First, all of the suitors would be lined up one after the other and be assigned numbers. 
// The first suitor would be number 1, the second number 2, and so on up to the last suitor, number n.
// Starting at the first suitor she would then count three suitors down the line 
// (because of the three letters in her name) and the third suitor would be eliminated 
// from winning her hand and he would be removed from the line.  
// Eve would then continue, counting three more suitors and eliminating every third suitor.  
// When she reached the end of the line she would continue counting from the beginning.

// 123456  initial list of suitors, start counting from 1
// 12456   suitor 3 eliminated, continue counting from 4
// 1245    suitor 6 eliminated, continue counting from 1
// 125     suitor 4 eliminated, continue counting from 5
// 15      suitor 2 eliminated, continue counting from 5
// suitor 5 eliminated, 1 is the lucky winner!

// int processSuitors(vector<int>& suitors, list<int>& eliminatedSuitors)
// {
//    int index = 0, count = 1;
//    while (suitors.size() > 1)
//    {
//       if (count % 3 == 0)
//       {
//          eliminatedSuitors.push_back(suitors[index]);
//          suitors.erase(suitors.begin() + index);
//       }
//       else ++index;
//       if (index == suitors.size()) index = 0;
//       ++count;
//    }
//    return suitors[0];
// }

int processSuitors(vector<int>& suitors, list<int>& eliminatedSuitors)
{
   int index = 2;
   while (suitors.size() > 1)
   {
      eliminatedSuitors.push_back(suitors[index]);
      suitors.erase(suitors.begin() + index);
      index = (index + 2) % suitors.size();
   }
   return suitors[0];
}

int main()
{
    vector<int> suitors = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    list<int> eliminatedSuitors;
    processSuitors(suitors, eliminatedSuitors);
    printSuitors(suitors, eliminatedSuitors);
    return 0;
}

void printSuitors(const vector<int>& suitors, const list<int>& eliminatedSuitors)
{
    cout << "suitors: ";
    for (const auto& e : suitors)
    {
		cout << e << " ";
    }
    cout << "\neliminatedSuitors: ";
    for (const auto& e : eliminatedSuitors)
    {
		cout << e << " ";
    }
    cout << endl;
}

// Number of suitors: 6
// Eliminated: 3 6 4 2 5 
// To win the princess, the suitor should stand in position 1.

// Number of suitors: 8
// Eliminated: 3 6 1 5 2 8 4 
// To win the princess, the suitor should stand in position 7.

// Number of suitors: 12
// Eliminated: 3 6 9 12 4 8 1 7 2 11 5 
// To win the princess, the suitor should stand in position 10.