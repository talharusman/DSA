#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Node* root;
    int idx;

    Tree() : root(nullptr), idx(-1) {}

    Node* buildTree(vector<int>& arr) {  // Pass vector by reference to avoid copying
        idx++;
        if (idx >= arr.size() || arr[idx] == -1)  // Check for end of array or -1 as null marker
            return nullptr;

        Node* newRoot = new Node(arr[idx]);
        newRoot->left = buildTree(arr);   // Build left subtree
        newRoot->right = buildTree(arr);  // Build right subtree
        return newRoot;  // Return the constructed node
    }

    void BuildTree(vector<int> arr) {
        idx = -1;  // Reset idx for building a new tree
        root = buildTree(arr);
    }

    // PreOrder Traversal for Testing
    void preorderHelper(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void Preorder() {
        preorderHelper(root);
        cout << endl;
    }
};

class Solution {
public:
    bool IsIdentical(Node* root, Node* subRoot) {
        if (!root && !subRoot) {
            return true;
        }
        if (!root || !subRoot) {
            return false;
        }
        if (root->data == subRoot->data) {
            return IsIdentical(root->left, subRoot->left) && IsIdentical(root->right, subRoot->right);
        }
        return false;
    }

    bool IsSubTree(Node* root, Node* subRoot) {
        if (subRoot == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        if (root->data == subRoot->data) {
            if (IsIdentical(root, subRoot)) {
                return true;
            }
        }
        return IsSubTree(root->left, subRoot) || IsSubTree(root->right, subRoot);
    }
};

int main() {
    // Create main tree and subtree
    Tree mainTree;
    Tree subTree;

    // Define the main tree and subtree using vectors
    vector<int> mainTreeData = {3,4,5,1,2}; // Main tree data
    vector<int> subTreeData = {4,1,2};               // Subtree data

    // Build the trees
    mainTree.BuildTree(mainTreeData);
    subTree.BuildTree(subTreeData);

    // Print the trees (optional, for verification)
    cout << "Main Tree (Preorder): ";
    mainTree.Preorder();

    cout << "Sub Tree (Preorder): ";
    subTree.Preorder();

    // Create a Solution object and check if subTree is a subtree of mainTree
    Solution solution;
    bool result = solution.IsSubTree(mainTree.root, subTree.root);

    // Display the result
    if (result) {
        cout << "The subtree is a part of the main tree." << endl;
    } else {
        cout << "The subtree is NOT a part of the main tree." << endl;
    }

    return 0;
}
