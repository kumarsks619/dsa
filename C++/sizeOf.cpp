#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char c;
    cout <<"char " << sizeof(c) << endl;

    int a;
    cout <<"int " << sizeof(a) << endl;

    float b;
    cout <<"float " << sizeof(a) << endl;

    float d;
    cout <<"double " << sizeof(a) << endl;

    string e;
    cout << "string " << sizeof(string) << endl;

    //finding length of an array using sizeof()
    int arr[10];
    cout << "array length:" << sizeof(arr) / sizeof(arr[0]) << endl;

}
 