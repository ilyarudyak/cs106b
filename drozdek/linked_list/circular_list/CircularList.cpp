#include "CircularList.h"
#include <iostream>
using namespace std;

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
    if (!empty() && cursor->next != cursor) {
        cursor = cursor->next;
    }
}

void CircularList::addAfterCursor(int data) {
    if (empty()) {
//        cursor = new Node(data, cursor);
//        cursor->next = cursor;

        Node *newNode = new Node;
        newNode->data = data;
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
    if (empty()) { throw "the list is empty"; }

    // only one node in the list
    if (cursor->next == cursor) {
        delete cursor;
        cursor = nullptr;
    } else {
        Node *tmp = cursor->next->next;
        delete cursor->next;
        cursor->next = tmp;
    }
}

void CircularList::printList() {
    if (empty()) {
        cout << "list is empty" << endl;
    }

    Node *walker = cursor;
    while (walker != nullptr) {
        cout << walker->data << "->";
        walker = walker->next;
        if (walker == cursor) {
            cout << cursor->data << endl;
            break;
        }
    }

}















