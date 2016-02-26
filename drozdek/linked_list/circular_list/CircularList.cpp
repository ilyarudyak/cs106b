#include "CircularList.h"

bool CircularList::empty() {
    return cursor == nullptr;
}

int CircularList::head() {
    if (empty()) { throw "the list is empty"; }
    if (cursor->next != nullptr) {
        return cursor->next->data;
    } else {
        return cursor->data;
    }
}

int CircularList::tail() {
    if (empty()) { throw "the list is empty"; }
    return cursor->data;
}

void CircularList::advance() {

}

void CircularList::addAfterCursor(int data) {
    if (empty()) {
//        cursor = new Node(data, cursor);
//        cursor->next = cursor;
        Node *newNode = new Node;
        newNode->data =data;
        // point to itself
        newNode->next = newNode;
        cursor = newNode;
    } else {
//        cursor->next = new Node(data, cursor->next);
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = cursor->next;
        cursor->next = newNode;
    }
}

void CircularList::removeAfterCursor() {

}


void CircularList::printList() {

}















