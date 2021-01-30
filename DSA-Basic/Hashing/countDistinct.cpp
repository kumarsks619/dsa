#include <bits/stdc++.h>
using namespace std;

int countDistinct(int arr[], int n) {
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(arr[i]);
    
    return st.size(); 
}

int main() {
    int vals[] = { 9, 7, 0, 10, 2, 7, 0, 17, 9, 19 };
    int size = sizeof(vals) / sizeof(vals[0]);

    cout << "Total number of elements: " << size << endl;
    cout << "Number of distinct elements: " << countDistinct(vals, size);

    return 0;
}