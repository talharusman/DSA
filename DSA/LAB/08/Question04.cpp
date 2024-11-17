#include <iostream>

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

    // Function to insert nodes in the tree (for demonstration purposes)
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

  
};

  // Function to check if two trees are identical
bool areIdentical(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    return (root1->data == root2->data) &&areIdentical(root1->left, root2->left) &&areIdentical(root1->right, root2->right);
}


bool isSubtree(Node* T1, Node* T2) {
    if (T2 == nullptr) {
        return true; 
    }
    if (T1 == nullptr) {
        return false; 
    }
    if (areIdentical(T1, T2)) {
        return true; 
    }
 
    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

int main() {
    Tree T1, T2;

    // Constructing tree T1
    T1.insert(10);
    T1.insert(5);
    T1.insert(15);
    T1.insert(3);
    T1.insert(7);
    T1.insert(12);
    T1.insert(18);

    T2.insert(5);
    T2.insert(3);
    T2.insert(7);

    if (isSubtree(T1.root, T2.root)) {
        std::cout << "T2 is a subtree of T1." << std::endl;
    } else {
        std::cout << "T2 is NOT a subtree of T1." << std::endl;
    }

    return 0;
}