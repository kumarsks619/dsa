#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int u, int l = 0) {
    if ( l >= u)
        return true;
    if (str[l] != str[u])
        return false;
    return isPalindrome(str, u - 1, l + 1);     // tail recursive call, therefore tail recursive function
}

int main() {
    cout << "Enter a string: ";
    string str;
    getline(cin, str);
    
    if (isPalindrome(str, str.length() - 1))
        cout << "Palindrome.";
    else
        cout << "NOT Palindrome!!!";

    return 0;
}