#include <bits/stdc++.h>
using namespace std;

// Bubble Sort Function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {    // loop to do the required number of passes to achive the sorted array 
        bool swapped = false;        // this variable is used to optimize the Bubble Sort function at its best
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {        // comparing adjacent elements
                swap(arr[j], arr[j+1]);     // swapping adjacent elements accordingly
                swapped = true;
            }
        }
        if (!swapped)           // if no swapping happend in a complete transversal of the array
            break;              // then break out of the loop as array is already sorted
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
// Algorithm: Compares adjacent array elements and swap them accordingly by transversing through the whole array.
// After each pass, the largest (or smallest) element of the remaining elements reaches inside the sorted array part at its correct position.
// Works as: [UNSORTED, SORTED]
// Time Complexity: O(n^2)
// Too many memory writes
// Simple Algorithm
