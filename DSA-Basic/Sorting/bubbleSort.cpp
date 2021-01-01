#include <bits/stdc++.h>
using namespace std;

// Bubble Sort Function
void bubbleSort(int arr[], int n) {
    bool swapped;       // this variable is used to optimize the Bubble Sort function at its best
    for (int i = 0; i < n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    int vals[] = { 5, 1, 9, 3, 0 };
    int size = sizeof(vals) / sizeof(vals[0]);

    bubbleSort(vals, size);
    for (int i = 0; i < size; i++)
        cout << vals[i] <<  " ";

    return 0;
}


// Bubble sort is a "STABLE algorithm" - the order of occurence of equal values remain preserved.
// Time Complexity: O(n^2)
// Too many memory writes
// Simple Algorithm
