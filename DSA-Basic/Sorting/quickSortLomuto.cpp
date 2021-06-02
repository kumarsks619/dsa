#include <bits/stdc++.h>
using namespace std;

int lomutoPartition(int arr[], int l, int u)
{
    // Just to handle the ADVERSE CASE ***********************************************************************************************
    srand(time(0));                               // seeding rand() function with time() to generate different random nos. each time
    int randomIndex = l + (rand() % (u - l + 1)); // generating random no. in range [l, u]
    swap(arr[u], arr[randomIndex]);               // putting a random no. from the array at the last index to act as the pivot element

    // Main Quick Algorithm starts here ************************************************************************************************
    int pivot = arr[u]; // last element is considered as the pivot by default and it gets sorted at the end of the function call.
    int i = l - 1;
    for (int j = l; j < u; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[u]);
    return (i + 1);
}

// Quick Sort Function (Utility Function: Lomuto Partition Function)
void quickSortL(int arr[], int l, int u)
{
    if (l < u)
    {
        int p = lomutoPartition(arr, l, u); // using Lomuto Partiton Method
        quickSortL(arr, l, p - 1);          // for sorting the left side array of the pivot
        quickSortL(arr, p + 1, u);          // for sorting the right side array of the pivot
    }
}

int main()
{
    int vals[] = {5, 1, 9, 4, 0, -5};
    int size = sizeof(vals) / sizeof(vals[0]);

    quickSortL(vals, 0, size - 1);
    for (int i = 0; i < size; i++)
        cout << vals[i] << " ";

    return 0;
}

// Quick Sort is most used sorting algorithm (preferred over Merge Sort).
// Quick Sort - Divide & Conquer Algorithm
// Time Complexity: O(n^2) - WORST CASE (but for average case: O(NlogN) therefore Quick Sort is preferred)
// Tail Recursive, therefore preferred over other sorting algorithms.
// UTILITY FUNCTIONS - Lomuto Partition or Hoare's Partition or Naive Partition
// Working principle: After every Lomuto Partition Function call it sorts the LAST element of the remaining array.
// Works as: [SMALLER UNSORTED Elements, SORTED, GREATER UNSORTED Elements]
// Quick Sort - BEST CASE: When the partition function divides the array in two almost equal halves. [Time Complexity: O(NlogN)]
// Quick Sort - WORST CASE: When the partition function divides the array in 1 and (n-1) parts. [Time Complexity: O(n^2)]
// Quick Sort is IN PLACE Algorithm but it requires EXTRA space for its recursive functions call stack.

// ADVERSE CASE - an input format for which the algorithm always falls in the worst case.
// In Quick Sort if the array is already sorted then it will partition as 1 and (n-1) which is the worst case.
