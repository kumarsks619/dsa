#include <iostream>

using namespace std;

class ComplexNumber {   
    private:
        int real, imaginary;
    public:
        // constructor
        ComplexNumber(int r, int img) {
            real = r;
            imaginary = img;
        }

        int getRealPart() {
            return real;
        }

        int getImgPart() {
            return imaginary;
        }

        void displayCompNum() {
            cout << real << " + " << imaginary << "i" << endl;
        }
}; 

// a normal function whose return-type is ComplexNumber
ComplexNumber add2CompNum(ComplexNumber n1, ComplexNumber n2) {
    int real = n1.getRealPart() + n2.getRealPart();
    int imaginary = n1.getImgPart() + n2.getImgPart();

    ComplexNumber result(real, imaginary);
    return result;
}


int main() {
    ComplexNumber num1(2, 3), num2(4, 5);
    num1.displayCompNum();
    num2.displayCompNum();

    ComplexNumber num3 = add2CompNum(num1, num2);   //here default copy constructor is called which 
    // copies the object returned by the add function to num3 object.
    cout << "Sum: ";
    num3.displayCompNum();    
}