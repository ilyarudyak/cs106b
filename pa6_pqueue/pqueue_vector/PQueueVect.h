#ifndef PA6_PQUEUE_PQUEUE_H
#define PA6_PQUEUE_PQUEUE_H

#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class PQueueVect {

public:
    PQueueVect() = default;
//    ~PQueueVect();

    // main operations
    void enqueue(T t);
    T dequeueMax();

    // utility functions
    int size();
    bool isEmpty();

private:

    vector<T> queue;


};

template <typename T>
void PQueueVect<T>::enqueue(T t) {
    queue.push_back(t);
}

template <typename T>
T PQueueVect<T>::dequeueMax() {
    if (queue.empty()) {
        throw "the queue is empty";
    }

    auto maxElemIter = max_element(queue.begin(), queue.end());
    T maxElem = *maxElemIter;
    queue.erase(maxElemIter);

    return maxElem;
}

template <typename T>
int PQueueVect<T>::size() {
    return (int) queue.size();
}

template <typename T>
bool PQueueVect<T>::isEmpty() {
    return queue.empty();
}


#endif //PA6_PQUEUE_PQUEUE_H


























