#ifndef DARRAY_H
#define DARRAY_H

class DArray
{
public:
    void rotate(int index); 
    void rotateRange(int first, int middle, int last);
private:
    int *a; // pointer to a dynamic array of type int          
    int capacity;      
    int numOfElements; 
};

#endif