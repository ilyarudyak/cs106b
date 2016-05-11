#include <iostream>
#include "StackWithVector.h"


using namespace std;

int main() {

    StackWithVector<int> stack;

    for (int i = 0; i < 10; ++i) { stack.push(i); }
    cout << "before reverse: "; stack.show();

    stack.reverse();
    cout << "after  reverse: "; stack.show();

    reverse(stack.getStack().begin(), stack.getStack().end());
    cout << "after reverse2: "; stack.show();

    return 0;
}