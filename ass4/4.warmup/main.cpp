#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *next;
};


void addToHead(Node *&head, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    // this works even if head == nullptr
    newNode->next = head;
    head = newNode;

};
void addToTail(Node *&tail, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    // this works even if head == nullptr
    newNode->next = nullptr;

    tail->next = newNode;
    tail = newNode;

};
void printList(Node *head) {
    for (Node *walker = head; walker != nullptr; walker = walker->next) {
        if (walker->next != nullptr) {
            cout << walker->data << "->";
        } else {
            cout << walker->data;
        }
    }
    cout << endl;
}
Node* convertToList(vector<int> v) {

    Node *head = nullptr;

    // add 0 node
    addToHead(head, v[0]);
    Node *tail = head;

    // add other nodes
    for (int i = 1; i < v.size(); ++i) {
        addToTail(tail, v[i]);
    }
    return head;
}


int main() {

    vector<int> v = {1, 2, 3, 4, 5};
    printList(convertToList(v));
    return 0;
}
































