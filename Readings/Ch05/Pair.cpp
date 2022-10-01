#include "Pair.h"
using namespace std;

/*
Note on friend functions:
1) They cannot be constants because they are non-member functions.
2) No need to use get functions to retrieve the value of the member
variables of the class, because they have direct access to them.
*/
ostream& operator<<(ostream& out, const Pair& pair)
{
	// NOTE: A friend function can access private member variables 
	// of the class. No need to call an accessor function.
	out << "(" << pair.first << ", " << pair.second << ")";
	return out;
}

Pair operator+(const Pair& leftPair, const Pair& rightPair)
{
	// Need to construct a temporary object.
	Pair tempPair ((leftPair.first + rightPair.first),
	(leftPair.second + rightPair.second));
	return tempPair;
}

Pair::Pair(int firstValue, int secondValue)
{
    first = firstValue;
    second = secondValue;
}

void Pair::setFirst(int newValue)
{
    first = newValue;
}

void Pair::setSecond(int newValue)
{
    second = newValue;
}

int Pair::getFirst() const
{
	return first;
}

int Pair::getSecond( ) const
{
    return second;
}

Pair Pair::operator*(const Pair& p) const
{
	// Need to construct a temporary object.
	Pair temp(first * p.first, second * p.second);
	return temp;
}

bool Pair::operator==(const Pair& p) const
{
	return (first == p.first && second == p.second);
}

Pair& Pair::operator++()
{
	++first;
	++second;
	return *this;  //return reference to incremented object
}

Pair Pair::operator++(int) //no need to write a parameter name
{
	Pair temp = *this; //hold current state of object
	++first;
	++second;
	return temp; //return unincremented, saved, temporary object
}

