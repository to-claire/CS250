#ifndef PAIR_H
#define PAIR_H

#include <iostream>

// VSC error: declaration of 'T' shadows template parameter
template<typename T>
class Pair
{
	// NOTE: The friend function declaration needs to be set as a template
	//       because it is not a member of the class Pair.
	template<typename T>	
	friend std::ostream& operator<<(std::ostream&, const Pair<T>&);

public:
	Pair(const T&, const T&);

	void setFirst(const T&);
	void setSecond(const T&);

	T getFirst( ) const;
	T getSecond( ) const;

	Pair<T> operator+(const Pair<T>&) const;

	~Pair() {}

private:
	T first;
	T second;
};

#endif 