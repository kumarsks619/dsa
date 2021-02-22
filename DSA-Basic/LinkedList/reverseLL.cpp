#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to reverse a linked list by changing the linking and return the new head
Node * reverseLL(Node *head) {
    Node *prev = NULL;              // prev ptr starts before head
    Node *curr = head;              // curr ptr starts at head
    
    while (curr != NULL) {          // loop till curr ptr reaches beyond the last Node
        Node *next = curr->next;    // to store the address to the Node after curr before changing the links
        curr->next = prev;          // changing the link (ONLY for curr)
        prev = curr;                // shifting the prev ptr a step ahead
        curr = next;                // shifting the curr ptr a step ahead
    }
    return prev;      // when curr reaches beyond last Node, the prev must be at last Node i.e. the new head
}

int main() {
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    head->next->next->next = new Node(20);

    cout << "Linked List before: ";
    for (Node *curr = head; curr != NULL; curr = curr->next)
        cout << curr->data << " ";

    head = reverseLL(head);

    cout << endl << "Linked List after: ";
    for (Node *curr = head; curr != NULL; curr = curr->next)
        cout << curr->data << " ";

    return 0;
}