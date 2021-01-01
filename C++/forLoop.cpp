#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = 1;
    for(cout << " init " ; cout << " test " , cout << " condition "; cout << " incerement/decrement ") {
        if(i){
            cout << " Hello ";
            i--;
        }
        else{
            cout << " Bye ";
            break;
        }
    }
    return 0;
}

// output => initconditionHello
// for(any valid statements)