#include <bits/stdc++.h>
using namespace std;

int haoresPartition(int arr[], int l, int u, int p) {
    swap(arr[l], arr[p]);       // moving the pivot element to first position to make the algorithm work
    int pivot = arr[l];         // storing the pivot element which is now at the first position
    int i = l-1, j = u+1;       // initializing the extreme boundaries
    
    while(true) {                       // running the loop till the return call has made
        do {
            i++;                        // moving the left side boundary ahead
        } while (arr[i] < pivot);       // stop the loop and preserve the index value(i.e. 'i') for swapping
        do {
            j--;                        // moving the right side boundary backward
        } while (arr[j] > pivot);       // stop the loop and preserve the index value(i.e. 'j') for swapping
        if (i >= j)                     // checking if the left and right side boundaries haven't crossed each other yet
            return j;                   // if crossed then the parition has completed and return the index of the final common boundary
        swap(arr[i], arr[j]);           // swap the elements at preserved 'i' and 'j' index values
    }
}


int main() {
    int vals[] = { 5, 1, 9, 4, 0 };
    int size = sizeof(vals) / sizeof(vals[0]);

    int boundaryIndex = haoresPartition(vals, 0, size-1, 3);
    for (int i = 0; i < size; i++)
        cout << vals[i] <<  " ";

    cout << endl << "Boundary Index of the partition: " << boundaryIndex;

    return 0;
}

// What does Hoare's Partition Function do?
// It moves all the elements smaller than the provided pivot element to left and all the elements greater than pivot element to right
// But it does not necessarily moves the pivot element to its correct position.
// Works faster than Lomuto Method.
// This function does NOT sort the array.
// UNSTABLE Algorithm - the order of occurence of equal elements may change.
// This function is used in QUICK SORT ALGORITHM [UTILITY FUNCTION]
// This function transverse the main array only ONCE. [Time Complexity: Theta(n)]
// No Auxiliary Array needed. [IN-PLACE]