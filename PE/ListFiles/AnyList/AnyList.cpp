#include "AnyList.h"

using namespace std;

void AnyList::clearList()
{ 	
	Node* temp = first;

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



