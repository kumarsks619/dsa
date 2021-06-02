#include <bits/stdc++.h>
using namespace std;

union Test
{
    int x;
    int y;
    double z;
    int arr[5]; // size of this union will depend on this array as it is the biggest member.
};

int main()
{
    Test t1;
    t1.x = 10; // changing one data member always affect other members.
    cout << "x = " << t1.x << " y = " << t1.y << " z = " << t1.z << endl;
    t1.y = 30;
    cout << "x = " << t1.x << " y = " << t1.y << " z = " << t1.z << endl;
    t1.z = 50000;
    cout << "x = " << t1.x << " y = " << t1.y << " z = " << t1.z << endl;

    cout << "Size of Test = " << sizeof(Test) << endl; // size of union = size of biggest data member.

    return 0;
}
