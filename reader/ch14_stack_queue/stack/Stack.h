

#ifndef STACK_STACK_H
#define STACK_STACK_H

template <typename ValueType>
class Stack {

public:

    // constructor and de-constructor
    Stack();
    ~Stack();

    // methods
    int size() const;
    bool isEmpty() const;
    void clear();

    void push(ValueType value);
    ValueType pop();
    ValueType peek() const;

private:

    static const int INITIAL_CAPACITY = 10;

    ValueType *array;
    int capacity;
    int count;

    void expandCapacity();
};

template <typename ValueType>
Stack<ValueType>::Stack() {
    capacity = INITIAL_CAPACITY;
    array = new ValueType[capacity];
    count = 0;
}

template <typename ValueType>
Stack<ValueType>::~Stack() {
    delete[] array;
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
    count = 0;
}


template <typename ValueType>
void Stack<ValueType>::push(ValueType value) {

    if (count == capacity) {
        expandCapacity();
    }
    array[count++] = value;
}

template <typename ValueType>
ValueType Stack<ValueType>::pop() {
    if (count > 0) {
        return array[--count];
    }
}

template <typename ValueType>
ValueType Stack<ValueType>::peek() const {
    if (count > 0) {
        return array[count - 1];
    }
}


template <typename ValueType>
void Stack<ValueType>::expandCapacity() {
    ValueType *oldArray = array;
    capacity *= 2;
    array = new ValueType[capacity];
    for (int i = 0; i < count; i++) {
        array[i] = oldArray[i];
    }
    delete[] oldArray;
}

#endif //STACK_STACK_H




















