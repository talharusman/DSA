#include<iostream>
#include<vector>

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

    void insertHelper(Node*& root, int val) {  // Change Node* to Node& to modify the pointer
        if (root == nullptr) {
            root = new Node(val);
        } else if (val < root->data) {
            insertHelper(root->left, val);
        } else if (val > root->data) {
            insertHelper(root->right, val);
        }
    }

    void insert(int val) {
        insertHelper(root, val);
    }

    Node* buildtree(vector<int>& arr) {  // Pass vector by reference to avoid copying
        idx++;
        if (idx >= arr.size() || arr[idx] == -1)  // Check for end of array or -1
            return nullptr;

        Node* newroot = new Node(arr[idx]);
        newroot->left = buildtree(arr);
        newroot->right = buildtree(arr);
        return newroot;  // Return the new node
    }

    void BuildTree(vector<int> arr) {
        root = buildtree(arr);
    }

    //PreOrder Traversal
    void preorderHelper(Node* Nroot) {
        if (Nroot == nullptr)
            return;
        cout << Nroot->data << " ";  // Print root first for preorder
        preorderHelper(Nroot->left);
        preorderHelper(Nroot->right);
    }

    void Preorder() {
        preorderHelper(root);
    }


};

int Height(Node* root){
    if(root == nullptr){
        return 0;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main(int argc, char const *argv[])
{
     Tree tree;
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    tree.BuildTree(arr);

    cout<<"Height OF Tree: "<<Height(tree.root)<<endl;

  
    
    return 0;
}