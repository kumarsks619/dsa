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

// Search function in BST using recursive approach
bool recursiveSearch(Node *root, int x)
{
    if (root == NULL)
        return false;
    else if (x == root->key)
        return true;
    else if (x < root->key)
        return recursiveSearch(root->left, x);
    else
        return recursiveSearch(root->right, x);
}

// Search function in BST using iterative approach
bool iterativeSearch(Node *root, int x)
{
    while (root != NULL)
    {
        if (x == root->key)
            return true;
        else if (x < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return false;
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
    cout << recursiveSearch(root, 50) << " --- " << recursiveSearch(root, 17);
    cout << endl;
    cout << recursiveSearch(root, 50) << " --- " << recursiveSearch(root, 17);

    return 0;
}

// for recursiveSearch():
// Time Complexity: O(h) (in general, when the BST is not balanced)
// Auxiliary Space: O(h) (required for function call stack)

// for iterativeSearch():
// Time Complexity: O(h) (in general, when the BST is not balanced)
// Auxiliary Space: O(1) (no extra space required)

// Therefore, ITERATIVE method is BETTER than recursive in this case.