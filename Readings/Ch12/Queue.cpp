/*
OUTPUT:
123
2 3 4 
*/

#include <iostream>
#include <string>

#include <queue>

using namespace std;

int main()
{
    // Create a queue of integers
    queue<int> myQueue;
    
    // Push 1, 2 and 3 into the queue
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    
    /*
        At this point, the front of the queue stores 1,
        while the rear of the queue stores 3.    
        If we want to access any element in between, 
        we will need to remove each element at the front.
    */
    
    // Retrieve and print the front element of the queue.
    cout << myQueue.front();

    // Remove the front element of the queue.
    myQueue.pop();
    
    // Retrieve and print the front and rear elements of the queue.
    cout << myQueue.front();
    cout << myQueue.back();
    cout << endl;
    
    // Insert an element into the queue.
    myQueue.push(4);

    /*
        Now the contains 2, 3 and 4, where 2 is at the front of 
        the queue, and 4 is at the rear of the queue.
        If we want to print all the items in the queue, 
        we will need to remove each one of them.
    */
    while (!myQueue.empty())
    {
        cout << myQueue.front() << " ";
        // Function front retrieves but does not remove.
        
        // We need to call function pop to remove the
        // element at the front of the queue.
         myQueue.pop();
    }

    cout << endl;
    return 0;
}
