//
// Created by Ilya Rudyak on 5/12/16.
//

#ifndef ASS7_DOUBLYLINKEDLIST_H
#define ASS7_DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T> struct DNode {
    T data;
    DNode* prev;
    DNode* next;
};

template <typename T> class DoublyLinkedList {

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool empty() const;

    const T& front() const;
    const T& back() const;

    void addFront(T&);
    void addBack(T&);
    void removeFront();
    void removeBack();

private:
    DNode<T> *header;
    DNode<T> *trailer;

};

#endif //ASS7_DOUBLYLINKEDLIST_H
















