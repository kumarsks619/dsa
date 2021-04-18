#include <bits/stdc++.h>
using namespace std;

// CIRCULAR array implementation of Queue data structure
struct Queue
{
    int cap, size, front;
    int *arr;

    // CONSTRUCTOR
    Queue(int c)
    {
        cap = c;
        arr = new int(cap); // dynamically allocating the requested capacity for the Queue array
        size = front = 0;   // keeping track of front as well
    }

    // method to push data to Queue
    void enqueue(int x)
    {
        if (isFull())
        {
            return;
        }

        int rear = getRear();
        rear = (rear + 1) % cap; //finding the new position to be inserted (incrementing in circular manner).
        arr[rear] = x;
        size++;
    }

    // method to remove data from Queue, it doesn't return the pulled out data
    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }

        front = (front + 1) % cap; // setting the new front in circular manner
        size--;
    }

    // method to get the index of the head of the Queue
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return front;
        }
    }

    // method to get the index of the tail of the Queue (i.e. index of last insterted data)
    int getRear()
    {

        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return (front + size - 1) % cap; // getting rear in circular manner
        }
    }

    // method to check if the Queue is full
    bool isFull()
    {
        return (cap == size);
    }

    // method to check if the Queue is empty
    bool isEmpty()
    {
        return (size == 0);
    }

    // method to get the current size of the Queue (i.e. the no. of elements inserted in the array)
    int getSize()
    {
        return size;
    }
};

int main()
{
    Queue qu = {3};

    cout << "isEmpty: " << qu.isEmpty();

    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);

    cout << endl
         << "isFull: " << qu.isFull();
    cout << endl
         << "Front: " << qu.getFront();
    cout << endl
         << "Rear: " << qu.getRear();
    cout << endl
         << "Size: " << qu.getSize();

    qu.dequeue();
    qu.dequeue();

    cout << endl
         << "Size: " << qu.getSize();
    cout << endl
         << "Front: " << qu.getFront();
    cout << endl
         << "Rear: " << qu.getRear();

    return 0;
}

// Time Complexity of all the methods: O(1)