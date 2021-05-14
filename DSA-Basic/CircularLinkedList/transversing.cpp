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

// function to transverse through a Circular LinkedList and print its Nodes.
void printCircularLL(Node *ptr)
{
    if (ptr == NULL) // if list is empty
        return;

    Node *curr = ptr;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != ptr); // till the curr reaches the starting point again
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head; // circularly linking the last Node back to head

    cout << "Circular LinkedList: ";
    printCircularLL(head->next); // any Node ptr can be passed as there is no specific head

    return 0;
}

// All the operations has O(1) Time Complexity when working with CIRCULAR LinkedLists.