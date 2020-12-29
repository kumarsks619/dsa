#include <bits/stdc++.h>
using namespace std;

class Base {
    protected:
        int x;
    public:
        Base(int x) {
            cout << "Base: Parameterized Constructor called..." << endl;
            this->x = x;
        }
};

class Derived : public Base {
    private:
        int y;
    public:
        Derived(int y, int x) : Base(x) {  // if there is no default constructor in the Base class then this will
            // give error so we need to call the parameterized constructor of Base class explicitly here
            // that too in the INITIALIZER LIST (otherwise error).
            cout << "Derived: Paramertized Constructor called..." << endl;
            this->y = y;
        }

        void displayData() {
            cout << "x = " << x << " y = " << y << endl;
        }
};


class A {
    public:
        A() { cout << "A: Constructor called" << endl; }
};

class B {
    public:
        B() { cout << "B: Constructor called" << endl; }
};

class C : public B, public A {
    public:
        C() { cout << "C: Constructor called" << endl; }
};

int main() {
    Derived d1(5, 10);
    d1.displayData();

    C c1;   // left to right base class constructor calls as written in inheritance statement.

    return 0;
}

// Base class contructor is always called first.
// If there is explicit call of Base class constructor inside its Derived class constructor then the compiler
// will automatically call the Default constructor of Base class and if it is not there in the Base class then
// it will give compiler error.