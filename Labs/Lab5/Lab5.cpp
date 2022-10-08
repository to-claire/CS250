#include <iostream>
#include <vector>
#include <list>

using namespace std;

void print(const vector<int>& suitors, 
    const list<int>& eliminatedSuitors, 
    const vector<int>::iterator& itr);

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

int processSuitors(vector<int>& suitors, list<int>& eliminatedSuitors)
{
   vector<int>::iterator itr = suitors.begin() + 2;
   int size = suitors.size();
   while (size > 1)
   {
      if (itr < suitors.end())
      {
         eliminatedSuitors.push_back(*itr);
         itr = suitors.erase(itr);
         --size;
         itr += 2;
      }
      else
      {
         itr = suitors.begin() + (2 - (suitors.end() - (itr - 2))); 
      }
   }
   print(suitors, eliminatedSuitors, itr);
   return suitors[0];
}



int main()
{
    vector<int> suitors = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> eliminatedSuitors;
    processSuitors(suitors, eliminatedSuitors);
    return 0;
}

void print(const vector<int>& suitors, const list<int>& eliminatedSuitors, const vector<int>::iterator& itr)
{
    cout << "Suitors: ";
    for (const auto& e : suitors)
    {
		cout << e << " ";
    }
    cout << "\nEliminated: ";
    for (const auto& e : eliminatedSuitors)
    {
		cout << e << " ";
    }
    cout << "\nCurrent itr: " << *itr << endl;
}