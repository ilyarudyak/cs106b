#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node *newNode(int data) {
    Node *temp=new Node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}
// we don't use here &node, instead we use node = insert(node)
Node* insert(Node* node, int data) {
    // 1. if the tree is empty, return a new, single node
    if (node == nullptr) {
        return newNode(data);
    }
    else {
        // 2. otherwise, recur down the tree
        if (data <= node->data) { node->left = insert(node->left, data); }
        else { node->right = insert(node->right, data); }

        return node; // return the (unchanged) node pointer
    }
}
Node *sampleBST() {
    Node *root         = newNode(80);
    root->left         = newNode(60);
    root->right        = newNode(110);
    root->left->left   = newNode(35);
    root->left->right  = newNode(40);
    root->right->left  = newNode(85);
    root->right->right = newNode(130);

    return root;
}
Node *sampleBST2(fstream &in) {
    int data;
    Node *root = nullptr;
    while (in >> data) {
        root = insert(root, data);
    }
    return root;
}

int size(Node *node) {

    if (node == nullptr) {
        return 0;
    }

    return 1 + size(node->left) + size(node->right);
}
int leafs(Node *node) {

    if (node == nullptr) {
        return 0;
    }

    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }

    return leafs(node->left) + leafs(node->right);
}
int height(Node *node) {
    if (node == nullptr) {
        return 0;
    }

    return 1 + max(height(node->left), height(node->right));
}
bool pathSum(Node* node, int sum) {

    if (node == nullptr) {
        return false;
    }

    if (node->left == nullptr && node->right == nullptr) {
        return sum == node->data;
    }

    return pathSum(node->left, sum - node->data) ||
           pathSum(node->right, sum - node->data);
}
void preOrder(Node *node) {
    if (node == nullptr) {
        return;
    }

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
void printLevel(Node *node) {

    if (node == nullptr) {
        cout << "tree is empty ..." << endl;
        return;
    }
    queue<Node *> q;
    q.push(node);
    while (!q.empty()) {
        Node *v = q.front();
        q.pop();
        if (v != nullptr) {
            cout << v->data << " ";
            q.push(v->left);
            q.push(v->right);
        }
    }
    cout << endl;
}
void printPaths(string path, Node *node) {
    if (node == nullptr) {
        return;
    }

    if (node->left == nullptr && node->right == nullptr) {
        cout << path + to_string(node->data) << endl;
    } else {
        printPaths(path + to_string(node->data) + "-", node->left);
        printPaths(path + to_string(node->data) + "-", node->right);
    }

}


int main() {

    fstream in("bst.txt");
//    Node *root = sampleBST();
    Node *root = sampleBST2(in);
//    preOrder(root); cout << endl;
//    printLevel(root);

    // count leafs of the tree
//    Node *root = sampleBST();
//    cout << "leafs=" << leafs(root) << endl;

    // problem 2 size()
//    Node *root = sampleBST();
//    cout << "size=" << size(root) << endl;

    // problem 3 height()
//    cout << "height=" << height(root) << endl;
//    root->right->right->right = newNode(150);
//    cout << "height=" << height(root) << endl;

    // problem 7 pathSum()
//    cout << "hasPath=" << pathSum(root, 32) << endl;

    // problem 8 printPaths()
    printPaths("", root);


    return 0;
}





















