#include "Maze.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

Maze::Maze(std::string filename) {
    readMazeFile(filename);
}

Point Maze::getStartPosition() {
    return startSquare;
}
bool Maze::isOutside(Point pt) {
    return pt.getX() < 0 || pt.getY() < 0
           || pt.getX() >= rows
           || pt.getY() >= cols;

}
bool Maze::wallExists(Point pt, Direction dir) {

    return maze[pt.getX()][pt.getY()].walls[dir];
}

// mark and unmark squares
void Maze::markSquare(Point pt) {
    if (isOutside(pt)) { throw "coordinates are out of range"; }
    maze[pt.getX()][pt.getY()].marked = true;
}
void Maze::unmarkSquare(Point pt) {
    if (isOutside(pt)) { throw "coordinates are out of range"; }
    maze[pt.getX()][pt.getY()].marked = false;
}
bool Maze::isMarked(Point pt) {
    if (isOutside(pt)) { throw "coordinates are out of range"; }
    return maze[pt.getX()][pt.getY()].marked;
}

// print maze
void Maze::printMaze() {

    for (int y = 0; y < cols; ++y) {
        cout << "+-";
    }
    cout << "+" << endl;

    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            string mark;
            if (maze[x][y].marked) {
                mark = "x";
            } else {
                mark = " ";
            }

            if (maze[x][y].walls[WEST]) {
                if (startSquare.getX() == x &&
                    startSquare.getY() == y) {
                    cout << "|S";
                } else {
                    cout << "|" + mark;
                }
            } else {
                if (startSquare.getX() == x &&
                    startSquare.getY() == y) {
                    cout << " S";
                } else {
                    cout << " " + mark;
                }
            }
            if (y == cols - 1 && maze[x][y].walls[EAST]) {
                cout << "|";
            }
        }
        cout << endl;

        for (int y = 0; y < cols; ++y) {
            if (maze[x][y].walls[SOUTH]) {
                cout << "+-";
            } else {
                cout << "+ ";
            }
        }
        cout << "+" << endl;
    }
}

/* private functions */

// read file
void Maze::readMazeFile(std::string filename) {
    std::ifstream in(filename.c_str());
    if (in.fail()) throw "can't open file";
    computeMazeSize(in);
    processMazeFile(in);
}
void Maze::computeMazeSize(std::ifstream &in) {
    string line;
    getline(in, line);
    rows = stoi(line);
    getline(in, line);
    cols = stoi(line);

    // resize and fill-in maze
    maze.resize((unsigned long)rows,
                vector<Square>((unsigned long)cols));
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            for (int i = 0; i < 4; i++) {
                maze[row][col].walls[i] = false;
            }
            maze[row][col].marked = false;
        }
    }
}
void Maze::processMazeFile(std::ifstream &in) {
    std::string line;
    for (int x = 0; x < rows; x++) {
        getline(in, line);
        processDividerLine(line, x);
        getline(in, line);
        processPassageLine(line, x);
    }
    getline(in, line);
    processDividerLine(line, rows);
}
// +-+-+-+-+-+-+-+-+
void Maze::processDividerLine(std::string line, int x) {
    for (int y = 0; y < cols; y++) {
        if (line[2 * y] != '+') { cerr << "missing corner symbol"; }
        switch (line[2 * y + 1]) {
            case ' ': break;
            case '-': setHorizontalWall(Point(x, y)); break;
            default: cerr << "illegal character in maze file" << endl;
        }
    }
}
// | | | | | | | | |
void Maze::processPassageLine(std::string line, int x) {
    for (int y = 0; y < cols; y++) {
        if (line[2 * y] == '|') {
            setVerticalWall(Point(x, y));
        }
        switch (line[2 * y + 1]) {
            case ' ': break;
            case 'S': setStartSquare(Point(x, y)); break;
            default:  cerr << "illegal character: "
                      << line[2 * y + 1] << "x=" << x << "y=" << y << endl;
        }
    }
    if (line[2 * cols] == '|') {
        setVerticalWall(Point(x, cols));
    }
}
void Maze::setHorizontalWall(Point pt) {

    if (!isOutside(pt)) {
        maze[pt.getX()][pt.getY()].walls[NORTH] = true;
    }

    if (!isOutside(Point(pt.getX() - 1, pt.getY()))) {
        maze[pt.getX() - 1][pt.getY()].walls[SOUTH] = true;
    }
}
void Maze::setVerticalWall(Point pt) {
    if (!isOutside(pt)) {
        maze[pt.getX()][pt.getY()].walls[WEST] = true;
    }
    if (!isOutside(Point(pt.getX(), pt.getY() - 1))) {
        maze[pt.getX()][pt.getY() - 1].walls[EAST] = true;
    }
}
void Maze::setStartSquare(Point pt) {
    startSquare = pt;
}


Point Maze::adjacentPoint(Point start, Direction dir) {
    int x = start.getX();
    int y = start.getY();
    switch (dir) {
        case NORTH: return Point(x - 1, y    );
        case EAST:  return Point(x    , y + 1);
        case SOUTH: return Point(x + 1, y    );
        case WEST:  return Point(x    , y - 1);
    }
    return start;
}
