#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value):  data(value), left(nullptr), right(nullptr) {}

};

class Tree {
    
    Node* root;

    // Helper function to insert a node
    void insertNode(Node*& node, int val) {
        if (node == NULL) {
            node = new Node(val);
        } else if (val < node->data) {
            insertNode(node->left, val);
        } else {
            insertNode(node->right, val);
        }
    }

    public:
    Tree() : root(NULL) {}

    void insert(int val) {
        insertNode(root, val);
    }

    // Optional: Function to print the tree in-order for testing
    void PreOrderTraversal(Node* node) {
        if (node != NULL) {
            std::cout << node->data << " ";
            PreOrderTraversal(node->left);
            PreOrderTraversal(node->right);
        }
    }

    // Public method to start in-order traversal
    void printpreOrder() {
        PreOrderTraversal(root);
        std::cout << std::endl;
    }

    Node* getRoot(){
        return root;
    }
   
};

void PreOrder(string& s,Node* root){
        if(root==NULL){
            return;
        }
        s += to_string(root->data) + " ";
        PreOrder(s,root->left);
        PreOrder(s,root->right);

}

void buildtree(Tree& NewTree,string & s){
    for(int i = 0; i <  s.length(); i++){
        if(s[i] == ' ')
            continue;
       int val = s[i] - '0';
       NewTree.insert(val);
    }
     

}



int main(int argc, char const *argv[])
{
    Tree tree;
    tree.insert(1);
    tree.insert(5);
    tree.insert(6);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(8);

    cout<<"Pre order  traversal of binary tree is "<<endl;
    tree.printpreOrder();
    std::string s;
    PreOrder(s,tree.getRoot());
    cout<<"\nString  representation of binary tree is ";
    std::cout<<endl<<s<<std::endl;
    Tree New_tree;
    buildtree(New_tree,s);
    cout<<endl;
    cout<<"New tree "<<endl;
    New_tree.printpreOrder();
    return 0;
}
