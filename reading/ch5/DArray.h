#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
const int CAP = 50;

class DArray
{
	friend std::ostream& operator<<(std::ostream& out, const DArray&);

public:
    DArray( );
    DArray(int);

    void addElement(int);
	int getNumOfElements() const;

	int& operator[](int idx); //overloaded subscript operator

	~DArray( ); 

private:
    int *a;
    int capacity;
    int numOfElements;
};

#endif