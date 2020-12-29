#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
int getSecondLargest(int arr[], int size) {
    int largestIndex = 0, secondLargestIndex = -1;  // because second largest may NOT be present every time.
    for(int i = 0; i < size; i++) {
        if(arr[i] > arr[largestIndex]) {
            secondLargestIndex = largestIndex;
            largestIndex = i;
        }else if(arr[i] != arr[largestIndex]) {
            if(secondLargestIndex == -1 || arr[i] > arr[secondLargestIndex])
                secondLargestIndex = i;
        }
    }
    return secondLargestIndex;
}

int main() {
    int size = 5;
    int arr[size] = { 11, 7, 10, 17, 19};
    cout << "Array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    if(getSecondLargest(arr, size) == -1)
        cout << endl << "There is NO second largest value in the array!!!";
    else
        cout << endl << "Greatest number is: " << arr[getSecondLargest(arr, size)];

    return 0;
}