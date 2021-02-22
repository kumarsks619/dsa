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

// function to insert at the end of a LinkedList and return the new head if the list is already empty, otherwise return the old head
Node * insertAtEnd(Node *head, int val) {
    Node *newHead = new Node(val);          // creating a new Node with the value
    if (head == NULL)                       // checking if the head is already NULL i.e. list is empty
        return newHead;                     // then return the new head

    Node *curr = head;                          
    while (curr->next != NULL)              // otherwise, iterating to the last Node to get its address
        curr = curr->next;

    curr->next = newHead;                   // inserting the address of the new Node at next of the found last Node
    
    return head;                            // returning the older head
}


int main() {
    Node *head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    cout << "LinkedList: " << head->data <<  " " << head->next->data << " " << head->next->next->data;

    return 0;
}