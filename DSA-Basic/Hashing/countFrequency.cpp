#include <bits/stdc++.h>
using namespace std;

void countFrequency(int arr[], int n) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;             // inserting as key, if not present and then increment the value count each time same key is encountered.

    for (auto x : mp)
        cout << x.first << " : " << x.second << endl;
}


int main() {
    int vals[] = { 9, 7, 0, 10, 2, 7, 0, 17, 9, 19 };
    int size = sizeof(vals) / sizeof(vals[0]);

    countFrequency(vals, size);

    return 0;
}