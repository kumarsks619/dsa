#include <bits/stdc++.h>
using namespace std;

// structure for SINGLY Linked List Node
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Queue
{
    Node *front, *rear;
    int size;
    // There is no need to set capacity in case of Linked List implementation.

    // CONSTRUCTOR
    Queue()
    {
        front = rear = NULL;
        size = 0;
    }

    // method to push data to Queue
    void enqueue(int x)
    {
        Node *temp = new Node(x);
        // CORNER CASE: when Queue is empty then both front and rear is needed to be changed.
        if (front == NULL)
        {
            front = rear = temp;
            size++;
            return;
        }

        // when Queue is not empty, then only rear is changed
        rear->next = temp; // pushing new data
        rear = temp;       // setting new rear
        size++;
    }

    // method to remove data from Queue, it doesn't return the pulled out data
    void dequeue()
    {
        if (front == NULL)
        {
            return;
        }

        Node *temp = front;  // storing the Node ptr, in order to delete it later
        front = front->next; // setting new front

        // CORNER CASE: when deleteing the last item from the Queue
        if (front == NULL)
        {
            rear = NULL; // rear is needed to be changed
        }

        delete temp;
        size--;
    }

    // method to get the current size of the Queue (i.e. the no. of Nodes)
    int getSize()
    {
        return size;
    }

    // method to get the ptr to the front of the Queue
    Node *getFront()
    {
        return front;
    }

    // method to get the ptr to the rear of the Queue
    Node *getRear()
    {
        return rear;
    }

    // method to check if the Queue is empty
    bool isEmpty()
    {
        return (front == NULL);
    }
};

int main()
{
    Queue qu;

    cout << "isEmpty: " << qu.isEmpty();

    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);

    cout << endl
         << "Front: " << qu.getFront();
    cout << endl
         << "Rear: " << qu.getRear();
    cout << endl
         << "Size: " << qu.getSize();

    qu.dequeue();
    qu.dequeue();

    // NOTICE: after dequeuing 2 items, the rear ptr remains the same (because dequeing is done from front)
    // whereas the front ptr changes to be equal to rear ptr (front = rear).

    cout << endl
         << "Size: " << qu.getSize();
    cout << endl
         << "Front: " << qu.getFront();
    cout << endl
         << "Rear: " << qu.getRear();

    return 0;

    return 0;
}

// Important: choose HEAD of the LinkedList as front to do the best implementation using SINGLY LinkdedList.
// Time Complexity of all the methods: O(1)