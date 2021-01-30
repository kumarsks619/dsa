#include <bits/stdc++.h>
using namespace std;

// OPEN ADDRESSING with Linear Probing
struct myHash {
    int *arr;               // address of a location to store keys in continuous memory locations
    int cap, size;          // cap = capacity of the hash table = m     ||      size = slots filled in the hash table


    // CONSTRUCTOR: initializes the hash table
    myHash(int c) {
        cap = c;                            // setting the provided value as the size of the hash table
        size = 0;                           // because initially the hash table is completely empty
        for (int i = 0; i < cap; i++)       // initializing the slots with -1 (flag for empty slot)
            arr[i] = -1;
    }


    // HASH FUNCTION: to hash a key to find its corresponding index in the hash table
    int hash(int key) {
        return key % cap;
    }


    // SEARCH OPERATION: 
    bool search(int key) {
        if (cap == size)                // if the whole hash table is already empty
            return false;

        int h = hash(key);              // calculating the hash for the provided key (its actual index)
        int i = h;
        while (arr[i] != -1) {          // until an empty slot is NOT found  [search operation doesn't stop at a deleted location (flag = -2)]
            if (arr[i] == key)          // if key is found
                return true;
            
            i = (i + 1) % cap;          // transversing the whole array in cyclic manner

            if (i == h)                 // if the whole array is transversed once
                return false;
        }
        return false;                   // if an empty slot (-1) is found
    }


    // INSERT OPERATION:
    bool insert(int key) {
        if (cap == size)                                        // if the hash table is already full
            return false;

        int i = hash(key);                                      // calculating the hash for the provided key (its actual index)
        
        while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)  // finding an empty slot (flag = -1) or a delete slot (flag == -2) or the key itself
            i = (i + 1) % cap;                              // increment the index in cyclic manner and preseve the last value when loop terminates.

        if (arr[i] == key)               // if the loop is terminated because the key to be inserted is already present in hash table
            return false;
        else {                           // else inserting procedure because either an empty slot or a deleted slot is found
            arr[i] = key;                // insert the key            
            size++;                      // increment the occupied slots
            return true;                 // key is successfully inserted
        }
    }


    // DELETE OPERATION:
    bool erase(int key) {
        if (cap == size)                // if the whole hash table is already empty
            return false;

        int h = hash(key);              // calculating the hash for the provided key (its actual index)
        int i = h;                      
        while (arr[i] != -1) {          // until an empty slot is NOT found
            if (arr[i] == key) {        // if the key is found
                arr[i] = -2;            // deleting the key (putting a deleted flag = -2)
                size--;                 // decrementing the occupied slots
                return true;            // deleted successfully
            }
            i = (i + 1) % cap;          // increment the index in circular manner
            if (i == h)                 // if the whole hash table is transversed completely
                return false;           
        }
        return false;                   // if an empty slot is found before finding the key that is to be deleted
    }

    // WHAT IF THE KEY ITSELF IS -1 OR -2
    // for handling -1 (empty slot flag), use NULL instead.
    // for handling -2 (deleted slot flag), a constant reference or pointer to a DUMMY node is stored in the deleted slot instead of -2.
};



int main() {
    myHash myhash(5);

    myhash.insert(99);
    myhash.insert(156);
    myhash.insert(25);
    cout << myhash.search(156) << endl;
    myhash.erase(156);
    cout << myhash.search(156);

    return 0;
}





// n = no. of keys to be inserted       ||      m = no. of slots in the hash table      ||      h(key) = main hashing function

// OPEN ADDRESSING is another way of handling collision.
// It only requires a single array (NO linked lists). Therefore, m >= n.
// It is cache friendly as it stores the data in continuous memory locations.
// Ways of implementing open addressing:-
// 1) Linear Probing    2) Quadratic Probing    3) Double Hashing 


// 1) LINEAR PROBING --- hash(key, i) = [ h(key) + i ] % m
// INSERT: Find hash, if collision occurs then linearly search for an empty slot (cyclicly transverse the array).
// SEARCH: Find the actual hash, if not found there then linearly search the array until the kay is found or an EMPTY slot is found or the array
// is transversed completely in circular manner.
// DELETE: Search in the same manner but do not simply remove the key (if found), instead replace it by DELETED flag. So that it won't cause any
// issue while searching afterwards.
// Issue with Linear Probing: Formation of primary CLUSTERS.


// 2) QUADRATIC PROBING --- hash(key, i) = [ h(key) + i^2 ] % m
// INSERT: Similar to linear probing but when collision happens, search for next slot by increasing the index (hash) quadratic manner (2, 4, 16,..).
// SEARCH: Similar to linear probing but move to the next slot in quadratic manner.
// DELETE: Similar to linear probing but move to the next slot in quadratic manner.
// Issues with Quadratic Probing:   1) All slots won't be covered.      2) Formation of secondary CLUSTERS.


// 3) DOUBLE HASHING ---- hash(key, i) = [ h1(key) + (i * h2(key)) ] % m
// here,  h1(key) = key % m         and         h2(key) = (m-1) - [key % (m - 1)]               <------------------- an example
// INSERT, SEARCH, DELETE : Similary to LP and QP but it moves to next index by computing the above mentioned formula (double hashing).
// Best of these 3 ways as in this method, NO CLUSTERS are formed and keys are uniformly distributed.
// In Linear Probing, h2(key) = 1.
// Algorithm (pseudo code):-
// void doubleHashingInsert (key) {
//      if (TABLE is full)      
//          return error;
//      probe = h1(key), offset = h2(key);
//      while (TABLE[probe] is occupied)
//          probe = (probe + offset) % m;               // keep adding the offset to the probe
//      TABLE[probe] = key;
// }