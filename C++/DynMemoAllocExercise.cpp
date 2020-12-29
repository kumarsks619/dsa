#include <bits/stdc++.h>
using namespace std;

// inappropriate function.
int * fun1() {
    int a = 10;
    int *ptr = &a;
    return ptr;
}

// correct function.
int * fun2() {
    int *ptr = new int;
    *ptr = 20;
    return ptr;
}


int main() {
    cout << *fun1() << endl;    // gives correct output but the way is wrong.
    cout << *fun2() << endl;    // correct way.

    delete fun2();  // can deallocate that memory here as it is globally available through its pointer.
}

// fun1() is not a reliable or right way as the ptr it returning is pointing to its local variable which 
// vanishes as the fun1() end.

// fun2() is the correct way because it dynmaically allocates the memory and return the ptr of that memory
// location which stays in HEAP even after fun2() ends.