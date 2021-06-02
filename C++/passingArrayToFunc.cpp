#include <bits/stdc++.h>
using namespace std;

void printArray(int *ptr, int n)
{ // same as: void printArray(int ptr[], int n)
    for (int i = 0; i < n; i++)
    {
        cout << ptr[i] << " "; // ptr[i] is converted to *(ptr + i) by the complier.
    }
}

int main()
{
    int arr[] = {10, 23, 50, 85, 42};
    printArray(arr, 5); // same as: printArray(&arr[0], 5);

    cout << endl
         << arr[2]; // arr[2] is converted to *(arr + 2) by the complier.

    return 0;
}

// Arrays are always passed as the address of the first element and received in a ptr inside the function.
// Array name alone gives the address of the first element. (arr = &arr[0])

// arr[i] = *(arr + i) thus pointer can be used to access array elements as ptr[i] given that ptr is the
// address of the first element of the array.