#include <bits/stdc++.h>
using namespace std;

void searchPattern(string txt, string pat)
{
    int n = txt.length(), m = pat.length();
    for (int i = 0; i <= n - m; i++)
    { // transversing the window to cover the whole Text string
        for (int j = 0; j < m; j++)
        {                                                   // transversing the WINDOW to match characters
            if (txt[i + j] != pat[j])                       // matching Text (only window part) with Pattern
                break;                                      // if any mis-match, then break and slide the window forward
            if (j == m - 1)                                 // if the WINDOW is transversed completely
                cout << "Occurred at index: " << i << endl; // print the first index of the WINDOW
        }
    }
}

int main()
{
    string text, pattern;
    cout << "Enter Text string: ";
    getline(cin, text);
    cout << "Enter Pattern to search for: ";
    getline(cin, pattern);

    searchPattern(text, pattern);

    return 0;
}

// Problem Statement: WAF that takes a TEXT string and a PATTERN string and prints the starting indexes of all the exact(NO anagrams)
// occurrences of the PATTERN string in the TEXT string.
// Working Principle: [NAIVE APPROACH]: make a window of length equal to the length of the Pattern string and transverse it through the
// Text string and match each character that falls into the window with the Pattern string and if all the characters get matched then return
// the starting index of the window (at its current position) and then slide the window forward by one step.
// Time Complexity: O((n-m+1) x m) => O(n^2)
// SPECIAL CASE: When the PATTERN has all DISTINCT characters. [Time Complexity: O(n) (after modifying Naive approach)]
// For SPECIAL case: Can watch GFG DSA(Basic) -> Strings -> Track 2 -> 17:00

// Other sub-string Searching Algorithms:-
// 1) Rabin Karp:  Pre-process PATTERN // [Time Complexity: O((n-m+1) x m)] -> both 'n' and 'm'
// 2) KMP: Pre-process PATTERN // [Time Complexity: O(n)] -> 'n'
// 3) Suffix Tree: Pre-process TEXT // [Time Complexity: O(m)] -> 'm'