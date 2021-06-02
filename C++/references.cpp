#include <bits/stdc++.h>
using namespace std;

// passing ref of vec1 so to prevent copy creation by the function.
void fun(const vector<int> &vec)
{ // const can also be added if the passed value is not modified inside the function.
    cout << vec[0] << endl;
}

int main()
{
    int x = 5;
    int &y = x; // here y is reference name given to x. Now both will point to same memory location.
    // references MUST be assigned to while creating. Otherwise syntax error.

    y = y + 1;
    cout << x << endl;

    vector<int> vec1(1000, 1); // a very large vector with 1000 values.
    fun(vec1);

    for (auto x : vec1)
    {              // here x is a copy of each element.
        x = x + 5; // so actual vector will not change. // to change use ref: for(auto &x : vec1)
    }
    fun(vec1);

    // Most efficient way of ONLY READING large vectors or arrays.
    for (const auto &x : vec1)
    {
        // cout << x;
    }

    // References can be assigned only ONCE.
    int a = 10, b = 20;
    int &c = a; // ref assigned.
    c = b;      // Error: &c = b;
    cout << a << " " << b << " " << c << endl;
}

// references are DIFFERENT from passing addresses.
// References can be used to save CPU time by restricting the copy of the actual values while passing to functions.
// If a value to be passed to a function is too big and we just want to read the values inside a function then
// we should pass it as reference such that the copy of that variable will not get formed.
// Refs are const pointers so they can't be re-assigned (cons). Whereas normal pointers can be re-assigned (pros).