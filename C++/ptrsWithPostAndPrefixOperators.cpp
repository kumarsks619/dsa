#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 1st Question: ++*ptr
    cout << "1st Question" << endl;
    int arr1[] = {10, 20};
    int *ptr1 = arr1;
    ++*ptr1; // evaluates as: ++(*ptr1)
    cout << arr1[0] << " " << arr1[1] << " " << *ptr1 << endl
         << endl;

    // 2nd Question: *ptr++
    // part 1
    cout << "2nd Question: Part A" << endl;
    int arr2a[] = {10, 20};
    int *ptr2a = arr2a;
    *ptr2a++; // evaluates as: *(ptr2++)
    cout << arr2a[0] << " " << arr2a[1] << " " << *ptr2a << endl;

    //part 2
    cout << "2nd Question: Part B" << endl;
    int arr2b[] = {10, 20};
    int *ptr2b = arr2b;
    cout << *ptr2b++ << endl; // postfix operator will take affect after this cout.
    cout << arr2b[0] << " " << arr2b[1] << " " << *ptr2b << endl
         << endl;

    // 3rd Question: *++ptr
    // part 1
    cout << "3rd Question: Part A" << endl;
    int arr3a[] = {10, 20};
    int *ptr3a = arr3a;
    *++ptr3a; // evaluates as: *(++ptr3a)
    cout << arr3a[0] << " " << arr3a[1] << " " << *ptr3a << endl;

    //part 2
    cout << "3rd Question: Part B" << endl;
    int arr3b[] = {10, 20};
    int *ptr3b = arr3b;
    cout << *++ptr3b << endl; // prefix operator will take affect in this cout too.
    cout << arr3b[0] << " " << arr3b[1] << " " << *ptr3b << endl
         << endl;

    return 0;
}