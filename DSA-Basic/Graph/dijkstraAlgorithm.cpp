// This is INCOMPLETE with BUGS ****************************************************************

#include <bits/stdc++.h>
using namespace std;
#define LITTLE_INF 99

void dijkstra(vector<vector<int>> mat, int src)
{
    int V = mat.size();
    int shortestDistance[V];
    for (int i = 0; i < V; i++)
    {
        if (i == src)
        {
            shortestDistance[i] = 0;
        }
        else
        {
            shortestDistance[i] = LITTLE_INF;
        }
    }

    unordered_set<int> sptSet;
    while (sptSet.size() != V)
    {
        int minIndex = 0;
        for (int i = 0; i < V; i++)
        {
            cout << sptSet.count(i);
            if (shortestDistance[i] < shortestDistance[minIndex] && !sptSet.count(i))
            {
                minIndex = i;
            }
        }

        sptSet.insert(minIndex);

        for (int i = 0; i < V; i++)
        {
            if (shortestDistance[minIndex] + mat[minIndex][i] < shortestDistance[i])
            {
                shortestDistance[i] = shortestDistance[minIndex] + mat[minIndex][i];
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << i << " ---> " << shortestDistance[i] << endl;
    }
}

// UTILITY function: to add a new edge (link)
void addEdge(vector<vector<int>> &mat, int v1, int v2, int w)
{
    mat[v1][v2] = w;
    mat[v2][v1] = w;
}

// function to print the adjacency list of the Graph
void printGraph(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << "    ";
        }
        cout << endl;
    }
}

int main()
{
    int V = 9;
    vector<vector<int>> mat(V, vector<int>(V, LITTLE_INF));

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
            {
                mat[i][j] = 0;
            }
        }
    }

    // Graph to be represented:
    //      0   1   2   3   4   5   6   7   8
    // 0    0   4   -   -   -   -   -   8   -
    // 1    4   0   8   -   -   -   -  11   -
    // 2    -   8   0   7   -   4   -   -   2
    // 3    -   -   7   0   9  14   -   -   -
    // 4    -   -   -   9   0  10   -   -   -
    // 5    -   -   4  14  10   0   2   -   -
    // 6    -   -   -   -   -   2   0   1   6
    // 7    8  11   -   -   -   -   1   0   7
    // 8    -   -   2   -   -   -   6   7   0

    addEdge(mat, 0, 1, 4);
    addEdge(mat, 0, 7, 8);
    addEdge(mat, 1, 2, 8);
    addEdge(mat, 1, 7, 11);
    addEdge(mat, 2, 3, 7);
    addEdge(mat, 2, 5, 4);
    addEdge(mat, 2, 8, 2);
    addEdge(mat, 3, 4, 9);
    addEdge(mat, 3, 5, 14);
    addEdge(mat, 4, 5, 10);
    addEdge(mat, 5, 6, 2);
    addEdge(mat, 6, 7, 1);
    addEdge(mat, 6, 8, 6);
    addEdge(mat, 7, 8, 7);

    // printGraph(mat);

    dijkstra(mat, 0);

    return 0;
}