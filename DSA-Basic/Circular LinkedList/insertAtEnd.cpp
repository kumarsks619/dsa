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

void printCircularLL(Node *head)
{
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

// function to insert data at the end (beyond the tail Node) of Circular LinkedList and return the new head.
Node *insertAtEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL) // if the list is empty
    {
        temp->next = temp;
        return temp;
    }

    // STEP 1: inserting the new Node at second position
    temp->next = head->next;
    head->next = temp;

    // STEP 2: swapping the data of head Node with the newly inserted Node's data
    temp->data = head->data;
    head->data = x;

    // STEP 3: returning the second Node ptr as the new head, then second Node will be treated as the starting point.
    return temp;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;

    cout << "Circular LinkedList before: ";
    printCircularLL(head);

    head = insertAtEnd(head, 40);

    cout << "\nCircular LinkedList after: ";
    printCircularLL(head);

    return 0;
}

// Time Complexity of insertAtEnd(): O(1)