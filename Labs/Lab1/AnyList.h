#ifndef ANYLIST_H
#define ANYLIST_H

#include <string>

class Node 
{ 
public: 
    Node() : data(0), ptrToNext(nullptr) {} 
    Node(int theData, Node *newPtrToNext)  
        : data(theData), ptrToNext(newPtrToNext){} 
    Node* getPtrToNext() const { return ptrToNext; } 
    int getData( ) const { return data; } 
    void setData(int theData) { data = theData; } 
    void setPtrToNext(Node *newPtrToNext)  
        { ptrToNext = newPtrToNext; } 
    ~Node(){} 
private: 
    int data;         
    Node *ptrToNext;
}; 

class AnyList 
{ 
public: 
    AnyList() : ptrToFirst(nullptr), count(0) {} 
    int getLastElem() const;
    bool allOdds() const;
    void deleteFirstNode();
    bool compareLists(const AnyList& rhs) const;
private: 
    Node *ptrToFirst;  
    int count;
};

#endif