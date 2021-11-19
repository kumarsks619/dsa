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

// function to print the Nth Node from end using length approach
void printNthNodeFromEnd(Node *head, int n)
{
    // STEP 1: finding the length of linked list
    int len = 0;
    for (Node *curr = head; curr != NULL; curr = curr->next)
        len++;

    if (n > len || n < 1) // if n is out of range
        return;

    // STEP 2: looping the curr ptr to our desired position i.e. (len-n+1) position from start
    Node *curr = head;
    for (int i = 1; i < (len - n + 1); i++)
        curr = curr->next;

    cout << endl
         << curr->data; // now the curr ptr will be at Nth position from end
}

// function to print Nth Node from end using two pointers approach
void printNthNodeFromEndPtrs(Node *head, int n)
{
    if (head == NULL)
        return;

    Node *first = head;
    for (int i = 0; i < n; i++)
    { // STEP 1: moving the first pointer by n positions
        first = first->next;
        if (first == NULL) // in this providing lead process, if first ptr becomes NULL means n > len
            return;
    }
    // now the first ptr is having a lead of n positions

    // STEP 2: moving both the ptrs together with same speed
    Node *second = head; // second ptr starts from head and first starts with a lead of n positions
    while (first != NULL)
    { // when the first ptr reaches end (NULL) then the second ptr will be at our desired position
        second = second->next;
        first = first->next;
    }
    cout << endl
         << second->data; // now the second ptr will be at Nth position from end
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    head->next->next->next = new Node(20);

    cout << "Linked List: ";
    for (Node *curr = head; curr != NULL; curr = curr->next)
        cout << curr->data << " ";

    printNthNodeFromEnd(head, 2);
    printNthNodeFromEndPtrs(head, 2);

    return 0;
}

// both the methods have O(n) time complexity.