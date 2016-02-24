#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList list;

    // (1) test add functions
    for (int i = 0; i < 5; ++i) {
        list.addToTail(i);
    }
    list.addToHead(10);
    list.addToTail(100);
    list.printList();

    // (2) test delete functions
    cout << list.deleteFromHead() << endl;
    cout << list.deleteFromTail() << endl;
//    list.deleteNode(2);
    list.printList();
//
//    // (3) test search
//    cout << list.isInList(1) << endl;


    return 0;
}























