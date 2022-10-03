#include "DArray.h"
#include <iostream>
#include <string>

using namespace std;

// part 1
/* Write the definition of the function rotate() as a member function of the class DArray. 
The function passes an index and rotates the elements in the array to the left, 
making the value at the index specified be the first value of the array.
Parameter: A variable of type int.
Assumption: The list has at least one element (node). */
void DArray::rotate(int index)
{
   if (index > numOfElements)
   {
      cout << "\nRotation index exceeds number of elements.";
   }
   else if (index == numOfElements)
   {
      cout << "\nNo need to rotate.";
   }
   else
   {
      int rotateToFront = a[index];
      int moveToBack = a[0];
      while (a[0] != rotateToFront)
      {
         for (int i = 0; i < numOfElements; ++i)
         {
            a[i] = a[i + 1];
         }
         a[numOfElements - 1] = moveToBack;
         moveToBack = a[0];
      }
   }
}

// part 2
/* Write the definition of the function rotateRange() as a member function of the class DArray. 
The function rotates a specified range in the array to the left. 
The range is determined by the paramters (first, middle, last), where "first" is the first element in the range, 
"middle" is the element that will become the first element after rotation, and "last" is the last element in the range.
Parameters: Three variables of type int.
Restrictions: Do not use pointers. Use only indices to rotate. 
Assumptions:
The array stores more than 3 elements (no need to check).
All parameters are valid (they do not exceed the number of elements in the array). */
void DArray::rotateRange(int first, int middle, int last)
{
   int middleValue = a[middle];
   int moveToLast = a[first];
   while (a[first] != middleValue)
   {
      for (int i = first; i < last; ++i)
      {
         a[i] = a[i + 1];
      }
      a[last] = moveToLast;
      moveToLast = a[first];
   }
}


int main()
{
    return 0;
}