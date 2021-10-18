#include <bits/stdc++.h>
using namespace std;

// UTILITY function: DFS to process all the Nodes that are somehow connected to a given source Node
void dfsRec(vector<int> adj[], int src, bool visited[])
{
    visited[src] = true;
    cout << src << " "; // single point of process: only here the processing of the Node takes place

    for (int u : adj[src])
    {
        if (!visited[u])
        {
            dfsRec(adj, u, visited);
        }
    }
}

// function to visit and process (exactly once) all the Nodes of a graph even if they are NOT connected in DFS manner
void dfsDisconnected(vector<int> adj[], int V)
{
    bool visited[V]; // to keep track of status of all the Nodes in the graph
    // loop to initialize all the Nodes as un-visited
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // loop to travel through each Node one-by-one to process them
    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) // only process the Node if it is never visited yet
        {
            dfsRec(adj, i, visited); // calling the DFS with the current Node (i) as the source
            // after this all the Nodes somehow connected to the current Node will get processed for sure so the dfsRec() won't be called
            // again for any Node that is somehow connected to the current Node, as they all get processed.
        }
    }
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
    // 0 |1|2|                        / |
    // 1 |0|2|3|                    0   |
    // 2 |0|1|                       \  |
    // 3 |1|                           2
    // 4 |6|7|
    // 5 |6|
    // 6 |4|
    // 7 |4|                        4---6---5           8---9
    // 8 |9|                         \ 
    // 9 |8|                          7

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    addEdge(adj, 4, 6);
    addEdge(adj, 6, 5);
    addEdge(adj, 4, 7);

    addEdge(adj, 8, 9);

    dfsDisconnected(adj, V);

    return 0;
}

// NOTE: the above code is for Adjacency List only

// Time Complexity of dfsDisconnected() ---> O(V + E)
// It looks like that this function will have high time complexity as it has too many nested loops but this it NOT true, as the visited check
// of each Node prevents most of the loops to be executed again and again. So the actual time complexity came out to be O(V + E).