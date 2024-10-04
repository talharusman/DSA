#include <iostream>
using namespace std;

class Node {
    int value;
    Node* next;

public:
    Node(int value) {
        this->value = value;
        next = nullptr;
    }
    friend class LinkedList; // Allow LinkedList to access private members
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
   
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }

    void reverse() {
        head = reverseRecursion(head);
    }

private:
    Node* reverseRecursion(Node* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }

        Node* newHead = reverseRecursion(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }
};

int main() {
    LinkedList l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.display();

    l.reverse();
    l.display();

    return 0;
}
