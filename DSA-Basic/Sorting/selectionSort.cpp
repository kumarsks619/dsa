#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    int minIndex;
    for (int i = 0; i < n-1; i++) {
        minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
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
// Does limited memory writes i.e. only (n-1) writes.
// Time Complexity: Theta(n^2) --FIXED
// Simple Algorithm