#include <iostream>

using namespace std;

int add(int a, int b) {
    cout << "Function 1" << endl;
    return a + b;
}

int add(int a, int b, int c) {
    cout << "Function 2" << endl;
    return a + b + c;
}

double add(int a, double b) {
    cout << "Function 3" << endl;
    return a + b;
}


double add(double a, int b) {
    cout << "Function 4" << endl;
    return a + b;
}


int main() {

    cout << add(2, 5) << endl;
    cout << add(2, 5, 1) << endl;
    cout << add(2, 5.5) << endl;
    cout << add(2.5, 5) << endl;

}

// Function Overloading can be done by: 
// 1) Changing the number of arguements.
// 2) Chnaging the type of arguements.
// 3) Changing the SEQUENCE of arguements. (shown b/w func 3 & func 4)