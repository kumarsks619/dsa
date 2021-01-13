#include <bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int n, int q) {
    int l = 0, u = n-1;
    while (l <= u) {
        int m = (l + u)/2;
        if (q == arr[m])
            return m;
        else if (q < arr[m])
            u = m-1;
        else
            l = m+1; 
    }
    return -1;
}


int main() {
    int vals[] = { 17, 43, 79, 83, 92, 99, 99 };
    int size = sizeof(vals) / sizeof(vals[0]);
    int query;
    cout << "Enter query value: ";
    cin >> query;

    cout << "Found at index: " << binarySearch(vals, size, query);

    return 0;
}


// Binary Search works only with SORTED arrays.
// Binary Search doesn't prefer recursion method because it is less efficient then normal looping method as it demands extra auxiliary
// space to store the functions call-stack (recursive calls).
// Time Complexity: O(logn) - worst case: element NOT found