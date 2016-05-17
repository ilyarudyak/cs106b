//
// Created by Ilya Rudyak on 5/17/16.
//

#ifndef ASS8_QUEUEWITHARRAY2_H
#define ASS8_QUEUEWITHARRAY2_H

#include <iostream>

template<typename T> class QueueWithArray2 {
public:
    QueueWithArray2() {
        size = initSize;
        storage = new T[initSize];
        first = last = -1;
        for (int i = 0; i < size; ++i) {
            storage[i] = -1;
        }
    }

    void enqueue(T);
    T dequeue();

    bool isFull()  {
        return (first == 0 && last == size-1) ||
               first == last + 1;
    }
    bool isEmpty() {
        return first == -1;
    }
    void show() {
        for (int i = 0; i < size; ++i) {
            std::cout << storage[i] << " ";
        }
        std::cout << "first=" << first
        << " last=" << last << std::endl;
    }
    void resize();

private:
    int first, last;
    const static int initSize = 5;
    int size;
    T *storage;
};

template<class T> void QueueWithArray2<T>::enqueue(T el) {

    if (isFull()) {
        resize();
    }

    if (isEmpty()) {
        first = 0;
    }

    last = (last + 1) % size;
    storage[last] = el;

}
template<class T> T QueueWithArray2<T>::dequeue() {

    if (isEmpty()) {
        std::cout << "queue is empty ..." << std::endl;
        return *(new T);
    }

    T tmp = storage[first];
    storage[first] = -1;
    first = (first + 1) % size;
    return tmp;
}
template<class T> void QueueWithArray2<T>::resize() {
    T *newStorage = new T[2 * size];
    for (int i = 0; i < size; ++i) {
        newStorage[i] = storage[(first + i) % size];
    }

    first = 0;
    last = size - 1;

    size = 2 * size;
    storage = newStorage;
}

#endif //ASS8_QUEUEWITHARRAY2_H
