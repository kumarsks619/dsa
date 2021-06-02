#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string name;
    int age;
    double salary;
}; //terminated by ;

int main()
{
    cout << "Enter Person one details: " << endl;
    Person p1, *ptr;
    ptr = &p1;

    cout << "Name: ";
    getline(cin, ptr->name); // taking whole string including spaces. // func of <string>.
    cout << "Age: ";
    cin >> ptr->age;
    cout << "Salary: ";
    cin >> ptr->salary;

    cout << endl;

    cout << "Person P1: " << endl;
    cout << "Name: " << ptr->name << endl;
    cout << "Age: " << ptr->age << endl;
    cout << "Salary: " << ptr->salary << endl;
}

// using Arrow Selection Operator to access structure attributes.
// using pointers we can access different struct objects using the same pointer (ptr = &p1; ptr = &p2).