#include <bits/stdc++.h>
using namespace std;


void bucketSort(int arr[], int n, int k) {
    // STEP 1: finding the largest element in the array to determine the range of values present.
    int maxVal = arr[0];
    for (int i = 0; i < n; i++)
        maxVal = max(arr[i], maxVal);

    maxVal += 1;                // incrementing the maxVal by 1 so that bucketIndex will aways fall in range [0, k-1]

    // STEP 2: creating buckets and distributing the elements among these buckets.
    vector<int> bucket[k];                              
    for (int i = 0; i < n; i++) {                           // transversing through the main array
        int bucketIndex = (k * arr[i]) / maxVal;            // finding the appropriate bucket for an element
        bucket[bucketIndex].push_back(arr[i]);              // putting the element into that particular bucket
    }

    // STEP 3: sorting each bucket individually one by one.
    for (int i = 0; i < k; i++)                             // loop to target one bucket at a time
        sort(bucket[i].begin(), bucket[i].end());           // sorting buckets individually  (use INSERTION sort when bucket is small)

    // STEP 4: contcatenating the buckets (containing sorted elements) together inside the main array.
    int index = 0;
    for (int i = 0; i < k; i++)                             // transversing through the array the array of buckets
        for (int j = 0; j < bucket[i].size(); j++)          // transversing inside a bucket
            arr[index++] = bucket[i][j];                    // putting elements inside the main array
}


int main() {
    int vals[] = { 55, 19, 92, 37, 10, 4, 56, 83, 27, 69 };
    int size = sizeof(vals) / sizeof(vals[0]);
    int numOfBuckets = 5;                           // providing the number of buckets to distribute the array elements among these

    bucketSort(vals, size, numOfBuckets);
    for (int i = 0; i < size; i++)
        cout << vals[i] <<  " ";

    return 0;
}


// Working principle: re-distribute the given array elements in various ranges (sub-arrays) and then sort those sub-arrays invidually and
// finally put them together to form the main sorted array.
// BEST CASE: when the array elemets are uniformly distributed over the range : [Time Compelxity: O(n)] - when used insertion sort (small sub-arrays)
// WORST CASE: when the array elements are non-uniformly distributed over the range, then in such case when the elements are re-distributed
// in various buckets then all (mostly all) of the elements fall inside the same bucket: [Time Complexity: O(nlogn)] - when O(nlogn) algo is used.
// DON'T use insertion sort when the sub-arrays are large (as in worst case) because it will take O(n^2) time.