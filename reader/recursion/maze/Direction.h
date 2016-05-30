//
// Created by Ilya Rudyak on 1/27/16.
//

#ifndef MAZE_DIRECTION_H
#define MAZE_DIRECTION_H

#include <string>
using namespace std;

enum Direction { NORTH, EAST, SOUTH, WEST };
Direction leftFrom(Direction dir);
Direction rightFrom(Direction dir);
Direction opposite(Direction dir);
string directionToString(Direction dir);

std::ostream &operator<<(std::ostream & os, const Direction & dir);
Direction operator++(Direction & dir, int);

#endif //MAZE_DIRECTION_H
