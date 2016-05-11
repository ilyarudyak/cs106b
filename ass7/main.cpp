#include <iostream>
#include "StackWithVector.h"
#include "RandomQueue.h"
#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList<int> list;
    for (int i = 4; i >= 0; --i) {
        list.addFront(i);
    }
    list.show();

    list.stutter();
    list.show();

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



















