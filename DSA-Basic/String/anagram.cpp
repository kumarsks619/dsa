#include <bits/stdc++.h>
using namespace std;

bool anagram(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;

    int count[256] = { 0 };                         // trick to initialize the array with ZEROS
    for (int i = 0; i < s1.length(); i++) {         // transversing through a string
        count[s1[i]]++;                             // using the character's ASCII codes as array indexes of the count[] array
        count[s2[i]]--;
    }
    for (int i = 0; i < 256; i++)                   // if the whole count[] array is still found out to be zero than Anagrams
        if (count[i] != 0)
            return false;
    
    return true;
}


int main() {
    string str1, str2;
    cout << "Enter a string: ";
    getline(cin, str1);
    cout << "Enter another string: ";
    getline(cin, str2);

    if (anagram(str1, str2))
        cout << "Anagrams";
    else 
        cout << "NOT Anagrams!";

    return 0;
}


// Two strings are said to be Anagrams of each other when one can be formed by just re-arranging the characters of other string. (Permutations)
// Time Complexity: O(n) 
// Auxiliary Space: Theta(256) or O(1)