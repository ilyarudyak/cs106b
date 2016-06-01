#include <iostream>

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

    if (node->left == nullptr && node->right == nullptr) {
        return sum == node->data;
    }

    return pathSum(node->left, sum - node->data) ||
           pathSum(node->right, sum - node->data);
}

int main() {

    Node *root = sampleBST();

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
//    cout << "hasPath=" << pathSum(root, 180) << endl;


    return 0;
}





















