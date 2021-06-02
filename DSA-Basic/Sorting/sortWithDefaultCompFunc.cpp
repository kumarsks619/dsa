// sort() function with DEFAULT comparison functions

#include <bits/stdc++.h>
using namespace std;

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void displayVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    // SORTING IN ARRAYS
    int arr[] = {10, 4, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n); // without using the comparison function (default is increasing order)
    displayArray(arr, n);

    sort(arr, arr + n, greater<int>()); // by passing a provided comparison function
    displayArray(arr, n);

    // SORTING IN VECTORS
    vector<int> vec = {2, 7, 6, 3, 5};

    sort(vec.begin(), vec.end());
    displayVector(vec);

    sort(vec.begin(), vec.end(), greater<int>());
    displayVector(vec);

    return 0;
}

// sort() is a STL function provided by c++
// sort(first element address, address beyond last element, comparison function)
// sort() can be used to sort data structures with random access. (example - arrays and vectors)
// Time Complexity of sort(): O(NlogN)