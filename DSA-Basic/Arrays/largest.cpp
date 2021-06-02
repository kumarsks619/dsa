#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
int getLargest(int arr[], int size)
{
    int largestIndex = 0; // because there always will be a largest value in an array.
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[largestIndex])
            largestIndex = i;
    }
    return largestIndex;
}

int main()
{
    int size = 5;
    int arr[size] = {11, 7, 10, 19, 17};
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << "Greatest number is: " << arr[getLargest(arr, size)];

    return 0;
}