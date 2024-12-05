#include<iostream>
using namespace std;

// An AVL tree node
class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// A utility function to get the height 
// of the tree
int height(Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}


// A utility function to right rotate 
// subtree rooted with y


Node* LL_Rotation(Node* node) {
        Node* child = node->left;
        node->left = child->right;
        child->right = node;

        node->height = max(height(node->left), height(node->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;

        return child;
    }

// A utility function to left rotate 
// subtree rooted with x


Node* RR_Rotation(Node* node) {
        Node* child = node->right;
        node->right = child->left;
        child->left = node;

        node->height = max(height(node->left), height(node->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;

        return child;
}



// Get Balance factor of node N
int getBalance(Node *N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key) {
    // 1. Perform the normal BST rotation
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys not allowed
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left),height(node->right));

    // 3. Get the balance factor of this 
    // ancestor node to check whether this 
    // node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then 
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return LL_Rotation(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return RR_Rotation(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = RR_Rotation(node->left);
        return LL_Rotation(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = LL_Rotation(node->right);
        return RR_Rotation(node);
    }

    // return the (unchanged) node pointer
    return node;
}

// Given a non-empty binary search tree, 
// return the node with minimum key value 
// found in that tree. Note that the entire 
// tree does not need to be searched.
Node * minValueNode(Node* node) {
    Node* current = node;

    // loop down to find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;

    return current;
}

// Recursive function to delete a node with 
// given key from subtree with given root. 
// It returns root of the modified subtree.
Node* deleteNode(Node* root, int key) {
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == nullptr)
        return root;

    // If the key to be deleted is smaller 
    // than the root's key, then it lies in 
    // left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater 
    // than the root's key, then it lies in 
    // right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then 
    // this is the node to be deleted
    else {
        // node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else // One child case
                *root = *temp; // Copy the contents of 
                               // the non-empty child
            free(temp);
        } else {
            // node with two children: Get the 
            // inorder successor (smallest in 
            // the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's 
            // data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS 
    // NODE (to check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then 
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return LL_Rotation(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = RR_Rotation(root->left);
        return LL_Rotation(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return RR_Rotation(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = LL_Rotation(root->right);
        return RR_Rotation(root);
    }

    return root;
}

// A utility function to print preorder 
// traversal of the tree. 
void preOrder(Node *root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Driver Code
int main() {
    Node *root = nullptr;

    // Constructing tree given in the 
    // above figure
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    root = deleteNode(root, 10);

    cout << "\nPreorder traversal after"
            " deletion of 10 \n";
    preOrder(root);

    return 0;
}