#include <iostream>
#include <cstdlib>  // includes rand(), srand()
#include <ctime>    // includes time()

using namespace std;

int main() {
    srand(time(0));

    for(int i = 0; i < 10; i++) {
        cout << 1 + (rand() % 6) << endl;
    }
}

//this program generates random number between 1 to 6
// srand() is a function used to seed random values to rand() function