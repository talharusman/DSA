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
// =========== Approach 1 ===============
// Time complexcity of this Approach is O(N^2)
int Height(Node* root){
    if(root == nullptr){
        return 0;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int Diameter(Node* root){

    if(root == nullptr){
        return 0;
    }

    int diam1 = Diameter(root->left);
    int diam2 = Diameter(root->right);
    int diam3 = Height(root->left) + Height(root->right) + 1;

    return max(diam3,max(diam1,diam2));

}


// ============== Approach 2 ==============

struct treeInfo
{
    int ht;
    int diam;
    treeInfo(int h, int d) {
        ht = h;
        diam = d;
    }

};

treeInfo Diameter2(Node* root){
    if(root == nullptr){
        return treeInfo(0,0);
    }

    treeInfo left = Diameter2(root->left);
    treeInfo right = Diameter2(root->right);
    //    int leftHeight = Height(root->left);
    //    int rightHeight = Height(root->right);
    int myHeight = max(left.ht,right.ht) + 1;

    int diam1 = left.diam;
    int diam2 = right.diam;
    int diam3 = left.ht + right.ht + 1;
    int mydiam = max(diam3,max(diam1,diam2));
    return treeInfo(myHeight,mydiam);
}



int main(int argc, char const *argv[])
{
     Tree tree;
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    tree.BuildTree(arr);
    cout << "Height of tree is " << Height(tree.root)<<endl;
    cout<<"Diameter of Tree "<<Diameter(tree.root)<<endl;
    cout<<"Diameter 2: "<<Diameter2(tree.root).diam<<endl;


  
    
    return 0;
}
