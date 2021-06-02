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

// function to print the data of the middle Node of a linked list
void printMiddleNode(Node *head)
{
    // if the linked list is empty then do nothing
    if (head == NULL)
        return;

    Node *slow = head, *fast = head; // two pointers to point to a Node
    while (fast != NULL && fast->next != NULL)
    {                            // loop until fast reaches end of the linked list
        slow = slow->next;       // slow moves ahead by one step at a time
        fast = fast->next->next; // fast moves ahead by two steps at a time
    }
    cout << "Middle Node: " << slow->data << endl; // when fast reaches end then slow must be at middle
}

int main()
{
    Node *head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);
    // odd number of Nodes in the linked list
    cout << "Linked List 1st: " << head1->data << " " << head1->next->data << " " << head1->next->next->data << endl;
    printMiddleNode(head1);

    Node *head2 = new Node(3);
    head2->next = new Node(8);
    head2->next->next = new Node(12);
    head2->next->next->next = new Node(17);
    // even number of Nodes in the linked list
    cout << "Linked List 2nd: " << head2->data << " " << head2->next->data << " " << head2->next->next->data << " " << head2->next->next->next->data << endl;
    printMiddleNode(head2);

    return 0;
}