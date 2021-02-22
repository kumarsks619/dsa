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

// METHOD 1: recursive function to reverse a linked list and return the new head
Node *recursiveReverseLL(Node *head)
{
    // BASE CASE:
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest_head = recursiveReverseLL(head->next); // recursively calling for remaining linked list
    // getting hold of the tail of the reversed linked list by using the earlier head
    Node *rest_tail = head->next; // earlier rest_tail = NULL

    // now linking the left out head with the reversed linked list
    rest_tail->next = head;
    head->next = NULL;
    return rest_head; // returning the new head of the reversed linked list
}

// METHOD 2: recursive function to reverse a linked list and return the new head
Node *tailRecursiveReverseLL(Node *curr, Node *prev)
{
    // BASE CASE:
    if (curr == NULL) // when current reaches beyond last Node (curr = NULL)
        return prev;  // then prev must be at the last Node i.e. the new head

    Node *next = curr->next;                   // getting hold of the next Node before reversing the link so that it won't get lost
    curr->next = prev;                         // revsering the link
    return tailRecursiveReverseLL(next, curr); // calling recursively by shifting both prev and curr one step ahead
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    head->next->next->next = new Node(20);

    cout << "Linked List before: ";
    for (Node *curr = head; curr != NULL; curr = curr->next)
        cout << curr->data << " ";

    head = recursiveReverseLL(head);

    cout << endl
         << "Linked List reverse by Method I: ";
    for (Node *curr = head; curr != NULL; curr = curr->next)
        cout << curr->data << " ";

    head = tailRecursiveReverseLL(head, NULL);

    cout << endl
         << "Linked List reverse by Method II: ";
    for (Node *curr = head; curr != NULL; curr = curr->next)
        cout << curr->data << " ";

    return 0;
}

// METHOD 1: recursiveReverseLL() works as:  head -> | NULL <- rest_tail <- Node <- Node <- rest_head
// In method 1, LAST (n-1) Nodes are reversed first and then the earlier head (1st Node) is linked to it.

// METHOD 2: tailRecursiveReverseLL() works as: NULL <- head <- Node <- Node | Node -> Node -> Node -> NULL
// In method 2, FIRST (n-1) Nodes are reversed and then the earlier tail (last Node) is linked to it.