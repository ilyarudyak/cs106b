//
// Created by Ilya Rudyak on 5/12/16.
//

#ifndef ASS7_QUEUEWITHCLL_H
#define ASS7_QUEUEWITHCLL_H

#include "CircularLinkedList.h"

template <typename T>
class QueueWithCLL {

public:
    QueueWithCLL();

    int size() const;
    bool empty() const;

    const T& peek();

    void enqueue(const T&);
    void dequeue();

    void show();

private:
    CircularLinkedList<T> clist;
    int n;
};

template <typename T> QueueWithCLL<T>::QueueWithCLL() : clist(), n(0) { }

template <typename T> int QueueWithCLL<T>::size() const { return n; }
template <typename T> bool QueueWithCLL<T>::empty() const { return n == 0; }

template <typename T> const T& QueueWithCLL<T>::peek() {
    if (empty()) { return nullptr; }
    return clist.front();
}

template <typename T> void QueueWithCLL<T>::enqueue(const T &t) {
    clist.add(t);
    clist.advance();
}
template <typename T> void QueueWithCLL<T>::dequeue() {
    clist.remove();
}
template <typename T> void QueueWithCLL<T>::show() {
    clist.show();
}

#endif //ASS7_QUEUEWITHCLL_H


















