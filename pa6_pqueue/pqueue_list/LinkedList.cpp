#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::addToHead(int data) {
    head = new Node(data, head);
}

void LinkedList::addSorted(int data) {

    if (isEmpty() || head->data > data) {
        addToHead(data);
        return;
    }


    Node *prev = head; Node *walker = head;
    while (walker != nullptr) {
        if (walker->data > data) {
            prev->next = new Node(data, walker);
            return;
        }
        prev = walker;
        walker = walker->next;
    }

    prev->next = new Node(data);
}

// ------------- utility functions -------------

void LinkedList::printList() const {

    Node *walker = head;
    while (walker != nullptr) {
        if (walker->next != nullptr) {
            cout << walker->data << "->";
        } else {
            cout << walker->data << endl;
        }
        walker = walker->next;
    }

}



