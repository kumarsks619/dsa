#include <iostream>

using namespace std;

// this an ABSTRACT CLASS as it contains a virtual function.
class Animal {
    public:
        virtual void eat() = 0;   //syntax of definning a PURE VIRTUAL Function

        void run() {    // just a dummy function to show that this class is still ABSTRACT.
            cout << "Run" << endl ;
        }
};

class Dog: public Animal {
    public:
        void eat() override {    // no need to mention the virtual keyword here.
            // 'override' keyword is added just to increase readability, without it still works fine.
            cout << "Eating Dog food..." << endl;
        }
};

class Cat: public Animal {
    public:
        void eat() override {    // no need to mention the virtual keyword here.
            // 'override' keyword is added just to increase readability, without it still works fine.
            cout << "Eating Cat food..." << endl;
        }
};

// Abstract Class
class Cow: public Animal {
    // virtual function is not re-redefined so this will contain the same Virtual function.
    // Therefore object of this class can't be created.
};


int main() {
    Animal *animalPtr;  // pointer of base class.
    // Animal an1;      object of Abstract class can't be created.
    // Cow cw1;         object of Abstract class can't be created.
    
    Dog dg1;
    animalPtr = &dg1;   // pointing to derived class.
    animalPtr->eat();   // accessing re-definiton of the virtual function.

    Cat ct1;
    animalPtr = &ct1;   // pointing to derived class.
    animalPtr->eat();   // accessing re-definiton of the virtual function.
}

// Any class that contains a virtual function is an abstract class. 
// Object of Abstract class can't be created.

// Pure Virtual Functions must have same signature (void eat()) while re-defining them.

// Pointer of base class can be used to point derived classes objects and can access the re-definiton
// of virtual function present in that derived class.
// We can't do this without making the function virtual in the Base class.
// This can't be done by function overriding too.

// If we try to access the derived class re-defined function using a ptr of base class which is pointing
// to the derived class obj without making that function virtual then it will call the base class function and
// NOT the derived class re-definition of the function.
// We can verify this by putting some function body in the Base class virtual function and removing the 
// virtual keyword.

// Function OVERRIDING: virtual function in base class and then re-definition of it in its derived class.
// The re-definition must have same function signature (func signature => void eat()) unlike func overloading.
// Function OVERRIDING is RUNTIME POLYMORPHISM.
// Whereas function OVERLOADING is COMPILE TIME POLYMORPHISM. 