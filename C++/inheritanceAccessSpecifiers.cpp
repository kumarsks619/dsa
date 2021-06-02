#include <iostream>
#include <string>

using namespace std;

class Shape
{
private: // public members CAN't be inherited.
    string color = "Default Color";

protected: // protected members are similar to private but they CAN be inherited.
    int length;
    int width;

public: // CAN be inherited and accessed directly by the class objects.
    void setLength(int l)
    {
        length = l;
    }
    void setWidth(int w)
    {
        width = w;
    }
};

// Shape class is inherited as public.
class Rectangle : public Shape
{
    // access to all the protected and public members of Shape class.
    // protected members will remain protected here.
    // public members will remain public here.
public:
    int calcArea()
    {
        return length * width;
    }
};

// Shape class is inherited as protected.
class Cuboid : protected Shape
{
    // access to all the protected and public members of Shape class.
    // all the inherited members converts to protected here.
protected:
    int height; //  protected members can't be accessed directly using objects outside the class.
public:
    void setHeight(int h)
    {
        height = h;
    }
    int calcVolume()
    {
        return length * width * height;
    }
};

// Shape class is inherited as private.
class Circle : private Shape
{
    // access to all the protected and public members of Shape class.
    // all the inherited members are private here so they can't be inherited further using the Circle
    // class itself.
public:
    Circle()
    {
        cout << "Circle class" << endl;
    }
};

int main()
{
    Rectangle rect1;
    rect1.setLength(5);
    rect1.setWidth(2);
    cout << "Area of rectangle: " << rect1.calcArea() << endl;

    Cuboid cub1;
    // cub1.setLength(6);
    // cub1.setWidth(3);
    // setLength() & setWidth() can't be used outside Cuboid class using its object as it is
    // inherited as protected member.
    cub1.setHeight(2);

    Circle cir1;
}

// ACCESS SPECIFIERS tells the level of accessabilty of Base class members in its Derived class.
// If the access specifier is not mentioned while inheriting than it will be inherited as private by default
// in case of classes.

// More Powerful -> Less Powerful : private > protected > public

// ORDER of Constructor Calls if a child class obj is created: first Base class cons and then child class cons.