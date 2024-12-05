#include <iostream>
#include <vector>
#include <queue>
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
    // InOrder Traversal
    void InOrderHelper(Node* root){
        if(root == nullptr)
            return;
        InOrderHelper(root->left);
        cout << root->data << " ";
        InOrderHelper(root->right);

    }
    void InOrder(){
        InOrderHelper(root);
    }

    // PostOrder Traversal
    void PostOrderHelper(Node* root){
        if(root == nullptr)
            return;
        PostOrderHelper(root->left);
        PostOrderHelper(root->right);
        cout << root->data << " ";
    }

    void PostOrder(){
        PostOrderHelper(root);
    }

    //Level Order Traversalwe use in this Queue
    void LevelOrdeHelper(Node* root){
        if(root == nullptr)
           return;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty())
        {
            Node* currNode = q.front();
            q.pop();
            if(!currNode){
                cout<<endl;
                if(q.empty()){
                    break;
                }else
                    q.push(nullptr);
            }else{
                cout<<currNode->data<<" ";
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }
                
            }
        }
        
    }
    
    void LevelOrder(){
        LevelOrdeHelper(root);
    }






};

int main() {
    Tree tree;
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    tree.BuildTree(arr);
    // tree.Preorder();  // Call to print preorder traversal
    tree.LevelOrder();
    return 0;
}
