#include <bits/stdc++.h>
using namespace std;


// merge function to merge two sorted array [UTILITY FUNCTION] [Time Complexity: O(n)]
void merge(int arr[], int l, int m, int u) {
    int arrL[m-l+1], arrR[u-m];       // declaring new arrays to copy the sorted parts seprately [AUXILLARY ARRAYS]

    // copying values to left sorted array
    for (int i = 0; i < m-l+1; i++)
        arrL[i] = arr[l+i];                 // copying starts from 'l'
    // copying values to right sorted array
    for (int i = 0; i < u-m; i++)
        arrR[i] = arr[m+i+1];
    
    int i = 0, j = 0, k = l;            // index for the actual array starts from 'l'
    while (i < m-l+1 && j < u-m) {      // merging arrays based on values
        if (arrL[i] <= arrR[j])         // '=' sign here is the reason for mergeSort() algo to be STABLE
            arr[k++] = arrL[i++];
        else
            arr[k++] = arrR[j++];
    }
    // copying the remaning elements of one of the array that is left
    while (i < m-l+1)
        arr[k++] = arrL[i++];
    while (j < u-m)
        arr[k++] = arrR[j++];
}


void mergeSort(int arr[], int l, int u) {
    if (u > l) {                        // checking if the array contains more than one element
        int m = l + (u-l)/2;          // finding the mid-point of the array
        mergeSort(arr, l, m);           // dividing the array in two halves
        mergeSort(arr, m+1, u);          
        merge(arr, l, m, u);            // merging the two sorted arrays in sorted form
    }
}


int main() {
    int vals[] = { 5, 1, 9, 3, 0 };
    int size = sizeof(vals) / sizeof(vals[0]);

    mergeSort(vals, 0, size-1);

    for (int  i = 0; i < size; i++)
        cout << vals[i] << " "; 

    return 0;
}

// Merge Sort - Divide & Conquer Algorithm
// Working priciple: ARRAY CONTAINING ONE ELEMENT IS ALREADY A SORTED ARRAY.
// Works as: [SORTED, SORTED]
// Stable Algorithm - the order of occurence of equal values remain preserved.
// Complex Algorithm
// Time Complexity: Theta(nlogn)
// Merge sort requires auxillary space of O(n) to copy the arrays in merge() function.
// The merge() function takes the whole array but only works between the passed bounds(limits: l & u) thats why we can't ignore 'l' in merge().
