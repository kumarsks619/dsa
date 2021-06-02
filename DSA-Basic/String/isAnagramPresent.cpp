#include <bits/stdc++.h>
using namespace std;

// function to check wether two arrays of equal sizes are same or not [UTILITY Function]
bool areArraysSame(int arr1[], int arr2[], int size)
{
    for (int i = 0; i < size; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

bool isAnagramPresent(string txt, string pat)
{
    int countText[256] = {0}, countPattern[256] = {0}; // arrays to keep the count of frequency of each character in Text and Pattern

    // counting the frequency of characters in Pattern and Text (in case of Text, only upto the window length i.e. size of Pattern)
    for (int i = 0; i < pat.length(); i++)
    {
        countPattern[pat[i]]++;
        countText[txt[i]]++;
    }

    // shifting the window side by side, one by one to transverse through the whole Text length
    for (int i = pat.length(); i < txt.length(); i++)
    {
        // checking if the anagram is present in the particular current window by comparing both count arrays
        if (areArraysSame(countPattern, countText, 256))
            return true;

        countText[txt[i - pat.length()]]--; // removing the count for the first window element that is moving out of the window scope
        countText[txt[i]]++;                // adding the count for the last window element that is coming into the window
    }

    return false;
}

int main()
{
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    if (isAnagramPresent(text, pattern))
        cout << "Anagram of the Pattern is present in the Text";
    else
        cout << "Anagram of the Pattern is NOT present in the Text";

    return 0;
}

// Problem Statement: WAF that takes a Text string and a Pattern string and returns TRUE if an ANAGRAM of the provided Pattern is present
// in Text string at CONTINUOUS locations, else return FALSE.
// Working Principle: make a window of length of the Pattern string and transverse it through the Text string and check for the characters
// that fall inside the window are Anagrams of the Pattern string by counting the frequency of the characters and keeping the count in count
// arrays and then comparing those arrays for equality.