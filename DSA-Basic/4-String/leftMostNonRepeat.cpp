#include <bits/stdc++.h>
using namespace std;

int leftMostNonRepeat(string str)
{
    int firstIndex[256]; // array to keep the index of ONLY first occurrence of each character in the string
    for (int i = 0; i < 256; i++)
        firstIndex[i] = -1; // initializing the whole array with -1

    for (int i = 0; i < str.length(); i++)
        if (firstIndex[str[i]] == -1) // checking for first occurrence
            firstIndex[str[i]] = i;   // if first occurrence then store its index in the array
        else
            firstIndex[str[i]] = -2; // if repeated then destroy the already stored index

    int result = INT_MAX;                        // initializing the result index with INFINITY
    for (int i = 0; i < 256; i++)                // transversing through the firstIndex[] array to check only for VALID index values that are stored
        if (firstIndex[i] >= 0)                  // checking for valid index value
            result = min(result, firstIndex[i]); // finding the minimum of the stored indexes to get the leftmost element

    return result == INT_MAX ? -1 : result; // if all the characters are repeated then return -1
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "The left most repeating character's index: " << leftMostNonRepeat(str);

    return 0;
}

// Problem Statement: WAF which takes a string as an argument and returns the index of leftmost NON-repeating character in that string.
// Example:  str = "hello world"  then, answer = 0
// Time Complexity: O(n)
// Auxiliary Space: Theta(256) or O(1)