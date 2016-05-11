#include <iostream>
#include "StackWithVector.h"
#include "RandomQueue.h"


using namespace std;

int main() {

    srand((unsigned int) time(nullptr));
    RandomQueue<int> queue;
    for (int i = 0; i < 10; ++i) { queue.enqueue(i); }
    queue.show();

    for (int j = 0; j < 10; ++j) {
        cout << queue.dequeue() << " queue: ";
        queue.show();
    }


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



















