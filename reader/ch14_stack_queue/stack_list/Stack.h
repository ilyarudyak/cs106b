
#ifndef STACK_LIST_STACK_H
#define STACK_LIST_STACK_H

template <typename ValueType>
class Stack {

public:
    Stack();
    ~Stack();

    int size() const;
    bool isEmpty() const;
    void clear();

    void push(ValueType value);
    ValueType pop();
    ValueType peek() const;


private:

    struct Node {

        ValueType data;
        Node *next;
    };

    Node *first;
    int count;
};

template <typename ValueType>
Stack<ValueType>::Stack() {
    first = nullptr;
    count = 0;
}

template <typename ValueType>
Stack<ValueType>::~Stack() {
    clear();
}

template <typename ValueType>
int Stack<ValueType>::size() const {
    return count;
}

template <typename ValueType>
bool Stack<ValueType>::isEmpty() const {
    return count == 0;
}

template <typename ValueType>
void Stack<ValueType>::clear() {
    while (count > 0) {
        pop();
    }
}


template <typename ValueType>
void Stack<ValueType>::push(ValueType value) {

    Node *cp = new Node;
    cp->data = value;

    // this works even if first == nullptr
    cp->next = first;
    first = cp;

    count++;
}

template <typename ValueType>
ValueType Stack<ValueType>::peek() const {
    if (first != nullptr) {
        return first->data;
    }
}

template <typename ValueType>
ValueType Stack<ValueType>::pop() {
    if (first != nullptr) {

        // store tmp variables
        ValueType res = first->data;
        Node *tmp = first;

        // update first (now it points to
        // the 2nd element)
        first = first->next;

        // clear popped Node
        delete tmp;
        count--;

        return res;
    }
}

#endif //STACK_LIST_STACK_H






























