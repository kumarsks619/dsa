#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = NULL;
    }
};


int searchLL(Node *head, int k) {
    int pos = 1;
    Node *curr = head;
    while (curr != NULL) {
        if (curr->data == k)
            return pos;
        else {
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}


int searchLLRecursive(Node *head, int k) {
    if (head == NULL)
        return -1;
    else if (head->data == k)
        return 1;
    else {
        int result = searchLLRecursive(head->next, k);
        if (result == -1)
            return -1;
        else
            return (result + 1);
    }
}


int main() {
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    head->next->next->next = new Node(20);

    int key;
    cout << "Enter key to be searched: ";
    cin >> key;
    cout << "Found at: " << searchLL(head, key) << endl;
    cout << "Found at: " << searchLLRecursive(head, key);

    return 0;
}


// Time Complexity for both: O(n)
// Auxiliary space required by Recursive method: O(n) to store function call-stack