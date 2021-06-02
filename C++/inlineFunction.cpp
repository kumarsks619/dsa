#include <iostream>

using namespace std;

// function prototype - forward declaration
inline int calcSum(int x, int y);

int main()
{
    cout << "Enter two numbers: ";
    int a, b;
    cin >> a >> b;

    cout << "Sum of " << a << " and " << b << " is: " << calcSum(a, b);
}

//an INLINE Function
inline int calcSum(int x, int y)
{
    return x + y;
}

// Inline function call doesn't transfer the control of programme to the function definition,
// unlike normal functions. It replaces the function call statements with the whole function definition
// during compilation.
// Therefore Inline functions executes faster than normal functions at the cost of memory.