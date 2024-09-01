#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;
    Node(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class doubleLinkedList {
public:
    Node* head;
    Node* tail;
    doubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void InsertAtHead(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void InsertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void InsertAtKthPos(int value, int k) {
        Node* newNode = new Node(value);
        // assuming k is less or equal to the length of doubly linked list
        if (k == 1) {
            InsertAtHead(value);
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < k - 1) {
            temp = temp->next;
            count++;
        }
        // temp will be pointing to the node at (k-1)th position
        if (temp->next == nullptr) { // Insert at the tail
            InsertAtTail(value);
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    void DeleteAtStart() {
        if (!head) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (!head) { // if doubly linked list had only 1 node
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete temp;
    }

    void DeleteAtTail() {
        if (!tail) {
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (!tail) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        delete temp;
    }

    void DeleteAtKthNode(int k) {
        // Assuming k is less than or equal to the length of dll
        if (k == 1) {
            DeleteAtStart();
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }
        // now temp is pointing to the node at kth position
        if (temp->next == nullptr) { // If it's the last node
            DeleteAtTail();
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
};

int main() {
    doubleLinkedList dll;
    cout << "Insert at Tail" << endl;
    dll.InsertAtTail(1);
    dll.InsertAtTail(2);
    dll.InsertAtTail(3);
    dll.InsertAtTail(4);
    dll.InsertAtTail(5);
    dll.display();

    cout << "Insert At Head" << endl;
    dll.InsertAtHead(0);
    dll.display();

    cout << "Insert at Kth position" << endl;
    dll.InsertAtKthPos(4, 3);
    dll.display();

    cout << "Delete At Start" << endl;
    dll.DeleteAtStart();
    dll.display();

    cout << "Delete at Tail" << endl;
    dll.DeleteAtTail();
    dll.display();

    cout << "Delete at Kth position" << endl;
    dll.DeleteAtKthNode(3);
    dll.display();

    return 0;
}
