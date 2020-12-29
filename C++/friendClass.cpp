#include <iostream>

using namespace std;

class Value {
    private:
        int val;
    public:
        Value(int v) {
            val = v;
        }

    friend class ValueFriend;   // declaring other class as friend of this class.
};

class ValueFriend {
    public:
        int getVal(Value obj) {
            return  obj.val;   // friend of Value therefore has full access to all its data members.
        }
};

int main() {
    Value v1(5);
    ValueFriend vf1;

    cout << "val = " << vf1.getVal(v1);
}

// A friend class has full access to ALL the data members of the class to which it is friend. 

// Friendship:
// 1) is Granted, NOT taken.
// 2) NOT MUTUAL, if A is friend of B then B is not friend of A unless specified explicitly.
// 3) is NOT INHERITED.
// 4) NOT TRANSITIVE, if A is friend of B and B is friend of C then C is NOT friend of A or vice-versa.

// FRIENDSHIP ALWAYS NEEDS TO BE SPECIFIED EXPLICITLY.