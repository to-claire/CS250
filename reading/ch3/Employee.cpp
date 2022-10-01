// Implementation of class Employee.

#include "Employee.h"
using namespace std;

Employee::Employee( )
{
	ssn = "No data yet.";
}

Employee::Employee(const string& newSSN) 
{			
	ssn = newSSN;
}

string Employee::getSSN( ) const 
{
	return ssn;
}

void Employee::setSSN(const string& newSSN)
{
	ssn = newSSN;
}

void Employee::print() const
{
	cout << "SSN: " << ssn << endl;
}

Employee::~Employee(){}