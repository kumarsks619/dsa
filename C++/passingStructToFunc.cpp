#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int standard;
    char section;
    int rollno;
}; // terminated by semi-colon.

// Passing struct directly will create copy and will take more memory and CPU time.
void displayStd(Student std)
{
    cout << "Normally Passing Structure: ";
    cout << std.name << " " << std.standard << " " << std.section << " " << std.rollno << endl;
}

// Passing as ref will save memory by NOT creating copy of the struct.
void displayStdRef(const Student &std)
{
    cout << "Passing Structure as Reference: ";
    cout << std.name << " " << std.standard << " " << std.section << " " << std.rollno << endl;
}

// Passing as ptr will also save memory by NOT creating copy of the struct.
void displayStdPtr(const Student *ptr)
{
    cout << "Passing Structure as Pointer: ";
    cout << ptr->name << " " << ptr->standard << " " << ptr->section << " " << ptr->rollno << endl;
}

int main()
{
    Student std1 = {"Shubham Kumar Singh", 12, 'A', 54};
    displayStd(std1);
    displayStdRef(std1);

    Student *ptrStd;       // creating pointer for pointing Student struct.
    ptrStd = &std1;        // assinging the address of struct var to ptr.
    displayStdPtr(ptrStd); // direct way:  displayStdPtr(&std1);

    return 0;
}