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

// recursive function to get the size of a Binary Tree (size = No. of Nodes)
int getSize(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + getSize(root->left) + getSize(root->right);
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

    cout << "Size of Binary Tree: " << getSize(root);

    return 0;
}

// Time Complexity of getSize(): O(N)
// Auxiliary Space (required for recursive function call-stack): O(h)
// If the tree is SKEWED (i.e. all N Nodes on one branch), then iterative solution will be better than recursive.

// SKEWED BINARY TREE:
//                  10
//              20
//          30
//      40
//  50