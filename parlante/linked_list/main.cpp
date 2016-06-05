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
void pushTail(Node *&head, Node *&tail, int data) {
    Node *node = newNode(data);

    if (head == nullptr) {
        head = tail = node;
        return;
    }

    tail->next = node;
    tail = node;
}
void pushTail2(Node *&head, Node *&tail, Node *node) {

    if (head == nullptr) {
        head = tail = node;
        return;
    }

    tail->next = node;
    tail = node;
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
void sortedInsert2(Node *&node, Node *node2) {
    if (node == nullptr) {
        node2->next = nullptr;
        node = node2;
        return;
    }

    if (node2->data < node->data) {
        node2->next = node;
        node = node2;
        return;
    }

    sortedInsert2(node->next, node2);
}
void insertSort(Node *&head, Node *&head2) {
    while (head != nullptr) {
        Node *tmp = head->next;
        sortedInsert2(head2, head);
        head = tmp;
    }
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
void shuffleMerge(Node *a, Node *b, Node *&head, Node *tail) {

    if (a == nullptr) {
        pushTail2(head, tail, b);
        return;
    }

    if (b == nullptr) {
        pushTail2(head, tail, a);
        return;
    }

    pushTail2(head, tail, a);
    shuffleMerge(b, a->next, head, tail);

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

    // test sorted (again)
//    fstream in("insert.txt");
//    Node *head = sampleList(in);
//    Node *node2 = newNode(6);
//    printList(head);
//
//    sortedInsert2(head, node2);
//    printList(head);

    // test insert sort
//    fstream in("insert_sort.txt");
//    Node *head = sampleList(in);
//    Node *head2 = nullptr;
//    printList(head);
//
//    insertSort(head, head2);
//    printList(head2);

    // test shuffling
//    fstream in("shuffle.txt");
//    Node *a = sampleList(in);
//    fstream in2("shuffle2.txt");
//    Node *b = sampleList(in2);
//    printList(a);
//    printList(b);
//
//    Node *head = nullptr;
//    Node *tail = nullptr;
//    shuffleMerge(a, b, head, tail);
//    printList(head);

    // test pushTail()
//    Node *head = nullptr;
//    Node *tail = nullptr;
//
//    pushTail(head, tail, 1);
//    printList(head);
//
//    pushTail(head, tail, 2);
//    printList(head);
//
//    pushTail(head, tail, 3);
//    printList(head);

    return 0;
}
















