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

// function to insert new Node in sorted linked list at its correct position and return the head (or new head)
Node * insertSorted(Node *head, int data) {
    Node *temp = new Node(data);
    // if the linked list is empty i.e. head=NULL
    if (head == NULL) {
        return temp;       // return the new head (changed)
    }

    // if the correct position of the data to be inserted is at the head Node i.e. head->data > data
    if (head->data > data) {
        temp->next = head;
        return temp;        // return the new head (changed)
    }

    // else
    Node *curr = head;
    while (curr->next != NULL && curr->next->data < data) //looping to find the correct position
        curr = curr->next;
    // inserting the new Node at the found correct position
    temp->next = curr->next;
    curr->next = temp;
    return head;                // return the old head (not changed)
}

int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "LinkedList before: " << head->data << " " << head->next->data << " " << head->next->next->data << endl;
    head = insertSorted(head, 25);
    cout << "LinkedList after: " << head->data << " " << head->next->data << " " << head->next->next->data << " " << head->next->next->next->data;

    return 0;
}