#include <iostream>

using namespace std;

int bae = 1;

int main() {
    int bae = 5;
    cout << ::bae;   
}

// :: - unary scope resolution operator
// :: this is used to access the global variables