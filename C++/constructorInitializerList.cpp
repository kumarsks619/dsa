#include <bits/stdc++.h>
using namespace std;

class Inner
{
    int x;

public:
    Inner()
    {
        cout << "Inner: Default Constructor called..." << endl;
    }
    Inner(int a)
    {
        cout << "Inner: Parameterized Constructor called..." << endl;
        x = a;
    }
};

class Outer
{
    Inner in;

public:
    // Outer() { in = Inner(10); }      // constructor without initializer list.
    Outer() : in(10) {} // constructor with initializer list.
};

int main()
{
    Outer out1;

    return 0;
}

// using Initializer list is a more efficient way to initialize class data-members.
// Because without initializer list, the obj will first be initialized with Default constructor and then with
// the Parameterized constructor.