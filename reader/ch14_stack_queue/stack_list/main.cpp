#include <iostream>
#include "Stack.h"
using namespace std;

int main() {

    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.peek() << endl;
    return 0;
}