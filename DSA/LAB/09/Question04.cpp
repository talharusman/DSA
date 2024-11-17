#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Node {
    std::vector<int> keys;
    std::vector<Node*> children;
    bool isLeaf;

    Node() : isLeaf(true) {}
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
            root->keys.push_back(key);
        } else {
            Node* newChild = insert(root, key);
            if (newChild) {
                Node* newRoot = new Node();
                newRoot->isLeaf = false;
                newRoot->keys.push_back(root->keys[1]);
                newRoot->children.push_back(root);
                newRoot->children.push_back(newChild);
                root = newRoot;
            }
        }
    }

    void levelOrderTraversal() {
        if (!root) {
            std::cout << "The tree is empty." << std::endl;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                Node* current = q.front();
                q.pop();

                for (int key : current->keys) {
                    std::cout << key << " ";
                }

                if (!current->isLeaf) {
                    for (Node* child : current->children) {
                        q.push(child);
                    }
                }
            }
            std::cout << std::endl;
        }
    }

private:
    Node* insert(Node* node, int key) {
        if (node->isLeaf) {
            node->keys.push_back(key);
            std::sort(node->keys.begin(), node->keys.end());

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

        newNode->keys.push_back(node->keys[2]);
        node->keys.pop_back();

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
    TwoThreeTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(30);
    tree.insert(3);
    tree.insert(8);

    std::cout << "Level-order traversal of the 2-3 tree:" << std::endl;
    tree.levelOrderTraversal();

    return 0;
}
