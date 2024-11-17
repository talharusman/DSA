#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    std::vector<int> keys;
    std::vector<Node*> children;
    bool isLeaf;

    Node() : isLeaf(true) {}

    void insertKey(int key) {
        keys.push_back(key);
        std::sort(keys.begin(), keys.end());
    }
};

class TwoThreeTree {
public:
    Node* root;

    TwoThreeTree() : root(nullptr) {}

    ~TwoThreeTree() {
        clear(root);
    }

    void insert(int key) {
        if (!root) {
            root = new Node();
            root->insertKey(key);
        } else {
            Node* newChild = insert(root, key);
            if (newChild) {
                // Create a new root
                Node* newRoot = new Node();
                newRoot->isLeaf = false;
                newRoot->keys.push_back(root->keys[1]);
                newRoot->children.push_back(root);
                newRoot->children.push_back(newChild);
                root = newRoot;
            }
        }
    }

    void inOrderTraversal(Node* node, std::vector<int>& result) {
        if (!node) return;
        for (size_t i = 0; i < node->keys.size(); ++i) {
            if (!node->isLeaf) {
                inOrderTraversal(node->children[i], result);
            }
            result.push_back(node->keys[i]);
        }
        if (!node->isLeaf) {
            inOrderTraversal(node->children[node->keys.size()], result);
        }
    }

    Node* mergeTrees(TwoThreeTree& otherTree) {
        std::vector<int> result;
        inOrderTraversal(this->root, result);
        inOrderTraversal(otherTree.root, result);
        std::sort(result.begin(), result.end());

        TwoThreeTree newTree;
        for (int key : result) {
            newTree.insert(key);
        }
        return newTree.root;
    }

    void showTree(Node* node, int level = 0) {
        if (node == nullptr) return;

        for (int key : node->keys) {
            std::cout << std::string(level * 4, ' ') << key << " ";
        }
        std::cout << std::endl;

        if (!node->isLeaf) {
            for (Node* child : node->children) {
                showTree(child, level + 1);
            }
        }
    }

private:
    Node* insert(Node* node, int key) {
        if (node->isLeaf) {
            node->insertKey(key);
            if (node->keys.size() > 2) {
                return split(node);
            }
            return nullptr;
        } else {
            int i = 0;
            while (i < node->keys.size() && key > node->keys[i]) {
                ++i;
            }
            Node* newChild = insert(node->children[i], key);
            if (newChild) {
                node->keys.insert(node->keys.begin() + i, newChild->keys[0]);
                node->children.insert(node->children.begin() + i + 1, newChild);
                if (node->keys.size() > 2) {
                    return split(node);
                }
            }
            return nullptr;
        }
    }

    Node* split(Node* node) {
        Node* newNode = new Node();
        newNode->isLeaf = node->isLeaf;

        // Move the last key to the new node
        newNode->keys.push_back(node->keys[2]);
        node->keys.pop_back();

        // Move children if not a leaf
        if (!node->isLeaf) {
            newNode->children.push_back(node->children[2]);
            newNode->children.push_back(node->children[3]);
            node->children.pop_back();
            node->children.pop_back();
        }

        return newNode;
    }

    void clear(Node* node) {
        if (node) {
            for (Node* child : node->children) {
                clear(child);
            }
            delete node;
        }
    }
};

int main() {
    TwoThreeTree tree1;
    tree1.insert(10);
    tree1.insert(20);
    tree1.insert(5);
    tree1.insert(15);
    tree1.insert(25);

    TwoThreeTree tree2;
    tree2.insert(35);
    tree2.insert(40);
    tree2.insert(30);
    tree2.insert(38);
    tree2.insert(50);

    TwoThreeTree mergedTree;
    mergedTree.root = tree1.mergeTrees(tree2);

    std::vector<int> mergedResult;
    mergedTree.inOrderTraversal(mergedTree.root, mergedResult);

    std::cout << "Merged 2-3 Tree (In-Order): ";
    for (int key : mergedResult) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    std::cout << "Structure of Merged 2-3 Tree:" << std::endl;
    mergedTree.showTree(mergedTree.root);

    return 0;
}
