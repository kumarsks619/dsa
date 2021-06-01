#include <bits/stdc++.h>
using namespace std;

struct Person
{
    int age;
    float height;
    Person(int a, float h)
    {
        age = a;
        height = h;
    }
};

struct myComparison
{
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.height < p2.height;
    }
};

int main()
{
    // Implementation 1: priority_queue as MaxHeap ********************************************************************************
    priority_queue<int> pq; // priority queues are by default MaxHeap

    pq.push(10);
    pq.push(5);
    pq.push(15);
    cout << "Size: " << pq.size();
    cout << "\nMax key: " << pq.top();

    cout << "\nMaxHeap: ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    // Implementation 2: priority_queue as MinHeap *********************************************************************************
    priority_queue<int, vector<int>, greater<int>> pqMin; // weird syntax to initialize priority_queue as MinHeap

    pqMin.push(10);
    pqMin.push(5);
    pqMin.push(15);
    cout << "\nSize: " << pqMin.size();
    cout << "\nMin key: " << pqMin.top();

    cout << "\nMinHeap: ";
    while (!pqMin.empty())
    {
        cout << pqMin.top() << " ";
        pqMin.pop();
    }

    // Implementation 3: priority_queue as MaxHeap(or can be MinHeap) by passing all keys in an array/vector ******************************
    int arr[] = {10, 5, 15};
    priority_queue<int> pqArr(arr, arr + (sizeof(arr) / sizeof(arr[0]))); // BEST approach to initialize a priority_queue (TimeComp: O(N))

    cout << "\nSize: " << pqArr.size();
    cout << "\nMax key: " << pqArr.top();

    cout << "\nMaxHeap: ";
    while (!pqArr.empty())
    {
        cout << pqArr.top() << " ";
        pqArr.pop();
    }

    // Implementation 4: priority_queue of user-defined data-types *************************************************************************
    priority_queue<Person, vector<Person>, myComparison> pqDt; // priority_queue by passing custom comparison structure
    Person p1(25, 6.9), p2(72, 5.3), p3(45, 4.7);

    pqDt.push(p1);
    pqDt.push(p2);
    pqDt.push(p3);
    cout << "\nSize: " << pqDt.size();
    cout << "\nMax key: age=" << pqDt.top().age << " height=" << pqDt.top().height;

    cout << "\nMaxHeap: ";
    while (!pqDt.empty())
    {
        cout << "age=" << pqDt.top().age << " height=" << pqDt.top().height << "    ";
        pqDt.pop();
    }

    return 0;
}