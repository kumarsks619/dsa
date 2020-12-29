#include <bits/stdc++.h>
using namespace std;

int & fun() {       // this function return a ref to a variable.
    static int x = 10;  // only refs of static variables should be returned if they are local.
    return x; 
}

int main() {
    int &z = fun();
    cout << fun() << endl;
    z = 30;     // this will modify the x variable of fun()
    cout << fun();
}

// Local variables vanishes as their scope ends so there refs can't be returned.
// It will give runtime error if we do not use static for the variables whose refs are need to be returned outside
// their actual scope.