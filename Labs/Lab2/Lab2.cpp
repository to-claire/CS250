#include "DoublyList.h"
#include <iostream>
#include <string>

using namespace std;

// part 1
/* Write the definition of the function search() as a member function of the class DoublyList. 
The function searches for a given value passed by the parameter and returns true if found, or false otherwise.
Parameter: A variable of type int.
Assumption: The list has at least one element (node). */
bool DoublyList::search(int data) const
{
   if (count == 1)
   {
      return (first->getData() == data);
   }
   else if (first->getData() == data || last->getData() == data)
   {
      return true;
   }
   else
   {
      Node* current = first->getNext();
      while (current != nullptr)
      {
         if (current->getData() == data)
         {
            return true;
         }
         else
         {
            current = current->getNext();
         }
      }
      return false;
   }
}

// part 2
/* Write the definition of the function swapLists() as a member function of the class DoublyList. 
The function swaps the calling list and the parameter lists. Your code should be efficient (no need to use loops).
Parameter: An object of type DoublyList.
Assumption: Both lists are non-empty. */
void DoublyList::swapLists(DoublyList& otherList)
{
   Node* firstTemp = first;
   Node* lastTemp = last;
   int countTemp = count;
   
   first = otherList.first;
   last = otherList.last;
   count = otherList.count;
   
   otherList.first = firstTemp;
   otherList.last = lastTemp;
   otherList.count = countTemp;
   
}

// part 3
/* Write the definition of the function insertInOrder() as a member function of the class DoublyList. 
The function inserts an element in the list in ascending order. 
Parameter: A variable of type int storing the value to insert. */
void DoublyList::insertInOrder(int value)
{
   if (count == 0)
   {
      first = new Node(value, nullptr, nullptr);
      last = first;
   }
   else if (value < first->getData())
   {
      first = new Node(value, nullptr, first);
      first->getNext()->setPrev(first);
   }
   else if (value > last->getData())
   {
      last = new Node(value, last, nullptr);
      last->getPrev()->setNext(last);
   }
   else
   {
      Node* current = first->getNext();
      bool indexFound = false;
      
      while (current != nullptr && !indexFound)
      {
         if (current->getData() > value)
         {
            indexFound = true;
         }
         else
         {
            current = current->getNext();
         }
      }
      
      Node* newNode = new Node(value, current->getPrev(), current);
      current->getPrev()->setNext(newNode);
      current->setPrev(newNode);
      current = nullptr;
   }
   count++;
}

int main()
{
    return 0;
}