#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
int searchUnsorted(int arr[], int size, int query) {
    // sizeof() operator can't be used here to get the size of array as only array's ptr(arr) is passed.
    // so we need to take it as a function parameter.
    for(int i = 0; i < size; i++) {
        if(arr[i] == query) {
           return i;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {21, 4, 23, 5, 7, 19, 55, 73, 46, 83};
    
    cout << "Array: ";
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << "  ";
    }
    
    cout << "\nEnter a value to be searched: ";
    int val;
    cin >> val;
    
    int result = searchUnsorted(arr, 10, val);
    cout << val << " is found at index: " << result << " and position: " << (result + 1);

    return 0;
}