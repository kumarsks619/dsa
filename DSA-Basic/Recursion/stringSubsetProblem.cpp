#include <bits/stdc++.h>
using namespace std;

void stringSubset(string str, string curr = "", int index = 0) {
    if (index == str.length()) {
        cout << curr << ", ";
        return;
    }
    stringSubset(str, curr, index + 1);
    stringSubset(str, curr + str[index], index + 1);    // '+' can be used to concatenate strings in C++ too.
}

int main() {
    cout << "Enter a string: ";
    string str;
    getline(cin, str);
    cout << "Subsets of " << str << " are: ";
    stringSubset(str);
    
    return 0;
}

// Problem: print all the subsets of a string (not necessary to appear together in the actual string).
// Problem Explained in DSA (Basics) - Recursion - Track 4 (Time- 19:30)