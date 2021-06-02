#include <iostream>

using namespace std;

void callByReference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void callByAddress(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 7, b = 11;

    cout << "Before Swapping: ";
    cout << "a = " << a << " b = " << b << endl;

    cout << "Calling by Reference: ";
    callByReference(a, b); //NOTICE: no need to pass the address
    cout << "a = " << a << " b = " << b << endl;

    cout << "Calling by Address: ";
    callByAddress(&a, &b); //NOTICE: address of the variables are being passed
    cout << "a = " << a << " b = " << b << endl;
}

// in both ways the actual variables changes.
// in callByReference(&x, &y) the actual variables are just given new labels i.e. x and y respectively.
// in callByAddress(*x, *y) the address of the actual variables are being passed to their pointers.