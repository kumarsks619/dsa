#include <bits/stdc++.h>
using namespace std;

int fun(int n) {
    if (n < 1)
        return 0;       // these returned values is NOT printed anywhere.
    else {
        cout << n << endl;
        fun(n - 1);     // when the recursive call happens then rest of the function code is paused until the
        // inner recursive calls are over and then again the control is passed to the caller (parent) function.
        cout << n << endl;
        return 0;       // these returned values is NOT printed anywhere.
    }
} 

int main() {
    fun(3);

    return 0;
}