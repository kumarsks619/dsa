#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// function to print all nodes one by one in IN-ORDER way.
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);      // recursively handling the LEFT subtree
        cout << root->key << " "; // ONLY print statement (always the root is printed in each subtrees)
        inOrder(root->right);     // recursively handling the RIGHT subtree
    }
}

// function to print all nodes one by one in PRE-ORDER way.
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// function to print all nodes one by one in POST-ORDER way.
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

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

    cout << "In-Order: ";
    inOrder(root);

    cout << "\nPre-Order: ";
    preOrder(root);

    cout << "\nPost-Order: ";
    postOrder(root);

    return 0;
}

// Types of IN-DEPTH Traversals: 1) In-Order    2) Pre-Order    3) Post-Order
// In all these three In-Depth Traversals, left subtree is always handled BEFORE right subtree.
// Time Complexity for all the In-Depth Traversals: O(N)
// Auxiliary Space (required for recursive function call-stack): O(h)

// IN-ORDER Traversal: left sub-tree, root, right sub-tree
// PRE-ORDER Traversal: root, left sub-tree, right sub-tree
// POST-ORDER Traversal: left sub-tree, right sub-tree, root
