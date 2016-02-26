//
// Created by Ilya Rudyak on 2/26/16.
//

#include "PQueueList.h"

void PQueueList::enqueue(int data) {
    queue.addSorted(data);
}

int PQueueList::dequeueMin() {
    if (isEmpty()) { throw "queue is empty"; }
    return queue.removeFromHead();
}

bool PQueueList::isEmpty() {
    return queue.isEmpty();
}
