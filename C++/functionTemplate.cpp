#include <iostream>

using namespace std;

// Overloaded Functions *******************************
int add(int x, int y) {     // function 1
    return x + y;
}

float add(int x, float y){  // function 2
    return x + y;
}

float add(float x, int y) { // function 3
    return x + y;
}

float add(float x, float y) {   // function 4
    return x + y;
}
// *****************************************************

// Function TEMPLATE
// keywords: template & typename
template <typename T, typename U, typename V>
T add(U x, V y) {
    return x + y;
}


int main() {
    cout << "By Function Overloading ****************************" << endl;
    cout << "Calling Function 1: " << add(3, 4) << endl;
    cout << "Calling Function 2: " << add(3, 4.5f) << endl;
    cout << "Calling Function 3: " << add(3.5f, 4) << endl;
    cout << "Calling Function 4: " << add(3.5f, 4.5f) << endl << endl;

    cout << "By Function Templates *******************************" << endl;
    cout << "Performing operation of Function 1: " << add<int, int, int>(3, 4) << endl;
    cout << "Performing operation of Function 2: " << add<float, int, float>(3, 4.5f) << endl;
    cout << "Performing operation of Function 3: " << add<float, float, int>(3.5f, 4) << endl;
    cout << "Performing operation of Function 4: " << add<float, float, float>(3.5f, 4.5f) << endl;
}