#ifndef MAZE_POINT_H
#define MAZE_POINT_H

#include <iostream>
#include <string>

class Point {

public:
    Point();
    Point(int x, int y);
    int getX() const;
    int getY() const;
    std::string toString() const;
    bool operator==(const Point &p2) const;
    bool operator!=(const Point &p2) const;


private:
    int x;
    int y;
};

// overload << operator to print Point w/o toString()
std::ostream & operator<<(std::ostream & os, const Point & pt);

#endif //MAZE_POINT_H
