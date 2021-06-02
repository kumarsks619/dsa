#include <iostream>

using namespace std;

class Value
{
private:
    int val;

public:
    Value(int v = 0)
    {
        val = v;
    }

    int getVal()
    {
        return val;
    }

    // Overloading PRE decrement operator.
    // one-way solution i.e. obj can't be assigned directly to other obj after performing operation.
    void operator--()
    {
        --val;
    }

    // Overloading POST decrement operator.
    // one-way solution i.e. obj can't be assigned directly to other obj after performing operation.
    // ONLY (int) must be passed as argument to differentiate it from pre operator.
    void operator--(int)
    {
        val--;
    }

    // Overloading PRE increment operator
    // both-way solution: obj can be assigned to other obj directly as the following type of
    // overloading returns an object of the same data-type.
    Value operator++()
    {
        Value result;
        result.val = ++val;
        return result;
    }
    // Overloading POST increment operator
    Value operator++(int)
    {
        Value result;
        result.val = val++;
        return result;
    }
};

int main()
{
    Value v1;

    --v1;
    cout << "val1 = " << v1.getVal() << endl;

    v1--;
    cout << "val1 = " << v1.getVal() << endl;

    Value v2, v3;

    v3 = v2++; // can be assigned to other object directly.
    cout << "val2 = " << v2.getVal() << endl;
    cout << "val3 = " << v3.getVal() << endl;

    ++v3;
    cout << "val3 = " << v3.getVal() << endl;
}