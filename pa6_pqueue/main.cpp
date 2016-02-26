#include <iostream>
#include "pqueue_vector/PQueueVect.h"
#include "pqueue_list/LinkedList.h"
#include "pqueue_list/PQueueList.h"

using namespace std;

int main() {

    PQueueList pql;
    for (int i = 0; i < 10; ++i) {
        pql.enqueue(i);
    }
    cout << pql.dequeueMin() << endl;
    cout << pql.dequeueMin() << endl;
    cout << pql.dequeueMin() << endl;



//    srand((unsigned int) time(nullptr));
//    LinkedList list;

    // random test of add sorted
//    for (int i = 0; i < 10; ++i) {
//        list.addSorted(rand() % 100);
//    }
//    list.printList();


    // simple test of add sorted
//    list.addSorted(5);
//    list.addSorted(7);
//    list.printList();
//
//    list.addSorted(3);
//    list.addSorted(1);
//    list.printList();

    // test priority queue based on vector
//    PQueueVect<int> pqv;
//    for (int i = 0; i < 100; ++i) {
//        pqv.enqueue(i);
//    }
//    cout << pqv.dequeueMax() << endl;
//    cout << pqv.dequeueMax() << endl;

    return 0;
}