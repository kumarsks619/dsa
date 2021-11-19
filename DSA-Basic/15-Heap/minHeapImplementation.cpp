#include <bits/stdc++.h>
using namespace std;

// MinHeap Class
class MinHeap
{
    int *arr, size, capacity;
    // array(int *arr) is used to store the Nodes (NOT in Tree).
    // size(int size) is used to keep the count of Nodes currently present in the array.
    // capacity(int capacity) defines the maximum number of Nodes the MinHeap can store.

public:
    // CONSTRUCTOR: to initialize the MinHeap with given capacity.
    MinHeap(int c)
    {
        capacity = c;            // setting the capacity
        arr = new int[capacity]; // dynamically allocating memory for MinHeap according to given capacity
        size = 0;                // setting the initial size = 0, as the MinHeap is empty initially
    }

    // method to get the index of LEFT CHILD (in array) of a given Node.
    int left(int i)
    {
        return (2 * i) + 1;
    }

    // method to get the index of RIGHT CHILD (in array) of a given Node.
    int right(int i)
    {
        return (2 * i) + 2;
    }

    // method to get the index of PARENT (in array) of a given Node.
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // method to INSERT a new Node into the MinHeap (basically in the array) by obeying MinHeap rules.
    void insert(int x)
    {
        // if the MinHeap is already full, then do nothing.
        if (size == capacity)
            return;

        size++;              // incrementing the current size
        arr[size - 1] = x;   // inserting the new key after the last value in the array
        int curr = size - 1; // setting the current to point to the just inserted key

        // loop to move the just inserted key to its correct place (MinHeap rule).
        // loop will terminate when the current reaches the main-root or when the parent's key of
        // the current Node becomes LESS than the current Node's key.
        while (curr != 0 && arr[curr] < arr[parent(curr)])
        {
            // swapping the current Node's key with its parent's key because the parent > child.
            swap(arr[curr], arr[parent(curr)]);
            curr = parent(curr); // moving current upwards in the MinHeap to point the parent of the
            // current Node (and finally the current can reach the main-root i.e. index zero)
        }
    }

    // method to turn a normal Heap into a MinHeap by providing the index of the topmost violating Node.
    void minHeapify(int i)
    {
        // finding the index of left and right child of the given violating Node
        int leftChildIndex = left(i), rightChildIndex = right(i);
        int smallestChildIndex = i; // assuming the smallest key to be the parent itself

        // checking if the left child exists AND if the left child's key is smaller than current smallest key (i.e. parent's key)
        if (leftChildIndex < size && arr[leftChildIndex] < arr[smallestChildIndex])
            smallestChildIndex = leftChildIndex; // then set the smallest key's Node's index to be left child's Node's index

        // checking if the right child exists AND if the right child's key is smaller than current smallest key (i.e. parent's/left child's key)
        if (rightChildIndex < size && arr[rightChildIndex] < arr[smallestChildIndex])
            smallestChildIndex = rightChildIndex; // then set the smallest key's Node's index to be right child's Node's index

        // BASE CASE FOR RECURSIVE CALLS: checking if the parent's key is already NOT the smallest key among the three Nodes
        if (smallestChildIndex != i)
        {
            swap(arr[smallestChildIndex], arr[i]); // swapping the smallest key with the parent's key
            minHeapify(smallestChildIndex);        // recursively calling the function again for the DISTURBED SUB-TREE
        }
    }

    // method to extract the topmost Node from the MinHeap (i.e. minimum element/key) [this method will modify the Heap]
    int extractMin()
    {
        // CORNER CASE 1: when the Heap is empty
        if (size == 0)
            return INT_MAX;

        // CORNER CASE 2: when the Heap has only ONE Node
        if (size == 1)
        {

            size--;
            return arr[0];
        }

        // control reaches here when the MinHeap's size > 1
        swap(arr[0], arr[size - 1]); // swapping the main-root Node's key (min key) with the last Node's key (max key)
        size--;                      // reducing the Heap size (this will remove the min key form the Heap)
        minHeapify(0);               // calling heapify to fix the disturbed MinHeap
        return arr[size];            // returning the removed min key
    }

    // method to replace the key with smaller value of the Node at a given index
    void decreaseKey(int i, int x)
    {
        arr[i] = x; // replacing the key at the given the index with the new key

        // loop to move the newly inserted key to its correct place in the MinHeap
        // the loop will terminate only when the i reaches main-root(index=0) or parent's key becomes less than the current index's key
        while (i != 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]); // swapping the current key with its parent key
            i = parent(i);                // shifting the current to point its parent
        }
    }

    // method to delete a key (or say Node) at given index from a MinHeap
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN); // STEP 1: replacing the key to be deleted with -INFINITY, so it will reach the top.
        extractMin();            // STEP 2:  then removing the min key from the MinHeap (i.e. now already present at the top).
    }

    // method to re-arrange keys in a given array so as to form a MinHeap
    void buildHeap()
    {
        // loop to iterate through all the internal Nodes upto main-root, starting from bottom-most right-most internal Node
        for (int i = parent(size - 1); i >= 0; i--)
        {
            minHeapify(i); // heapify the sub-tree (all Nodes below index i Node)
        }
    }

    // UTILITY Method: to print the array
    void printInArray()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }
};

int main()
{
    MinHeap mh(10);

    int keys[] = {20, 10, 15, 40, 25, 35, 5, 55};
    for (int key : keys)
        mh.insert(key);

    mh.printInArray();

    cout << "\nMinimum Element from Heap: " << mh.extractMin() << endl;
    mh.printInArray();

    mh.decreaseKey(6, 3); // replacing the last Node's key with 3
    cout << endl;
    mh.printInArray();

    mh.deleteKey(4); // deleting the Node present at index 4
    cout << endl;
    mh.printInArray();

    return 0;
}

// MinHeap Rules:
// 1) Must be a COMPLETE Binary Tree. (NOT necessarily Binary Search Tree).
// 2) Each Node's key must be LESS than all its descendants. (i.e. min value always at the top - index 0).

// Time Complexity for (N = size = No. of Nodes):
// insert(): O(log(N)) = O(h)
// minHeapify(): O(log(N)) = O(h)
// extractMin(): O(1) + O(log(N)) = O(log(N)) = O(h)
// decreaseKey(): O(log(N)) = O(h)
// deleteKey(): O(log(N)) + O(log(N)) = O(log(N)) = O(h)
// buildHeap(): O(N) ---> Mathematically Proved (IMPORTANT: NOT O(Nlog(N)))

// Auxiliary Space for (h = height of MinHeap):
// minHeapify(): O(h) (required for recursive function call stack)
// extractMin(): O(h) or O(1) (depends upon the minHeapify() implementation)