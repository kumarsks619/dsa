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

// function to traverse a Binary Tree in IN-ORDER way using iterative method (not recursive).
void iterativeInOrder(Node *root)
{
    stack<Node *> st; // stack to store Nodes and access them in LIFO order (to get access to parent Node
    // of each pushed Node)
    Node *curr = root;

    // loop will stop when the stack becomes empty or the provided tree itself is empty.
    while (curr != NULL || !st.empty())
    {
        // another loop to push Nodes into stack by always moving towards the left of each encountered Node.
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left; // moving towards left
        }
        // now, when the extreme left of a sub-tree is reached then the above while loop terminates.

        curr = st.top(); // now getting out the last pushed Node form the stack to print the stored key and
        // then move towards it's right sub-tree
        cout << curr->key << " "; // printing the stored key in it
        curr = curr->right;       // moving towards it's right sub-tree

        st.pop(); // just removing the last pushed Node after processing it as top() method doesn't remove
        // it from the stack
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

    iterativeInOrder(root);

    return 0;
}

// Time Complexity of iterativeInOrder(): O(N) or Theta(N), as each Node is processed exactly ONCE in O(1)
// Auxiliary Space required (for stack storage): Theta(h), where (h = height of tree)