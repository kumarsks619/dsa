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

string infixToPostfix(string infix)
{
    string postfix; // string to hold the output string i.e. the postfix expression string
    stack<char> st; // Stack to hold the OPERATORS and OPENING PARANTHESIS ONLY
    int len = infix.length();

    for (int i = 0; i < len; i++)
    {
        // checking if char is an OPERAND: then add it to the output string
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
        }

        // checking if the char is an OPENING PARANTHESIS: then push it to the stack
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }

        // checking if the char is a CLOSING PARANTHESIS: then keep popping out everything the from the
        // stack and append it to the output string until an OPENING PARANTHESIS is encountered
        else if (infix[i] == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top(); // appending the top char to output string
                st.pop();            // removing the top char from the stack
            }
            st.pop(); // removing the encountered '(' character from the stack
        }

        // when the char is an OPERATOR:
        else
        {
            // case 1: if the stack is empty: then push the OPERATOR to the stack
            if (st.empty())
            {
                st.push(infix[i]);
            }

            // case 2: if the OPERATOR has HIGHER precedence than the stack top OPERATOR: then push to stack
            else if (getPrec(infix[i]) > getPrec(st.top()))
            {
                st.push(infix[i]);
            }

            // case 3: if the OPERATOR has LOWER or EQUAL (because of associativity) precedence than the
            // stack top OPERATOR: then keep popping out everthing and append it to the output string
            // until a lower precedence OPERATOR is found (lower precedence than the infix[i] OPERATOR).
            // After popping is done, then push the infix[i] OPERATOR to stack
            else
            {
                while (!st.empty() && getPrec(infix[i]) <= getPrec(st.top()))
                {
                    // if the OPERATORS having same precedence are '^' OPERATOR than simply push it to stack
                    // as their ASSOCIATIVITY is from RIGHT to LEFT
                    if ((getPrec(infix[i]) == getPrec(st.top())) && infix[i] == '^')
                        break;

                    postfix += st.top(); // appending to output string
                    st.pop();            //removing the top character
                }
                st.push(infix[i]); //after removing all the higher precedence OPERATORS, now pushing the
                // infix[i] OPERATOR to the stack
            }
        }
    }

    // After transversing the whole infix string: empty the stack one by one and append it to output string
    while (!st.empty())
    {
        postfix += st.top(); // appending to output string
        st.pop();            // removing the top character
    }

    return postfix;
}

int main()
{
    string exp = "a^b^c";
    string result = infixToPostfix(exp);
    cout << result;

    exp = "a+b*(c^d-e)^(f+g*h)-i";
    result = infixToPostfix(exp);
    cout << endl
         << result;

    return 0;
}

// ADVANTAGES of Postfix or Prefix expressions over Infix expressions:
// They don't need any brackets or precedence or associativity rules to get evaluated.

// They only need those rules and brackets to get converted from Infix to Postfix or Prefix.

// Precedence Order of Operators:
//  ^ >> * or / >> + or - >> (

// Associativity Direction:
// + or - or * or /   have LEFT to RIGHT
// ^    have RIGHT to LEFT