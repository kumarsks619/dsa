#include <bits/stdc++.h>
using namespace std;

class ArraySizeZero {};
class ArraySizeNegative {};

int avgArray(int arr[], int n) {
    if(n == 0) {
        throw ArraySizeZero();  // throwing an user-defined data type exection.
    }
    if( n < 0) {
        throw ArraySizeNegative();  // throwing an user-defined data type exection.
    }
    
    return accumulate(arr, arr + n, 0) / n;
}


int main() {
    cout << "Enter array size: ";
    int size;
    cin >> size;
    
    int *arr = new int(size);
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    try {
        int avg = avgArray(arr, size);
        cout << "Average = " << avg << endl;      
    }catch(ArraySizeZero err) {
        cout << "Array size can't be zero !!!" << endl;
    }catch(ArraySizeNegative err) {
        cout << "Array size can't be negative !!!" << endl;
    } 

    delete[] arr;       // deallocating dynamically allocated memory. (Safe Practice)
    cout << "Program excecuted successfully !";

    return 0;
}

// It is a good practice to throw user-defined data-types as execptions.

// Watch GFG C++ 25 : for pre-defined exception classes and their inhertiance.