#include <bits/stdc++.h>
using namespace std;

void getAddMul(int a, int b, int *ptrAdd, int *ptrMul)
{
    *ptrAdd = a + b;
    *ptrMul = a * b;
}

int main()
{
    int x = 10, y = 5, add, mul;
    getAddMul(x, y, &add, &mul);
    cout << "Addition: " << add << endl;
    cout << "Product: " << mul << endl;

    return 0;
}