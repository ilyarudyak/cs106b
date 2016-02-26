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
Node* convertToListRec(vector<int> &v, int index) {
    if (index >= v.size()) {
        return nullptr;
    }

    Node *cur = new Node;
    cur->data = v[index];
    cur->next = convertToListRec(v, index + 1);
    return cur;
}
Node * convertToListRec(vector<int> &v) {
    return convertToListRec(v, 0);
}
int sumList(Node *&head) {
    int sum = 0;
    for (Node *w = head; w != nullptr; w = w->next) {
        sum += w->data;
    }
    return sum;

}
int sumListRec(Node *&head) {
    if (head == nullptr) {
        return 0;
    } else {
        return head->data + sumList(head->next);
    }
}
void popRocks(Node * & mikey) {
    Node *ptr;
    for (ptr = mikey; ptr->next != NULL; ptr = ptr->next) { }
    ptr->next = mikey;
    ptr = ptr->next;
    mikey = mikey->next;
    ptr->next = NULL;
}
void append (Node *&first, Node *&second) {
    if (first == nullptr) { first = second; }
    Node *w = nullptr;
    for( w = first; w->next != nullptr; w = w->next) { }
    w->next = second;
}
void appendRec(Node *&first, Node *&second) {
    if (first == NULL) {
        first = second;
    }
    else {
        appendRec(first->next, second);
    }
}

int main() {

    vector<int> v = {1, 4, 6};
    vector<int> v2 = {3, 19, 2};
    Node *first = convertToList(v);
    Node *second = convertToList(v2);
//    append(first, second);
    appendRec(first, second);
    printList(first);

    // test popRocks()
//    vector<int> v = {15, 30, 45, 60};
//    Node *head = convertToList(v);
//    popRocks(head);
//    printList(head);

//    vector<int> v = {1, 2, 3, 4, 5};

//    Node *head = convertToList(v);
//    printList(head);
//
//    cout << sumList(head) << endl;
//    cout << sumListRec(head) << endl;

//    Node *head2 = convertToListRec(v);
//    printList(head2);

    return 0;
}
































