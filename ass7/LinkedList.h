//
// Created by Ilya Rudyak on 5/11/16.
//

#ifndef ASS7_LINKEDLIST_H
#define ASS7_LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T> struct Node {
    T data;
    Node* next;
};

template <typename T> class LinkedList {

public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    int getSize() const ;
    const T& getFront() const;
    void addFront(const T&);
    void removeFront();
    void show();
    void showRec(Node<T>*);
    void showRec();
    void insertSorted(T&);

    // from ass. 7
    // duplicate every node in the list
    // 1->2->3 modified to 1->1->2->2->3->3
    void stutter();
    void unstutter();

private:
    Node<T>* head;
    int size;
};

template <typename T> LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}
template <typename T> LinkedList<T>::~LinkedList() {
    while (!empty()) {
        removeFront();
    };
}
template <typename T> bool LinkedList<T>::empty() const {
    return head == nullptr;
}
template <typename T> int LinkedList<T>::getSize() const {
    return size;
}
template <typename T> const T& LinkedList<T>::getFront() const {
    if (empty()) { return nullptr; }
    else { return head->data; }
}
template <typename T> void LinkedList<T>::addFront(const T &t) {
    Node<T>* newNode = new Node<T>;
    newNode->data = t;

    // this code works even if head == nullptr
    newNode->next = head;
    head = newNode;
    size++;
}
template <typename T> void LinkedList<T>::removeFront() {
    if (empty()) { return; }
    Node<T>* oldHead = head;
    head = head->next;
    delete oldHead;
    size--;
}
template <typename T> void LinkedList<T>::show() {
    if (empty()) {
        cout << "list is empty..." << endl;
        return;
    }
    Node<T>* cur;
    for (cur = head; cur->next != nullptr ; cur = cur->next) {
        cout << cur->data << "->";
    }
    cout << cur->data << endl;
}

template <typename T> void LinkedList<T>::showRec(Node<T>* node) {
    if (node == nullptr) {
        return;
    } else if (node->next == nullptr) {
        cout << node->data << endl;
    } else {
        cout << node->data << "->";
        showRec(node->next);
    }

}
template <typename T> void LinkedList<T>::showRec() {
    showRec(head);
}

template <typename T> void LinkedList<T>::stutter() {
    if (empty()) {
        return;
    }

    for (Node<T> *cur = head; cur != nullptr; cur = cur->next) {
        Node<T> *newNode = new Node<T>;
        newNode->data = cur->data;
        newNode->next = cur->next;
        cur->next = newNode;
        cur = newNode;

    }
}
template <typename T> void LinkedList<T>::unstutter() {
    if (getSize() <= 1) {
        return;
    }

    Node<T>* cur = head->next;
    Node<T>* prev = head;

    for (; cur != nullptr ; cur = cur->next) {
        if (prev->data == cur->data) {
            // remove node
            Node<T> *tmp = cur;
            prev->next = cur->next;
            delete tmp;
        } else {
            // advance pointers
            prev = cur;
        }
    }

}

template <typename T> void LinkedList<T>::insertSorted(T &t) {
    Node<T>* newNode = new Node<T>;
    newNode->data = t;

    cout << "t=" << t << " ";

    Node<T> *cur = head;
    Node<T> *prev = nullptr;

    for (; cur != nullptr; cur = cur->next) {
        if (t == cur->data) { return; }
        if (t < cur->data) { break; }
        prev = cur;
    }

    if (prev == nullptr) {
        newNode->next = nullptr;
        head = newNode;
        cout << "prev=null" << endl;
    } else {
        cout << "prev=" << prev->data << endl;
        newNode->next = cur;
        prev->next = newNode;
    }
}

#endif //ASS7_LINKEDLIST_H



































