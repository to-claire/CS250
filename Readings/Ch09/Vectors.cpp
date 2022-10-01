// Include the header file of the vector class.
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	// An empty vector that will store doubles.
	vector<double> prices;

	// A vector of 10 int values.
	vector<int> boxes(10);

	// Using the subscript operator to access an
	// element in a vector.
	vector<int> scores(3);	// Create a vector of 3 elements.
	scores[0] = 99;			// Set the value of the 1st element.
	scores[1] = 87;			// Set the value of the 2nd element.
	scores[2] = 91;			// Set the value of the 3rd element.
	cout << scores[1] << endl;		// Display the 2nd element.
	cout << scores[2] << endl;		// ERROR! Out of bound access!

	// Creating a vector using an initialization list.
	vector<int> points = { 99, 87, 91 };

	// Printing the vector.
	// If you are using a regular FOR loop, do not let the 
	// function size be called in the header at each iteration.
	// Create a variable instead. Although new compilers will 
	// hold the size value as soon as it is clear that the size 
	// is not changing, not all compilers have this ability.
	// Also, remember that function size does NOT return an int.
	// Therefore, you need to either (1) cast the value or use
	// unsigned_int or size_t.
	int vectorSize = static_cast<int>(points.size());
	for (int i = 0; i < vectorSize; ++i)
		cout << points[i] << " ";

	cout << endl;

	// Using a range-based FOR loop.
	// Using auto with iterator is recommended for readability.
	// Do NOT use auto everywhere though. It is important to keep
	// track of what type YOU assigned, instead of leaving the 
	// choice to the compiler.
	for (const auto& element : points)
		cout << element << " ";

	cout << endl;

	// Let's try a few member functions.
	vector<string> names = { "Jane", "Mary", "Bob", "Jill" };

	// Add an element to the end.
	names.push_back("Sean");
	// Recall that this is not the most efficient way, 
	// but sometimes we cannot predict the size of a vector.

	// Print the first element.
	cout << names.front() << endl;

	// Print other elements using the subscript operator
	// and using function at().
	cout << names[1] << endl;
	cout << names.at(2) << endl;

	// Print the last element.
	cout << names.back() << endl;

	// Delete "Bob"
	names.erase(names.begin() + 2);

	// Function insert will insert to the front.
	names.insert(names.begin(), "Matt");

	// Print the vector.
	for (const auto& name : names)
		cout << name << " ";

	cout << endl;

	// Remove the last element in the vector.
	names.pop_back();

	// Print the vector.
	for (const auto& name : names)
		cout << name << " ";

	cout << endl;
	return 0;
}

