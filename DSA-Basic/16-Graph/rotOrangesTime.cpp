#include <bits/stdc++.h>
using namespace std;

// structure to store coordinates of a cell in the Adjacency Matrix.
struct Cell
{
    int x, y;

    Cell() // constructor to initialize the coordinates as -1
    {
        x = -1;
        y = -1;
    }
};

// UTILITY function: to check if a given coordinate is a delimiter (i.e. point == (-1, -1)) or not.
bool isDelimiter(Cell point)
{
    if (point.x == -1 && point.y == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// UTILITY function: to check if a given coordinate lies inside the given matrix of not.
bool isValidPoint(int x, int y, int R, int C)
{
    if (x < 0 || x >= R || y < 0 || y >= C)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// UTILITY function: to check if a given matrix contains all rotten oranges (i.e. all values = 2 or 0 but NOT 1) or not.
bool isAllRotten(int mat[][5], int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == 1)
            {
                return false;
            }
        }
    }

    return true;
}

// function to calculate the minimum time frame required to rot all the oranages in a given box.
int rotOranges(int mat[][5], int R, int C)
{
    queue<Cell> q;     // queue to store the coordinates of cells containing rotten orange
    Cell point;        // a temp point to store points throughout the algorithm as required
    int timeFrame = 0; // to store time frame count = number of waves(cycles/phases/iterations) required to rot all oranges

    // loop to push all the initial rotten oranages to the queue
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == 2)
            {
                point.x = i;
                point.y = j;
                q.push(point);
            }
        }
    }

    // creating a delimiter point
    point.x = -1;
    point.y = -1;
    q.push(point); // pushing the delimiter after pushing all the rotten oranges to separate different phases (waves/iterations)

    // loop to process all the rotten oranges already present in the queue
    while (!q.empty())
    {
        bool isRotOther = false; // to keep track of if any of the rotten oranges in the queue is able to rot any of its neighbour in the current iteration or not

        // loop to process all the oranges in one phase (i.e. until the delimiter/boundary is encountered)
        while (!isDelimiter(q.front()))
        {
            point = q.front(); // getting a rotten orange from queue one-by-one to process it

            // rotting the TOP neighbour of the current rotten orange's cell
            if (isValidPoint(point.x, point.y - 1, R, C) && mat[point.x][point.y - 1] == 1) // checking if the neighbour is rottable or not
            {
                mat[point.x][point.y - 1] = 2; // rotting the orange

                point.y--;     // decrementing the y coordinate to get the neighbour's coordinate so as to push that cell point to the next phase of rottening
                q.push(point); // pushing the newly rotten neighbour cell to queue for next rottening phase
                point.y++;     // getting back to the current cell coordinate

                // checking if the rotten oranges in the current phase is NOT YET able to rot any of its neighbors and this neighbour is the first one to get rotten
                // in this phase of rottening, ONLY then increase the time frame count. (time frame MUST increase only ONCE in one rottening phase)
                if (!isRotOther)
                {
                    isRotOther = true; // marking the isRotOther flag as true for the current rottening phase
                    timeFrame++;       // incrementing the time frame for the current rottening phase
                }
            }

            // rotting the RIGHT neighbour of the current rotten orange's cell
            if (isValidPoint(point.x + 1, point.y, R, C) && mat[point.x + 1][point.y] == 1) // checking if the neighbour is rottable or not
            {
                mat[point.x + 1][point.y] = 2; // rotting the orange

                point.x++;     // incrementing the x coordinate to get the neighbour's coordinate so as to push that cell point to the next phase of rottening
                q.push(point); // pushing the newly rotten neighbour cell to queue for next rottening phase
                point.x--;     // getting back to the current cell coordinate

                if (!isRotOther)
                {
                    isRotOther = true;
                    timeFrame++;
                }
            }

            // rotting the BOTTOM neighbour of the current rotten orange's cell
            if (isValidPoint(point.x, point.y + 1, R, C) && mat[point.x][point.y + 1] == 1) // checking if the neighbour is rottable or not
            {
                mat[point.x][point.y + 1] = 2; // rotting the orange

                point.y++;     // incrementing the y coordinate to get the neighbour's coordinate so as to push that cell point to the next phase of rottening
                q.push(point); // pushing the newly rotten neighbour cell to queue for next rottening phase
                point.y--;     // getting back to the current cell coordinate

                if (!isRotOther)
                {
                    isRotOther = true;
                    timeFrame++;
                }
            }

            // rotting the LEFT neighbour of the current rotten orange's cell
            if (isValidPoint(point.x - 1, point.y, R, C) && mat[point.x - 1][point.y] == 1) // checking if the neighbour is rottable or not
            {
                mat[point.x - 1][point.y] = 2; // rotting the orange

                point.x--;     // decrementing the x coordinate to get the neighbour's coordinate so as to push that cell point to the next phase of rottening
                q.push(point); // pushing the newly rotten neighbour cell to queue for next rottening phase
                point.x++;     // getting back to the current cell coordinate

                if (!isRotOther)
                {
                    isRotOther = true;
                    timeFrame++;
                }
            }

            q.pop(); // removing the just processed rotten orange from the queue
        }

        q.pop(); // after one phase is complete and a delimiter is encountered ---> so removing (popping out) that delimiter

        // checking if there are any newly rotten oranges pushed to the queue for the next rottening phase
        if (!q.empty())
        {
            // if YES, then create a delimiter and push that as a boundary for the next rottening phase
            point.x = -1;
            point.y = -1;
            q.push(point);
        }
    }

    // after all the rotten oranges in the queue are processed
    return isAllRotten(mat, R, C) ? timeFrame : -1; // checking if there are no good oranges left in the matrix, then return the time frame (rottening phase count) required
    // to rotten all the oranges, else return -1 if all the oranges in the matrix can't be rotten.
}

int main()
{
    int R = 3, C = 5;
    int mat1[3][5] = {{2, 1, 0, 2, 1},
                      {1, 0, 1, 2, 1},
                      {1, 0, 0, 2, 1}};

    cout << rotOranges(mat1, R, C) << endl;

    int mat2[3][5] = {{2, 1, 0, 2, 1},
                      {0, 0, 1, 2, 1},
                      {1, 0, 0, 2, 1}};

    cout << rotOranges(mat2, R, C);

    return 0;
}

// Problem Info: file:///E:/Tutorials/My%20AddOn/GFG%20-%20Placement%20100/2.Data%20structures(%20Basic)/17.%20Graph/Copy%20of%20Graph%20Track%20Theory.html