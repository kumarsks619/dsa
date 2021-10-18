#include <bits/stdc++.h>
using namespace std;

// function to process each Node (vertex) in recursive DFS manner
bool dfsDetectDirectedCycleRec(vector<int> adj[], int src, bool visited[], bool recStack[])
{
    visited[src] = true;  // mark the current source Node as visited
    recStack[src] = true; // mark the current source Node as true in the recStack[] as it is currently present in the recursion call stack

    // traversing the Adjacency List of the current source Node
    for (int u : adj[src])
    {
        if (!visited[u]) // call dfsDetectDirectedCycleRec() for the current Node as the new source if the Node is NOT visited yet
        {
            if (dfsDetectDirectedCycleRec(adj, u, visited, recStack))
            {
                return true; // return true from this recursive function if dfsDetectDirectedCycleRec() return true and STOP further execution of the function
            }
        }
        else if (recStack[u]) // if the current Node is already present in the current recStack[] then there must be a DIRECTED cycle
        {
            return true; // ONLY POINT OF TRUTH ----> only this return is responsible for all the TRUE RETURNS in both the functions
        }
    }

    recStack[src] = false; // once the current source Node is processed, it is removed from the recStack[] (again marked as false)

    return false; // if no cycle is detected among all the Nodes connected to the current source Node, then return false for this Island
}

// function to detect a DIRECTED cycle in a given Adjacency List of a Graph by processing each Node (vertex) one-by-one even if they are disconnected
bool dfsDetectDirectedCycle(vector<int> adj[], int V)
{
    bool visited[V], recStack[V]; // recStack array is used to store the Nodes that are currently in the recursion call stack

    // loop to initialize both the arrays with false value
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // loop to call dfsDetectCycleRec() for each Node (vertex) even if they are disconnected (separate Islands)
    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) // only call dfsDetectCycleRec() if the current Node (vertex) is NOT visited yet
        {
            if (dfsDetectDirectedCycleRec(adj, i, visited, recStack))
            {
                return true; // if a cycle is found then return true from the function and STOP the further execution of the Graph
            }
        }
    }

    return false; // return false if no cycle is found even after traversing the whole graph
}

// UTILITY function: to add a new DIRECTED edge (link)
void addEdge(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y); // adding only single directed link from x--->y
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

    cout << dfsDetectDirectedCycle(adj, V);

    return 0;
}

// Time Complexity of dfsDetectDirectedCycle(): O(V+E) ---> because same DFS algorithm is happening
// The above code is for DIRECTED Graph (Adjacency List).

//  Solution Logic: When traversing connected Nodes (directed connections ONLY) in RECURSIVE manner, all the Nodes reachable from a source Node will be in the recursion
// CALL STACK at the time when traversing that particular ISLAND. So if a Node encountered while traversing the Island is already present in the RECURSION CALL STACK
// at that particular moment, then there must be a DIRECTED cycle. [Refer GFG - DSA(Basic) - Graph - TRACK 12]