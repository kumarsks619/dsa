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

// function to traverse a Binary Tree in PRE-ORDER way using iterative method (not recursive).
void iterativePreOrder(Node *root)
{
    // CORNER CASE: if the TREE is empty don't proceed
    if (root == NULL)
        return;

    // stack to store ALL the Nodes to process them later when their turn came.
    stack<Node *> st;
    st.push(root); // pushing the main root to the stack just to start the while loop
    while (!st.empty())
    {
        Node *curr = st.top();    // getting the last pushed item from the stack
        cout << curr->key << " "; // the only print statement
        st.pop();                 // removing the processed Node from the stack
        if (curr->right != NULL)  // now pushing the right Node first so that it will pop out later (LIFO)
            st.push(curr->right);
        if (curr->left != NULL) // now pushing the left Node later so that it will pop out first (LIFO)
            st.push(curr->left);
    }
}

// function to traverse a Binary Tree in PRE-ORDER way using iterative method along with SPACE OPTIMIZATION.
void iterativePreOrderSpaceOptimized(Node *root)
{
    // CORNER CASE: if the TREE is empty don't proceed
    if (root == NULL)
        return;

    // stack to store ONLY RIGHT child of each Node
    stack<Node *> st;
    Node *curr = root; // starting the current from the root Node

    // loop will stop when the stack becomes empty
    while (curr != NULL || !st.empty())
    {
        // another loop to push ONLY the RIGHT Nodes into stack by always moving towards the
        // left of each encountered Node and printing the LEFT Node's key then and there.
        while (curr != NULL)
        {
            cout << curr->key << " "; // printing the LEFT Node's key (for first iteration it is the root)
            if (curr->right != NULL)  // checking if RIGHT child is present for the current Node
                st.push(curr->right); // if present then push it to the stack to process it later
            curr = curr->left;        // moving to the LEFT child of the current Node again
        }

        // when the all the LEFT children of the current Node is processed then control comes here, so to
        // process the RIGHT children stored in the stack waiting for their turn according to PRE-OREDER rule.
        if (!st.empty())
        {
            curr = st.top(); // retriving the last pushed RIGHT child from the stack. Now the main outer
            // loop will run again for this Node as the current Node and will again keep moving to the left
            // of this Node and keep pushing all the encountered RIGHT children to stack until the LEFT
            // becomes NULL.
            st.pop(); // removing the retrived Node from the stack
        }
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

    cout << "Iterative Pre-Order: ";
    iterativePreOrder(root);

    cout << endl
         << "Iterative Pre-Order (SPACE OPTIMIZED): ";
    iterativePreOrderSpaceOptimized(root);

    return 0;
}

// Time Complexity of iterativePreOrder(): O(N) or Theta(N), as each Node is processed exactly ONCE in O(1)
// Auxiliary Space required (for stack storage) by iterativePreOrder(): Theta(h), where (h = height of tree)

// For iterativePreOrderSpaceOptimized():
// Time Complexity: O(N) (same as normal iterative function)
// Auxiliary Space: O(h), as ONLY the RIGHT children are pushed to the stack