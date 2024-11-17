#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Node* root;

    Tree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    void recoverTree() {
        Node* first = nullptr;
        Node* second = nullptr;
        Node* prev = nullptr;

        inOrderTraversal(root, first, second, prev);

        if (first && second) {
            swap(first->data, second->data);
        }
    }

    void inOrderTraversal(Node* node, Node*& first, Node*& second, Node*& prev) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversal(node->left, first, second, prev);

        if (prev != nullptr && prev->data > node->data) {
            if (first == nullptr) {
                first = prev;
            }
            second = node;
        }
        prev = node;

        inOrderTraversal(node->right, first, second, prev);
    }

    void inOrderPrint(Node* node) {
        if (node != nullptr) {
            inOrderPrint(node->left);
            std::cout << node->data << " ";
            inOrderPrint(node->right);
        }
    }

    void printInOrder() {
        inOrderPrint(root);
        std::cout << std::endl;
    }
};

int main() {
    Tree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "Original In-order Traversal: ";
    tree.printInOrder();

    swap(tree.root->left->data, tree.root->right->data); // Swap nodes with values 5 and 15

    cout << "In-order Traversal after swapping: ";
    tree.printInOrder();

    tree.recoverTree();

    cout << "In-order Traversal after recovery: ";
    tree.printInOrder();

    return 0;
}