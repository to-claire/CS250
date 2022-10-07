#include "AnyList.h"

using namespace std;

// Consider all options: list is empty/non-empty, 1 node, 2 nodes, 3 nodes, several nodes
// Assume NO duplicates, unless otherwise stated
// Restrictions: can use only one loop, cannot use any pointers, etc
// To swap nodes, rearrange pointers


// Sum of the first 2 calling and add to the end of parameter 
void AnyList::sumCallingToEndParamater(AnyList& otherList) const
{
    if (count > 1)
    {
        int sum = first->getData() + first->getNext()->getData();
        if (otherList.count == 0)
        {
            otherList.first = new Node(sum, nullptr);
        }
        else
        {
            Node* current = otherList.first;
            int loopCount = 0;
            while (++loopCount < otherList.count)
            {
                current = current->getNext();
            }
            current->setNext(new Node(sum, nullptr));
        }
        ++otherList.count;
    }
}

// Swap the last value of parameter w the first value of calling 
void AnyList::swapLastParamFirstCalling(AnyList& otherList)
{
    if (count > 1)
    {
        if (otherList.count == 1)
        {
            int temp = otherList.first->getData();
            otherList.first->setData(first->getData());
            first->setData(temp);
        }
        else
        {
            Node* current = otherList.first;
            int loopCount = 0;
            while (++loopCount < otherList.count)
            {
                current = current->getNext();
            }
            int temp = current->getData();
            current->setData(first->getData());
            first->setData(temp);
        }
    }
}


bool AnyList::searchAndInsert(int value, AnyList& otherList) const
{
   bool found = false;
   // assume calling object has at least one element
   if (first->getData() == value)
   {
      found = true;
   }
   else
   {
      // search through calling object
      Node* current = first->getNext();
      while (current != nullptr && !found)
      {
         if (current->getData() == value)
         {
            found = true;
         }
         else
         {
            current = current->getNext();
         }
      }
   }
   
   // if value found, insert into parameter object
   if (found)
   {
      otherList.first = new Node(value, otherList.first);
      ++otherList.count;
   }
   return found;
}

// 1. Insert a new node, storing a given value, to the front of the calling object
void AnyList::insertBack(int newData)
{
    if (count == 0)
    {
        first = new Node(newData, nullptr);
    }
    else
    {
        Node* current = first;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
        current->setNext(new Node(newData, nullptr));
    }
    ++count;
}

// 8. Delete the second node of the calling object.
void AnyList::deleteSecond()
{
    if (count > 1)
    {
        Node* second = first->getNext();
        first->setNext(second->getNext());
        delete second;
        second = nullptr;
        --count;
    }
}

// 10. Delete the node before-last of the calling object.
void AnyList::deleteNode()
{
    if (count == 0)
    {
        cerr << "List is empty.\n";
    }
    else if (count < 2)
    {
        cout << "Not enough nodes.\n";
    }
    else
    {
        Node* current = first;
        if (count == 2)
        {
            first = first->getNext();
            first->setNext(nullptr);
        }
        else
        {
            Node* trailCurrent = first;
            int i = 0;
            while (i < (count - 3))
            {
                trailCurrent = trailCurrent->getNext();
                ++i;
            }
            current = trailCurrent->getNext();

            trailCurrent->setNext(current->getNext());
        }
        delete current;
        current = nullptr;
        --count;
    }
}

// 26. Swap the second node with the node before last.
// NOT EFFICIENT
void AnyList::swapSecondWithBeforeLast()
{
    if (count == 0)
    {
        cerr << "List is empty\n";
    }
    else if (count < 4);
    else
    {
        Node* second = first->getNext();
        Node* beforeLast = second->getNext();
        Node* last = beforeLast->getNext();

        if (count == 4)
        {
            second->setNext(last);
            beforeLast->setNext(second);
            first->setNext(beforeLast);
        }
        else
        {
            Node* trailBeforeLast = second;
            while (last->getNext() != nullptr)
            {
                last = last->getNext();
                beforeLast = beforeLast->getNext();
                trailBeforeLast = trailBeforeLast->getNext();
            }
            
            first->setNext(beforeLast);
            beforeLast->setNext(second->getNext());
            trailBeforeLast->setNext(second);
            second->setNext(last);
        }
    }
}



// 54. Swap the value of the last node of the calling object with the value of the first node of the parameter object.
void AnyList::swapLastCallingValueAndFirstParamValue(AnyList& otherList)
{
    if (count > 1 && otherList.count > 1)
    {
        int temp = otherList.first->getData();
        Node* current = first;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
        otherList.first->setData(current->getData());
        current->setData(temp);

    }
}

// 70. Sum first two nodes of the parameter object to a node end of calling object.
void AnyList::sumParamToEndCalling(const AnyList& otherList)
{
    if (count > 1 && otherList.count > 1)
    {
        int sum = otherList.first->getData() + 
                otherList.first->getNext()->getData(); // note the + placement
        Node* current = first;
        int loopCount = 1;
        while (loopCount < count)
        {
            current = current->getNext();
            ++loopCount;
        }
        current->setNext(new Node(sum, nullptr));
        ++count;
    }
}

// 81. Given an empty calling object, copy one or more elements of the array into the calling object.
void AnyList::arrayToEmptyCalling(const int a[], int numOfElements)
{
    for (int i = 0; i < numOfElements; ++i)
    {
        first = new Node(a[i], first);
    }
    count = numOfElements;
}




void AnyList::print() const
{
    if (first == nullptr) 
        cerr << "List is empty.";  
    else
    {
        Node *current = first;
        while (current != nullptr)
        {                         
            cout << current->getData() << " "; 
            current = current->getNext();
        }
    }
    cout << "\nCount: " << count << endl;
}

// This function does not delete the 
// list object; it ONLY deletes the nodes.
void AnyList::clearList()
{ 
    Node  *temp = first; 
    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }
    count = 0;
}

AnyList::~AnyList()
{
	clearList();
}



