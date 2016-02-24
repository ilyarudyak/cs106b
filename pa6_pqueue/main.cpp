#include <iostream>
#include "PQueueVect.h"
using namespace std;

int main() {

    PQueueVect<int> pqv;
    for (int i = 0; i < 100; ++i) {
        pqv.enqueue(i);
    }
    cout << pqv.dequeueMax() << endl;
    cout << pqv.dequeueMax() << endl;

    return 0;
}