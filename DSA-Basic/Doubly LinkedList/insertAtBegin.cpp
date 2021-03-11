#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = next = NULL;
    }
};

void printDoublyLL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// function to insert new Node before head and return the new head
Node *insertAtBegin(Node *head, int x)
{
    Node *temp = new Node(x);

    // CORNER CASE
    if (head == NULL)
        return temp;

    // inserting the new Node
    temp->next = head;
    head->prev = temp;
    return temp;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    cout << "Doubly LinkedList before: ";
    printDoublyLL(head);

    head = insertAtBegin(head, 5);

    cout << "\nDoubly LinkedList after: ";
    printDoublyLL(head);

    return 0;
}

// In Doubly LinkedList following operations can be done in O(1) time:
// 1) New Node can be inserted just before a given Node.
// 2) A Node can be deleted from a position just before a given Node.
// 3) A given Node can be deleted directly.