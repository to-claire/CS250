#include "AnyList.h"
#include <iostream>
#include <string>

using namespace std;

// part 1
/* Write the definition of the function getLastElem() 
as a member function of the class AnyList. 
The function should return the first element in the list. 
Assumption: The list has at least one element (node). */
int AnyList::getLastElem() const
{
   if (count == 1)
   {
      return ptrToFirst->getData();
   }
   else
   {
      Node* current = ptrToFirst;
      while (current->getPtrToNext() != nullptr)
      {
         current = current->getPtrToNext();
      }
      return current->getData();
   }
}

// part 2
/* Write the definition of the function allOdds() as a member function of the class AnyList. 
The function returns true if all the elements in the list are odd numbers.
Assumption: The list has at least one element (node). */
bool AnyList::allOdds() const
{
   if (count == 1)
   {
      return (ptrToFirst->getData() % 2 == 1);
   }
   else
   {
      Node* current = ptrToFirst;
      while (current != nullptr)
      {
         if (current->getData() % 2 == 0) 
         {
            return false;
         }
         else
         {
            current = current->getPtrToNext();
         }
      }
      return true;
   }
}

// part 3
/* Write the definition of the function deleteFirstNode() as a member function of the class AnyList. 
The function deletes the first node in the list. */
void AnyList::deleteFirstNode()
{
   if (count == 0)
   {
      cerr << "Cannot delete from an empty list.\n";\
   }
   else
   {
      if (count == 1)
      {
         delete ptrToFirst;
         ptrToFirst = nullptr;
      }
      else 
      {
         Node* current = ptrToFirst;
         ptrToFirst = ptrToFirst->getPtrToNext();
         delete current;
         current = nullptr;
      }
      count--;
   }
}

// part 4
/* Write the definition of the function compareLists() as a member function of the class AnyList. 
The function passes an object of the class AnyList and returns true if the calling object 
and the parameter objects have the same elements in the same order.
Assumption: Both lists have at least one element. */
bool AnyList::compareLists(const AnyList& rhs) const
{
   if (count != rhs.count)
   {
      return false;
   }
   else
   {
      if (count == 1) 
      {
         return (ptrToFirst->getData() 
            == rhs.ptrToFirst->getData());
      }
      else
      {
         Node* leftPtr = ptrToFirst;
         Node* rightPtr = rhs.ptrToFirst;
      
         while (leftPtr != nullptr && rightPtr != nullptr)
         {
            if (leftPtr->getData() != rightPtr->getData())
            {
               return false;
            }
            else
            {
               leftPtr = leftPtr->getPtrToNext();
               rightPtr = rightPtr->getPtrToNext();
            }
         }
         return true;
      }
   }
}


int main()
{
   return 0;
}
