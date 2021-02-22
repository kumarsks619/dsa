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

Node * deleteLastNode(Node *head) {
    // if the linked list is already empty i.e. head is NULL
    if (head == NULL)
        return NULL;
    
    // if the linked list only contain one Node i.e. head->next=NULL
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    
    // when there are more than one Node in the linked list
    Node *curr = head;
    while (curr->next->next != NULL) {       // the loop breaks when curr points to second last Node
        curr = curr->next;
    }
    delete curr->next;   // curr is still pointing the second last Node, so deleting its next i.e. last Node
    return head;        //  returning the same head as before
}

int main() {
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    
    cout << "LinkedList before: " << head->data << " " << head->next->data << " " << head->next->next->data << endl;
    deleteLastNode(head);
    cout << "LinkedList after: " << head->data << " " << head->next->data << " ";

    return 0;
}
