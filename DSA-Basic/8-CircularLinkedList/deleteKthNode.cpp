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

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

// function to delete the Kth Node from a Circular LL and return the new head (assuming K<=Num of Nodes)
Node *deleteKthNode(Node *head, int k)
{
    // CORNER CASE 1
    if (head == NULL)
        return NULL;

    // CORNER CASE 2: head will change
    if (k == 1)
        return deleteHead(head);

    Node *curr = head;
    for (int i = 1; i <= k - 2; i++) // looping till the the Node just before the Node to be deleted
        curr = curr->next;

    // process of deleting the desired Node
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head; // returning the same head
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;

    cout << "Circular LinkedList before: ";
    printCircularLL(head);

    head = deleteKthNode(head, 3);

    cout << "\nCircular LinkedList after: ";
    printCircularLL(head);

    return 0;
}