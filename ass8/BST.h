//
// Created by Ilya Rudyak on 5/16/16.
//

#ifndef ASS8_BST_H
#define ASS8_BST_H

#include <queue>
#include <iostream>
#include <algorithm>

template<class T> class Node {
public:
    Node() {
        left = right = nullptr;
    }
    Node(const T& e, Node<T> *l = 0, Node<T> *r = 0) {
        data = e; left = l; right = r;
    }
    T data;
    Node<T> *left, *right;
};

template<class T> class BST {

public:

    BST() { root = nullptr; }

    bool isEmpty() const { return root == 0; }

    T* search(const T&) const;
    void insert(const T&);

    void breadthFirst();
    bool operator==(BST<T> &other);
    void trimLeaves();
    int height();


private:
    Node<T> *root;
    bool compare(Node<T> *v, Node<T> *w);
    void trimLeaves(Node<T> *&v);
    bool isLeaf(Node<T> *v) {
        return v->left == nullptr && v->right == nullptr;
    }
    int height(int acc, Node<T> *v);
    int height2(Node<T> *v);
};

template<class T> T* BST<T>::search(const T &t) const {
    if (isEmpty()) { return nullptr; }

    Node<T> *cur = root;
    while (cur != nullptr) {
        if (cur->data == t) {
            return &cur->data;
        }
        else if (cur->data < t) { cur = cur->left; }
        else { cur = cur->right; }
    }
}
template<class T> void BST<T>::insert(const T &t) {

    Node<T> *newNode = new Node<T>(t);
    Node<T> *cur = root;

    if (isEmpty()) {
        root = newNode;
        return;
    }

    while (true) {
        //update data
        if (cur->data == t) {
            cur->data = t;
            return;
        }
        else if (cur->data < t) {
            if (cur->left == nullptr) {
                cur->left = newNode;
                return;
            }
            cur = cur->left;
        }
        else {
            if (cur->right == nullptr) {
                cur->right = newNode;
                return;
            }
            cur = cur->right;
        }
    }
}

template<class T> void BST<T>::breadthFirst() {

    if (isEmpty()) { return; }

    std::queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
        Node<T> *v = q.front();
        q.pop();

        if (v != nullptr) {
            std::cout << v->data << " ";
        }

        if (v->left != nullptr) {
            q.push(v->left);
        }
        if (v->right != nullptr) {
            q.push(v->right);
        }

    }
    std::cout << std::endl;
}

template<class T> bool BST<T>::compare(Node<T> *v, Node<T> *w) {

    if (v == nullptr && w == nullptr) {
        return true;
    } else if ((v != nullptr && w == nullptr) ||
               (v == nullptr && w != nullptr)) {
        return false;
    }

    if (v->data != w->data) {
        return false;
    } else {
        return  compare(v->left, w->left) &&
                compare(v->right, w->right);
    }
}
template<class T> bool BST<T>::operator==(BST<T> &other) {
    return compare(root, other.root);
}

template<class T> void BST<T>::trimLeaves(Node<T> *&v) {

    if (v == nullptr) { return; }
    if (isLeaf(v)) {
        delete(v);
        v = nullptr;
        return;
    }
    trimLeaves(v->left);
    trimLeaves(v->right);
}
template<class T> void BST<T>::trimLeaves() {
    trimLeaves(root);
}

template<class T> int BST<T>::height(int acc, Node<T> *v) {

    if (v == nullptr) { return acc; }

    return std::max(height(acc + 1, v->left),
                    height(acc + 1, v->right));
}
template<class T> int BST<T>::height2(Node<T> *v) {
    if (v == nullptr) {
        return 0;
    }
    return std::max(height2(v->left), height2(v->right)) + 1;
}
template<class T> int BST<T>::height() {
//    return height(0, root);
    return height2(root);
}

#endif //ASS8_BST_H























