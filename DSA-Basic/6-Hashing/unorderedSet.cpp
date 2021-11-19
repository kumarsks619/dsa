#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st;

    // INSERT operation
    st.insert(10);
    st.insert(5);
    st.insert(20);
    st.insert(15);
    st.insert(5); // this insert will be IGNORED as sets do not allow repetition of elements
    st.insert(19);
    st.insert(30);

    // Output may vary on different compilers as unordered sets do NOT mantain any order of elements
    for (int x : st)
        cout << x << " ";

    // Use of .size() --- return the size of the set
    cout << endl
         << "Size: " << st.size() << endl;

    // Use of .find() --- if element found return the iterator of that particular element, else return .end()
    if (st.find(15) != st.end())
        cout << "FOUND";
    else
        cout << "NOT FOUND";

    cout << endl
         << *(st.find(15)) << endl; // de-referencing the found iterator will give that particular element again

    // Use of .count() --- return the count of the element in the set (always return 1 or 0 because an element can't be present more than once in set)
    if (st.count(5))
        cout << "FOUND";
    else
        cout << "NOT FOUND";

    cout << endl;

    // Use of .erase() --- removes the element from the set
    st.erase(20);         // by passing the element itself
    st.erase(st.find(5)); // by passing the iterator of that element

    // Use of .begin() and .end() --- they both return an iterator (an address)     ||    .end() --- returns an iterator beyond the last element
    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it << " ";

    // Use of .clear() --- clears the set
    st.clear();
    st.erase(st.begin(), st.end()); // another way to clear the whole set by using .erase() by passing a range to be removed

    cout << endl
         << "Size: " << st.size() << endl;

    return 0;
}

// UNORDERED_SET uses hashing to store elements therefore, Time Complexity of insert, search and delete is O(1) --- constant time on average.