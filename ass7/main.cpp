#include <iostream>
#include "StackWithVector.h"
#include "RandomQueue.h"
#include "LinkedList.h"
#include "CircularLinkedList.h"

using namespace std;

int main() {

    CircularLinkedList<int> clist;

//    clist.add(0);
//    clist.show();
//
//    clist.add(1);
//    clist.show();

    for (int i = 9; i >=0; --i) {
        clist.add(i);
    }
    clist.show();


//    LinkedList<int> list;

//    list.insertSorted(0); list.show();
//    list.insertSorted(1); list.show();
//    list.insertSorted(5); list.show();
//    list.insertSorted(2); list.show();
//    list.insertSorted(1); list.show();
//    list.insertSorted(1); list.show();
//    list.insertSorted(0); list.show();
//    list.insertSorted(7); list.show();
//    list.insertSorted(8); list.show();
//    list.insertSorted(1); list.show();


//    srand(0);
//    for (int i = 0; i < 10; ++i) {
//        int n = rand() % 10;
//        cout << n << " ";
////        list.insertSortedRec(n);
//    }
//    cout << endl;
//    list.show();


//    for (int i = 4; i >= 0; --i) {
//        list.addFront(i);
//    }
//    list.showRec();

//    list.stutter();
//    list.show();
//
//    list.unstutter();
//    list.show();

//    srand((unsigned int) time(nullptr));
//    RandomQueue<int> queue;
//    for (int i = 0; i < 10; ++i) { queue.enqueue(i); }
//    queue.show();
//
//    for (int j = 0; j < 10; ++j) {
//        cout << queue.dequeue() << " queue: ";
//        queue.show();
//    }

//    StackWithVector<int> stack;
//
//    for (int i = 0; i < 10; ++i) { stack.push(i); }
//    cout << "before reverse: "; stack.show();
//
//    stack.reverse();
//    cout << "after  reverse: "; stack.show();
//
//    reverse(stack.getStack().begin(), stack.getStack().end());
//    cout << "after reverse2: "; stack.show();

    return 0;
}



















