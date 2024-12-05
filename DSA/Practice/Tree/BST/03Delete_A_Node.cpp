#include<iostream>
#include<vector>
using namespace std;
struct Node
{
   int data;
   Node* left;
   Node* right;
   Node(int val):data(val),left(nullptr),right(nullptr){}

};

class BST{
    public:
    Node* root; 
    BST(){
        root = nullptr;
    }
     Node* insertnode(Node* root,int value){
        Node* newnode = new Node(value);
        if(root == nullptr){
            root = newnode;
            return root;
        }
        if(root->data > value){
            root->left = insertnode(root->left,value);

        }else
            root->right = insertnode(root->right,value);

            return root;
    }
    void insertnode(vector<int> arr){
        for(int i = 0; i < arr.size(); i++){
            root = insertnode(root,arr[i]);
        }
    }
    void Inorder(Node* root){
        if(root == nullptr){
           return;
        }
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);

    }
    void Inorder(){
        Inorder(root);
    }

    
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

    Node* Delete(Node* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }

        // Traverse the tree to find the node to delete
        if (root->data > val) {
            root->left = Delete(root->left, val);
        } 
        else if (root->data < val) {
            root->right = Delete(root->right, val);
        } 
        else { // root->data == val, found the node to delete
            // Case 1: No children (leaf node)
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            // Case 2: Only one child (right child only)
            if (root->left == nullptr) {
                Node* temp = root;
                root = root->right;
                delete temp;
                return root;
            }

            // Case 2: Only one child (left child only)
            if (root->right == nullptr) {
                Node* temp = root;
                root = root->left;
                delete temp;
                return root;
            }

            // Case 3: Two children
            // Find the inorder successor (smallest node in the right subtree)
            Node* successor = findMin(root->right);

            // Swap the root with the successor
            std::swap(root->data, successor->data);

            // Delete the successor in the right subtree
            root->right = Delete(root->right, successor->data);
        }
        return root;
    }
    void DeleteNode(int val){
        root = Delete(root, val);
    }




};

int main(int argc, char const *argv[])
{
    vector<int> arr = {5,1,3,4,2,7};
    BST bst;
    bst.insertnode(arr);
    bst.Inorder();
    cout << endl;
    bst.DeleteNode(3);
    bst.Inorder();
    return 0;
}
