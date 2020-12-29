#include <iostream>

using namespace std;

class Distance {
    private:
        int meters;
    public:
        Distance() {
            meters = 0;
        }
        void getDist() {
            cout << "Meters: " << meters << endl;
        }

        friend void incrementDist(Distance &d); // prototype for the friend function
};

// definition of friend function
void incrementDist(Distance &d) {
    d.meters = d.meters + 5;
}


int main() {
    Distance d1;
    d1.getDist();

    incrementDist(d1);     // no object needed to call this friend function. (d1.incrementDist(d1))
    d1.getDist();
}

// Friend function is used when we want to access the data members of a class without using any obejct.
// Friend function's prototype must lie inside the class body under ANY(public/private) section.
// Friend function have full access of all the members of the respective class. 

// Friend functions and classes are against OOP concept of Abstraction (Data-hiding).