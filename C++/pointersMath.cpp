#include <iostream>

using namespace std;

int main() {
    int arr[5];
    int *ap0 = &arr[0];     // same as int* ap0 = &arr[0]
    int *ap1 = &arr[1];
    int *ap2 = &arr[2];

    cout << "ap0 holds: " << ap0 << endl;
    cout << "ap1 holds: " << ap1 << endl;
    cout << "ap2 holds: " << ap2 << endl;

    ap0 = ap0 + 2;  //ap0 now points to next to next address of the type of data it is pointing to.

    cout << "ap0 holds now: " << ap0 << endl;
}

// we can't perform maths on address values.
// when doing maths with a pointer variable it affects the pointer itself and based upon the
// type of value it is pointing to, it changes accordingly and now points to another memory location.