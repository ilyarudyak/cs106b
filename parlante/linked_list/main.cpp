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
int pop(Node *&head) {

    if (head == nullptr) {
        cout << "list is empty ..." << endl;
        return -1;
    }

    int tmp = head->data;
    Node *tmpNode = head;
    head = head->next;
    delete(tmpNode);
    return tmp;
}
void sortedInsert(Node *&node, int data) {
    if (node == nullptr || data < node->data) {
        push(node, data);
        return;
    }

    sortedInsert(node->next, data);
}
void split(Node *&head, Node *&head2) {

    // check for case len == 1

    int n = length(head);
    int count = 0;
    int half = (n % 2 == 0 ? (n / 2) : (n / 2 + 1));

    Node *cur = head;
    while (count < half - 1) {
        count++;
        cur = cur->next;
    }

    head2 = cur->next;
    cur->next = nullptr;
}
void split2(Node *&head, Node *&head2) {

    // check for case len == 1

    Node *slow = head;
    Node *fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    head2 = slow->next;
    slow->next = nullptr;
}
void duplicates(Node *&node) {

    if (node == nullptr || node->next == nullptr) {
        return;
    }

    if (node->next->data == node->data) {
        pop(node->next);
        duplicates(node);
    } else {
        duplicates(node->next);
    }
}
void altSplit(Node *&node, Node *&node2) {

    if (node == nullptr || node->next == nullptr) {
        return;
    }

    Node *tmp = node->next;
    node->next = node->next->next;

    // this works even if node2 == null
    tmp->next = node2;
    node2 = tmp;

    altSplit(node->next, node2);
}


int main() {

//    fstream in("list.txt");
//    Node *head = sampleList(in);

    // test basic functions
//    Node *head = buildOneTwoThree();
//    printList(head);
//    cout << length(head) << endl;

    // test push()
//    Node *head = nullptr;
//    push(head, 3); push(head, 2); push(head, 1);
//    printList(head);

    // test count
//    printList(head);
//    cout << count(0, head, 3) << endl;

    // test pop()
//    cout << pop(head) << endl;
//    printList(head);
//
//    cout << pop(head) << endl;
//    printList(head);

    // test sortedInsert()
//    printList(head);
//
//    sortedInsert(head, 3);
//    printList(head);
//
//    sortedInsert(head, 7);
//    printList(head);

    // test split()
//    fstream in("split2.txt");
//    Node *head = sampleList(in);
//    Node *head2 = nullptr;
//    printList(head);
//
//    split2(head, head2);
//    printList(head);
//    printList(head2);

    // test remove duplicates()
//    fstream in("duplicates.txt");
//    Node *head = sampleList(in);
//    printList(head);
//
//    duplicates(head);
//    printList(head);

    // test altSplit()
//    fstream in("split3.txt");
//    Node *head = sampleList(in);
//    Node *head2 = nullptr;
//    printList(head);
//
//    altSplit(head, head2);
//    printList(head);
//    printList(head2);

    return 0;
}
















