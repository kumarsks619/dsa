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

// UTILITY Function: just to get the closest greater key for a given Node's key (i.e. always going to be
// the LEFT-MOST KEY OF THE RIGHT CHILD of the given Node [this is the case ONLY in BST when the
// right child of the given Node != NULL])
Node *getSuccessor(Node *curr)
{
    curr = curr->right; // moving to the right child of the given Node
    // loop to navigate to the left-most child (leaf)
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr; // returning the left-most child (leaf)
}

// function to delete a key from a given BST using recursive approach
Node *recursiveDelete(Node *root, int x)
{
    // CORNER CASE: if the tree itself is empty, then do nothing
    if (root == NULL)
        return root;

    // Now recursively searching for the key that is to be deleted.
    // searching in the left sub-tree of the current Node
    if (x < root->key)
        root->left = recursiveDelete(root->left, x); // modified Node is returned after deletion for the caller to re-build the link
    // searching in the right sub-tree of the current Node
    else if (x > root->key)
        root->right = recursiveDelete(root->right, x); // modified Node is returned after deletion for the caller to re-build the link
    // when the key is found
    else
    {
        // CASE 1: left child is empty whereas right child can be empty or occupied
        if (root->left == NULL)
        {
            Node *temp = root->right; // peserving the right child to return it to the caller
            delete root;              // deleting the desired Node
            return temp;              // returning the preserved right child (whether it is NULL or not) to the caller to establish new link
        }
        // CASE 2: right child is empty whereas left child can be empty or occupied
        else if (root->right == NULL)
        {
            Node *temp = root->left; // peserving the left child to return it to the caller
            delete root;             // deleting the desired Node
            return temp;             // returning the preserved left child (whether it is NULL or not) to the caller to establish new link
        }
        // CASE 3: both children are present
        else
        {
            Node *succ = getSuccessor(root);                       // getting the successor (i.e. the closest key for the key to be deleted)
            root->key = succ->key;                                 // overwriting the key value that is to deleted with the successor key value
            root->right = recursiveDelete(root->right, succ->key); // now recursively calling the function to delete the actual successor Node
        }
    }
    return root; // finally returning the root Node of the current MODIFIED sub-tree to its caller
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
    Node *root = new Node(30);
    root->left = new Node(20);
    root->left->left = new Node(10);
    root->left->right = new Node(25);
    root->right = new Node(40);
    root->right->left = new Node(35);
    root->right->right = new Node(50);
    // Now the BST looks like:
    //               30
    //          20        40
    //      10     25  35     50

    printInOrder(root);
    cout << endl;

    root = recursiveDelete(root, 40);
    printInOrder(root);
    cout << endl;

    root = recursiveDelete(root, 60); // No such key exists so No change
    printInOrder(root);

    return 0;
}

// for recursiveDelete():
// Time Complexity: O(h) (in general, when the BST is not balanced)
// Auxiliary Space: O(h) (required for function call stack)