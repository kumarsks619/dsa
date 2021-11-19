#include <bits/stdc++.h>
using namespace std;

int maxCuts(int l, int a, int b, int c)
{
    if (l == 0)
        return 0;
    if (l < 0)
        return -1;
    int result = max({maxCuts(l - a, a, b, c), maxCuts(l - b, a, b, c), maxCuts(l - c, a, b, c)});
    if (result == -1)
        return -1;
    return (result + 1);
}

int main()
{
    cout << "Enter length of rope (integer): ";
    int len, x, y, z;
    cin >> len;
    cout << "Enter 3 cut values (space seperated integers): ";
    cin >> x >> y >> z;
    int maxNumOfCuts = maxCuts(len, x, y, z);
    if (maxNumOfCuts == -1)
        cout << "Rope CAN'T be cut completely in the given length parts!!!";
    else
        cout << "Max number of cuts: " << maxNumOfCuts;

    return 0;
}

// Problem Explained in DSA (Basics) - Recursion - Track 4 (Time- 3:40)