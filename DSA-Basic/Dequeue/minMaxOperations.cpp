#include <bits/stdc++.h>
using namespace std;

struct MinMax
{
    deque<int> dq;

    void insertMin(int x)
    {
        if (dq.front() < x)
            return;
        dq.push_front(x);
    }

    void insertMax(int x)
    {
        if (dq.back() > x)
            return;
        dq.push_back(x);
    }

    int getMin()
    {
        return dq.front();
    }

    int getMax()
    {
        return dq.back();
    }

    void extractMin()
    {
        return dq.pop_front();
    }

    void extractMax()
    {
        return dq.pop_back();
    }

    void display()
    {
        for (auto x : dq)
        {
            cout << x << " ";
        }
    }
};

int main()
{
    MinMax mm;
    mm.insertMin(10);
    mm.insertMin(20); // this won't get inserted as it is not the min value (min = 10)

    mm.display();
    cout << "\nCurrent Min: " << mm.getMin() << endl;
    cout << "Current Max: " << mm.getMax() << endl;

    mm.insertMin(5);
    mm.insertMax(15); // this will get inserted as it is the max value (prevMax = 10, as 20 is NOT inserted)
    mm.insertMax(8);  // this won't get inserted as it is NOT the max value (max = 15)

    mm.display();
    cout << "\nCurrent Min: " << mm.getMin() << endl;
    cout << "Current Max: " << mm.getMax() << endl;

    return 0;
}