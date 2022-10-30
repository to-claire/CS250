#include "AnyList.h"

using namespace std;

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



