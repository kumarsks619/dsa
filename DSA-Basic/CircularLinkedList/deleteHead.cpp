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

// function to delete head Node from a Circular LL and return the new head
Node *deleteHead(Node *head)
{
    // CORNER CASE 1
    if (head == NULL)
        return NULL;

    // CORNER CASE 2
    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    // STEP 1: copying data of second Node in first (head) Node
    head->data = head->next->data;

    // STEP 2: deleting the second Node
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;

    // STEP 3: returning the same head again as the new head
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;

    cout << "Circular LinkedList before: ";
    printCircularLL(head);

    head = deleteHead(head);

    cout << "\nCircular LinkedList after: ";
    printCircularLL(head);

    return 0;
}

// Time Complexity of deleteHead(): O(1)