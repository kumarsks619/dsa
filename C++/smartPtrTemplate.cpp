#include <bits/stdc++.h>
using namespace std;

// this SmartPtr class can handle pointers of any data type.
template <typename T>
class SmartPtr
{
    T *ptr;

public:
    SmartPtr(T *p = NULL)
    {
        ptr = p;
    }
    T &operator*()
    {
        return *ptr;
    }
    T *operator->()
    {
        return ptr;
    }
    ~SmartPtr()
    {
        delete ptr;
    }
}; // terminated by semi-colon.

int main()
{
    cout << "SmartPtr for int: " << endl;
    SmartPtr<int> sp1(new int(5)); // creating an SmartPtr obj by passing a ptr of dynamically allocated memory.
    cout << *sp1 << endl;
    *sp1 = 10;
    cout << *sp1 << endl;

    cout << "SmartPtr for char: " << endl;
    SmartPtr<char> sp2(new char('A')); //creating an SmartPtr obj by passing a ptr of dynamically allocated memory.
    cout << *sp2 << endl;
    *sp2 = 'Z';
    cout << *sp2 << endl;

    return 0;
}

// MUST Watch GFG C++ 26 : for detailed explanation.
