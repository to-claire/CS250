#include "LinkedQueue.h"

#include <iostream>
using namespace std;

// part 1
void LinkedQueue::push(int data)
{
   Node* newNode = new Node(data, nullptr);
   if (count == 0)
   {
      ptrToFront = ptrToBack = newNode;
   }
   else
   {
      ptrToBack->setNext(newNode);
      ptrToBack = newNode;
   }
   ++count;
}

// part 2
void LinkedQueue::pop()
{
   if (count == 1)
   {
      delete ptrToFront;
      ptrToFront = ptrToBack = nullptr;
   }
   else
   {
      Node* temp = ptrToFront;
      ptrToFront = ptrToFront->getNext();
      delete temp;
      temp = nullptr;
   }
   --count;
}

// part 3
bool LinkedQueue::empty() const
{
   return (count == 0);
}

int LinkedQueue::front() const
{
   return ptrToFront->getData();
}

int LinkedQueue::back() const
{
   return ptrToBack->getData();
}

size_t LinkedQueue::size() const
{
   return count;
}



int main()
{
    return 0;
}