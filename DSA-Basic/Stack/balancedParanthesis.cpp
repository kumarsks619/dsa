#include <bits/stdc++.h>
using namespace std;

// UTILITY function: to check for match of the OPEN symbol with their corresponding CLOSE symbol
bool isMatched(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

// function to check if the passed string contains balanced no. of paranthesis
bool isBalanced(string str)
{
    stack<int> st;

    // transversing the string character by character
    for (int i = 0; i < str.length(); i++)
    {
        // checking if the char is an OPEN symbol
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            st.push(str[i]); // then push it to the stack
        else
        {
            // checking if a CLOSE symbol is encountered before when the stack is already empty
            if (st.empty() == true)
                return false;
            // checking if the CLOSE symbol encountered is the counter for the last OPEN symbol found
            else if (isMatched(st.top(), str[i]) == false)
                return false;
            // If the pair was correct
            else
                st.pop(); // then remove its OPEN symbol from the stack (i.e. at the top position in the stack)
        }
    }
    return (st.empty() == true); // if the whole string is transversed and there is still some unpaired symbols left in the stack
}

int main()
{
    string str;

    cout << "Enter a set of paranthesis: ";
    getline(cin, str);

    if (isBalanced(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}