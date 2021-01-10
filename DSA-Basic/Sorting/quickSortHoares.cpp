#include <bits/stdc++.h>
using namespace std;

int hoaresPartition(int arr[], int l, int u) {
    // Just to handle the ADVERSE CASE ***********************************************************************************************
    srand(time(0));                                 // seeding rand() function with time() to generate different random nos. each time
    int randomIndex = l + (rand() % (u-l+1));       // generating random no. in range [l, u]
    swap(arr[l], arr[randomIndex]);                 // putting a random no. from the array at the first index to act as the pivot element

    // Main Quick Algorithm starts here ************************************************************************************************
    int pivot = arr[l];     // first element is considered as the pivot element by default and elements are moved around on the its basis
    int i = l-1, j = u+1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

// Quick Sort Function (Utility Function: Hoare's Partition Function)
void quickSortH(int arr[], int l, int u) {
    if (l < u) {
        int p = hoaresPartition(arr, l, u);
        quickSortH(arr, l, p);
        quickSortH(arr, p+1, u);
    }
}

int main() {
    int vals[] = { 5, 1, 9, 4, 0, -5 };
    int size = sizeof(vals) / sizeof(vals[0]);
    
    quickSortH(vals, 0, size-1);
    for (int i = 0; i < size; i++)
        cout << vals[i] <<  " ";

    return 0;
}

// Quick Sort is most used sorting algorithm (prefered over Merge Sort).
// Quick Sort - Divide & Conquer Algorithm
// Time Complexity: O(n^2) - WORST CASE (but for average case: O(nlogn) therefore Quick Sort is prefered)
// Tail Recursive, therefore prefered over other sorting algorithms.
// UTLITY FUNCTIONS - Lomuto Partition or Hoare's Partition or Naive Partition
// Working principle: After every Hoare's Partition Function call it moves smaller and greater elements side by side based on a pivot element.
// Works as: [SMALLER Elements, GREATER Elements]
// Quick Sort - BEST CASE: When the partition function divides the array in two almost equal halves. [Time Complexity: O(nlogn)]
// Quick Sort - WORST CASE: When the partition function divides the array in 1 and (n-1) parts. [Time Complexity: O(n^2)]
// Quick Sort is IN PLACE Algorithm but it requires EXTRA space for its recursive functions call stack.

// ADVERSE CASE - an input format for which the algorithm always falls in the worst case.
// In Quick Sort if the array is already sorted then it will partition as 1 and (n-1) which is the worst case.

// QUICK SORT using HOARE'S PARTITION ALGORITHM is BEST.