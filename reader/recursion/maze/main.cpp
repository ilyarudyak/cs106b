#include <iostream>
#include <vector>
#include "Maze.h"
using namespace std;

void testVector() {
    vector<vector<int>> v = { {1, 2, 3},
                              {10, 20, 30},
                              {100, 200, 300}
    };

    cout << v[2][1] << endl;

    vector<vector<int>> w(5, vector<int>(5));
    w[1][2] = 10;
    cout << w[1][2] << endl;
}

int main() {

    Maze maze("SampleMaze.txt");
    maze.printMaze();

    return 0;
}




















