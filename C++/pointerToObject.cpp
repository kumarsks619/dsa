#include <iostream>
#include <string>

using namespace std;

class Boy {
    private:
        string name;
        int age;
    public:
        void setBoy(string n, int a) {
            name = n;
            age = a;
        }

        void getBoy() {
            cout << "Name: " << name << " || Age: " << age << endl;
        }

};

int main() {
    Boy *ptr, b1, b2;

    ptr = &b1;
    ptr->setBoy("Shubham", 21);
    ptr->getBoy();

    ptr = &b2;
    ptr->setBoy("VeNoM", 21);
    ptr->getBoy();
    
}

// same pointer can be used to point different objects and access their properties.
// Arrow Selection is used while using pointer to access class properties.