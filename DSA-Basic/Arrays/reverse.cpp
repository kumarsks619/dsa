#include <bits/stdc++.h>
using namespace std;

//Time Complexity: Theta(n/2)
void reverse(int arr[], int size)
{
    int frontIndex = 0, rearIndex = size - 1;
    while (frontIndex < rearIndex)
    {
        swap(arr[frontIndex], arr[rearIndex]);
        frontIndex++;
        rearIndex--;
    }
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

    reverse(arr, size);

    cout << endl
         << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}