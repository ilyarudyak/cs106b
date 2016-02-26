//
// Created by Ilya Rudyak on 2/24/16.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;


LinkedList::~LinkedList() {
    Node *walker = nullptr;
    while (head != nullptr) {
        walker = head->next;
        delete head;
        head = walker;
    }
}

// ------------- add functions -------------

void LinkedList::addToHead(int data) {

    // this is a traditional approach
    // we may also use: head = new Node(data,head);
    Node *newNode = new Node();
    newNode->data = data;
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}
void LinkedList::addToTail(int data) {

    Node *newNode = new Node();
    newNode->data = data;
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }


}

// ------------- delete functions -------------

int LinkedList::deleteFromHead() {

    Node *tmp = nullptr;
    if (!isEmpty()) {
        int data = head->data;
        tmp = head;
        if (head != tail) {
            head = head->next;
        } else {
            head = tail = nullptr;
        }
        delete tmp;
        return data;
    } else {
        throw "list is empty";
    }
}
int LinkedList::deleteFromTail() {

    if (!isEmpty()) {
        int data = tail->data;
        if (head != tail) {
            Node *walker = head;
            while (walker->next != tail) {
                walker = walker->next;
            }
            tail = walker;
            tail->next = nullptr;
            delete walker->next;
        } else {
            delete head;
            head = tail = nullptr;
        }
        return data;
    } else {
        throw "list is empty";
    }
}
void LinkedList::deleteNode(int i) {

}

// ------------- search functions -------------

bool LinkedList::isInList(int i) const {
    return false;
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



















