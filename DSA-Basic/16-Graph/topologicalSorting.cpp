#include <bits/stdc++.h>
using namespace std;

// function to print Nodes in Topological Sorting order using KAHN's Algorithm (BFS based)
void bfsTopologicalSort(vector<int> adj[], int V)
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

    // loop to process the Nodes that are already stored in the queue
    while (!q.empty())
    {
        int processingNode = q.front(); // getting the Nodes one-by-one from the queue
        cout << processingNode << " ";  // ONLY POINT OF PROCESSING ---> printing the Node (vertex)
        q.pop();                        // removing the Node from the queue after it is processed

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
}

// function to recursively process each Node of graph in DFS manner
void dfsTopologicalSortRec(vector<int> adj[], int src, bool visited[], stack<int> &st)
{
    visited[src] = true;

    for (int u : adj[src])
    {
        if (!visited[u])
        {
            dfsTopologicalSortRec(adj, u, visited, st);
        }
    }

    st.push(src);
}

// function to print Nodes in Topological Sorting order DFS by traversing the whole graph even if they are disconnected
void dfsTopologicalSort(vector<int> adj[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsTopologicalSortRec(adj, i, visited, st);
        }
    }

    while (!st.empty())
    {
        int processingNode = st.top();
        cout << processingNode << " ";
        st.pop();
    }
}

// UTILITY function: function to add edge (Directed link) between two Nodes (vertices)
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
    // 7                            4---6---5           8---9
    // 8 |9|                         \ /
    // 9                              7

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    addEdge(adj, 4, 6);
    addEdge(adj, 6, 5);
    addEdge(adj, 6, 7);

    addEdge(adj, 8, 9);

    cout << "BFS Topological Sorting: ";
    bfsTopologicalSort(adj, V);

    cout << "\nDFS Topological Sorting: ";
    dfsTopologicalSort(adj, V);

    return 0;
}

// Topological Sorting ---> Job priority order ---> The order in which jobs must be finished based on each job's dependencies on each other.
// All the Incoming-Edges to a Node (vertex) depicts its dependency on the Nodes (vertices) from which the edges are coming out, so the Node must
// be processed only after all its dependencies are processed.

// Solution Logic: The vertices having ZERO IN-DEGREE have no dependency on any other vertex so it must be processed first and then after processing
// the Vertex, all the connected (Directed Connections) Vertices's In-degree is reduced by one as one of their depedency is processed. Then to vertices with
// zero In-degree is processed and this cycle continues until all the vertices of the graph gets processed.

// Time Complexity of bfsTopological(): O(V+E)  | Auxiliary Space: O(V) ---> for array to store indegrees of all the Nodes (vertices)
// Time Complexity of dfsTopological(): O(V+E)  | Auxiliary Space: O(V) ---> for stack to store the  Nodes (vertices) to be processed in desired order.
// TOPOLOGICAL SORTING is ONLY applicable to DAG (Directed Acyclic Graphs). This is because if there is a cycle then it is not possible to priorities any Node from
// the cycle as they are interdependent on each other.

// NOTE: the OUTPUTS of BFS and DFS methods may VARY but they are both correct according to the logic of Topological Sorting.