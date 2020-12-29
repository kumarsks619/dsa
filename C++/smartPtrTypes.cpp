#include <bits/stdc++.h>
using namespace std;

class Test {
    int x;
    public:
        Test(int a = 0) {
            cout << "Test: Constructor called..." << endl;
            x = a;
        }
        int fun() {
            cout << "Test: Member function called..." << endl;
            return x;
        }
        ~Test() {
            cout << "Test: Destructor called..." << endl;
        }
};

int main() {
    cout << "main() begins..." << endl;
    {   
        cout << "Type 1: UNIQUE POINTERS" << endl;
        unique_ptr<Test> ptrUnq(new Test(5));   // "unique_ptr" is the unique pointer template class name.
        // unique_ptr<Test> ptrUnq = make_unique<Test>(5);      // can also be declared like this.

        // unique_ptr<Test> ptrUnq2 = ptrUnq;   // this will give compiler error as unique ptr can't be
        // assigned to other ptr. Basically it does not allows multiple ptrs to point same memory location.

        unique_ptr<Test> ptrUnq2 = move(ptrUnq);   // above error can be overcome by using "move" function.
        
        ptrUnq2->fun();  // simply accessing member function using a smart pointer.
    }

    {
        cout << endl << "Type 2: SHARED POINTERS" << endl;
        shared_ptr<Test> ptrShrd(new Test(10));
        // shared_ptr<Test> ptrShrd = make_shared<Test>(10);    // can also be declared like this.
        shared_ptr<Test> ptrShrd2 = ptrShrd;

        // Refernce count keeps a count of the number of ptrs pointing the same object or memory location.
        cout << "Refernce count: " << ptrShrd.use_count() << endl;
        cout << "Refernce count: " << ptrShrd2.use_count() << endl;

        // Shared ptr allows multiple ptrs to point to same obj (same memory location).
        // Shared ptr keeps a track of number of ptrs pointing to same memory location and only calls the
        // destructor when all the ptrs pointing to that location gets out of scope i.e. reference count
        // becomes zero.

        ptrShrd->fun();
        ptrShrd2->fun();
    }

    cout << endl << "Type 3: WEAK POINTERS" << endl;
    weak_ptr<Test> ptrWk; //weak ptrs can't have objects of their own so it is just declared here (NOT assigned).
    {
        shared_ptr<Test> ptrShrd(new Test(20));
        ptrWk = ptrShrd;    // the weak ptr is now given to point someone else's obj.

        cout << "Reference count: " << ptrShrd.use_count() << endl;  // weak ptrs are not counted in the
        // referneces as they are just temporary pointers to access already created objects in a smart way.
        
        // ptrWk->fun();   // IDK WHY I'M NOT ABLE TO USE THE WEAK PTR LIKE THIS. THEN WHAT IS ITS USE IF WE CAN"T
        // ACCESS THE MEMBER FUNCTIONS OF THE OBJECT TO WHICH IT IS POINTING ???

        // after this, the scope of the ptrShrd is over so the Destructor will be called irrespective of the
        // scope of ptrWk as it just a temporary ptr whose references is NOT counted.
    }

    cout << "main() ends...";

    return 0;
}

// MUST Watch GFG C++ 27 : for detailed explanation.