#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
#include <vector>
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
    bool function1(const std::vector<int>&);

	~DArray( ); 

private:
    int *a;
    int capacity;
    int numOfElements;
};

#endif