#include <iostream>
#include <cstring>

using namespace std;

class Test {
    private:
        string name;
        int age;
    public:
        Test() {
            name = "anonymous";
            age = 0;
        }

        Test(string name, int age) {
            this->name = name;       // good practice to keep the passed parameter name same and use 'this'.
            this->age = age;
        }

        void getName() {
            cout << "name = " << name << endl;
            cout << "this->name = " << this->name << endl;
            cout << "(*this).name = " << (*this).name << endl;
        }

        void getAge() {
            cout << "Age = " << age << endl;
        }

        Test & setName(string name) {
            this->name = name;
            return *this;       // returning the obj to do channing.
        }

        Test & setAge(int age) {
            this->age = age;
            return *this;       // returning the obj to do channing.
        }

};

int main() {
    Test t1("VeNoM", 19);
    t1.getName();

    Test t2;
    t2.setName("Batook").setAge(21);     // 'this' can be used to do function channing.
    t2.getAge();
}

// this keyword is a pointer that stores the address of the current class object.
// this is a constant pointer so changing it will give complier error.
// arrow selection operator (->) is used to access the attributes or methods using pointers.