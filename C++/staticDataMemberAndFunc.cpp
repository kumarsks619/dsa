#include <iostream>

using namespace std;

class Student {
    private:
        int marks;
        static int count;   // a static data member.
    public:
        Student() {
            count++;
        }
        static int getCount() {     // a static member function.
            return count;           // can only access static data member.
        }
};

// initialization of a static data member must be done outside the class.
int Student::count = 0;

int main() {
    Student s1, s2, s3;

    cout << "No. of Student Objects created: " << Student::getCount(); //static func is called without obj.
}

// Static Data Member is same for all the objects of that class. (only one value throught all objects)
// Static Data Member can be accessed without obj if they are declared under public section.(Student::count)
// Static Data Member can be accessed by other member functions but this is NOT a good practice.

// Static Member Function can ONLY access static data members  and static member functions.
// Static Member functions can't have 'this' pointer as it is independent of objects.
// Static Member function is accessed without any object.
// Static Member functions can also be accessed using obj (s1.getCount()) but it is NOT a good practice.