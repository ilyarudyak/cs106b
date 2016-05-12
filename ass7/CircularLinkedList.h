//
// Created by Ilya Rudyak on 5/12/16.
//

#ifndef ASS7_CIRCULARLINKEDLIST_H
#define ASS7_CIRCULARLINKEDLIST_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

template <typename T> class CircularLinkedList {

public:
    CircularLinkedList();
    ~CircularLinkedList();

    bool empty() const;

    const T& front();           // element next to cursor
    const T& back();            // element *at* cursor

    void advance();

    void add (const T&);        // add *after* cursor
    void remove();              // remove *after* cursor

    void show();


private:
    Node<T>* cursor;
};

template <typename T> CircularLinkedList<T>::CircularLinkedList() {
    cursor = nullptr;
}
template <typename T> CircularLinkedList<T>::~CircularLinkedList() {
    while (!empty()) { remove(); }
}

template <typename T> bool CircularLinkedList<T>::empty() const {
    return cursor == nullptr;
}

template <typename T> const T& CircularLinkedList<T>::front() {
    if (empty() || cursor->next == nullptr) {
        return nullptr;
    }
    return cursor->next->data;
}
template <typename T> const T& CircularLinkedList<T>::back() {
    if (empty()) { return nullptr; }
    return cursor->data;
}

template <typename T> void CircularLinkedList<T>::advance() {
    if (empty()) { return; }

    // if only one element cursor will be null
    cursor = cursor->next;
}

template <typename T> void CircularLinkedList<T>::add(const T &t) {
    Node<T> *newNode = new Node<T>;
    newNode->data = t;

    if (empty()) {
        // circular link
        newNode->next = newNode;
        cursor = newNode;
    } else {
        newNode->next = cursor->next;
        // add *after* cursor
        cursor->next = newNode;
    }

}
template <typename T> void CircularLinkedList<T>::remove() {
    if (empty()) { return; }

    // if only one element we delete it (check if it points to itself)
    // otherwise delete element *after* cursor
    if (cursor == cursor->next) {
        delete cursor;
        cursor = nullptr;
    } else {
        Node<T> *tmp = cursor->next;
        cursor->next = tmp->next;
        delete tmp;
    }

}

template <typename T> void CircularLinkedList<T>::show() {
    if (empty()) { cout << "list is empty..."; }

    Node<T> *cur = cursor->next;
    while (true) {
        if (cur == cursor) {
            cout << cur->data << "--->" << cur->next->data << endl;
            break;
        } else {
            cout << cur->data << "->";
            cur = cur->next;
        }
    }

}



#endif //ASS7_CIRCULARLINKEDLIST_H





















