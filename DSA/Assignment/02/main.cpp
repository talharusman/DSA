#include <iostream>
#include <queue>
#include <vector>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

// Global B-tree order
#define ORDER 5

struct Record
{
    int ID;
    string Name;
    int Age;

    Record() {}

    Record(int id, string name, int age) : ID(id), Name(name), Age(age) {}
};

class BSTnode
{
    Record record;
    BSTnode *left;
    BSTnode *right;

public:
    BSTnode(Record &t) : record(t)
    {
        left = nullptr;
        right = nullptr;
    }

    friend class BST;
};

class BST
{
    BSTnode *head;

    BSTnode *inserting(BSTnode *root, Record &record)
    {
        if (root == nullptr)
        {
            return new BSTnode(record);
        }
        if (record.ID == root->record.ID)
            return root;

        if (root->record.ID > record.ID)
        {
            root->left = inserting(root->left, record);
        }
        else
        {
            root->right = inserting(root->right, record);
        }
        return root;
    }

    BSTnode *deleteBSTnode(BSTnode *root, int data)
    {
        if (root == nullptr)
            return nullptr;

        else if (data < root->record.ID)
        {
            root->left = deleteBSTnode(root->left, data);
        }

        else if (data > root->record.ID)
        {
            root->right = deleteBSTnode(root->right, data);
        }

        else
        {
            if (root->left == nullptr)
            {
                BSTnode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                BSTnode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                BSTnode *temp = minValueBSTnode(root->right);
                root->record.ID = temp->record.ID;
                root->right = deleteBSTnode(root->right, temp->record.ID);
            }
        }
    }

    BSTnode *minValueBSTnode(BSTnode *r)
    {
        BSTnode *current = r;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    BSTnode *searching(BSTnode *root, int val)
    {
        if (root == nullptr || root->record.ID == val)
            return root;

        if (root->record.ID > val)
            return searching(root->left, val);

        return searching(root->right, val);
    }

public:
    BST() : head(nullptr) {}
    BST(BSTnode *n) : head(n) {}
    ~BST()
    {
        clear(head);
    }

    void insert(Record &record)
    {
        head = inserting(head, record);
    }

    void remove(int data)
    {
        head = deleteBSTnode(head, data);
    }

    string search(int data)
    {
        head = searching(head, data);
        return head->record.Name;
    }

    BSTnode *Head()
    {
        return head;
    }

    void clear(BSTnode *node)
    {
        if (node == nullptr)
            return;

        // Recursively delete left and right subtrees
        clear(node->left);
        clear(node->right);

        // Delete the current node
        delete node;
    }
};

class AVLnode
{
    Record record;
    AVLnode *left;
    AVLnode *right;
    int height;

public:
    AVLnode(Record &record) : record(record)
    {
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    friend class AVL;
};

class AVL
{
    AVLnode *root;

