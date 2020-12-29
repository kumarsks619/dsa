#include <bits/stdc++.h>
using namespace std;

// Time Complexity: Theta(n)
void leftRotate(int arr[], int size) {
    int firstElement = arr[0];
    for(int i = 1; i < size; i++)
        arr[i - 1] = arr[i];
    arr[size - 1] = firstElement;
}

int main() {
    int size = 5;
    int arr[size] = { 11, 7, 10, 19, 17};
    cout << "Array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    leftRotate(arr, size);
    cout << endl << "Array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    leftRotate(arr, size);
    cout << endl << "Array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}