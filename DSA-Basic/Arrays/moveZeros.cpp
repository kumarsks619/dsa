#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
void moveZeros(int arr[], int size) {
    int nonZeroCount = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] != 0) {
            swap(arr[nonZeroCount], arr[i]);    // nonZeroCount is same as the index of first zero after nonZero.
            nonZeroCount++;
        }
    }
}

int main() {
    int size = 5;
    int arr[size] = { 11, 0, 0, 7, 0};
    cout << "Array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    moveZeros(arr, size);

    cout << endl << "Array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}