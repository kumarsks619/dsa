#include <iostream>
#include <string>

using namespace std;

class Car {
    private:
        string companyName;
        string modelName;
        float mileage;
        double price;
    public:
        //DEFAULT CONSTRUCTOR
        Car() {
            cout << "Default Constructor called !!!" << endl;
        }
        //PARAMETRIZED CONSTRUCTOR
        Car(string cName, string mName, float mil, double p) {
            cout << "Parameterized Constructor called !!!" << endl;
            companyName = cName;
            modelName = mName;
            mileage = mil;
            price = p;
        }
        //COPY CONSTRUCTOR - takes reference of an object.
        Car(Car &obj) {     // obj to be copied must be passed as ref otherwise it will again call a copy
            // constructor to make its own copy and which will lead to a non-terminating loop.
            cout << "Copy Constructor called !!!" << endl;
            companyName = obj.companyName;
            modelName = obj.modelName;
            mileage = obj.mileage;
            price = obj.price;
        }
        
        //SETTER METHOD
        void setData(string cName, string mName, float mil, double p) {
            companyName = cName;
            modelName = mName;
            mileage = mil;
            price = p;
        }
        //GETTER METHOD
        void getData() {
            cout << "Company Name: " << companyName << endl;
            cout << "Model Name: " << modelName << endl;
            cout << "Mileage: " << mileage << endl;
            cout << "Price: " << price << endl;
        }

        //DESTUCTOR - automaticaly gets called when the scope of the current object ends.
        ~Car() {
            cout << "Destructor called for " << objNum << " !!!" << endl;
        }

        int objNum;         // to assign nth for an object.

};  //terminated by ;


int main() {
    Car c1;
    c1.setData("Lamborghini", "Galardo Spider", 14.7, 109999);
    c1.getData();

    cout << endl;

    Car c2("Default Company Name", "Default Model Name", 0.00, 0);
    c2.getData();

    cout << endl;

    Car c3 = c1;    // copy constructor will be called. Same as: Car c3(c1);
    // Car c3;  c3 = c1;    // this is NOT a copy constructor call. This will first call default constructor
    // and then simple assignment of corresponding data members without any error.
    c3.getData();

    cout << endl;

    // just to check the order of destructor calls.
    c1.objNum = 1;
    c2.objNum = 2;
    c3.objNum = 3;

    return 0;
}

// Types of Constructor:-
// 1) Default Constructor
// 2) Parameterized Constructor
// 3) Copy Constructor - no need to manually create this contructor unless we want to do some 
//     modifications while copying values from other object to the current object.
// Copy Constructor is provided with the class by default which does shallow copy (NOT deep copy). So, when
// working with ptrs inside classes we shoudl create our own copy constructor to do deep copy.

// Class data members are private by default.
// Constructors & Destructors DON'T have a return.
// Whenver an object is created, its corresponding constructor is ALWAYS called ( same with the Destructor).


// NOTICE the order of Destructor calls: in the same scope, by default, the obj created FIRST is destructed LAST.
// There must be ONLY one Destructor in a class.
// Destructors are also provided by the complier but in case of dynamic memory allocations inside the class, we
// must create our custom destructor to deallocate the memory.