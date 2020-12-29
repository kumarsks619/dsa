#include <iostream>

using namespace std;

class A {
    public:
        void printMsg() {
            cout << "Class A Function" << endl;
        }
};

class B {
    public:
        void printMsg() {
            cout << "Class B Function" << endl;
        }
};

// Multiple Inheritance
class ABerror: public A, public B {
   // here both printMsg() from base class A and B will come.
   // here is no overriding of printMsg() so an ambiguous situation will create.      
};

// Multiple Inheritance
class AB: public A, public B {
    public:
        void printMsg() {
            A::printMsg();  // way to call base class A function.
            B::printMsg();  // way to call base class B function.
            cout << "Class AB Function" << endl;
        }
};


int main() {
    ABerror abErrorObj;
    // abErrorObj.printMsg();   this will give error as this object don't know which printMsg() to call.

    AB abObj;
    abObj.printMsg();
}