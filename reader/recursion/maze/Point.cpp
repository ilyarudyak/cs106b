#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

std::string Point::toString() const {
    return "(" + std::to_string(x) + "," + std::to_string(y) + ")";;
}

// operator overloading
bool Point::operator==(const Point &p2) const {
    return (x == p2.x) && (y == p2.y);
}
bool Point::operator!=(const Point &p2) const {
    return (x != p2.x) || (y != p2.y);
}
std::ostream &operator<<(std::ostream &os, const Point &pt) {
    return os << pt.toString();
}
