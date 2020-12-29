#include <iostream>

using namespace std;

int main() {
    int year;
    cout << "Enter year: ";
    cin >> year;

    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400) {
                cout << "Leap year";
            }else {
                cout << "NOT a leap year";
            }
        }else {
            cout << "Leap year";
        }
    }else {
        cout << "NOT a leap year";
    }
}