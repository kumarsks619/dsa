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

// function to insert a key in BST by following the BST Rule using RECURSIVE approach.
Node *recursiveInsert(Node *root, int x)
{
    // when the root is empty ONLY then the main-root of the tree get changed
    if (root == NULL)
        return new Node(x); // the ONLY statement where insert of new key takes place in ALL CASES

    // root->left = recursiveInsert() and root->right = recursiveInsert() are IMPORTANT because of this,
    // the new Node created in the above statement will get linked to its CORRECT LEAF.

    if (x < root->key)
        root->left = recursiveInsert(root->left, x);

    // checking for the below case also so that if the key is already present(i.e. x = root->key)
    // then no insert should occur.
    else if (x > root->key)
        root->right = recursiveInsert(root->right, x);
    return root; // the root of each sub-tree is returned to its caller
}

// function to insert a key in BST by following the BST Rule using ITERATIVE approach.
Node *iterativeInsert(Node *root, int x)
{
    // CORNER CASE: when the tree is empty.
    if (root == NULL)
        return new Node(x);

    Node *curr = root;
    // loop to navigate the curr ptr to the CORRECT leaf for the new key
    while (curr != NULL)
    {
        if (x < curr->key)
            curr = curr->left;
        else if (x > curr->key)
            curr = curr->right;
        else // when the same key already exists then do nothing
            return root;
    }
    // after successfully navigating to the correct key, then inserting the new key at its correct place
    curr = new Node(x);
    return root; // finally returning the main-root
}

// function just to print the BST
void printInOrder(Node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        cout << root->key << " ";
        printInOrder(root->right);
    }
}

int main()
{
    int keys[] = {30, 50, 10, 25, 40, 20, 35, 10};
    Node *root = NULL;

    for (int key : keys)
        root = recursiveInsert(root, key);

    printInOrder(root);
    cout << endl;

    for (int key : keys)
        root = iterativeInsert(root, key);

    printInOrder(root);

    return 0;
}

// for recursiveInsert():
// Time Complexity: O(h) (in general, when the BST is not balanced)
// Auxiliary Space: O(h) (required for function call stack)

// for iterativeInsert():
// Time Complexity: O(h) (in general, when the BST is not balanced)
// Auxiliary Space: O(1) (no extra space required)

// Therefore, ITERATIVE method is BETTER than recursive in this case.