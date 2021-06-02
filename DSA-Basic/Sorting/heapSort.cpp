#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) // comparing the NODE with its LEFT children
        largest = left;
    if (right < n && arr[right] > arr[largest]) // comparing the NODE with its RIGHT children
        largest = right;
    if (largest != i)
    {                                // checking if the NODE is already greatest among its TWO children
        swap(arr[largest], arr[i]);  // swapping the greater children with its Parent Node
        maxHeapify(arr, n, largest); // recursively calling the maxHeapify() function for the disturbed children but now considering it as NODE
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--) // handling each NODE starting from bottom, one by one
        maxHeapify(arr, n, i);             // for moving the greater element among the NODE and its TWO children to its NODE position
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n); // building a MAX HEAP DATA STRUCTURE (by doing this for the FIRST time, the greatest element moves to TOP [index 0])
    for (int i = n - 1; i >= 1; i--)
    {                          // reducing the size of the array one by one ([UNSORTED, SORTED])
        swap(arr[0], arr[i]);  // swapping the index[0] element (ROOT) with the last element (LEAF), i.e. moving the max element to last
        maxHeapify(arr, i, 0); // re-heapifying the disturbed ROOT Node (because of swapping done in above step) // size is also reduced
    }
}

int main()
{
    int vals[] = {5, 1, 9, 3, 0, -5, 10, 4, -14, 1};
    int size = sizeof(vals) / sizeof(vals[0]);

    heapSort(vals, size);
    for (int i = 0; i < size; i++)
        cout << vals[i] << " ";

    return 0;
}

// Algorithm: Works the same as SELECTION SORT(i.e. moving the max element to last and deacreasing the size of the array, one by one), but
// Heap Sort uses Max Heapify function to find the max element (this is the ONLY difference which reduces its time complexity).
// Works as: [UNSORTED, SORTED]
// Time Complexity: O(NlogN) - in ALL cases
// MAX HEAP DATA STRUCTURE: in pictorial representation of an array in the form of a BINARY TREE (each node has TWO children only)
// then, each NODE must be greater than its TWO children.
