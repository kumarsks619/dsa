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

void printDLL(Node *head)
{
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != NULL);
}

Node *reverseDLL(Node *head)
{
    // CORNER CASE: empty or only one Node in the linkedlist
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head, *tempPrev = NULL;
    // iterating through each Node and swapping its prev ptr with its next ptr
    while (curr != NULL)
    {
        // swapping the ptrs
        tempPrev = curr->prev;
        curr->prev = curr->next;
        curr->next = tempPrev;

        // shifting the curr ptr ahead (NOTE: it is being shifted to its prev ptr because the ptrs swapped)
        curr = curr->prev;
    }
    // returning the new head i.e. the last Node
    return tempPrev->prev;
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

    cout << "Doubly LinkedList before: ";
    printDLL(head);

    head = reverseDLL(head);

    cout << "\nDoubly LinkedList after: ";
    printDLL(head);

    return 0;
}

// Time Complexity of reverseDLL(): O(n)