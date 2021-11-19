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

Node *insertAtPos(Node *head, int pos, int data)
{
    Node *temp = new Node(data); // creating a new Node for the new data
    // if the new Node is to be inserted at first postion
    if (pos == 1)
    {
        temp->next = head;
        return temp; // then the head of the linked list will change
    }

    Node *curr = head;
    for (int i = 1; i <= pos - 2 && curr != NULL; i++) // looping to the Node at pos-1 until the end of linked list
        curr = curr->next;
    // if the position is beyond size+1 of the linked list
    if (curr == NULL)
        return head; // then do nothing
    // else inserting the Node
    temp->next = curr->next; // STEP 1       (order matters)
    curr->next = temp;       // STEP 2        (order matters)
    return head;             // returning the same head
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);

    cout << "LinkedList before: " << head->data << " " << head->next->data << " " << head->next->next->data << endl;
    head = insertAtPos(head, 3, 13);
    cout << "LinkedList after: " << head->data << " " << head->next->data << " " << head->next->next->data << " " << head->next->next->next->data;

    return 0;
}