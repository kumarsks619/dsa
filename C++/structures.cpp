#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int age;
    double salary;

    // Person() {       // struc can also have a constructor.
    //     name = "";
    //     age = 0;
    //     salary = 0;
    // }

    void displayPerson() {
        cout << "Name: " << name << " Age: " << age << " Salary: " << salary << endl;
    }
};  //terminated by ;


int main() {
    cout << "Enter Person one details: " << endl;
    Person p1;      // same as: struct Person p1;   // struct keyword while creating struct var is optional.
    cout << "Name: ";
    cin >> p1.name;
    cout << "Age: ";
    cin >> p1.age;
    cout << "Salary: ";
    cin >> p1.salary;

    cout << endl;

    cout << "Person P1: " << endl;
    cout << "Name: " << p1.name << endl;
    cout << "Age: " << p1.age << endl;
    cout << "Salary: " << p1.salary << endl;

    // initialization of a structure object
    Person p2 = {"Batook", 21, 50000};  // order must be same as that in structure definition.
    p2.displayPerson();

    // Person p3 = {.name = "Bubble", .age = 22, .salary = 50000};      this way work in C but not in C++

}

// Structures are same as Classes but in struct data members are public by default.
// Structures can always be used in place of classes. But not preferred.

// Structures also show inheritance.
// Like classes, there is also constructor and destructor functions in structures.
// If the type of inheritence is not specified than it will be public by default in case of structures.