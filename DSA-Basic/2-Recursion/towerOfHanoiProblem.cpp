#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int numOfDiscs, char origin, char intermediate, char destination)
{
    // Base case: to simply move one disc from origin to destination directly.
    if (numOfDiscs == 1)
    {
        cout << "Move Disc " << 1 << " from " << origin << " to " << destination << endl;
        return;
    }
    // following 3 steps are used to move three discs from origin to destination (in order):
    towerOfHanoi(numOfDiscs - 1, origin, destination, intermediate);                           // step 1: to move two discs (A to B)
    cout << "Move Disc " << numOfDiscs << " from " << origin << " to " << destination << endl; //step 2 (A to C)
    towerOfHanoi(numOfDiscs - 1, intermediate, origin, destination);                           // step 3: to move two discs (B to C)
}

int main()
{
    cout << "Enter number of discs: ";
    int n;
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}

// Problem Explained in DSA (Basics) - Recursion - Track 5
// The Problem is broken down in: 3 Discs => 2 Discs => 1 Disc
