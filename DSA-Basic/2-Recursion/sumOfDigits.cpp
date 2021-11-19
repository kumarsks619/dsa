#include <bits/stdc++.h>
using namespace std;

// recursive function to find sum of digits of a number
int sumOfDigits(int num)
{
    if (num < 10)
        return num;
    return sumOfDigits(int(num / 10)) + (num % 10); // NOT a tail recursive call
}

int main()
{
    cout << "Enter a number: ";
    int n;
    cin >> n;
    cout << "Sum of digits of " << n << ": " << sumOfDigits(n);

    return 0;
}