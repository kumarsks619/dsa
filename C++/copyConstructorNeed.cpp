#include <bits/stdc++.h>
using namespace std;

class NoCopyCon {
    int *ptr;
    public:
        NoCopyCon(int x) {
            ptr = new int(x);
        }
        void setVal(int x) {
            *ptr = x;
        }
        int getVal() {
            return *ptr;
        }
};

class WithCopyCon {
    int *ptr;
    public:
        WithCopyCon(int x) {
            ptr = new int(x);
        }
        WithCopyCon(WithCopyCon &obj) {     // obj to be copied must be passed as ref otherwise it will again
            // call a copy constructor to make its own copy and which will lead to a non-terminating loop.
            ptr = new int(obj.getVal());
        }
        void setVal(int x) {
            *ptr = x;
        }
        int getVal() {
            return *ptr;
        }
};

int main() {
    NoCopyCon nc1(5);
    NoCopyCon nc2(nc1);     // calling default copy constructor (shallow copy).
    nc2.setVal(10);         
    cout << "value at ptr in nc1 = " << nc1.getVal() << endl;   // value in nc1 also get changed.
    cout << "value at ptr in nc2 = " << nc2.getVal() << endl << endl;

    WithCopyCon wc1(7);
    WithCopyCon wc2(wc1);   // calling our copy constructor (deep copy).
    wc2.setVal(11);
    cout << "value at ptr in wc1 = " << wc1.getVal() << endl;   // value in wc1 remains unaffected.
    cout << "value at ptr in wc2 = " << wc2.getVal() << endl << endl;

    return 0;
}

// Whenever our class is doing some dynamic memory allocation and is working with pointers, we should go for
// our custom copy constructor to do deep copy.