#include <iostream>

using namespace std;

class ComplexNumber
{
private:
    int real;
    int imag;

public:
    ComplexNumber(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    void displayComNum()
    {
        cout << real << " + " << imag << "i";
    }

    // Overloading "+" operator
    // Signature: return-type operator[operator-symbol] (arguments)
    ComplexNumber operator+(ComplexNumber cn)
    {
        ComplexNumber result;
        result.real = real + cn.real;
        result.imag = imag + cn.imag;

        return result;
    }

    // Overloading "*" operator
    // Signature: return-type operator[operator-symbol] (arguments)
    ComplexNumber operator*(ComplexNumber cn)
    {
        ComplexNumber result;
        result.real = (real * cn.real) - (imag * cn.imag);
        result.imag = (real * cn.imag) + (imag * cn.real);

        return result;
    }
};

int main()
{
    ComplexNumber cn1(4, 3), cn2(2, 5), cn3(1, 2), cn4;

    cn4 = cn1 + cn2 * cn3; // interpreted by complier as: cn4 = cn1.add(cn2.multiply(cn3));
    // the operators are ALWAYS solved from right to left (i.e. two at a time) irrespective of the operator.
    // Here is also an Assignment Operator call (NOT copy cons call) i.e. cn4 = result of expression.
    // Complier by default provides assignment operator function which copies all members one by one which
    // is shalllow copy. So when there is dynamic memory allocations inside the classes then we should
    // create our own Assignment operator overloading function to do deep copy.

    cout << "Complex Number Sum = ";
    cn4.displayComNum();
}

// Following operators CAN'T be overloaded:
// 1) Scope resolution operator (::)
// 2) Ternary operator (?:)
// 3) Member selector operator (.)
// 4) sizeof