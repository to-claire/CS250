#include "DoublyList.h"

using namespace std;

// Consider all options: list is empty/non-empty, 1 node, 2 nodes, 3 nodes, several nodes
// Assume NO duplicates, unless otherwise stated
// Restrictions: can use only one loop, cannot use any pointers, etc
// To swap nodes, rearrange pointers

// Delete 4th node 
void DoublyList::deleteFourth()
{
    if (count > 3)
    {
        if (count == 4)
        {
            last = last->getPrev();
            delete last->getNext();
            last->setNext(nullptr);
        }
        else
        {
            Node* current = first;
            int loopCount = 0;
            while (++loopCount < 4)
            {
                current = current->getNext();
            }
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
            delete current;
            current = nullptr;
        }
        --count;
    }
}


// 1. Insert a new node, storing a given value, to the front of the calling object
void DoublyList::insertBack(int newData)
{
    if (first == nullptr)
    {
        first = last = new Node(newData, nullptr, nullptr);
    }
    else
    {
        last->setNext(new Node(newData, last, nullptr));
        last = last->getNext();
    }
    ++count;
}


void DoublyList::deleteThird()
{
    if (count > 2)
    {
        if (count == 3)
        {
            last = last->getPrev();
            delete last->getNext();
            last->setNext(nullptr);
        }
        else
        {
            Node* current = first->getNext()->getNext();
            // int loopCount = 0;
            // while (loopCount < (count - 3))
            // {
            //     current = current->getNext();
            //     ++loopCount;
            // }
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
            delete current;
            current = nullptr;

            // first->getNext()->getNext()->getNext()->
            //     setPrev(first->getNext()->getNext()->getPrev());
            // delete first->getNext()->getNext()->getNext();
            // first->getNext()->getNext()->getPrev()->
            //     setNext(first->getNext()->getNext()->getNext());
            
            
        }
        --count;
    }
}


// 10. Delete the node before-last of the calling object.
void DoublyList::deleteNode()
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
        if (count == 2)
        {
            last->setPrev(nullptr);
            delete first;
            first = last;
        }
        else
        {
            Node* current = last->getPrev();
            current->getPrev()->setNext(last);
            last->setPrev(current->getPrev());
            delete current;
            current = nullptr;
        }
        --count;
    }
}

// 26. Swap the second node with the node before last.
// NOT EFFICIENT
void DoublyList::swapSecondWithBeforeLast()
{
    if (count == 0)
    {
        cerr << "List is empty\n";
    }
    else if (count < 4);
    else if (count == 4)
    {
        // attatch to ends first and last
        first->getNext()->setNext(last);
        last->getPrev()->setPrev(first);

        // connect middle
        first->getNext()->setNext(last->getPrev());
        last->getPrev()->setPrev(first->getNext());
        
        // connect with first and last
        first->setNext(last->getPrev()->getPrev());
        last->setPrev(first->getNext()->getNext()); 
    }
    else
    {
        Node* second = first->getNext();
        Node* beforeLast = last->getPrev();

        beforeLast->setNext(second->getNext());
        beforeLast->getPrev()->setNext(second);

        second->setPrev(beforeLast->getPrev());
        second->getNext()->setPrev(beforeLast);

        beforeLast->setPrev(first);
        first->setNext(beforeLast);

        second->setNext(last);
        last->setPrev(second);
    }
}

// 30. Move the first two nodes (or more) to the end of the calling object. 
void DoublyList::moveToEnd(int nodesToMove)
{
    if (count > nodesToMove)
    {
        for (int i = 0; i < nodesToMove; ++i)
        {
            last->setNext(first);
            first = first->getNext();
            first->setPrev(nullptr);
            
            last->getNext()->setPrev(last);
            last = last->getNext();
            last->setNext(nullptr);
        }
    }
}


// 54. Swap the value of the last node of the calling object with the value of the first node of the parameter object.
void DoublyList::swapLastCallingValueAndFirstParamValue(DoublyList& otherList)
{
    if (count == 0 && otherList.count == 0)
    {
        cerr << "List(s) are empty.\n";
    }
    else if (count == 1 && otherList.count == 1)
    {
        int temp = last->getData();
        last->setData(otherList.first->getData());
        otherList.first->setData(temp);
    }
    else
    {
        last->setData(otherList.first->getData());
        otherList.first->setData(last->getData());
    }
}

// 70. Sum first two nodes of the parameter object to a node end of calling object.
void DoublyList::sumParamToEndCalling(const DoublyList& otherList)
{
    if (count > 1 && otherList.count > 1)
    {
        int sum = otherList.first->getData() + 
            otherList.first->getNext()->getData();
        last = new Node(sum, last, nullptr);
        last->getPrev()->setNext(last);
        ++count;
    }
}





void DoublyList::printForward() const
{
    Node* current = first;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << "\nCount: " << count << endl;
}

void DoublyList::printReverse() const
{
    Node* current = last;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getPrev();
    }
    cout << "\nCount: " << count << endl;
}

void DoublyList::clearList()
{ 	
    Node* temp = first;

    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }

    last = nullptr;		
    count = 0;
}

DoublyList::~DoublyList()
{
    clearList();
}