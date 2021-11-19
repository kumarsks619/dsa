#include <bits/stdc++.h>
using namespace std;

// function to process each Node and then recursively calling its adjacent un-visited Nodes to detect cycles in the graph
bool dfsDetectUndirectedCycleRec(vector<int> adj[], int src, bool visited[], int parent)
{
    visited[src] = true; // setting the current source Node as visited

    // now traversing through the all the adjacent nodes of the source (basically traversing the adjacency list of source Node)
    for (int u : adj[src])
    {
        if (!visited[u]) // inly proceed if the Node is NOT visited yet
        {
            if (dfsDetectUndirectedCycleRec(adj, u, visited, src)) // recursively calling again for the current Node as the new source and the current source as its new parent
            {
                return true;
            }
        }
        // ONLY CONDITION WHICH IS RESPONSIBLE FOR CYCLE SPOTTING
        else if (u != parent) // if the current Node is already visited and it is NOT the parent, then there must be a CYCLE
        {
            return true; // CYCLE FOUND
        }
    }

    return false; // if the whole CONNECTED graph is traversed and NO cycle is found, then return false
}

// function to initialize the DFS call for the graph and will also cover the disconnected Nodes
bool dfsDetectUndirectedCycle(vector<int> adj[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // loop to traverse all the Nodes even if they are disconnected
    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) // checking if the Node is visited or NOT, proceed only if it is NOT visited
        {
            if (dfsDetectUndirectedCycleRec(adj, i, visited, -1)) // for a new disconnected graph the initial parent will be NONE (so, parent = -1)
            {
                return true;
            }
        }
    }

    return false; // return false if NO cycle is found and the ALL the Nodes (including disconnected Nodes) are traversed
}

// UTILITY function: to add a new edge (link)
void addEdge(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

int main()
{
    int V = 10;
    vector<int> adj[V];

    // Graph to be represented:         1----3
    // 0 |1|2|                        /
    // 1 |0|3|                       0
    // 2 |0|                         \  
    // 3 |1|                          2
    // 4 |6|7|
    // 5 |6|
    // 6 |4|5|7|
    // 7 |4|6|                        4---6---5           8---9
    // 8 |9|                           \ /
    // 9 |8|                            7

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);

    addEdge(adj, 4, 6);
    addEdge(adj, 6, 5);
    addEdge(adj, 6, 7); // remove this line to break the cycle
    addEdge(adj, 4, 7);

    addEdge(adj, 8, 9);

    cout << dfsDetectUndirectedCycle(adj, V);

    return 0;
}

// Time Complexity of dfsDetectUndirectedCycle(): O(V+E) ---> because same DFS algorithm is happening
// The above code is for UNDIRECTED Graph (Adjacency List).