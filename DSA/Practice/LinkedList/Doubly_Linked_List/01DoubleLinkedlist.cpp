#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;
    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleLinkedList {
public:
    Node* head;
    Node* tail;
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    void InsertAtHead(int value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    
    void InsertAtTail(int value) {
        Node* new_node = new Node(value);
        if (tail == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
};

int main() {
    DoubleLinkedList dll;
    dll.InsertAtHead(1);
    dll.InsertAtHead(2);
    dll.InsertAtHead(3);
    dll.InsertAtTail(0);
    dll.InsertAtTail(4);
    dll.display();

    return 0;
}
