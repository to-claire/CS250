/*
OUTPUT:
4 2 1 
*/

#include <iostream>
#include <string>

#include <stack>

using namespace std;

int main()
{
    // Create a stack of integers
    stack<int> myStack;
    
    // Push 1, 2 and 3 into the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    
    /*
        At this point, 1 will be at the bottom 
        of the stack, while 3 will be at the top
        of the stack.
        Remember that we can only access what is
        at the top of the stack. If we want to access
        any element below, we will need to remove each
        element at the top.
    */
    
    /*
    Pop the top element of the stack.
    Make sure to check if the stack is empty, because 
    if it is, then there is nothing to pop and the 
    program will crash.
    */    
    if (!myStack.empty())
    {
        myStack.pop();
    }
        
    /*
        Now the stack contains 1 and 2, where 2 is at 
        the top of the stack.
    */
    
    // Push 4 into the stack.
    myStack.push(4);
    /*
    Now the stack contains 1, 2 and 4 where 4 is at 
    the top of the stack.
    */
    
    /*
    If we want to print all the items in the stack, 
    we will need to remove each one of them. 
    The printed elements will be in reverse order.
    */
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        // Function top retrieves but does not remove.

        // We need to call function pop to remove the
        // element at the top of the stack.
        myStack.pop();
    }

    cout << endl;
    return 0;
}