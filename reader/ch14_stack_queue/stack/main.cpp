#include <iostream>
#include "Stack.h"
using namespace std;

int main() {

    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.peek() << endl;
    return 0;
}