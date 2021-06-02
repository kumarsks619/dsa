#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter two values: ";
    int x, y;
    cin >> x >> y;

    try
    {
        if (x == 0)
        {
            throw int(0);
        }
        if (y == 0)
        {
            throw string("y is zero");
        }
        if (x * y < 0)
        {
            throw double(x * y); // this will throw a double data type error so it will be caught by
            // default catch block as there is no catch block specific to catch double.
        }

        cout << "x/y =" << x / y;
    }
    catch (int err)
    {
        cout << "x is " << err;
    }
    catch (string err)
    {
        cout << err;
    }
    catch (...)
    { // by using ... we can create a default catch block.
        cout << "Default catch block.";
    }

    cout << endl
         << "Programme executed successfully !";

    return 0;
}

// Default catch block must be created after all other catch blocks else it will not allow the errors to reach
// their specific catch blocks. This will also give Syntax error.

// only one catch block is executed for one try block.
// throw immediately sends the control to the corresponding catch block.