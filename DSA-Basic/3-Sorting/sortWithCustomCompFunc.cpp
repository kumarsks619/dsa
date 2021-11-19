// sort() with CUSTOM comparison functions

#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

// custom comparison function for sort()
// Increasing order of x-coordinate
bool customCompFuncInc(Point p1, Point p2)
{
    return (p1.x < p2.x);
}
// Decreasing order of x-coordinate
bool customCompFuncDec(Point p1, Point p2)
{
    return (p1.x >= p2.x);
}

int main()
{
    Point arr[] = {{2, 5}, {8, 1}, {5, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n, customCompFuncInc);
    // displaying the structures array
    for (auto pt : arr)
        cout << "(" << pt.x << ", " << pt.y << ") ";

    cout << endl;

    sort(arr, arr + n, customCompFuncDec);
    // displaying the structures array
    for (auto pt : arr)
        cout << "(" << pt.x << ", " << pt.y << ") ";

    return 0;
}