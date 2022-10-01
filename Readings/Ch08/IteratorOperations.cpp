#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 10, 11, 12, 13, 14, 15 };

	cout << "Vector is: " << endl;
	vector<int>::const_iterator iter = v.begin();	
	vector<int>::const_iterator iterEnd = v.end();
	while (iter != iterEnd)
	{
		cout << *iter << " ";
		++iter;
	}
	cout << endl;

	iter = v.begin();
	cout << "\niter = v.begin() => " << *iter << endl;		
	++iter;
	cout << "++iter => " << *iter << endl;					
	--iter;
	cout << "--iter => " << *iter << endl;					
	++iter;
	cout << "++iter => " << *iter << endl;					
	cout << "iter[2] => " << iter[2] << endl;				
	cout << "*iter => " << *iter << endl;				
	cout << "*(iter + 2) => " << *(iter + 2) << endl;		
	cout << "*iter => " << *iter << endl;	
	cout << endl;

	vector<int>::const_iterator firstIter = v.begin();
	vector<int>::iterator secondIter = v.begin() + 1;
	cout << "firstIter = v.begin() => " << *firstIter << endl;
	cout << "*secondIter = v.begin() + 1 => " << *secondIter << endl;
	if (secondIter == firstIter)
		cout << "secondIter == firstIter? => TRUE" << endl;
	else
		cout << "secondIter == firstIter? => FALSE" << endl;

	cout << "\nChange value of secondIter, BUT do not change position" << endl;
	*secondIter = 10;
	cout << "Vector is now:" << endl;
	for (iter = v.begin(); iter != iterEnd; ++iter)
		cout << *iter << " ";
	cout << endl;
	cout << "*firstIter => " << *firstIter << endl;
	cout << "*secondIter => " << *secondIter << endl;
	if (secondIter == firstIter)
		cout << "secondIter == firstIter? => TRUE" << endl;
	else
		cout << "secondIter == firstIter? => FALSE" << endl;
	
	cout << "\nMove both iterators to index 3 and compare again" << endl;
	firstIter += 3;
	secondIter += 2;
	cout << "*firstIter => " << *firstIter << endl;
	cout << "*secondIter => " << *secondIter << endl;
	if (secondIter == firstIter)
		cout << "secondIter == firstIter? => TRUE" << endl;
	else
		cout << "secondIter == firstIter? => FALSE" << endl;

	cout << endl;

	cout << endl;
	system("Pause");
	return 0;
}