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



};

int main(int argc, char const *argv[])
{
    vector<int> arr = {5,1,3,4,2,7};
    BST bst;
    bst.insertnode(arr);
    bst.Inorder();
    return 0;
}
