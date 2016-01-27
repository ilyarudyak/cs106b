#include <iostream>
#include "Maze.h"
using namespace std;

Point adjacentPoint(Point start, Direction dir) {
    switch (dir) {
        case NORTH: return Point(start.getX() - 1, start.getY()    );
        case EAST:  return Point(start.getX()    , start.getY() + 1);
        case SOUTH: return Point(start.getX() + 1, start.getY()    );
        case WEST:  return Point(start.getX(),     start.getY() - 1);
    }
    return start;
}

bool solveMaze(Maze &maze, Point start) {
    if (maze.isOutside(start)) return true;
    if (maze.isMarked(start)) return false;
    maze.markSquare(start);
    for (Direction dir = NORTH; dir <= WEST; dir++) {
        if (!maze.wallExists(start, dir)) {
            if (solveMaze(maze, adjacentPoint(start, dir))) {
                return true;
            }
        }
    }
    maze.unmarkSquare(start);
    return false;
}

int main() {

    Maze maze("SampleMaze.txt");
    if (solveMaze(maze, maze.getStartPosition())) {
        maze.printMaze();
        cout << "The marked path is a solution." << endl;
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}




















