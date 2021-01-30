#include <bits/stdc++.h>
using namespace std;

struct myHash {
    int BUCKET;             // size of the Hash Table
    list<int> *table;       // creating a Linked List
    myHash(int b) {
        BUCKET = b;
        table = new list<int>[BUCKET];
    }
    // function to create Hash i.e. assigning an index in the range [0, BUCKET-1]
    int hash (int key) {
        return key % BUCKET;
    }
    // function to perform INSERT operation
    void insertKey (int key) {
        int i = hash(key);              // generating hash for the provided key i.e. finding the index in the hash table for its placement
        table[i].push_back(key);        // inserting the key in the array which is present at the found index (hash)
    }
    // function to perform DELETE operation
    void deleteKey (int key) {
        int i = hash(key);              // generating the hash for the provided key
        table[i].remove(key);           // removing the key from the array which is present at the generated hash (index)
    }
    // function to perform SEARCH operation
    bool searchKey (int key) {
        int i = hash(key);              // generating the hash for the provided key
        for (auto x : table[i])         // transversing the whole array which is present at the genrated hash (index)
            if (x == key)               // comparing each of the array elements (keys) with the provided key
                return true;
        return false;
    }
};


int main() {
    myHash myhash(10);                  // creating a hash table of BUCKET size 10
    myhash.insertKey(906);
    cout << myhash.searchKey(906) << endl;
    myhash.deleteKey(906);
    cout << myhash.searchKey(906);

    return 0;
}


// Chaning is a way to handle COLLISIONS (when two or more keys generate the same hash) in the Hash Table.
// In Chaining, we use LINKED LISTS at every index of the Hash Table.
// There is no Hash function that never collides.

// Performance of Chaning:-
// m = no. of slots in the Hash Table = BUCKET
// n = no. of keys to be inserted
// LOAD FACTOR, alpha = n / m
// Expected Chain Length = alpha = the maximum length of the array in any of the slots (indexes) of the Hash Table (only when the hash 
// function generates equally likely hashes for each of the slots.)


// Chaining vs Open Addressing
// 1) In Chaining, hash table NEVER get full.
// 2) In Chaning: Poor caching (linked lists)      ||      In Open Addressing: Cache Friendly (same array)
// 3) Performance of Chaining (no. of comparisons for an operation): 1 + alpha      ||      Open Addressing: 1 / (1 - alpha)
// Therefore, Chaining has better performance (i.e. less number of comparisons)
// 4) Open Addressing: preferred when the no. of keys to be inserted are known in advance.   ||    Chaining: variable no. of keys can be inserted