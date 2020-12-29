#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec1;   // initializing vector
    cout << "Enter size of vector: ";
    int size;
    cin >> size;
    for(int i = 0; i < size; i++) {
        int val;
        cin >> val;
        vec1.push_back(val);    // adding elements to vector
    }

    // WAYS of Transversing through vector:
    for(int i = 0; i < vec1.size(); i++) {  // by using size() function of vector
        cout << vec1[i] << ",";
    }
    cout << endl;

    vector<int> vec2(5, 1);     // initialing vector of size 5 with all ements having 1 as default value.

    for(auto x: vec2) {     // using foreach loop   // auto is data type which detects data type automatically.
        cout << x << ",";
    }
    cout << endl;

    vector<int> vec3{5, 6, 1, 8};   // initalizing like normal arrays.

}