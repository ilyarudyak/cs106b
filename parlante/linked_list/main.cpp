#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};
Node *newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->next = nullptr;
    return node;
}
Node *buildOneTwoThree() {
    Node *node = newNode(1);
    node->next = newNode(2);
    node->next->next = newNode(3);
    return node;
}
void printList(Node *node) {
    if (node == nullptr) {
        cout << "the list is empty ..." << endl;
        return;
    }

    if (node->next == nullptr) {
        cout << node->data << endl;
    } else {
        cout << node->data << "->";
        printList(node->next);
    }
}
int length(Node *node) {
    if (node == nullptr) {
        return 0;
    }

    return 1 + length(node->next);
}
void pushWith2Ptr(Node **head, int data) {
    Node *node = newNode(data);
    node->next = *head;
    *head = node;
}
void push(Node *&head, int data) {
    Node *node = newNode(data);
    node->next = head;
    head = node;
}
int count(int acc, Node *node, int data) {
    if (node == nullptr) {
        return acc;
    }

    if (node->data == data) {
        return count(acc + 1, node->next, data);
    } else {
        return count(acc, node->next, data);
    }

}
Node *sampleList(fstream &in) {
    int data;
    Node *head = nullptr;
    while(in >> data) {
        push(head, data);
    }
    return head;
}


int main() {

    // test basic functions
//    Node *head = buildOneTwoThree();
//    printList(head);
//    cout << length(head) << endl;

    // test push()
//    Node *head = nullptr;
//    push(head, 3); push(head, 2); push(head, 1);
//    printList(head);

    // test count
    fstream in("list.txt");
    Node *head = sampleList(in);
    printList(head);
    cout << count(0, head, 3) << endl;

    return 0;
}
















