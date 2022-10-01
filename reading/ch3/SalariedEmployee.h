/*
  Interface of the class SalariedEmployee.
  This class derives from the Employee class.
  For simplicity, we will have only one member variable, 
  a salary of type double.
*/

#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

// Must include the base class.
#include "Employee.h"

/*
  No need to include iostream or string,
  because they are already included in the 
  base class.

  When defining the class, we declare that 
  the class SalariedEmployee is the derived class
  of the class Employee by adding a colon and adding
  "public Employee." 
  Recall that in C++ we need to explicitly declare
  what is public, otherwise it is assumed that it is
  private.
*/
class SalariedEmployee : public Employee
{
public:
	/*
	  We need to declare the constructors for the derived class.
	  The default constructor of this class will create
	  the object using its own member variables, and then
	  it will call the parent's default constructor to add
	  the parent's member variables.
	*/
	SalariedEmployee( );

	/*
	  The next constructor will define all member variables with
	  given values passed by the parameters. Therefore, we will 
	  need to pass values for both the salary and the social
	  security number.
	*/
	SalariedEmployee (const std::string& newSSN, double newSalary);

	// These are new functions.
	void setSalary(double newSalary); 
	double getSalary( ) const;

	// We redefine the function print.
	void print() const;

	~SalariedEmployee();

private:
	//This is a new variable.
	double salary;
};

#endif 