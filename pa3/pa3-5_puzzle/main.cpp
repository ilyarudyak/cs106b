#include <iostream>
#include <vector>
using namespace std;

void Solvable(string acc, int position, vector<int> &squares) {

    if (position == (squares.size() - 1)) {
        cout << acc << endl;
        return;
    }


    if (position + squares[position] < squares.size()) {
        Solvable(acc + to_string(position),
                 position + squares[position], squares);
    }

    if (position - squares[position] >= 0) {
        Solvable(acc + to_string(position),
                 position - squares[position], squares);
    }

}

int main() {

    vector<int> squares = {3, 6, 4, 1, 3, 4, 2, 5, 3, 0};
    Solvable("test", 0, squares);

    return 0;
}


















