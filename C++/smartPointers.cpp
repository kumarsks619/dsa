#include <bits/stdc++.h>
using namespace std;

// a SMART POINTER class : this SmartPtr class can only handle int pointers.
class SmartPtr {
    int *ptr;
    public:
        SmartPtr(int *p = NULL) {
            cout << "Constructor called..." << endl;
            ptr = p;
        }
        int & operator*() {     // returning a ref to value at ptr so that actual val can also be modified.
            cout << "* Operator overloaded..." << endl;
            return *ptr;
        }
        ~SmartPtr() {
            cout << "Destructor called..." << endl;
            delete ptr;
        }
};

int main() {
    SmartPtr sp(new int());     // creating an SmartPtr obj by passing a ptr of dynamically allocated memory.
    *sp = 20;
    cout << "Value in dynamically allocated int memory: " << *sp << endl;
    return 0;
}

// a smart ptr deallocates the dynamically allocated memory on its own.
// a smart ptr class can have more overloading functions as per requirement.