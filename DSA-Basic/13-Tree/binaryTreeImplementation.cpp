#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;            // key stores the main data
    Node *left, *right; // these are pointers to the leaves (or children)
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    // Tree created here looks like (h = 3):
    //          10
    //      20      30
    //  40      50

    return 0;
}

// Binary Tree nodes can have at most degree 2 (degree <= 2). Therefore all the nodes of a Binary Tree
// can have 2 child at max.

// Leaf of a tree has degree ZERO.
// If,  Node *root = NULL   --------> then the tree is said to be empty.
// Height of Tree (h) = No. of Nodes from root to leaf on the LONGEST branch of the tree.
