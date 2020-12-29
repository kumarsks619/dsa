#include <bits/stdc++.h>
using namespace std;

void f1() {
    cout << "f1() begins..." << endl;
    // throw int(1000);     // if this, then control will be transfered to f3() catch block.
    throw string("Error thrown by f1()");
    cout << "f1() ends..." << endl;         // this code will NOT execute.
}

void f2() {
    cout << "f2() begins..." << endl;
    f1();
    cout << "f2() ends..." << endl;         // this code will NOT execute.
}

void f3() {
    cout << "f3() begins..." << endl;
    try {
        f2();
    }catch(int err) {
        cout << "Inside f3(): " << err << endl;
    }
    cout << "f3() ends..." << endl;         // this code will NOT execute.
}


int main() {
    cout << "main() begins..." << endl;

    try {
        f3();
    }catch(string err) {
        cout << "Inside main(): " << err << endl;
    }

    cout << "main() ends...";       // this code will execute.

    return 0;
}


// Whenever an error is thrown it searches for its nearest data-type defined or a default catch block and the 
// control of the programe is transfered to that particular catch block.

// If a catch block is not found in the same function then it goes to search in its caller and if also not
// there then it goes so on and when it finally found the nearest catch block which is targeting the same
// data type (or default catch) of the thrown error, the program control is passed there.