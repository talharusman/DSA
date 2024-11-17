#include <iostream>
#include <algorithm>
#include <climits>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class Tree {
    Node* root;

    // Helper function to insert a node
    void insertNode(Node*& node, int val) {
        if (node == nullptr) {
            node = new Node(val);
        } else if (val < node->data) {
            insertNode(node->left, val);
        } else {
            insertNode(node->right, val);
        }
    }

public:
    Tree() : root(nullptr) {}

    void insert(int val) {
        insertNode(root, val);
    }

    void PreOrderTraversal(Node* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            PreOrderTraversal(node->left);
            PreOrderTraversal(node->right);
        }
    }

    void printPreOrder() {
        PreOrderTraversal(root);
        std::cout << std::endl;
    }

    Node* getRoot() {
        return root;
    }
};

class MaxProfitPath {
public:
    int maxPathSum(Node* root) {
        int max_sum = INT_MIN; 
        maxPathSumUtil(root, max_sum);
        return max_sum;
    }

private:
    int maxPathSumUtil(Node* node, int& max_sum) {
        if (node == nullptr) {
            return 0; // Base case: if the node is null, return 0
        }

        int left_max = std::max(maxPathSumUtil(node->left, max_sum), 0);  
        int right_max = std::max(maxPathSumUtil(node->right, max_sum), 0); 

        int current_max_path = node->data + left_max + right_max;

        max_sum = std::max(max_sum, current_max_path);

        return node->data + std::max(left_max, right_max);
    }
};

int main() {
    Tree tree;

    tree.insert(10);
    tree.insert(2);
    tree.insert(-5);
    tree.insert(20);
    tree.insert(1);
    tree.insert(2);

    std::cout << "Pre-order traversal of the tree: ";
    tree.printPreOrder();

    MaxProfitPath mpp;
    int result = mpp.maxPathSum(tree.getRoot());
    std::cout << "Maximum Profit Path: " << result << std::endl;

    return 0;
}