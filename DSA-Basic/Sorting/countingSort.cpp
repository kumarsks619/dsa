#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n, int k) {
    int count[k];                   // array to keep the count of occurences of every elememnt of the MAIn array
    for (int i = 0; i < k; i++)     // transversing the COUNT array
        count[i] = 0;               // initializing the whole count array with zero
        
    for (int i = 0; i < n; i++)     // transversing the MAIN array
        count[arr[i]]++;            // counting the occureneces of each element
    
    for (int i = 1; i < k; i++)                 // transversing the COUNT array starting form index 1
        count[i] = count[i-1] + count[i];       // converting the count array to CUMMULATIVE COUNT array

    int output[n];                              // array to build the output (SORTED) array
    for (int i = n-1; i >= 0; i--) {            // transversing the MAIN array backward to keep the STABILITY
        output[count[arr[i]]-1] = arr[i];       // Building the OUTPUT array:  putting the element of the MAIN array based on the position 
        // provvided by the CUMMULATIVE COUNT array in the OUTPUT array. 
        count[arr[i]]--;                        // decrementing the position value of that particluar element that has been already placed
        // in the OUTPUT array at its correct position so as to provide the correct position for the same element if it apperas again in the
        // MAIN array.
    }
    for (int i = 0; i < n; i++)     // tranversing the OUTPUT array
        arr[i] = output[i];         // copying the SORTED elements back to the MAIN array
}


int main() {
    int vals[] = { 6, 1, 4, 3, 0 };
    int size = sizeof(vals) / sizeof(vals[0]);
    int range = *max_element(vals, vals + size);

    countingSort(vals, size, range+1);
    for (int i = 0; i < size; i++)
        cout << vals[i] <<  " ";

    return 0;
}

// This algorithm works good only when tha range of elements is NOT very large. (for above case, elements >= 0)
// Working principle: keeps the count of occurences of elements in a separate array (associated with indexes) and then put the elements
// that many times in another array in sorted form and then copies the sorted array back to main array. [NAIVE Implementation]
// Counting Sort: it is NOT a COMPARISON based algorithm (no comparison is done between array elements anywhere in this algorithm)
// Time Complexity: Theta(n+k)
// Auxiliary Space: Theta(n+k) - count[k] and output[n]
// STABLE Algorithm: preserves the order of occurences of equal elements in the sorted array.
// Counting Sort is used in Radix Sort Algorithm as an utility function.
