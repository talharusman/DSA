#include <iostream>
#include <limits.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    bool isValidAVL(Node* node) {
        return isValidAVLHelper(node) != -1;
    }

private:
    int isValidAVLHelper(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = isValidAVLHelper(node->left);
        if (leftHeight == -1) {
            return -1;
        }

        int rightHeight = isValidAVLHelper(node->right);
        if (rightHeight == -1) {
            return -1;
        }

        if (node->left != nullptr && node->left->data >= node->data) {
            return -1;
        }
        if (node->right != nullptr && node->right->data <= node->data) {
            return -1;
        }

        int balanceFactor = leftHeight - rightHeight;
        if (balanceFactor < -1 || balanceFactor > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    AVLTree tree;

    tree.root = new Node(30);
    tree.root->left = new Node(20);
    tree.root->right = new Node(40);
    tree.root->left->left = new Node(10);
    tree.root->left->right = new Node(25);

    cout << "Is the tree a valid AVL tree? " << (tree.isValidAVL(tree.root) ? "Yes" : "No") << endl;

    tree.root->left->left->left = new Node(5);

    cout << "Is the tree a valid AVL tree? " << (tree.isValidAVL(tree.root) ? "Yes" : "No") << endl;

    return 0;
}