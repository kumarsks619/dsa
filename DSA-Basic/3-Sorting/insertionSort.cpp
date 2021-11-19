#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {                     // starts from 2nd array element
        int key = arr[i]; // key takes the element to be put at correct place one by one
        int j = i - 1;
        // loop to shift the elements one position ahead to create space for the correct element ( i.e. stored in key) to be inserted
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // shifting elements one position ahead
            j--;
        }
        if (arr[j + 1] != key) // just to optimize the algo by escaping overwrites
            arr[j + 1] = key;  // finally inserting the correct element in place inside the sorted part of the array
    }
}

int main()
{
    int vals[] = {5, 1, 9, 3, 0};
    int size = sizeof(vals) / sizeof(vals[0]);

    insertionSort(vals, size);
    for (int i = 0; i < size; i++)
        cout << vals[i] << " ";

    return 0;
}

// Insertion Sort is a "STABLE algorithm" - the order of occurrence of equal values remain preserved
// Algorithm: Traverse through the array from 2nd element and puts the element in the sorted part of the array at its correct place one by one.
// Works as: [SORTED, UNSORTED]
// Simple Algorithm
// Works BEST (among simple sorting algorithms) in case of small arrays.
// Time Complexity: O(n^2)
// Time Complexity in best case (fully sorted array): Theta(n-1)