#include "Pair.h"

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const Pair<T>& p)
{
	out << "(" << p.first << ", " << p.second << ")";
	return out;
}

template<typename T>
Pair<T>::Pair(const T& firstValue, const T& secondValue)
{
    first = firstValue;
    second = secondValue;
}

template<typename T>
void Pair<T>::setFirst(const T& newValue)
{
    first = newValue;
}

template<typename T>
void Pair<T>::setSecond(const T& newValue)
{
    second = newValue;
}

template<typename T>
T Pair<T>::getFirst( ) const
{
    return first;
}

template<typename T>
T Pair<T>::getSecond( ) const
{
    return second;
}

template<typename T>
Pair<T> Pair<T>::operator+(const Pair<T>& otherPair) const
{
    Pair<T> temp(first + otherPair.first, second + otherPair.second);
    return temp;
}


