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

void removeDuplicates(Node *head)
{
    Node *curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;       // storing the ptr to free the memory later
            curr->next = curr->next->next; // changing the current's next one step ahead
            delete (curr->next);           // freeing the memory
        }
        else
        {
            curr = curr->next; // only place where curr itself shifts one step ahead
        }
    }
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(10);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(15);
    head->next->next->next->next->next = new Node(15);

    cout << "Linked List before: ";
    for (Node *curr = head; curr != NULL; curr = curr->next)
        cout << curr->data << " ";

    removeDuplicates(head); // the function's return type is void as the head will never
                            // change so no need to return any new head.

    cout << "\nLinked List after: ";
    for (Node *curr = head; curr != NULL; curr = curr->next)
        cout << curr->data << " ";

    return 0;
}

// Problem Statement: WAF to remove duplicates from a linked list. (The duplicates occurs consecutively)