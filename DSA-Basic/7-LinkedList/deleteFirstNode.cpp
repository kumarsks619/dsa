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

// function to delete the first Node of a LinkedList and return the new head of the modified LinkedList
Node *deleteFirstNode(Node *head)
{
    if (head == NULL)           // if the list is already empty
        return NULL;            // then do nothing and return the same head i.e. NULL
    Node *newHead = head->next; // storing the next of the 2nd Node for later return
    delete head;                // de-allocating the memory of 1st Node
    return newHead;             // returning the ptr to the 2nd Node.
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "LinkedList before: " << head->data << " " << head->next->data << " " << head->next->next->data << endl;
    head = deleteFirstNode(head);
    cout << "LinkedList after: " << head->data << " " << head->next->data << " ";

    return 0;
}