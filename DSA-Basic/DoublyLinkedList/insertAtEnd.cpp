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
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != NULL);
}

Node *insertAtEnd(Node *head, int x)
{
    Node *temp = new Node(x);

    // CORNER CASE: only in this case, the head will change
    if (head == NULL)
        return temp;

    // STEP 1: looping till the last Node
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    // STEP 2: linking the new Node (both with next and prev)
    curr->next = temp;
    temp->prev = curr;

    // STEP 3: returning the same head
    return head;
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

    head = insertAtEnd(head, 40);

    cout << "\nDoubly LinkedList after: ";
    printDoublyLL(head);

    return 0;
}

// Time Complexity of insertAtEnd(): O(n)