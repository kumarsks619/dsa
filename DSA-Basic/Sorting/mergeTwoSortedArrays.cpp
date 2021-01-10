#include <bits/stdc++.h>
using namespace std;

// function returning the resultant array(basically the address of the first element) after merging two ALREADY SORTED arrays
int* mergeSortedArray(int arr1[], int arr2[], int m, int n, int arr[]) {
    int i = 0,  j = 0,  k = 0;
    // this while loop will terminate only when one of the sorted arrays (arr1 or arr2) is over
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++]; 
    }
    // Now both the while loops below are to print the left out elements in one of the arrays
    while (i < m)
        arr[k++] = arr1[i++];
    
    while (j < n)
        arr[k++] = arr2[j++];

    return arr;
}


int main() {
    int vals1[] = { 0, 5, 7, 9, 20 };               // SORTED array 1
    int size1 = sizeof(vals1) / sizeof(vals1[0]);

    int vals2[] = { 4, 7, 20, 50, 55, 69, 99 };     // SORTED array 2
    int size2 = sizeof(vals2) / sizeof(vals2[0]);

    int vals[size1+size2];                          // array to store the merged array
    mergeSortedArray(vals1, vals2, size1, size2, vals);
    for (int  i = 0; i < size1+size2; i++)
        cout << vals[i] << " "; 

    return 0;
}

// the working of this mergeTwoSortedArray() function is the same as the merge() function used in Merge Sorte Algorithm.