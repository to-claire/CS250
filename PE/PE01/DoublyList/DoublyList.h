#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>

class Node
{
public:
	Node() : data(0), prev(nullptr), next(nullptr) {}
	Node(int theData, Node* prevLink, Node* nextLink)
		: data(theData), prev(prevLink), next(nextLink) {}
	int getData() const { return data; }
	Node* getPrev() const { return prev; }
	Node* getNext() const { return next; }
	void setData(int theData) { data = theData; }
	void setPrev(Node* prevLink) { prev = prevLink; }
	void setNext(Node* nextLink) { next = nextLink; }
	~Node(){}
private:
	int data;   
	Node* prev;
	Node* next;
};

class DoublyList
{
public:
	DoublyList() : first(nullptr), last(nullptr), count(0) {}

	// member functions
	void insertBack(int newData);
	void printForward() const;
	void printReverse() const;
	void clearList();

	void deleteNode();
	void swapSecondWithBeforeLast();
	void swapLastCallingValueAndFirstParamValue(DoublyList& otherList);
	void sumParamToEndCalling(const DoublyList& otherList);
	void moveToEnd(int nodesToMove);
	void deleteThird();
	void deleteFourth();
	~DoublyList();

private:
	Node *first;		
	Node *last;			
	int count;			
};

#endif