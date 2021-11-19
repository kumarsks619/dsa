#include <bits/stdc++.h>
using namespace std;

bool areRotations(string s1, string s2)
{
    if (s1.length() != s2.length()) // if the lengths are not equal then return FALSE
        return false;

    s1 = s1 + s1;                       // concatenating two same strings
    return s1.find(s2) != string::npos; // checking for substring  // 'npos' is returned by the function when it fails to find a value
}

int main()
{
    string str1, str2;
    cout << "Enter a string: ";
    getline(cin, str1);
    cout << "Enter another string: ";
    getline(cin, str2);

    if (areRotations(str1, str2))
        cout << "Strings are rotations of each other";
    else
        cout << "Strings are NOT rotations of each other";

    return 0;
}

// Problem Statement: WAF that takes two strings and returns TRUE if one string can be obtained by ROTATING the characters of the other string
// in any manner (clockwise or counter-clockwise), else return FALSE.
// Working Principle: contatenate any one string with itself and check if the other string is a substring of that concatenated string.