#include <bits/stdc++.h>
using namespace std;

int main() {
    int *ptr1;
    char *ptr2;
    string *ptr3;

    // All the couts will give same value which varries with machine to machine.
    // Because ultimately each ptr is storing an address value irrespective of the data type.
    cout << sizeof ptr1 << endl;    // same as: sizeof(ptr1)
    cout << sizeof(ptr2) << endl;
    cout << sizeof(ptr3) << endl;

    cout << endl;

    // Following couts will give different values depending upon the data type.    
    cout << sizeof(*ptr1) << endl;
    cout << sizeof(*ptr2) << endl;
    cout << sizeof(*ptr3) << endl;

    cout << endl;

    // in case of arrays
    int arr[] = {10, 50, 70, 60};
    int *ptr = arr;
    cout << sizeof(arr) << endl;  //this will give size of whole array although arr stores the address of 1st element.
    cout << sizeof(ptr) << endl;    // this will give the address same as above pointers.

    return 0;
}

