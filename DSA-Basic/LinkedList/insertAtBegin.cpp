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

// function to insert new Node (basically data) at the begin of the linked list and returning the new Head of the updated linked list
Node *insertAtBegin(Node *head, int val)
{
    Node *newHead = new Node(val); // creating new Node and storing its pointer
    newHead->next = head;
    return newHead;
}

int main()
{
    Node *head = NULL;
    head = insertAtBegin(head, 30);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 10);

    cout << "LinkedList: " << head->data << " " << head->next->data << " " << head->next->next->data;

    return 0;
}

// Time Complexity of insertAtBegin() in LinkedLists: O(1) --- constant work