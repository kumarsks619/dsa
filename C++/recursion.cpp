#include <iostream>

using namespace std;

int factorial(int num)
{
    if (num != 1)
    {
        return num * factorial(num - 1);
    }
    else
    {
        return 1;
    }
}

int main()
{
    cout << "Enter an integer: ";
    int n;
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n);
}

// a recursive must contain condition to stop. (if/else)
// recursion is SLOWER than normal loops.