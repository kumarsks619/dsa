#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n) [NOTICE - two nested loops]
void deleteByValue(int arr[], int &size, int &value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            for (int j = i; j < size; j++)
            {
                arr[j] = arr[j + 1];
            }
            size--;
            break;
        }
    }
}

void deleteByPos(int arr[], int &size, int &pos)
{
    if (pos <= size)
    {
        for (int i = (pos - 1); i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

int main()
{
    int size = 8;
    int arr[size] = {14, 2, 17, 11, 10, 77, 19, 7};
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << "Enter element to be deleted: ";
    int element;
    cin >> element;

    deleteByValue(arr, size, element);
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << "Enter position of the element to be deleted: ";
    int pos;
    cin >> pos;

    deleteByPos(arr, size, pos);
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}