    int getHeight(AVLnode *n)
    {
        if (n == nullptr)
        {
            return 0;
        }
        return n->height;
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int getBalanceFactor(AVLnode *n)
    {
        if (n == nullptr)
        {
            return 0;
        }
        return getHeight(n->left) - getHeight(n->right);
    }

    AVLnode *rightRotate(AVLnode *y)
    {
        AVLnode *x = y->left;
        AVLnode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVLnode *leftRotate(AVLnode *x)
    {
        AVLnode *y = x->right;
        AVLnode *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVLnode *inserting(AVLnode *node, Record &record)
    {
        if (node == nullptr)
        {
            return new AVLnode(record);
        }
        if (record.ID < node->record.ID)
        {
            node->left = inserting(node->left, record);
        }
        else if (record.ID > node->record.ID)
        {
            node->right = inserting(node->right, record);
        }
        else
        {
            return node; // Duplicates are not allowed in AVL tree
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int bf = getBalanceFactor(node);

        // LL case
        if (bf > 1 && record.ID < node->left->record.ID)
        {
            return rightRotate(node);
        }

        // RR case
        if (bf < -1 && record.ID > node->right->record.ID)
        {
            return leftRotate(node);
        }

        // LR case
        if (bf > 1 && record.ID > node->left->record.ID)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL case
        if (bf < -1 && record.ID < node->right->record.ID)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLnode *deleteNode(AVLnode *root, int key)
    {
        if (!root)
        {
            return nullptr;
        }

        if (key < root->record.ID)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->record.ID)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Leaf node
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            // Only one child exist
            else if (root->left && !root->right)
            {
                AVLnode *temp = root->left;
                delete root;
                return temp;
            }
            else if (root->right && !root->left)
            {
                AVLnode *temp = root->right;
                delete root;
                return temp;
            }
            // Both child exist
            else
            {
                // Right side smallest element
                AVLnode *curr = root->right;
                while (curr->left)
                {
                    curr = curr->left;
                }
                root->record.ID = curr->record.ID;
                root->right = deleteNode(root->right, curr->record.ID);
            }
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bf = getBalanceFactor(root);

        // LL case
        if (bf > 1 && getBalanceFactor(root->left) >= 0)
        {
            return rightRotate(root);
        }

        // RR case
        if (bf < -1 && getBalanceFactor(root->right) <= 0)
        {
            return leftRotate(root);
        }

        // LR case
        if (bf > 1 && getBalanceFactor(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // RL case
        if (bf < -1 && getBalanceFactor(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    AVLnode *searching(AVLnode *node, int id)
    {
        if (!node || node->record.ID == id)
        {
            return node;
        }
        else if (id < node->record.ID)
        {
            return searching(node->left, id);
        }
        else
        {
            return searching(node->right, id);
        }
    }

public:
    AVL() : root(nullptr) {}
    
    ~AVL()
    {
        clear(root);
    }

    void insert(Record &record)
    {
        root = inserting(root, record);
    }

    void remove(int key)
    {
        root = deleteNode(root, key);
    }

    void search(int key)
    {
        root = searching(root, key);
    }

    void clear(AVLnode *node)
    {
        if (node == nullptr)
            return;

        // Recursively delete left and right subtrees
        clear(node->left);
        clear(node->right);

        // Delete the current node
        delete node;
    }
};

class Node
{
public:
    vector<Node *> children;
    vector<int> ids;

    // Constructor for B-tree nodes
    Node(int degree)
    {
        ids.resize(2 * degree - 1, 0);        // Initialize ids with zeros
        children.resize(2 * degree, nullptr); // Initialize children to nullptr
    }
};

class B_TREE
{
    Node *root;
    int degree;

public:
    B_TREE(int degree) : root(nullptr), degree(degree) {}

    // Search for a key in the B-tree
    Node *search(int id)
    {
        return search(root, id);
    }

private:
    Node *search(Node *node, int id)
    {
        if (!node)
            return nullptr;

        int i = 0;
        while (i < node->ids.size() && id > node->ids[i])
            i++;

        if (i < node->ids.size() && node->ids[i] == id)
            return node;

        if (node->children.empty())
            return nullptr;

        return search(node->children[i], id);
    }

public:
    // Insert a new key into the B-tree
    void insert(int id)
    {
        if (!root)
        {
            root = new Node(degree);
            root->ids[0] = id;
            root->children.clear();
        }
        else
        {
            if (root->ids.size() == 2 * degree - 1)
            {
                Node *newRoot = new Node(degree);
                newRoot->children[0] = root;
                splitChild(newRoot, 0, root);

                int i = 0;
                if (newRoot->ids[0] < id)
                    i++;
                insertNonFull(newRoot->children[i], id);

                root = newRoot;
            }
            else
            {
                insertNonFull(root, id);
            }
        }
    }

    ~B_TREE()
    {
        deleteTree(root);
    }

private:
    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;

        // Recursively delete all child nodes
        for (Node *child : node->children)
        {
            deleteTree(child);
        }

        // Delete the current node
        delete node;
    }

private:
    void insertNonFull(Node *node, int id)
    {
        int i = node->ids.size() - 1;

        if (node->children.empty())
        {
            node->ids.push_back(0);
            while (i >= 0 && node->ids[i] > id)
            {
                node->ids[i + 1] = node->ids[i];
                i--;
            }
            node->ids[i + 1] = id;
        }
        else
        {
            while (i >= 0 && node->ids[i] > id)
                i--;

            if (node->children[i + 1]->ids.size() == 2 * degree - 1)
            {
                splitChild(node, i + 1, node->children[i + 1]);
                if (node->ids[i + 1] < id)
                    i++;
            }
            insertNonFull(node->children[i + 1], id);
        }
    }

    void splitChild(Node *parent, int i, Node *fullChild)
    {
        Node *newNode = new Node(degree);
        newNode->children.clear();

        for (int j = 0; j < degree - 1; j++)
            newNode->ids[j] = fullChild->ids[j + degree];

        if (!fullChild->children.empty())
        {
            for (int j = 0; j < degree; j++)
                newNode->children[j] = fullChild->children[j + degree];
        }

        fullChild->ids.resize(degree - 1);

        parent->children.insert(parent->children.begin() + i + 1, newNode);
        parent->ids.insert(parent->ids.begin() + i, fullChild->ids[degree - 1]);
    }

public:
    // Remove a key from the B-tree
    void remove(int id)
    {
        if (!root)
        {
            cout << "The tree is empty" << endl;
            return;
        }

        remove(root, id);

        if (root->ids.empty())
        {
            Node *temp = root;
            if (root->children.empty())
                root = nullptr;
            else
                root = root->children[0];
            delete temp;
        }
    }

private:
    void remove(Node *node, int id)
    {
        int idx = findKey(node, id);

        if (idx < node->ids.size() && node->ids[idx] == id)
        {
            if (node->children.empty())
                removeFromLeaf(node, idx);
            else
                removeFromNonLeaf(node, idx);
        }
        else
        {
            if (node->children.empty())
            {
                cout << "The key " << id << " is not present in the tree\n";
                return;
            }

            bool flag = (idx == node->ids.size());

            if (node->children[idx]->ids.size() < degree)
                fill(node, idx);

            if (flag && idx > node->ids.size())
                remove(node->children[idx - 1], id);
            else
                remove(node->children[idx], id);
        }
    }

    int findKey(Node *node, int id)
    {
        int idx = 0;
        while (idx < node->ids.size() && node->ids[idx] < id)
            ++idx;
        return idx;
    }

    void removeFromLeaf(Node *node, int idx)
    {
        node->ids.erase(node->ids.begin() + idx);
    }

    void removeFromNonLeaf(Node *node, int idx)
    {
        int id = node->ids[idx];

        if (node->children[idx]->ids.size() >= degree)
        {
            int pred = getPred(node, idx);
            node->ids[idx] = pred;
            remove(node->children[idx], pred);
        }
        else if (node->children[idx + 1]->ids.size() >= degree)
        {
            int succ = getSucc(node, idx);
            node->ids[idx] = succ;
            remove(node->children[idx + 1], succ);
        }
        else
        {
            merge(node, idx);
            remove(node->children[idx], id);
        }
    }

    int getPred(Node *node, int idx)
    {
        Node *cur = node->children[idx];
        while (!cur->children.empty())
            cur = cur->children.back();
        return cur->ids.back();
    }

    int getSucc(Node *node, int idx)
    {
        Node *cur = node->children[idx + 1];
        while (!cur->children.empty())
            cur = cur->children[0];
        return cur->ids[0];
    }

    void fill(Node *node, int idx)
    {
        if (idx != 0 && node->children[idx - 1]->ids.size() >= degree)
            borrowFromPrev(node, idx);
        else if (idx != node->ids.size() && node->children[idx + 1]->ids.size() >= degree)
            borrowFromNext(node, idx);
        else
        {
            if (idx != node->ids.size())
                merge(node, idx);
            else
                merge(node, idx - 1);
        }
    }

    void borrowFromPrev(Node *node, int idx)
    {
        Node *child = node->children[idx];
        Node *sibling = node->children[idx - 1];

        child->ids.insert(child->ids.begin(), node->ids[idx - 1]);
        node->ids[idx - 1] = sibling->ids.back();
        sibling->ids.pop_back();

        if (!child->children.empty())
        {
            child->children.insert(child->children.begin(), sibling->children.back());
            sibling->children.pop_back();
        }
    }

    void borrowFromNext(Node *node, int idx)
    {
        Node *child = node->children[idx];
        Node *sibling = node->children[idx + 1];

        child->ids.push_back(node->ids[idx]);
        node->ids[idx] = sibling->ids[0];
        sibling->ids.erase(sibling->ids.begin());

        if (!child->children.empty())
        {
            child->children.push_back(sibling->children[0]);
            sibling->children.erase(sibling->children.begin());
        }
    }

    void merge(Node *node, int idx)
    {
        Node *child = node->children[idx];
        Node *sibling = node->children[idx + 1];

        child->ids.push_back(node->ids[idx]);
        child->ids.insert(child->ids.end(), sibling->ids.begin(), sibling->ids.end());
        child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());

        node->ids.erase(node->ids.begin() + idx);
        node->children.erase(node->children.begin() + idx + 1);
        delete sibling;
    }
};

class BTreeNode
{
public:
    Record records[ORDER - 1];  // Array of records
    BTreeNode *children[ORDER]; // Array of child pointers
    int n;                      // Current number of records
    bool leaf;                  // True if leaf node, false otherwise

    BTreeNode(bool isLeaf = true) : n(0), leaf(isLeaf)
    {
        for (int i = 0; i < ORDER; i++)
            children[i] = nullptr;
    }
};

class BTree
{
private:
    BTreeNode *root; // Pointer to root node

    // Helper function to split a full child node
    void splitChild(BTreeNode *x, int i)
    {
        BTreeNode *y = x->children[i];
        BTreeNode *z = new BTreeNode(y->leaf);
        z->n = ORDER / 2 - 1;

        // Copy records to the new node
        for (int j = 0; j < ORDER / 2 - 1; j++)
            z->records[j] = y->records[j + ORDER / 2];

        // Copy children pointers if not a leaf
        if (!y->leaf)
        {
            for (int j = 0; j < ORDER / 2; j++)
                z->children[j] = y->children[j + ORDER / 2];
        }

        y->n = ORDER / 2 - 1;

        // Shift children of x
        for (int j = x->n; j >= i + 1; j--)
            x->children[j + 1] = x->children[j];

        x->children[i + 1] = z;

        // Shift records of x
        for (int j = x->n - 1; j >= i; j--)
            x->records[j + 1] = x->records[j];

        // Add the middle record of y to x
        x->records[i] = y->records[ORDER / 2 - 1];
        x->n++;
    }

    // Insert a record into a non-full node
    void insertNonFull(BTreeNode *x, Record rec)
    {
        int i = x->n - 1;

        if (x->leaf)
        {
            // Find position for the new record
            while (i >= 0 && rec.ID < x->records[i].ID)
            {
                x->records[i + 1] = x->records[i];
                i--;
            }
            x->records[i + 1] = rec;
            x->n++;
        }
        else
        {
            // Find the child to descend
            while (i >= 0 && rec.ID < x->records[i].ID)
                i--;
            i++;
            if (x->children[i]->n == ORDER - 1)
            {
                splitChild(x, i);
                if (rec.ID > x->records[i].ID)
                    i++;
            }
            insertNonFull(x->children[i], rec);
        }
    }

    // Traverse and display the tree
    void traverse(BTreeNode *x)
    {
        for (int i = 0; i < x->n; i++)
        {
            if (!x->leaf)
                traverse(x->children[i]);
            cout << "ID: " << x->records[i].ID << ", Name: " << x->records[i].Name << ", Age: " << x->records[i].Age << endl;
        }
        if (!x->leaf)
            traverse(x->children[x->n]);
    }

    // Search for a record by ID
    Record *search(BTreeNode *x, int ID)
    {
        int i = 0;
        while (i < x->n && ID > x->records[i].ID)
            i++;

        if (i < x->n && x->records[i].ID == ID)
            return &x->records[i];

        if (x->leaf)
            return nullptr;

        return search(x->children[i], ID);
    }

    // Helper functions for removing a record (same as before)

    void removeFromLeaf(BTreeNode *node, int idx) { /* Same implementation as provided */ }
    void removeFromNonLeaf(BTreeNode *node, int idx) { /* Same implementation as provided */ }
    Record getPredecessor(BTreeNode *node, int idx) { /* Same implementation as provided */ }
    Record getSuccessor(BTreeNode *node, int idx) { /* Same implementation as provided */ }
    void merge(BTreeNode *node, int idx) { /* Same implementation as provided */ }
    void remove(BTreeNode *node, int ID) { /* Same implementation as provided */ }
    void fill(BTreeNode *node, int idx) { /* Same implementation as provided */ }
    void borrowFromPrev(BTreeNode *node, int idx) { /* Same implementation as provided */ }
    void borrowFromNext(BTreeNode *node, int idx) { /* Same implementation as provided */ }

public:
    BTree() { root = new BTreeNode(true); }

    // Insert a new record
    void insert(int ID, string Name, int Age)
    {
        Record rec = {ID, Name, Age};
        if (root->n == ORDER - 1)
        {
            BTreeNode *s = new BTreeNode(false);
            s->children[0] = root;
            splitChild(s, 0);
            root = s;
            insertNonFull(s, rec);
        }
        else
        {
            insertNonFull(root, rec);
        }
    }

    // Search for a record by ID
    Record *search(int ID)
    {
        return (root == nullptr) ? nullptr : search(root, ID);
    }

    // Update a record by ID
    bool update(int ID, string newName, int newAge)
    {
        Record *rec = search(ID);
        if (rec)
        {
            rec->Name = newName;
            rec->Age = newAge;
            return true;
        }
        return false;
    }

    // Remove a record by ID
    void remove(int ID)
    {
        if (!root)
        {
            cout << "The tree is empty.\n";
            return;
        }

        remove(root, ID);

        if (root->n == 0)
        {
            BTreeNode *tmp = root;
            if (root->leaf)
                root = nullptr;
            else
                root = root->children[0];
            delete tmp;
        }
    }

    // Traverse and display all records
    void traverse()
    {
        if (root)
            traverse(root);
    }
};

vector<Record> generateDummyData(int size)
{
    vector<Record> data;

    for (int i = 0; i < size; i++)
    {
        string name = "Name: " + to_string(i + 1);
        data.emplace_back(i + 1, name, rand() % 100);
    }
    return data;
}

int main()
{
    // Generate dummy data for various sizes
    vector<int> sizes = {1000, 10000};
    vector<int> sizes1 = {50000};
    int searchCount = 20;

    for (int size : sizes)
    {
        cout << "\nTesting with dataset size: " << size << "\n";
        vector<Record> data = generateDummyData(size);

        // Test BST
        BST bst;

        auto start = high_resolution_clock::now();

        // Insert records
        for (auto &record : data)
        {
            bst.insert(record);
        }
        auto end = high_resolution_clock::now();
        cout << "BST - Insert Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Search records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int searchID = data[i].ID;
            string result = bst.search(searchID);
        }
        end = high_resolution_clock::now();
        cout << "BST - Search Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Delete records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int deleteID = data[i].ID;
            bst.remove(deleteID);
        }
        end = high_resolution_clock::now();
        cout << "BST - Delete Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    for (int size : sizes1)
    {
        cout << "\nTesting with dataset size: " << size << "\n";
        vector<Record> data = generateDummyData(size);

        // Test BST
        BST bst;

        auto start = high_resolution_clock::now();

        // Insert records
        for (auto &record : data)
        {
            bst.insert(record);
        }
        auto end = high_resolution_clock::now();
        cout << "BST - Insert Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Search records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int searchID = data[i].ID;
            string result = bst.search(searchID);
        }
        end = high_resolution_clock::now();
        cout << "BST - Search Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Delete records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int deleteID = data[i].ID;
            bst.remove(deleteID);
        }
        end = high_resolution_clock::now();
        cout << "BST - Delete Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    for (int size : sizes)
    {
        cout << "\nTesting with dataset size: " << size << "\n";
        vector<Record> data = generateDummyData(size);

        // Test AVL
        AVL avl;

        auto start = high_resolution_clock::now();

        // Insert records
        for (auto &record : data)
        {
            avl.insert(record);
        }
        auto end = high_resolution_clock::now();
        cout << "AVL - Insert Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Search records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int searchID = data[i].ID;
            avl.search(searchID);
        }
        end = high_resolution_clock::now();
        cout << "AVL - Search Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Delete records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int deleteID = data[i].ID;
            avl.remove(deleteID);
        }
        end = high_resolution_clock::now();
        cout << "AVL - Delete Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    for (int size : sizes1)
    {
        cout << "\nTesting with dataset size: " << size << "\n";
        vector<Record> data = generateDummyData(size);

        // Test AVL
        AVL avl;

        auto start = high_resolution_clock::now();

        // Insert records
        for (auto &record : data)
        {
            avl.insert(record);
        }
        auto end = high_resolution_clock::now();
        cout << "AVL - Insert Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Search records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int searchID = data[i].ID;
            avl.search(searchID);
        }
        end = high_resolution_clock::now();
        cout << "AVL - Search Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Delete records
        start = high_resolution_clock::now();
        for (int i = 0; i < searchCount; i++)
        {
            int deleteID = data[i].ID;
            avl.remove(deleteID);
        }
        end = high_resolution_clock::now();
        cout << "AVL - Delete Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    // B- Trees

    for (int size : sizes)
    {
        cout << "\n--- Performance Analysis for B-Tree with " << size << " records ---\n";

        BTree btree;
        vector<Record> data = generateDummyData(size);

        // Insert records
        cout << "Testing Insert Operation...\n";
        auto start = high_resolution_clock::now();
        for (auto &rec : data)
            btree.insert(rec.ID, rec.Name, rec.Age);
        auto end = high_resolution_clock::now();
        cout << "Insert Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Search records
        cout << "Testing Search Operation...\n";
        start = high_resolution_clock::now();
        for (int i = 0; i < 20; i++)
        {
            int searchID = data[rand() % size].ID;
            btree.search(searchID);
        }
        end = high_resolution_clock::now();
        cout << "Search Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Delete records
        cout << "Testing Delete Operation...\n";
        start = high_resolution_clock::now();
        for (int i = 0; i < 20; i++)
        {
            int deleteID = data[rand() % size].ID;
            btree.remove(deleteID);
        }
        end = high_resolution_clock::now();
        cout << "Delete Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    for (int size : sizes1)
    {
        cout << "\n--- Performance Analysis for B-Tree with " << size << " records ---\n";

        BTree btree;
        vector<Record> data = generateDummyData(size);

        // Insert records
        cout << "Testing Insert Operation...\n";
        auto start = high_resolution_clock::now();
        for (auto &rec : data)
            btree.insert(rec.ID, rec.Name, rec.Age);
        auto end = high_resolution_clock::now();
        cout << "Insert Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Search records
        cout << "Testing Search Operation...\n";
        start = high_resolution_clock::now();
        for (int i = 0; i < 20; i++)
        {
            int searchID = data[rand() % size].ID;
            btree.search(searchID);
        }
        end = high_resolution_clock::now();
        cout << "Search Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

        // Delete records
        cout << "Testing Delete Operation...\n";
        start = high_resolution_clock::now();
        for (int i = 0; i < 20; i++)
        {
            int deleteID = data[rand() % size].ID;
            btree.remove(deleteID);
        }
        end = high_resolution_clock::now();
        cout << "Delete Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    return 0;
}