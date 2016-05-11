//
// Created by Ilya Rudyak on 5/10/16.
//

#ifndef ASS7_STACKWITHVECTOR_H
#define ASS7_STACKWITHVECTOR_H

#include <vector>
#include <algorithm>
using namespace std;

template <typename T> class StackWithVector {

public:
    StackWithVector();
    void push(T);
    T pop();
    bool isEmpty();
    void reverse();
    void show();
    vector<T> & getStack();

private:
    vector<T> stack;

};

template <typename T> StackWithVector<T>::StackWithVector() {

}

template <typename T> void StackWithVector<T>::push(T t) { stack.push_back(t); }

template <typename T> T StackWithVector<T>::pop() {
    T temp = stack.back();
    stack.pop_back();
    return temp;
}

template <typename T> bool StackWithVector<T>::isEmpty() {
    return stack.empty();
}

template <typename T> void StackWithVector<T>::reverse() {
    std::reverse(stack.begin(), stack.end());
}

template <typename T> void StackWithVector<T>::show() {
        for (int i = 0; i < stack.size(); ++i) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

template <typename T> vector<T> & StackWithVector<T>::getStack() {
    return stack;
}


#endif //ASS7_STACKWITHVECTOR_H




















