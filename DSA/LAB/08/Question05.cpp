#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    Node* sortedArrayToBST(int arr[], int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        Node* root = new Node(arr[mid]);
        root->left = sortedArrayToBST(arr, start, mid - 1);
        root->right = sortedArrayToBST(arr, mid + 1, end);
        return root;
    }

    void insert(int arr[], int size) {
        root = sortedArrayToBST(arr, 0, size - 1);
    }

    void InOrderTraversal(Node* root) {
        if (root != nullptr) {
            InOrderTraversal(root->left);
            std::cout << root->data << " ";
            InOrderTraversal(root->right);
        }
    }

    void InOrder() {
        InOrderTraversal(root);
    }
};

int main() {
    BST bst;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    bst.insert(arr, size);
    std::cout << "In-order traversal of the constructed BST: ";
    bst.InOrder();
    std::cout << std::endl;
    return 0;
}