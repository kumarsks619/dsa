#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n, int exp) {  // exp is NOT k (range) as range is always going to be 10 here
    int count[10], output[n];                   // count[10] array keeps the count of 0-9 numbers always (based on indexes) [k = 10]
    for (int i = 0; i < 10; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;   // (arr[i] / exp) % 10 is used to extract a digit (ones place, tens place, so on) based on exp provided
    for (int i = 1; i < 10; i++)
        count[i] = count[i-1] + count[i];
    for (int i = n-1; i >= 0;  i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixSort(int arr[], int n) {
    // PART 1: finding the maximum element in the array to get the highest number of digits in a number (element)
    int max = arr[0];               
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    // PART 2: sorting the elements based on its digits place by place (starting from ones place)
    for (int exp = 1; max/exp > 0; exp *= 10)       // running the loop for 'd' (highest number of digits) times 
        countingSort(arr, n, exp);                  // using counting sort to sort the elements in range of [0,9] , i.e. digits based.      
}


int main() {
    int vals[] = { 653, 10, 455, 312, 7 };
    int size = sizeof(vals) / sizeof(vals[0]);


    radixSort(vals, size);
    for (int i = 0; i < size; i++)
        cout << vals[i] <<  " ";

    return 0;
}


// Working principle: sort elements based on its digits place by place starting for ones place and after sorting the elements based on all
// the places available (based on the max element) using countingSort() and finally we get a sorted array.
// UTILITY Function: countingSort()
// Radix Sort is also NOT a COMPARISON based algorithm.
// Time Complexity: Theta(d*(n+b)) ~~ Theta(n)  [b = 10, d = highest no. of digits present]
// Radix Sort works good for even larger ranges of values UNLIKE countingSort().
// Radix Sort can do trade off between SPACE and TIME by increasing or decreasing 'b'
