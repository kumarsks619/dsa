#include <iostream>

using namespace std;

int main() {
    int age = 2;
    int x = 2;

    switch (age) {
        default: // default case in switch always execute at last irrespective of its position in the cases.
            cout << "Default case." << endl;
            break;
        //case 36/x:  ---- arthimetic operations using variables is not allowed.
        case 36/2:  // ---  normal arthimetic operation is allowed.
            cout << "Normal aithmetic operation without any variable." << endl;
            break;
        case 3>1 && 4<2:
            cout << "Using logical operation inside case." << endl;
            break;
        case 21>1:  // --- normal comparison operation is allowed.
            cout << "Using comparison operation without any variable." << endl;
            break;
        case 5/2:  // floating point value is not allowed. This will convert to 2 automatically.
            cout << "Using floating point value." << endl;
            break;
        
    }   
}

// cases having same test value is not allowed.
