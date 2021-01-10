#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {             // loop to take care of all the positions
        int minIndex = i;                       // to keep the index of the smallest(or largest) element
        for (int j = i+1; j < n; j++) {         // loop starts after the sorted array to find the smallest(or largest) element index
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // swapping the element present at the found index with its correct position inside the sorted array
        swap(arr[i], arr[minIndex]);            // swapping happens only (n-1) times [FIXED]
    }
}

int main() {
    int vals[] = { 5, 1, 9, 3, 0 };
    int size = sizeof(vals) / sizeof(vals[0]);

    selectionSort(vals, size);
    for (int i = 0; i < size; i++)
        cout << vals[i] <<  " ";

    return 0;
}

// Selection sort is an "UNSTABLE algorithm" - the order of occurence of equal values may change.
// Algorithm: Transverse through the whole array and finds the smallest(or largest) element and swaps it with its correct position.
// Works as: [SORTED, UNSORTED]
// Does limited memory writes i.e. only (n-1) writes.
// Time Complexity: Theta(n^2) --FIXED
// Simple Algorithm