#include <bits/stdc++.h>
using namespace std;

// function to detect a DIRECTED cycle in a graph using KAHN's Algorithm
bool kahnsDetectDirectedCycle(vector<int> adj[], int V)
{
    int indegree[V] = {0}; // array to keep the In-degrees of each Node (vertex), initialized with all zeros

    // loop to traverse the whole graph to count the In-degrees of all the Nodes (vertices)
    for (int i = 0; i < V; i++)
    {
        // loop to traverse the Adjacency List of the current Node (vertex)
        for (int u : adj[i])
        {
            indegree[u]++; // increment In-degree count of the Nodes as they appear in the Adjacency List of the current Vertex (Node)
        }
    }

    queue<int> q; // queue to collect the Nodes with ZERO In-degree so that it can be processed later

    // loop to push Nodes with zero In-degree to the Queue
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0) // ONLY push to queue if the In-degree of Node is equal to ZERO
        {
            q.push(i);
        }
    }

    int processedCount = 0; // to store the count of Nodes that gets processed

    // loop to process the Nodes that are already stored in the queue
    while (!q.empty())
    {
        int processingNode = q.front(); // getting the Nodes one-by-one from the queue
        q.pop();                        // removing the Node from the queue after it is processed
        processedCount++;               // incrementing the count as one is just processed

        // now traversing the Adjacency List of the Node that is just processed, so as to reduce the dependncy count (In-degree) by one.
        for (int u : adj[processingNode])
        {
            indegree[u]--; // decrementing the In-degree

            if (indegree[u] == 0) // if the In-degree is reduced to ZERO than push that Node to queue so as to process it later
            {
                q.push(u);
            }
        }
    }

    // after the execution of whole algorithm, if the processed count is less than total number of Vertices than there must be some vertices left out (not processed)
    // as they (those Vertices) are surely a part of a Directed cycle, therefore a cycle exists in the given Graph
    if (processedCount < V)
    {
        return true; // cycle exists
    }
    else
    {
        return false; // no cycle found ---> (processedCount = V)
    }
}

void addEdge(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
}

int main()
{

    int V = 10;
    vector<int> adj[V];

    // Graph to be represented:         1----3
    // 0 |1|2|                        / |
    // 1 |2|3|                      0   |
    // 2                             \  |
    // 3                               2
    // 4 |6|
    // 5
    // 6 |5|7|
    // 7 |4|                        4---6---5           8---9
    // 8 |9|                         \ /
    // 9                              7

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    addEdge(adj, 4, 6);
    addEdge(adj, 6, 5);
    addEdge(adj, 6, 7);
    addEdge(adj, 7, 4); // remove this line to break the DIRECTED cycle

    addEdge(adj, 8, 9);

    cout << kahnsDetectDirectedCycle(adj, V);

    return 0;
}

// Solution Logic: When processing the Nodes through Kahn's algorithm, at the end of the whole algorithm, if the count of Nodes that get processed is less than total
// number of Nodes then there must be a directed cycle whose Node's In-degree doesn't get reduced to ZERO in the process (at this of point time, only Nodes that are
// a part of a directed cycle remains, else gets processed already).

// Time Complexity of kahnsDetectDirectedCycle(): O(V+E)  | Auxiliary Space: O(V) ---> for array to store indegrees of all the Nodes (vertices)
