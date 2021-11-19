#include <bits/stdc++.h>
using namespace std;

// function to traverse the graph in Depth-first manner [RECURSIVE FUNCTION]
void dfsRec(vector<int> adj[], int src, bool visited[])
{
    visited[src] = true; // marking the current source as visited
    cout << src << " ";  // processing the current source [SINGLE-PROCESS-POINT]
    // (each recursive call will process only one Node i.e. its current source)

    // travesing the whole adjacency list of the current source to process all its adjacent Nodes
    for (int u : adj[src])
    {
        if (!visited[u]) // checking if the Node is already visited or not
        {
            dfsRec(adj, u, visited); // recursive calling the DFS for the current Node as the new source
        }
    }
}

// function to initialize the DFS algorithm
void dfs(vector<int> adj[], int src, int V)
{
    bool visited[V]; // array to keep track of visited Nodes (vertices)
    // loop to initialize all the Nodes as un-visited
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    dfsRec(adj, src, visited); // calling the main DFS recursive algorithm with the passed source, to process all the Nodes
}

// UTILITY function: to add a new edge (link) in a graph
void addEdge(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

int main()
{
    int V = 6;          // no. of vertices
    vector<int> adj[V]; // array (length = V) of vectors

    // Graph to be represented:         1----3---4---5
    // 0 |1|2|                        / |
    // 1 |0|2|3|                    0   |
    // 2 |0|1|                       \  |
    // 3 |1|4|                         2
    // 4 |5|
    // 5 |4|

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);

    cout << "DFS when source = 0 ----> ";
    dfs(adj, 0, V);
    cout << endl
         << "DFS when source = 3 ----> ";
    dfs(adj, 3, V);

    return 0;
}

// NOTE: the above code is for Adjacency List only

// DepthFirstSearch: It is Graph traversal algorithm that takes a source Node and traverses the Node that are connected one after
// the other, once finished then it moves to its (source) adjacent and traverses in the same way (uses recursion).

// Applications of DFS:
// + Topological Sorting ---> Make file utility
// + Solving Maze type puzzles
// + Path finding (source ---> destination)