#include <iostream>
#include "Maze.h"
using namespace std;

Point adjacentPoint(Point curPos, Direction dir) {
    switch (dir) {
        case NORTH: return Point(curPos.getX() - 1, curPos.getY()    );
        case EAST:  return Point(curPos.getX()    , curPos.getY() + 1);
        case SOUTH: return Point(curPos.getX() + 1, curPos.getY()    );
        case WEST:  return Point(curPos.getX(),     curPos.getY() - 1);
    }
    return curPos;
}
bool solveMaze(Maze &maze, Point curPos) {

    // base case
    if (maze.isOutside(curPos)) {
        return true;
    }

    if (maze.isMarked(curPos)) {
        return false;
    }


    // inductive case
    maze.markSquare(curPos);
    for (Direction dir = NORTH; dir <= WEST; dir++) {
        if (!maze.wallExists(curPos, dir)) {
            if (solveMaze(maze, adjacentPoint(curPos, dir))) {
                return true;
            }
        }
    }
    maze.unmarkSquare(curPos);

    return false;

}

int main() {

    Maze maze("simple_maze.txt");
    if (solveMaze(maze, maze.getStartPosition())) {
        maze.printMaze();
        cout << "The marked path is a solution." << endl;
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}




















