//
// Created by Ilya Rudyak on 2/26/16.
//

#ifndef PA6_PQUEUE_PQUEUELIST_H
#define PA6_PQUEUE_PQUEUELIST_H


#include "LinkedList.h"

class PQueueList {
public:
    PQueueList() = default;

    // main operations
    void enqueue(int t);
    int dequeueMin();

    // utility functions
    bool isEmpty();

private:

    LinkedList queue;

};


#endif //PA6_PQUEUE_PQUEUELIST_H
