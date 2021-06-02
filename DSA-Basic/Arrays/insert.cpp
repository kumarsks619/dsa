#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
int insert(int arr[], int currSize, const int &capacity, const int &newVal, const int &pos)
{
    if (currSize == capacity)
    {
        return -1;
    }
    if (pos >= currSize)
    {
        arr[currSize] = newVal;
    }
    else
    {
        for (int i = currSize; i >= (pos - 1); i--)
        {
            arr[i] = arr[i - 1];
        }
    }
    arr[pos - 1] = newVal;

    return (currSize + 1);
}

int main()
{
    int capacity = 10, currSize = 7;
    int arr[capacity] = {21, 4, 23, 5, 7, 19, 55};
    cout << "Array: ";
    for (int i = 0; i < currSize; i++)
    {
        cout << arr[i] << "  ";
    }

    while (true)
    {
        int newVal, pos;
        cout << "\nEnter position at which value to be inserted: ";
        cin >> pos;
        if (pos == -1)
        {
            break;
        }
        cout << "Enter value to be inserted: ";
        cin >> newVal;

        currSize = insert(arr, currSize, capacity, newVal, pos);

        if (currSize == -1)
        {
            cout << "Array is full!!!";
            break;
        }
        cout << "New Array: ";
        for (int i = 0; i < currSize; i++)
        {
            cout << arr[i] << "  ";
        }
    }

    return 0;
}