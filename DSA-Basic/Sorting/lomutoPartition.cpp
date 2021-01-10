#include <bits/stdc++.h>
using namespace std;

int lomutoPartition(int arr[], int l, int u, int p) {
    swap(arr[p], arr[u]);       // moving the provided pivot element to last to make the algorithm work
    int pivot = arr[u];         // storing the pivot element which is now at the last position in the array
    int i = l-1;                // boundary index of the smaller elements window
    for (int j = l; j < u; j++) {       // Transversing the array only ONCE
        if (arr[j] < pivot) {           // Take action only when the element is smaller than the pivot element
            i++;                        // increasing the smaller elements window size
            swap(arr[j], arr[i]);       // moving the smaller element inside the window by swapping it with larger element
        }
    }
    swap(arr[i+1], arr[u]);             // Finally moving the pivot element to its correct position(i.e. after the boundary of the window)
    return (i+1);                       // returning the final index of the pivot element
}

int main() {
    int vals[] = { 5, 1, 9, 4, 0 };
    int size = sizeof(vals) / sizeof(vals[0]);

    int correctPivotIndex = lomutoPartition(vals, 0, size-1, 3);
    for (int i = 0; i < size; i++)
        cout << vals[i] <<  " ";

    cout << endl << "Correct Pivot Index: " << correctPivotIndex;

    return 0;
}

// What does the Lomuto Partition Function do?
// It simply moves all the elements less than the provided pivot element before it and all the greater element than the pivot element
// after it and then return the correct index for the pivot element after moving the elements accordingly.
// This function does NOT sort the array.
// This function transverse the main array only ONCE. [Time Complexity: Theta(n)]
// This function is used in QUICK SORT ALGORITHM [UTILITY FUNCTION]
// UNSTABLE Algorithm - the order of occurence of equal elements may change.
// No Auxiliary Array needed. [IN-PLACE]

// Naive Parition Method - Stable but requires a Theta(n) Auxiliary Space