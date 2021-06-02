#include <iostream>

using namespace std;

int main()
{
    cout << "Enter number of terms required: ";
    int n;
    cin >> n;

    int x = 0, y = 1, z;

    for (int i = 0; i < n; i++)
    {
        cout << x << endl; // only single cout statement
        z = x + y;
        x = y;
        y = z;
    }
}