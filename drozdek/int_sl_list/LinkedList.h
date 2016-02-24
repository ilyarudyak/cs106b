#ifndef INT_SL_LIST_INTSLLIST_H
#define INT_SL_LIST_INTSLLIST_H

class Node {

public:

    Node() : data(0), next(nullptr) { };
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }

    int data;
    Node *next;
};

class LinkedList {
public:

    LinkedList() : head(nullptr), tail(nullptr) { }
    ~LinkedList();

    int isEmpty() {
        return head == 0;
    }
    void addToHead(int);
    void addToTail(int);
    int  deleteFromHead();
    int  deleteFromTail();
    void deleteNode(int);
    bool isInList(int) const;
    void printList() const;

private:
    Node *head, *tail;
};


#endif //INT_SL_LIST_INTSLLIST_H














