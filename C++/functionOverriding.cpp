#include <iostream>

using namespace std;

class Shape
{
public:
    void calcArea()
    {
        cout << "Area of Shape: ";
    }
};

class Circle : public Shape
{
public:
    float calcArea(int r)
    {
        return 3.14 * r * r;
    }
};

class Square : public Shape
{
public:
    float calcArea(int a)
    {
        Shape::calcArea(); // indirectly calling the base class overriden function.
        return a * a;
    }
};

int main()
{
    Circle cir1;
    cout << "Area of Circle: " << cir1.calcArea(2) << endl;

    Square sq1;
    cout << sq1.calcArea(4);
}

// the derived class will always overide the base class function with the same name.
// function is different from function overloading as overriding happens irrespective of
// type of arg, no. of arg or sequence of arg.
// however the function of base class can be accessed indirectly using the scope resolution operator(::)
// inside the derived class function.

// Polymorphism: having multiple forms like function overloading, function overriding, operator overloading.
// Polymorphism is also shown in Procedural Programming by function overloading.
// Compile time Polymorphism: func overloading, operator overloading.
// Runtime Polymorphism: func overriding