//
// Created by Ilya Rudyak on 2/26/16.
//

#ifndef CIRCULAR_LIST_CIRCULARLIST_H
#define CIRCULAR_LIST_CIRCULARLIST_H

class Node {
public:
    Node() : data(0), next(nullptr) { }
    Node(int data, Node *next = nullptr) {
        this->data = data;
        this->next = next;
    }
    int data;
    Node *next;
};

class CircularList {

public:
    CircularList() : cursor(nullptr) { };

    bool empty();
    int head();                         // node after cursor
    int tail();                         // node at cursor
    void advance();                     // advance cursor one position forward
    void addAfterCursor(int data);      // add after cursor
    void removeAfterCursor();           // remove after cursor
    void printList();                   // print list

private:
    Node *cursor;
};


#endif //CIRCULAR_LIST_CIRCULARLIST_H


























