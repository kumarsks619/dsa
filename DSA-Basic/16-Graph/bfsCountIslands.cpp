#include <bits/stdc++.h>
using namespace std;

// UTILITY function: BFS to process all the Nodes that are somehow connected to a given source Node
void bfs(vector<int> adj[], int src, bool visited[])
{
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

// function to count the total number of Islands (disconnected sub-graphs) in a given set of vertices
int bfsCountIslands(vector<int> adj[], int V)
{
    bool visited[V]; // to keep track of status of each Node
                     // loop to initialize all the Nodes as un-visited
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    int count = 0; // to keep the count of islands
    // travelling through each Node (vertex) one-by-one of the given graph
    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) // checking if the Node is not visited yet
        {
            count++;              // incrementing the island count as the current Node will surely be a part of a NEW ISLAND
            bfs(adj, i, visited); // processing all the Nodes somehow connected to the current Node (or say part of the current island) so as
            // to mark all its associated Nodes as visited, so that any Node of the current island won't be ever visited again
        }
    }

    return count;
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
    // 4 |5|6|7|
    // 5 |4|                          5
    // 6 |4|                         /
    // 7 |4|                        4---6           8---9
    // 8 |9|                         \ 
    // 9 |8|                          7

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 4, 7);

    addEdge(adj, 8, 9);

    cout << "Total no. of Islands: " << bfsCountIslands(adj, V);

    return 0;
}

// NOTE: the above code is for Adjacency List only

// Total number of Islands = No. of disconnected sub-graphs (separate entities)

// The same problem (Count Islands) can be solved using DFS in the exact same way.