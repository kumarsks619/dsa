#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> mp;

    // INSERT operations
    mp["gfg"] = 10;
    mp.insert({ "ide", 20 });       // Use of .insert({ key, value })
    mp["gfg"] = 30;                 // over-writes the previous key
    mp["code"] = 404;

    // Transversing the Unordered Map (output => any order as it is an ordered map)
    for (auto i : mp)
        cout << i.first << " : " << i.second << "   ";

    cout << endl;

    // Another way to transverse an Unordered map
    for (auto it = mp.begin(); it != mp.end(); it++) 
    // for (auto it = mp.rbegin(); it != mp.rend(); it++)   // use to transverse in reverse order but it is of NO use in Unordered Map
        cout << it->first << " : " << it->second << "   ";
    

    cout << endl;

    // SEARCH operation --- use of .find()
    auto it = mp.find("gfg");
    if (it != mp.end())
        cout << "FOUND, value = " << it->second <<endl;
    else
        cout << "NOT FOUND" << endl;

    // Another way to do SEARCH operation --- use of .count()
    if (mp.count("ide") > 0)
        cout << "FOUND" << endl;
    else
        cout << "NOT FOUND" << endl;

    // Use of .size() --- returns the number of key-value pairs present in the map
    cout << "Size: " << mp.size() << endl;

    // DELETE operation --- use of .erase()
    mp.erase("gfg");
    mp.erase(mp.find("ide"));               // an iterator can also be passed to the .erase() function
    mp.erase(mp.begin(), mp.end());         // a range can also be passed to the .erase() function

    cout << "Size: " << mp.size() << endl;

    return 0;
}

// UNORDERED_MAP uses hashing to store elements therefore, Time Complexity of insert, search and delete is O(1) --- constant time on average.
