#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq = {10, 20, 30}; // initializing the Dequeue with some values

    dq.push_front(5); // pushing new data from front
    dq.push_back(40); // pushing new data from back

    // way 1 to transverse through the Dequeue
    cout << "1st Print: ";
    for (auto x : dq)
    {
        cout << x << " ";
    }

    // getFront and getBack methods, these methods didn't modify the Dequeue itself.
    cout << endl
         << "Front: " << dq.front() << "  Back: " << dq.back() << endl;

    auto it = dq.begin(); // method to get an iterator for the Dequeue that starts  from FIRST element
    it++;                 // incrementing to point to 2nd element.
    dq.insert(it, 7);     // method to insert new data just BEFORE the provided iterator

    cout << "2nd Print: ";
    for (auto x : dq)
    {
        cout << x << " ";
    }

    dq.pop_front(); // removing from the front
    dq.pop_back();  // removing from the back

    cout << endl
         << "After popping, now the iterator is STILL pointing to: " << *it;

    cout << endl
         << "Size: " << dq.size() << endl; // method to getSize (no. of elements) of the Dequeue

    it = dq.insert(it, 19);    // insert() method can also return a iterator to its LAST insert
    it = dq.insert(it, 2, 80); // insert() method can be also used to insert same item but multiple times
    // here inserting '80' two times and returning the iterator to its last insert i.e. 2nd '80'.

    // way 2 to transverse through the Dequeue
    cout << "3rd Print: ";
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " "; // by this way, Dequeue can also be altered like dq[i] = newValue
    }

    it = dq.erase(it); // erase() method  deletes an element to which the provided iterator is pointing and
    // returns the iterator pointing to just the PREVIOUS of the element that is being deleted.
    it = dq.erase(it, dq.end()); // erase() method can be used to deleted multiple values
    // like: erase(star, end) where end value is EXCLUDED (end() points beyond the last element).

    cout << "\n4th Print: ";
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }

    cout << endl
         << "Iterator points to: " << *it << endl; // the iterator may point to a DELETED element also

    return 0;
}

// Time Complexity of all the methods (expect insert() & erase()): O(1)
// Time Complexity of insert() & erase(): O(N)