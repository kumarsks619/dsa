#include <iostream>

using namespace std;

int main()
{
    int arr1[5] = {4, 7, 3}; //put zero for left out values
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << ",";
    }

    cout << endl;

    int arr2[5]; //put garbage values
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << ",";
    }

    // some other ways of initializing arrays
    int arr3[] = {2, 5, 6};
    int arr4[]{2, 8, 9};
    int arr5[5] = {0}; // trick to initialize all elements with 0.
    int arr6[5] = {1}; // trick will not work in this case. Here only arr6[0] = 1 and other will have zeros.

    return 0;
}

// In case of LOCAL Variables:
// if array is not provided with all its values while initializing it then it will put zero at the remaining places.
// But if none of the array elements are initialized then all the array elements will get random values.