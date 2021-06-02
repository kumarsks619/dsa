#include <iostream>

using namespace std;

class Base
{
public:
    int val;
};

// virtual keyword is used in the middle level classes.
class Derived1 : virtual public Base
{
public:
    Derived1()
    {
        val = 1;
    }
};

// virtual keyword is used in the middle level classes.
class Derived2 : virtual public Base
{
public:
    Derived2()
    {
        val = 2;
    }
};

// virtual keyword is NOT used here.
class Hybrid : public Derived1, public Derived2
{
    // Without virtual inheritance: both the val from Derived1 and Derived2 are available here.
    // With virtual inheritance, the right most class's val will get passed here ONLY.
    // So after using virtual inheritance, ambiguity is solved.
public:
    int getVal()
    {
        // return val;  without virtual inheritance the val is ambiguous here.
        // return Derived1::val;    without virtual inheritance we have to explicitly choose one val.
        return val; //this give the val of right most class written here while inheriting(i.e. Derived2).
    }
};

int main()
{
    Hybrid hyObj;

    cout << "Val = " << hyObj.getVal();
}

// To solve the ambiguity in hybrid inheritance, the middle level of inheritance classes need to
// inherit the Base class virtually. This ensures that only copy will be send to the next level of
// inheritance in case of ambiguity.
