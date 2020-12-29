#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4};
    int size  = *(&arr + 1) - arr;
    int sum = 0;
    sum = accumulate(arr, arr + size, sum); // initial value of sum is a mandatory parameter.
    cout << sum;

    return 0;
}

// this is a direct way to find sum of array elements.
// can be used with vectors too.    sum = accumulate(vec1.begin(), vec1.end(), sum);