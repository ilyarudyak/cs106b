#include <iostream>
#include "Point.h"
using namespace std;

int main() {

    Point p1(1, 2), p2(3, 4);
    cout << "compare points p1 and p2: " << (p1 != p2) << endl;
    return 0;
}