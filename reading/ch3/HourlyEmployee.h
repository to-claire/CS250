/*
  Interface of the class HourlyEmployee.
  This class derives from the Employee class.
  For simplicity, we will have only one member variable, 
  an hourly rate of type double.
*/

#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

// Must include the base class.
#include "Employee.h"

/*
  No need to include iostream or string,
  because they are already included in the 
  base class.

  When defining the class, we declare that 
  the class HourlyEmployee is the derived class
  of the class Employee by adding a colon and adding
  "public Employee." 
  Recall that in C++ we need to explicitly declare
  what is public, otherwise it is assumed that it is
  private.
*/
class HourlyEmployee : public Employee 
{
public:
	/* 
	  We need to declare the constructor for the derived class.
	  The parent constructor will create the object
	  using its own member variables, and then
	  the derived constructor will add the variables 
	  of this class.
	*/
	HourlyEmployee( );

	/*
	  The next constructor will define all member variables with
	  given values passed by the parameters. Therefore, we will 
	  need to pass values for both the hourly rate and the social
	  security number.
	*/
	HourlyEmployee(const std::string& newSSN, double newRate);

	// These are new functions.
	void setRate(double newRate);
	double getRate( ) const;

	// We redefine the function print.
	void print() const;

	~HourlyEmployee();

private:
	//This is a new variable.
	double hourlyRate; 
};

#endif 

