#include <bits/stdc++.h>
using namespace std;

// function to add a new edge (link), here x and y are the vertices between which the new edge is to be formed.
void addEdge(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x); // Undirected Graph, therefore need to form both ways links
}

// function to print the adjacency list of the Graph
void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int a : adj[i])
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

int main()
{
    int V = 4;          // no. of vertices
    vector<int> adj[V]; // array (length = V) of vectors

    // Graph to be represented:
    // 0 |1|2|
    // 1 |0|2|3|
    // 2 |0|1|
    // 3 |1|

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    printGraph(adj, V);

    return 0;
}

// This is Adjacency List representation using VECTOR.