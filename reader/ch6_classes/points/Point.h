
#ifndef POINTS_POINT_H
#define POINTS_POINT_H


#include <iostream>
#include <string>

class Point {

public:
    Point();
    Point(int xc, int yc);
    int getX();
    int getY();
    std::string toString();

    friend bool operator==(Point p1, Point p2);

private:
    int x;
    int y;
};

std::ostream &operator<<(std::ostream &os, Point pt);

bool operator==(Point p1, Point p2);

bool operator!=(Point p1, Point p2);

#endif //POINTS_POINT_H
