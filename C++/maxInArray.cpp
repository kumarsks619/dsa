#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {10, 60, 1, 81, 11, 65, 7};

    int size = *(&arr + 1) - arr;   // hack to find size of array using pointers.

    cout << *max_element(arr, arr + size) << endl;  // direct way to find max val. Can also be used with vectors.

    vector<int> vec1{10, 60, 1, 81, 11, 65, 7};
    cout << *max_element(vec1.begin(), vec1.end()) << endl;

    cout << "arr = " << arr << endl;    // gives address to first element
    cout << "&arr = " << &arr << endl;  // gives address to whole array (basically address of first element).
}