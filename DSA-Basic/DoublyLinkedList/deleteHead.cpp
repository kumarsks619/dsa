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

Node *deleteHead(Node *head)
{
    // CORNER CASE 1: when linkedlist is already empty
    if (head == NULL)
        return NULL;

    // CORNER CASE 2: when linkedlist contains only single Node
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *temp = head;
    head = head->next; // shifting the head ahead
    head->prev = NULL; // breaking the link from the prev head
    delete temp;       // deleting the prev head
    return head;       // returning the new head
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

    head = deleteHead(head);

    cout << "\nDoubly LinkedList after: ";
    printDLL(head);

    return 0;
}

// Time Complexity of deleteHead(): O(1)