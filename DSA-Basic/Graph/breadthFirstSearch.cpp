#include <bits/stdc++.h>
using namespace std;

// BreadthFirstSearch: the function takes and an Adjacency List, no. of Vertices and the source Node and prints
// all the linked Nodes starting from the source in breadth first manner (i.e. direct connections of the source
// first, then their direct connections and so on).
// NOTE: each Node is printed (visited) exactly ONCE.
void bfs(vector<int> adj[], int V, int src)
{
    bool visited[V]; // to keep track of status (visited/un-visited) of a Node
    // loop to initialize all Nodes as un-visited (NOTE: each Node is addressed by an index)
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    queue<int> q;        // queue to push UN-VISITED Nodes only, to process them one-by-one
    visited[src] = true; // setting the source Node as visited
    q.push(src);         // pushing the source Node to the queue

    // run the loop until the queue is NOT empty (i.e. until all Nodes get visited)
    while (!q.empty())
    {
        int v = q.front(); // getting the first Node from the queue to process it as well as its connections
        q.pop();           // removing the above taken Node from the queue
        cout << v << " ";  // processing the taken out Node (ONLY here the processing (printing) takes place)

        // loop to process all the connections of the taken out Node by travelling through the array (or vector or linkedlist)
        // at its index in the Adjacency List
        for (int u : adj[v])
        {
            if (!visited[u]) // checking if the current Node is visited or not
            {
                visited[u] = true; // mark the Node as visited
                q.push(u);         // if the Node is un-visited then push it to the queue to process it later
            }
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
    int V = 4;          // no. of vertices
    vector<int> adj[V]; // array (length = V) of vectors

    // Graph to be represented:         1----3
    // 0 |1|2|                        / |
    // 1 |0|2|3|                    0   |
    // 2 |0|1|                       \  |
    // 3 |1|                           2

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    cout << "BFS when source = 0 ----> ";
    bfs(adj, V, 0);
    cout << endl
         << "BFS when source = 3 ----> ";
    bfs(adj, V, 3);

    return 0;
}

// NOTE: the above code is for Adjacency List only

// BreadthFirstSearch: It is Graph traversal algorithm that takes a source Node and traverses the Node that are one edge away first
// (adjacent Nodes), then the Nodes that are two edges away (their adjacent Nodes) and so on (uses queue data structure).

// Applications of BFS:
// + Shortest path in an UNWEIGHTED graphs.
// + Web crawlers
// + Social Networking search
// + Peer to Peer networks in Networking
// + Broadcasting