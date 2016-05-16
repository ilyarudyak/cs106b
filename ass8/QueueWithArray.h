//
// Created by Ilya Rudyak on 5/16/16.
//

#ifndef ASS8_QUEUEWITHARRAY_H
#define ASS8_QUEUEWITHARRAY_H

#include <iostream>

template<class T, int size = 5> class QueueWithArray {
public:
    QueueWithArray() {
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

private:
    int first, last;
    T storage[size];
};

template<class T, int size> void QueueWithArray<T,size>::enqueue(T el) {

    if (isFull()) {
        std::cout << "queue is full..." << std::endl;
        return;
    }

    if (isEmpty()) {
        first = 0;
    }

    last = (last + 1) % size;
    storage[last] = el;


}
template<class T, int size> T QueueWithArray<T,size>::dequeue() {

    if (isEmpty()) {
        std::cout << "queue is empty ..." << std::endl;
    }

    T tmp = storage[first];
    storage[first] = -1;
    first = (first + 1) % size;
    return tmp;
}


#endif //ASS8_QUEUEWITHARRAY_H






















