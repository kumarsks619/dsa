#include <iostream>

using namespace std;

int main() {
    cout << "Enter a number: ";
    int num;
    cin >> num;

    int actualNum = num;
    int revNum = 0;

    while(num != 0) {
        revNum  = (revNum * 10) + (num % 10);
        num /= 10;    
    }

    actualNum == revNum ? cout << "Palindrome" : cout << "NOT Palindrome";
}