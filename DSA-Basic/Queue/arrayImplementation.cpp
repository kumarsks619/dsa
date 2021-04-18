#include <bits/stdc++.h>
using namespace std;

// array implementation of Queue data structure
struct Queue
{
    int size, cap;
    int *arr;

    // CONSTRUCTOR
    Queue(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap]; // dynamically allocating the requested capacity for the Queue array
    }

    // method to push data to Queue
    void enqueue(int x)
    {
        if (isFull())
            return;

        arr[size] = x; // new data is added at the  end
        size++;
    }

    // method to remove data from Queue, it doesn't return the pulled out data
    void dequeue()
    {
        if (isEmpty())
            return;

        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1]; // shifting the data by one step

        size--;
    }

    // method to get the index of the head of the Queue (always ZERO in case of STRAIGHT array implementation)
    int getFront()
    {
        if (isEmpty())
            return -1; // -1 ONLY when the Queue is empty
        else
            return 0;
    }

    // method to get the index of the tail of the Queue (i.e. index of last insterted data)
    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return size - 1;
    }

    // method to check if the Queue is full
    bool isFull()
    {
        return (size == cap);
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

    return 0;
}

// Time Complexity of all the methods except dequeue(): O(1)
// Time Complexity of dequeue(): O(n)