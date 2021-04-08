#include <bits/stdc++.h>
using namespace std;

// UTILITY Function: to convert a char to int (eg: '3' to 3)
int scanNum(char ch)
{
    int value;
    value = ch;
    return int(value - '0'); //return int from char
}

// UTILITY Function: to identify an Operator
bool isDigit(char c)
{
    return !(c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// UTILITY Function: to evaluate a sub-expression
int evalExp(char c, int val1, int val2)
{
    switch (c)
    {
    case '+':
        return val2 + val1;
    case '-':
        return val2 - val1;
    case '*':
        return val2 * val1;
    case '/':
        return val2 / val1;
    case '^':
        return pow(val2, val1); // val2 ^ val1, as transversing from LEFT to RIGHT
    default:
        return INT_MIN; // negative infinity
    }
}

// Function to evaluate a Postfix Expression
int evalPostfixExp(string exp)
{
    stack<int> st; // Stack to store OPERANDS only.
    int len = exp.length(), result = 0;

    // transversing through the expression string char by char
    for (int i = 0; i < len; i++)
    {
        // Case 1: the char is a number, then push it to the stack
        if (isDigit(exp[i]))
        {
            st.push(scanNum(exp[i])); // converting the char to int before pushing to the stack
        }

        // Case 2: the char is an operator, then evaluate it using the top two numbers from the stack
        // and then again push the result to the stack
        else
        {
            int op1 = st.top();                 // topmost number from the stack
            st.pop();                           // removing the topmost number from the stack
            int op2 = st.top();                 // second topmost number from the stack
            st.pop();                           // removing the second topmost number from the stack
            result = evalExp(exp[i], op1, op2); // evaluating the sub-expression using the operands and the operator
            st.push(result);                    // pushing the result to stack
        }
    }
    return st.top(); // after complete transversal of the expression string, stack top stores the
    // final result of the whole expression
}

int main()
{
    string exp = "231*+9-";
    cout << evalPostfixExp(exp);

    exp = "21+3*";
    cout << endl
         << evalPostfixExp(exp);

    return 0;
}