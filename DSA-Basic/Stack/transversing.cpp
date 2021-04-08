#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    // .push() inserts an element on the top of the Stack
    st.push(10);
    st.push(20);
    st.push(30);

    // .size() returns the count of elements in the Stack
    cout << "Stack size: " << st.size() << endl
         << "Stack: ";

    // .empty() returns true when the Stack is empty
    while (st.empty() == false)
    {
        cout << st.top() << " "; // .top() returns the topmost element in the Stack
        st.pop();                // .pop() removes the topmost element from the Stack
    }

    cout << "\nStack size: " << st.size();

    return 0;
}

// Stack is LIFO (Last In First Out) data structure.
// On Stack: .push(), .pop(), .top(), .size(), .empty() ---> Time Complexity = O(1)
// Stacks can be implemented using: Arrays, Vectors or Dequeue (In STL, Dequeue impelemantion is used)
// In Singly LinkedList implementation of Stack: push() and pop() both happens at the head as pop()
// operation can't be done at the end of the LL, even we maintain a tail ptr.
