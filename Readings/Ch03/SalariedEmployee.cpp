// Implementation of the class SalariedEmployee.

#include "SalariedEmployee.h"

using namespace std;

SalariedEmployee::SalariedEmployee( ) 
{
	/*
	  We only need to set up the member variable 
	  for this class, because the base class constructor
	  will be called automatically and it will do the 
	  rest.
	*/
	salary = 0.0;
	/*
	  Remember to write your code in a readable way by
	  using a zero before and after the decimal point.
	*/
}

/*
  Pay careful attention to the syntax of the overloaded 
  constructor. The first portion of the header is declaring
  both parameters, but it is followed by a call to the parent's
  constructor. The format is: a colon, the name
  of the base class and, in parenthesis, the value of the member
  variable that the parent's constructor will need.
*/
SalariedEmployee::SalariedEmployee(const string& newSSN,
             double newWeeklyPay) :Employee(newSSN)
{
	salary = newWeeklyPay;
}

double SalariedEmployee::getSalary( ) const 
{
	return salary;
}

void SalariedEmployee::setSalary(double newSalary)
{
	salary = newSalary;
}

void SalariedEmployee::print() const
{
	/*
	  An object of this class will call its own function print,
	  not the parent's function print.

	  How can we print the parent's member variable? We cannot
	  access the parent's private	member variable, because it is
	  private. We have two choices:
	  1) Calls the parent's print function.
	  2) Call the parent's accessor function.

	  Which one should you choose?
	  If the parent's print function prints in an elaborate format,
	  then it is better to simply let the parent's print function
	  complete the job.
	  If we are only printing the value, then the parent's accessor
	  function will do.
	*/
	
	// Printing the output using the parent's accessor function.
	cout << "Print using accessor function...\n";
	cout << "SSN: " << getSSN() << endl;

	cout << endl;

	/*
	  Printing the output using the parent's print function.
	  We will need to specify that we are calling the Employee 
	  print function by adding the class qualifier and the scope
	  resolution operator, otherwise it will be a recursive call.
	*/
	cout << "Print using parent class print function...\n";
	Employee::print();

	cout << "Salary: $" << salary << endl;
}

SalariedEmployee::~SalariedEmployee() {}