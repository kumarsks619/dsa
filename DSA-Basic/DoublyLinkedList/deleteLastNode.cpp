#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;
    Node(int x)
    {
        data = x;
        prev = next = NULL;
    }
};

void printDLL(Node *head)
{
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != NULL);
}

Node *deleteLastNode(Node *head)
{
    // CORNER CASE 1: if linkedlist is empty
    if (head == NULL)
        return NULL;

    // CORNER CASE 2: if linkedlist contains only single Node
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    // iterating to the last Node
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    // making the next of second last Node to be NULL (basically breaking the link from the last Node)
    curr->prev->next = NULL;
    // freeing up the memory occupied by the last Node
    delete curr;
    // returning the same head
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
    printDLL(head);

    head = deleteLastNode(head);

    cout << "\nDoubly LinkedList after: ";
    printDLL(head);

    return 0;
}

// Time Complexity of deleteLastNode(): O(n)