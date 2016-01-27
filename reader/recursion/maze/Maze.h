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

class Maze {

public:
    Maze(std::string filename);
    Point getStartPosition();
    bool isOutside(Point pt);
    bool wallExists(Point pt, Direction dir);
    void markSquare(Point pt);
    void unmarkSquare(Point pt);
    bool isMarked(Point pt);
    void printMaze();

private:
    struct Square {
        bool marked;
        bool walls[4];
    };

    // maze.size()    - number of rows
    // maze[0].size() - number of columns
    std::vector<std::vector<Square> > maze;
    Point startSquare;
//    double x0;
//    double y0;
    int rows;
    int cols;

    /* private functions */

    // read file
    void readMazeFile(std::string filename);
    void computeMazeSize(std::ifstream & infile);
    void processMazeFile(std::ifstream &in);
    void processDividerLine(std::string line, int x);
    void processPassageLine(std::string line, int z);
    void setHorizontalWall(Point pt);
    void setVerticalWall(Point pt);
    void setStartSquare(Point pt);



    // adj point in given direction
    Point adjacentPoint(Point start, Direction dir);

};


#endif //MAZE_MAZE_H
