//
// Created by Ilya Rudyak on 1/27/16.
//

#ifndef MAZE_DIRECTION_H
#define MAZE_DIRECTION_H

#include <string>

enum Direction { NORTH, EAST, SOUTH, WEST };
Direction leftFrom(Direction dir);
Direction rightFrom(Direction dir);
Direction opposite(Direction dir);
std::string directionToString(Direction dir);

std::ostream &operator<<(std::ostream & os, const Direction & dir);
Direction operator++(Direction & dir, int);

#endif //MAZE_DIRECTION_H
