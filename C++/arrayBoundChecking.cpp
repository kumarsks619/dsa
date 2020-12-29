#include <bits/stdc++.h>
using namespace std;

int main() {
    // int arr[3] = {5, 6, 7, 8};           while initializing c++ checks for bounds. 
    int arr[3] = {5, 6, 7};

    cout << arr[10];     // but while accessing array elements, c++ does not check for bound checking, 
    // this will give some random value or segmentation error at runtime.

    return 0;
}