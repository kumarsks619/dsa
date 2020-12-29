#include <iostream>
#include <string>

using namespace std;

// Class Template
template <typename T>
class Value {
    private:
        T val;
        int a;  // template class can also contain non-template data-members.
    public:
        Value(T v) {
            val = v;
        }

        T getVal() {
            return val;
        }
};


int main() {
    Value <int>v1(5);   // syntax for instantiating object.
    Value <string>v2("VeNoM");  // syntax for instantiating object.

    cout << "Class object for int: " << v1.getVal() << endl;
    cout << "Class object for string: " << v2.getVal() << endl;
}

// Class Templates are used when we want to perform same kind of operations on different data type members.
// In the above case if we don't use class template then we have to create 2 diiferent classes with
// respective data-type of val, constructor and the getVal(). 