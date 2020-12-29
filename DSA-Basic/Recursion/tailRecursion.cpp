#include <bits/stdc++.h>
using namespace std;

// 1 to N
void oneToN(int n) {
    if ( n <= 0)
        return;
    oneToN(n - 1);
    cout << n << " ";
}

// N to 1: Tail Recursive Function
void nToOne(int n) {
    if (n <= 0)
        return;
    cout << n << " ";
    nToOne(n - 1);  // Tail Recursive Call
}

// Normal factorial recursive function
int fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);     // NOT a Tail Recursive Call as the function (caller) waits for the value of 
    // fact(n - 1) to multiply it with n and then return successfully.
}

// Tail Recursive version of the above factorial function
int factTail(int n, int val = 1) {
    if (n == 0)
        return val;
    return factTail(n - 1, val * n);
}

int main() {
    cout << "Enter n: ";
    int N;
    cin >> N;

    cout << "1 to " << N << ": ";
    oneToN(N);
    cout << endl << N << " to 1" << ": ";
    nToOne(N);


    cout << "\nFind factorial of: ";
    int a;
    cin >> a;
    cout << "Factorial of " << a << " using fact(): " << fact(a) << endl;
    cout << "Factorial of using " << a << " using factTail(): " << factTail(a);

    return 0;
}

// Tail Recursive Functions are faster then normal recursive functions as they don't have to save the flag for the
// remaning function (caller function) code as the function is already completed.