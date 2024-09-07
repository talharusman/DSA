#include<iostream>
using namespace std;

class Node {
    int value;
    Node* next;
    Node* prev;
public:
    Node(int value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
    friend class DublyLinkedList;
};


class DublyLinkedList {
    Node* head;
    Node* tail;
public:
    DublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the end (tail)
    void InsertAtTail(int value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Delete duplicate nodes
    void DeleteDuplicate() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr->next;
            while (temp) {
                if (temp->value == curr->value) {
                    // Duplicate found, remove it
                    Node* next = temp->next;

                    if (temp->prev) {
                        temp->prev->next = temp->next;
                    }

                    if (temp->next) {
                        temp->next->prev = temp->prev;
                    }

                    if (temp == tail) {
                        tail = temp->prev; // Update tail if necessary
                    }

                    delete temp;
                    temp = next; // Move to the next node
                } else {
                    temp = temp->next;
                }
            }
            curr = curr->next;
        }
    }
};


int main(int argc, char const *argv[]) {
    DublyLinkedList dll;
    dll.InsertAtTail(1);
    dll.InsertAtTail(2);
    dll.InsertAtTail(3);
    dll.InsertAtTail(4);
    dll.InsertAtTail(3);  // Duplicate
    dll.InsertAtTail(5);
    dll.InsertAtTail(2);  // Duplicate
    dll.display();

    dll.DeleteDuplicate();  // Remove duplicates
    cout << "After deleting duplicates:" << endl;
    dll.display();

    return 0;
}
