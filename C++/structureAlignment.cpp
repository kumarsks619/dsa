#include <bits/stdc++.h>
using namespace std;

struct Test1
{ // notice th order of data members.
    char c1;
    double d1;
    char c2;
};

struct Test2
{ // notice th order of data members.
    char c1;
    char c2;
    double d1;
};

struct Test3
{ // notice th order of data members.
    char c1;
    double d1;
    char c2;
} __attribute__((packed)); // forcefully compacting the structure alignment.
// by compacting an struct alignment, it will take the sum of individual data members sizes.

int main()
{
    // Both the structs have exactly same things but in different orders so they can have diff sizes too.
    cout << "Size of Test1: " << sizeof(Test1) << endl;
    cout << "Size of Test2: " << sizeof(Test2) << endl;
    cout << "Size of Test3: " << sizeof(Test3) << endl;
}

// In structs, the order of declaration of data members can manipulate the struct size.
// For optimization: always declare struct data members either in increasing or decreasing order of their sizes.
// By doing so, the structure will occupy least memory.

// For more info: watch GFG C++ 19.