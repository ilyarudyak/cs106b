#ifndef PA6_PQUEUE_LINKEDLIST_H
#define PA6_PQUEUE_LINKEDLIST_H

class Node {
public:
    Node() : next(nullptr) { }
    Node(int data, Node *next = nullptr) {
        this->data = data;
        this->next = next;
    }
    int data;
    Node *next;
};

class LinkedList {

public:
    LinkedList() : head(nullptr) { }

    bool isEmpty() {
        return head == nullptr;
    }
    void addToHead(int);
    void addSorted(int);
    int removeFromHead();
    void printList() const;



private:
    Node *head;

};


#endif //PA6_PQUEUE_LINKEDLIST_H
