#include <iostream>
#include <fstream>
#include "BST.h"
#include "QueueWithArray.h"
using namespace std;

int main() {

    // queue implementation with array
    QueueWithArray<int> queue;
    queue.show();
    for (int i = 0; i < 5; ++i) {
        queue.enqueue(i);
    }
    queue.show();

    queue.dequeue();
    queue.show();

    queue.dequeue();
    queue.show();

    queue.enqueue(5);
    queue.show();

    queue.enqueue(6);
    queue.show();
    queue.enqueue(7);
    queue.show();

    // 5. height() and isBalanced()
//    BST<string> tree;
//    ifstream in("tinyST.txt");
//    string letter;
//    while (in >> letter) {
//        tree.insert(letter);
//    }
//
//    tree.breadthFirst();
//    cout << tree.height() << endl;

//    cout << tree.isBalanced() << endl;

//    BST<string> tree2;
//        ifstream in("balanced.txt");
//    string letter;
//    while (in >> letter) {
//        tree2.insert(letter);
//    }
//
//    tree2.breadthFirst();
//    cout << "balanced:" << tree2.isBalanced() << endl;
//    cout << "balanced:" << tree2.isBalancedEff() << endl;


    // 4. trim leaves
//    BST<string> tree;
//    tree.insert("Jan");
//    tree.insert("Cindy"); tree.insert("Marsha");
//    tree.insert("Bobby"); tree.insert("Greg"); tree.insert("Peter");
//    tree.insert("Tiger");
//    tree.breadthFirst();
//
//    tree.trimLeaves();
//    tree.breadthFirst();

    // 3. tree equal
//    BST<string> tree2;
//    tree.insert("B"); tree.insert("A"); tree.insert("C");
//    tree2.insert("B"); tree2.insert("A"); tree2.insert("X");
//    cout << (tree == tree2) << endl;

    // test BST methods
//    ifstream in("tinyST.txt");
//    string letter;
//    while (in >> letter) {
//        tree.insert(letter);
//    }
//
//    tree.breadthFirst();


    return 0;
}