#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <cstddef>

class Node
{
public:
    Node() : data(0), next(nullptr) {}
    Node(int theData, Node *newNext) : 
        data(theData), next(newNext){}
    Node* getNext() const { return next; }
    int getData( ) const { return data; }
    void setData(int theData) { data = theData; }
    void setNext(Node *newNext) { next = newNext; }
    ~Node(){}
private:
    int data;        
    Node *next;    //pointer that points to next node
};

class LinkedQueue
{
public:
    LinkedQueue();
    void clearList();
    ~LinkedQueue();

    void push (int data);
    void pop();
    bool empty() const;
    int back() const;
    int front() const;
    std::size_t size() const;
 
private:
    Node* ptrToFront;    
    Node* ptrToBack;
    int count;
};

#endif