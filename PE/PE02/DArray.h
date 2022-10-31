#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
#include <vector>
#include <list>
#include <set> // +multiset
#include <map> // +multimap
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>

const int CAP = 50;

class DArray
{
	friend std::ostream& operator<<(std::ostream& out, const DArray&);

public:
    DArray( );
    DArray(int);

    void addElement(int);
	int getNumOfElements() const;

	int& operator[](int idx);
    
    // add functions
    // bool function1(const std::vector<int>&);
    bool function2(const std::list<int>& aList, std::set<int>& aSet, int elem);


	~DArray( ); 

private:
    int *a;
    int capacity;
    int numOfElements;
};

#endif