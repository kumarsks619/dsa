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

// function to insert data at the begin (before the current head) of Circular LinkedList and return the new head.
Node *insertAtBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL) // if the list is empty
    {
        temp->next = temp; // linking back the new Node to itself
        return temp;       // returning the new head
    }

    // STEP 1: inserting the new Node at the second place i.e. after the current head.
    temp->next = head->next;
    head->next = temp;

    // STEP 2: swapping the data of head Node with the newly inserted Node's data
    temp->data = head->data;
    head->data = x;

    return head; // returning the same head but this time has the new data
}

void printCircularLL(Node *head)
{
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;

    cout << "Circular LinkedList before: ";
    printCircularLL(head);

    head = insertAtBegin(head, 5);

    cout << "\nCircular LinkedList after: ";
    printCircularLL(head);

    return 0;
}

// Time Complexity of insertAtBegin(): O(1)