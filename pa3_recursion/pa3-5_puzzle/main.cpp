#include <iostream>
#include <vector>
using namespace std;

bool solvable(string acc, int curPos, vector<int> &squares, vector<bool> marked) {

    if (curPos < 0 || curPos > squares.size() - 1 || marked[curPos]) {
        return false;
    }

    if (curPos == squares.size() - 1) {
        cout << acc + " " + to_string(curPos) + ":" + to_string(squares[curPos]) << endl;
        return true;
    }

    marked[curPos] = true;

    return solvable(acc + to_string(curPos) + ":" + to_string(squares[curPos]) + " ",
             curPos + squares[curPos], squares, marked) ||
           solvable(acc + to_string(curPos) + ":" + to_string(squares[curPos]) + " ",
             curPos - squares[curPos], squares, marked);


}

int main() {

    vector<int> squares = {3, 6, 4, 1, 3, 4, 2, 5, 3, 0};
    vector<bool> marked(squares.size(), false);
    solvable("", 0, squares, marked);

    return 0;
}


















