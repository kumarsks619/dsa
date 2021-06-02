#include <iostream>

using namespace std;

int main()
{
    cout << "Enter numerator and denominator: " << endl;
    int numerator, denominator;
    cin >> numerator >> denominator;

    try
    {
        if (denominator == 0)
        {
            throw denominator; // when throw occurs, programme control is passed to catch block
        }
        int result = numerator / denominator;
        cout << "Division result: " << result;
    }
    catch (int exception)
    { //whatever being thrown is caught here with the data-type
        cout << "Error: Divide by " << exception << " error.";
    }
}

// try-catch-throw all works together.
// single try block can have multiple catch blocks.
// throw is necessary to pass the control to catch block.