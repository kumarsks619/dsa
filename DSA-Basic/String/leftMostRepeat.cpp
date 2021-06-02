#include <bits/stdc++.h>
using namespace std;

int leftMostRepeat(string str)
{
    int result = -1;
    int count[256] = {0}; // array to keep the count of each character in the string

    // transversing the string from right so that the end result value will contain the index of leftmost repeating character.
    for (int i = str.length() - 1; i >= 0; i--)
        if (count[str[i]] == 0)
            count[str[i]]++;
        else
            result = i;

    return result;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "The left most repeating character's index: " << leftMostRepeat(str);

    return 0;
}

// Problem Statement: WAF which takes a string as an argument and returns the index of leftmost repeating character in that string.
// Example:  str = "hello world"  then, answer = 2
// Time Complexity: O(n)
// Auxiliary Space: Theta(256) or O(1)