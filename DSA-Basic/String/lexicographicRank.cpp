#include <bits/stdc++.h>
using namespace std;

int fact(int a) {
    if (a == 1)
        return 1;
    return a * fact(a - 1);
}

// This function works only for all DISTINCT characters in the string
int lexicographicRank(string str) {
    int rank = 1;
    int n = str.length();
    int mul = fact(n);
    int count[256] = { 0 };

    // counting the frequency of each character in string
    for (int i = 0; i < n; i++)
        count[str[i]]++;

    // making the cumulative counts array to get the number of characters that are less than or equal to a particular character
    for (int i = 1; i < 256; i++)
        count[i] = count[i] + count[i - 1];


    for (int i = 0; i < n; i++) {
        mul = mul / (n - i);                        // to get the factorial multiplier value
        rank = rank + count[str[i] - 1] * mul;
        
        // decreasing the counts for the characters that are already been fixed
        for (int j = str[i]; j < 256; j++)
            count[j]--;
    }
    
    return rank;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Lexicographic Rank: " << lexicographicRank(str);

    return 0;
}


// Lexigraphic Rank: PnC dictionary problem
// Works as: "STRING" = (4x5!)+(4x4!)+(3x3!)+(1x2!)+(1x1!)+1        => PnC method
// Can Watch: GFG DSA(Basic) -> Strings -> Track 2 -> 00:00