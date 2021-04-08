#include <bits/stdc++.h>
using namespace std;

// UTILITY Function: to get the precedence order of a given operator
int getPrec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string infix)
{
    string revPrefix, prefix; // string to hold the output string i.e. the prefix expression string in REVERSE order
    stack<char> st;           // Stack to hold the OPERATORS and OPENING PARANTHESIS ONLY
    int len = infix.length();

    for (int i = len - 1; i >= 0; i--)
    {
        // checking if char is an OPERAND: then add it to the output string
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            revPrefix += infix[i];
        }

        // checking if the char is an CLOSING PARANTHESIS: then push it to the stack
        else if (infix[i] == ')')
        {
            st.push(infix[i]);
        }

        // checking if the char is a OPENING PARANTHESIS: then keep popping out everything the from the
        // stack and append it to the output string until an CLOSING PARANTHESIS is encountered
        else if (infix[i] == '(')
        {
            while (st.top() != ')')
            {
                revPrefix += st.top(); // appending the top char to output string
                st.pop();              // removing the top char from the stack
            }
            st.pop(); // removing the encountered ')' character from the stack
        }

        // when the char is an OPERATOR:
        else
        {
            // case 1: if the stack is empty: then push the OPERATOR to the stack
            if (st.empty())
            {
                st.push(infix[i]);
            }

            // case 2: if the OPERATOR has HIGHER or EQUAL (because of associativity) precedence than the
            //stack top OPERATOR: then push it to the stack.
            // (When going from RIGHT to LEFT, in case of operators (except ^) with equal precedence, the
            // operator that occurs LATER has higher precedence (because of associativity) as it occurs
            // earlier in the expression (LEFT to RIGHT))
            else if (getPrec(infix[i]) >= getPrec(st.top()))
            {
                // if the OPERATORS having same precedence are '^' OPERATOR (as their ASSOCIATIVITY is from
                // RIGHT to LEFT) then keep popping out everthing and append it to the output string
                // until a lower precedence OPERATOR is found (lower precedence than the infix[i] OPERATOR).
                // After popping is done, then push the infix[i] OPERATOR to stack.
                if ((getPrec(infix[i]) == getPrec(st.top())) && infix[i] == '^')
                {
                    revPrefix += st.top(); // appending to output string
                    st.pop();              //removing the top character

                    while (!st.empty() && getPrec(infix[i]) < getPrec(st.top()))
                    {
                        revPrefix += st.top(); // appending to output string
                        st.pop();              //removing the top character
                    }
                }
                st.push(infix[i]);
            }

            // case 3: if the OPERATOR has LOWER precedence than the stack top OPERATOR: then keep
            // popping out everthing and append it to the output string until a lower precedence
            // OPERATOR is found (lower precedence than the infix[i] OPERATOR). After popping is done, then
            // push the infix[i] OPERATOR to stack
            else
            {
                while (!st.empty() && getPrec(infix[i]) < getPrec(st.top()))
                {
                    revPrefix += st.top(); // appending to output string
                    st.pop();              //removing the top character
                }
                st.push(infix[i]); //after removing all the higher precedence OPERATORS, now pushing the
                // infix[i] OPERATOR to the stack
            }
        }
    }

    // After transversing the whole infix string: empty the stack one by one and append it to output string
    while (!st.empty())
    {
        revPrefix += st.top(); // appending to output string
        st.pop();              // removing the top character
    }

    // Now reversing the reverse prefix string to get the final prefix expression
    for (int i = revPrefix.length() - 1; i >= 0; i--)
    {
        prefix += revPrefix[i];
    }

    return prefix;
}

int main()
{
    string exp = "a^b^c";
    string result = infixToPrefix(exp);
    cout << result;

    exp = "a+b*(c^d-e)^(f+g*h)-i";
    result = infixToPrefix(exp);
    cout << endl
         << result;

    return 0;

    return 0;
}

// NOTE:
// 1) The provided Infix experssion is transversed from RIGHT to LEFT.
// 2) CLOSING paranthesis is encountered before the opening paranthesis. So the closing paranthesis is
// pushed to the stack.
// 3) Associativity plays a tricky role in case of '^' operator.
// 4) The output string we get is the reverse of the desired Prefix expression so it need to be reversed.