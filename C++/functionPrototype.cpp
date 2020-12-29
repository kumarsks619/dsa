#include <iostream>

using namespace std;

int calcVol(int l, int b = 1, int h = 1);   //function prototype

int main() {
    cout << calcVol(5, 4, 2) << endl;
    cout << calcVol(2, 5);
}


int calcVol(int l, int b, int h){
    return l * b * h;
}

// to define the function after main() then we have to define function prototype
// default arguements are mentioned in the prototype, NOT in the function definition.
// TRAILING parameters can ONLY be made default.

// Functions support MODULARITY, which means reusability and breaking down of code in smaller
// components and then re-combining them together to produce the programme.