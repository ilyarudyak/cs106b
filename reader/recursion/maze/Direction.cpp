//
// Created by Ilya Rudyak on 1/27/16.
//

#include "Direction.h"

Direction leftFrom(Direction dir) {
    return Direction((dir + 3) % 4);
}

Direction rightFrom(Direction dir) {
    return Direction((dir + 1) % 4);
}

Direction opposite(Direction dir) {
    return Direction((dir + 2) % 4);
}

std::string directionToString(Direction dir) {
    switch (dir) {
        case NORTH: return "NORTH";
        case EAST: return "EAST";
        case SOUTH: return "SOUTH";
        case WEST: return "WEST";
        default: return "???";
    }
}

std::ostream & operator<<(std::ostream & os, const Direction & dir) {
    return os << directionToString(dir);
}

Direction operator++(Direction & dir, int) {
    Direction old = dir;
    dir = Direction(dir + 1);
    return old;
}









