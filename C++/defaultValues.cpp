#include <bits/stdc++.h>
using namespace std;

int Arr[5]; // global

int main()
{
    int arr[5]; // local

    for (int i = 0; i < 5; i++)
    {
        cout << Arr[i] << " " << arr[i] << endl;
    }
    return 0;
}

// global variables are always initialized by zero by the compiler if we left them un initialized.
// local variables can take any garbage values if left un initialized.