#include <iostream>
using namespace std;

int main()
{
    if (1 > 2 || 7 > 5 && 3 > 5)
    {
        cout << "Inside if" << endl;
    }
    else
    {
        cout << "Inside else" << endl;
    }

    return 0;
}

// && evaluates first