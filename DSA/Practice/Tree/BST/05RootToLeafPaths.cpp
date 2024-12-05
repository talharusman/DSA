#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}

    Node* insertnode(Node* root, int value) {
        Node* newnode = new Node(value);
        if (root == nullptr) {
            root = newnode;
            return root;
        }
        if (root->data > value) {
            root->left = insertnode(root->left, value);
        } else {
            root->right = insertnode(root->right, value);
        }
        return root;
    }

    void insertnode(vector<int> arr) {
        for (int i = 0; i < arr.size(); i++) {
            root = insertnode(root, arr[i]);
        }
    }

    void Inorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }

    void Inorder() {
        Inorder(root);
    }
};

void PrintPath(const vector<int>& path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) cout << "->";
    }
    cout << endl;
}

void PrintRoot2Leaf(Node* root, vector<int>& path) {
    if (root == nullptr) {
        return;
    }
    path.push_back(root->data);

    // If it's a leaf node, print the path
    if (root->left == nullptr && root->right == nullptr) {
        PrintPath(path);
    }

    // Recur on left and right subtrees
    PrintRoot2Leaf(root->left, path);
    PrintRoot2Leaf(root->right, path);

    // Backtrack: remove the last element for the next path
    path.pop_back();
}

int main(int argc, char const* argv[]) {
    vector<int> arr = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    BST bst;
    bst.insertnode(arr);
    bst.Inorder();
    cout << endl;

    vector<int> path;
    PrintRoot2Leaf(bst.root, path);

    return 0;
}
