#include <bits/stdc++.h>
using namespace std;

int avgArray(int arr[], int size) {
    if(size == 0) {
        throw string("Size of passed array can't be zero !!!");
    }else {
        return accumulate(arr, arr + size, 0) / size;
    }
}


int main() {
    int valsArr[] = {10, 20, 50, 70, 30};
    try {
        int avg = avgArray(valsArr, 5);
        cout << "Average of array = "<< avg << endl;
    }catch(string err) {
        cout << err << endl;
        cout << "Doing clean up operations..." << endl;
    }catch(...) {
        cout << "Default catch." << endl;
    }

    cout << "Programe executed successfully !";

    return 0;
}