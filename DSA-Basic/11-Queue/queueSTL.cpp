#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> qu;

    // enqueue() method
    qu.push(10);
    qu.push(20);
    qu.push(30);

    // getSize() method
    cout << "Size: " << qu.size() << endl;

    // transversing through the Queue
    while (qu.empty() == false)
    {
        cout << "First: " << qu.front() << " "
             << "Back: " << qu.back() << endl;
        qu.pop(); // dequeue() method
    }

    cout << "Size: " << qu.size();

    return 0;
}

// In STL, Queue is implemented using DEQUEUE.
// All the methods has Time Complexity: O(1)