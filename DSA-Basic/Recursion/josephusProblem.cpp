#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    return ((josephus(n - 1, k) + (k - 1)) % n) + 1;
}

int main()
{
    cout << "Enter no. of people in the circle: ";
    int numOfPeople, killPos;
    cin >> numOfPeople;
    cout << "Enter the position to be killed: ";
    cin >> killPos;

    cout << "Position to be given freedom: " << josephus(numOfPeople, killPos);

    return 0;
}