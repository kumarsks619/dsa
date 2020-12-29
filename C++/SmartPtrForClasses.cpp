#include <bits/stdc++.h>
using namespace std;

class Test {
    public:
        int x, y;
        Test(int a = 0, int b = 0) {
            cout << "Test: Constructor called..." << endl;
            x = a;
            y = b;
        }
        ~Test() {
            cout << "Test: Destructor called..." << endl;
        }
};

// this SmartPtr class can hanlde pointer of Test type ONLY.
class SmartPtr {
    Test *ptr;
    public:
        SmartPtr(Test *p = NULL) {
            cout << "SmartPtr: Constructor called..." << endl;
            ptr = p;
        }
        Test & operator*() {   // * is overloaded to return the obj of Test class whenever SmartPtr obj is used.
            cout << "SmartPtr: * Operator overloaded..." << endl;
            return *ptr;
        }
        Test * operator->() {   // -> is overloded to access the members of Test class.
            cout << "SmartPtr: -> Operator overloaded..." << endl;
            return ptr;
        }
        ~SmartPtr() {   // this destructor will lead to Test class destructor.
            cout << "SmartPtr: Destructor called..." << endl;
            delete ptr;
        }
};


int main() {
    cout << "main() begins..." << endl;
    {   // anywhere in the programe, a scope can be created by simply using these curly braces.
        // Test *ptr = new Test(5, 10);  // in this way, Destructor of Test is never reached as the obj is DAM.
        SmartPtr sp(new Test(5, 10)); // creating an SmartPtr obj by passing a ptr of dynamically allocated memory.
        cout << "x: " << sp->x << endl;
        cout << "y: " << sp->y << endl;
    }   // scope of Test class object is ends here.
    cout << "main() ends...";

    return 0;
}

// MUST Watch GFG C++ 26 : for detailed explanation.