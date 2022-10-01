/*
The Big Three
*/
#include "DArray.h"
#include "DArray.cpp"
#include <iostream>

using namespace std;

int main( )
{
    DArray myArray(20);
    for (int i = 10; i < 16; ++i)
        myArray.addElement(i);
    int numOfElements = myArray.getNumOfElements();
    cout << myArray << "\n";

    //Modify one element
    myArray[2] = 1000;
    cout << myArray << "\n";
    cout << "\n";
    system("Pause");
    return 0;
}