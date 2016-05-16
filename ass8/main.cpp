#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;

int main() {

    BST<string> tree;

    // 3. tree equal
    BST<string> tree2;
    tree.insert("B"); tree.insert("A"); tree.insert("C");
    tree2.insert("B"); tree2.insert("A"); tree2.insert("X");
    cout << (tree == tree2) << endl;

    // test BST mathods
//    ifstream in("tinyST.txt");
//    string letter;
//    while (in >> letter) {
//        tree.insert(letter);
//    }
//
//    tree.breadthFirst();


    return 0;
}