#include <iostream>

using namespace std;

int main() {
    int x = 7;
    int y = 11;

    cout << "Before swapping: ";
    cout << "x = " << x << " y = " << y << endl;

    x = x + y;  //x = 18  y = 11
    y = x - y;  //x = 18  y = 7
    x = x - y;  //x = 11  y = 7

    cout << "After swapping: ";
    cout << "x = " << x << " y = " << y << endl;

}