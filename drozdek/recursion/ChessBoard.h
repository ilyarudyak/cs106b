//
// Created by Ilya Rudyak on 5/26/16.
//

#ifndef RECURSION_CHESSBOARD_H
#define RECURSION_CHESSBOARD_H

#include <iostream>
using namespace std;

class ChessBoard {
public:
    ChessBoard();    // 8 x 8 chessboard;
    ChessBoard(int); // n x n chessboard;

    void findSolutions();

private:
    const bool available; // this is just a synonym for true
    const int squares;    // size of chessboard
    int norm;

    bool *column, *leftDiagonal, *rightDiagonal;
    int  *positionInRow;  // position of queen in a given row

    int countSolutions;

    void initializeBoard();
    void putQueen(int);
    void printBoard();

};

ChessBoard::ChessBoard() : available(true), squares(8), norm(squares-1) {
    initializeBoard();
}
ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(squares-1) {
    initializeBoard();
}

void ChessBoard::initializeBoard() {
    int i;

    // just allocate arrays for board
    column = new bool[squares];
    positionInRow = new int[squares];
    // we have 2 diagonals for a queen
    leftDiagonal  = new bool[squares*2 - 1];
    rightDiagonal = new bool[squares*2 - 1];

    for (i = 0; i < squares; i++) { positionInRow[i] = -1; }
    for (i = 0; i < squares; i++) { column[i] = available; }
    for (i = 0; i < squares*2 - 1; i++) { leftDiagonal[i] = rightDiagonal[i] = available; }

    countSolutions = 0;
}
void ChessBoard::printBoard() {
    for (int i = 0; i < squares; ++i) {
        for (int j = 0; j < squares; ++j) {
            if (j == positionInRow[i]) { cout << "X "; }
            else { cout << "- "; }
        }
        cout << endl;
    }
    cout << endl;

}

void ChessBoard::putQueen(int row) {
    for (int col = 0; col < squares; col++)

        // if column is available
        if (column[col] == available &&
            leftDiagonal [row+col] == available &&
            rightDiagonal[row-col+norm] == available) {

            // place queen in col
            positionInRow[row] = col;
            column[col] = !available;
            leftDiagonal[row+col] = !available;
            rightDiagonal[row-col+norm] = !available;

            // recursion
            if (row < squares-1) { putQueen(row+1); }
            else { printBoard(); countSolutions++; }

            // remove queen when return from recursion
            column[col] = available;
            positionInRow[row] = -1;
            leftDiagonal[row+col] = available;
            rightDiagonal[row-col+norm] = available;
        }
}
void ChessBoard::findSolutions() {
    putQueen(0);
    cout << countSolutions << " solutions found.\n";
}



#endif //RECURSION_CHESSBOARD_H
