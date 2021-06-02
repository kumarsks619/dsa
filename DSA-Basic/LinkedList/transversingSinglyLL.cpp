#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// function to display LinkedList's elements
void displayLL(Node *head)
{
    Node *curr = head; // head stores the address of the first Node OBJECT
    while (curr != NULL)
    {
        cout << curr->data << " "; // accessing the data from the POINTER to the particular Node OBJECT
        curr = curr->next;         // moving the curr to next Node address
    }
}

// function to display LinkedList's elements recursively
void displayLLRecursive(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    displayLLRecursive(head->next);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    displayLL(head);
    cout << endl;
    displayLLRecursive(head);

    return 0;
}

// the head ptr passed to the displayLL() function works with its OWN COPY of the head ptr so if it is changed inside the function body
// then it won't affect the main head ptr. So we can also minimize the code for displayLL() function by eleminating the curr ptr and then
// modifying the head ptr directly to store next addresses.

// Time Complexity of both the display() functions: O(n)
// Auxiliary Space required by Recursive method: O(n) to store function call stack.
// Therefore, iterative display() method is better.