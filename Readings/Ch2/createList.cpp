#include "DoublyList.h"
#include "DoublyList.cpp"

#include <iostream>
using namespace std;

void DoublyList::createList()
{
    first = last = new Node(1, nullptr, nullptr);
	++count;

    last = new Node(2, last, nullptr);
	first->setNext(last);
	++count;

    first->setNext(new Node(7, first, last));
	last->setPrev(first->getNext());
	++count;

    last = last->getPrev();
	delete last->getNext();
	last->setNext(nullptr);
	--count;

    first = new Node(4, nullptr, first);
	first->getNext()->setPrev(first);
	++count;

    delete first->getNext();
	first->setNext(last);
	last->setPrev(first);
	--count;

    first->setPrev(last);
	first->setNext(nullptr);
	last->setNext(first);
	last->setPrev(nullptr);
	first = last;
	last = last->getNext();

    last->setPrev(nullptr);
	delete first;
	first = last;
	--count;
}

int main()
{
	DoublyList aList;
	aList.createList();
	aList.printForward();
	return 0;
}