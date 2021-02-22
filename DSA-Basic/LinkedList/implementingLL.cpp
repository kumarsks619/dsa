#include <bits/stdc++.h>
using namespace std;

// Node: [data, *next]
struct Node {
    int data;           // to store the actual data
    Node *next;         // SELF-REFERENCING   ||  ptr of type Node to store the address of the next Node obj

    // Constructor
    Node (int x) {
        data = x;   
        next = NULL;    // default value of next = NULL   ||   the last Node of a linked list will have next = NULL
    }
};


int main() {
    // creating Node struct objects with "new" keyword so that it will return its address then it can be stored for further references.
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    // storing the addresses for the next nodes in subsequent manner
    head->next = temp1;
    temp1->next = temp2;

    // SHORTCUT to do the above procedure
    Node *head2 = new Node(7);
    head2->next = new Node(11);
    head2->next->next = new Node(17);

    return 0;
}