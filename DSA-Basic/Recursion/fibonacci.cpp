#include <bits/stdc++.h>
using namespace std;

// this function only returns the Nth fibonacci series term
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    cout << "Enter number of terms required: ";
    int numOfTerms;
    cin >> numOfTerms;

    for (int  i = 0; i < numOfTerms; i++)
        cout << fib(i) << " ";

    return 0;
}