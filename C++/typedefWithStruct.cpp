#include <bits/stdc++.h>
using namespace std;

// creating a typedef for Student structure.
typedef struct Student {
    string name;
    int rollno;
    char section;
} Std;  // now Std can be used in place of Student.

int main() {
    Std s1;     // same as: struct Student s1; or Student s1; // but struct Std s1; will give error.
    cout << "Enter details: " << endl;
    getline(cin, s1.name);
    cin >> s1.rollno >> s1.section;

    cout << s1.name << endl << s1.rollno << endl << s1.section;

    return 0;
}