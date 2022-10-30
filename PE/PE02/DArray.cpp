#include "DArray.h"

using namespace std;

ostream& operator<<(ostream& out, const DArray& outArray)
{
	for (int i = 0; i < outArray.numOfElements; ++i)
		out << outArray.a[i] << " ";
	return out;
}

DArray::DArray( )
{
    capacity = CAP;
	a = new int[capacity];
	numOfElements = 0;
}

DArray::DArray(int newCapacity) 
{
	capacity = newCapacity;
    a = new int[capacity];
	numOfElements = 0;  
}

void DArray::addElement(int element)
{
    if (numOfElements >= capacity)
    {
        cerr << "Attempt to exceed capacity in DArray.\n";
        exit(0); 
    }
    a[numOfElements] = element;
    ++numOfElements;
}

int DArray::getNumOfElements() const
{
	return numOfElements;
}

int& DArray::operator[](int idx)
{
	//Assume array is non-empty
	return a[idx];
}

DArray::~DArray( )
{
    delete [] a; //delete the array
	a = nullptr;
}