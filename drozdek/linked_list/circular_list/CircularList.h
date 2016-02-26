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
/*
class CircleList { public:
    CircleList();
    ̃CircleList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void advance();
    void add(const Elem& e);
    void remove();
private:
    CNode* cursor;
// a circularly linked list
// constructor
// destructor
// is list empty?
// element at cursor
// element following cursor // advance cursor
// add after cursor
// remove node after cursor
// the cursor
}; */


#endif //CIRCULAR_LIST_CIRCULARLIST_H


























