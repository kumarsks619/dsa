#include <iostream>

using namespace std;

int main()
{
    cout << "Enter size of array: ";
    int size;
    cin >> size;

    //DYNAMIC MEMORY ALLOCATION
    int *ptr = new int[size]; //allocates the required memory and store the first element address in ptr.
    cout << "Address in ptr: " << ptr << endl;

    // int *ptr = new int;      // allocates memory for one integer only.

    cout << "Enter array values: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> ptr[i]; // same as: cin >> *(ptr + i);
    }

    cout << "Values in array are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << endl;
    }

    delete[] ptr; //releasing the dynamically allocated memory. // for deallocating array memory.
    // delete ptr;  // for dellocating an integer memory.

    // Safe practice is to set ptr = NULL after deallocating the memory it is pointing to.
    ptr = NULL; // NULL is macro whose value is basically zero.
    cout << "ptr = " << ptr << endl;

    int *ptr2 = new int(5); // allocating memory with value.
    cout << "New memory with value: " << *ptr2;

    return 0;
}

// Dynamically Allocated memory can be released or deleted by the programmer itself but
// by declaring a variable length array (arr[size]), we have no control over it to delete. It will
// automatically gets released by the computer when the programme ends or the scope of the variable ends.

// 'new' is an OPERATOR which returns the pointer to the newly allocated memory.