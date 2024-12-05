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

void PrintInRange(Node* root,int x,int y){
    if(root == nullptr){
        return;
    }

    if (root->data >= x && root->data <= y)
    {
        PrintInRange(root->left,x,y);
        cout<<root->data<<" ";
        PrintInRange(root->right,x,y);
    }
    else if(root->data >= y){
        PrintInRange(root->left,x,y);

    }else
    {
        PrintInRange(root->right,x,y);
    }
    
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {8,5,3,1,4,6,10,11,14};
    BST bst;
    bst.insertnode(arr);
    bst.Inorder();
    cout<<endl;
    PrintInRange(bst.root,3,10);
    
    return 0;
}
