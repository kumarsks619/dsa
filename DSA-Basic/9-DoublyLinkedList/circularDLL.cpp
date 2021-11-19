#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;
    Node(int x)
    {
        data = x;
        prev = next = NULL;
    }
};

void printCircularDLL(Node *head)
{
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

// function to insert new Node at the begin of the linkedlist and return the new head
Node *insertAtBegin(Node *head, int x)
{
    Node *temp = new Node(x);

    // CORNER CASE: when linkedlist is empty
    if (head == NULL)
    {
        // single Node therefore making the temp to point itself in both directions (prev & next)
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    // STEP 1: linking the temp in the linkedlist at its correct position (before head)
    temp->next = head;
    temp->prev = head->prev;

    // STEP 2: breaking the re-linking the head and last Node to accommodate temp (new Node)
    head->prev->next = temp;
    head->prev = temp;

    // STEP 3: returning the temp as the new head
    return temp;
    // to insertAtEnd(): we just need to return the same head here, rest of the code remains same.
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;
    head->prev = head->next->next->next;
    head->next->next->next->next = head;

    cout << "Circular DLL before: ";
    printCircularDLL(head);

    head = insertAtBegin(head, 5);

    cout << "\nCircular DLL after: ";
    printCircularDLL(head);

    return 0;
}

// Time Complexity of insertAtBegin() and insertAtEnd(): O(1)
// Advatages of Circular DLL = Advantages of (Circular LinkedList + Doubly LinkedList)