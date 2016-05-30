//
// Created by Ilya Rudyak on 1/27/16.
//

#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

#include <string>
#include <vector>
#include <fstream>
#include "Point.h"
#include "Direction.h"

using namespace std;

class Maze {

public:
    Maze(string filename);

    // check if next move is possible
    bool isOutside(Point pt);
    bool wallExists(Point pt, Direction dir);

    // mark and unmark square
    void markSquare(Point pt);
    void unmarkSquare(Point pt);
    bool isMarked(Point pt);

    // utility functions
    void printMaze();
    Point getStartPosition();

private:
    struct Square {
        bool marked;
        bool walls[4];
    };

    // maze.size()    - number of rows
    // maze[0].size() - number of columns
    vector<vector<Square> > maze;
    Point startSquare;
    int rows;
    int cols;

    /* private functions */

    // read file
    void readMazeFile(string filename);
    void computeMazeSize(ifstream & infile);
    void processMazeFile(ifstream &in);
    void processDividerLine(string line, int x);
    void processPassageLine(string line, int z);
    void setHorizontalWall(Point pt);
    void setVerticalWall(Point pt);
    void setStartSquare(Point pt);

    // adj point in given direction
    Point adjacentPoint(Point start, Direction dir);

};


#endif //MAZE_MAZE_H
