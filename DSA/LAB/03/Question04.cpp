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

    // Insert at the front (head)
    void InsertAtHead(int value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    // Insert after a given value
    void InsertAt_AfterGivenValue(int NewNodeValue, int value) {
        Node* new_node = new Node(NewNodeValue);
        if (!head) {
            head = new_node;
            tail = new_node;
            return;
        }

        Node* temp = head;
        while (temp && temp->value != value) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Value " << value << " not found in the list." << endl;
            return;
        }

        new_node->prev = temp;
        new_node->next = temp->next;

        if (temp->next) {
            temp->next->prev = new_node;
        }

        temp->next = new_node;

        if (temp == tail) {
            tail = new_node;
        }
    }

    // Insert before a given value
    void InsertBeforeGivenValue(int NewNodeValue, int value) {
        Node* new_node = new Node(NewNodeValue);
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->value == value) {
            InsertAtHead(NewNodeValue);
            return;
        }

        Node* temp = head;
        while (temp && temp->value != value) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Value " << value << " not found in the list." << endl;
            return;
        }

        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev->next = new_node;
        temp->prev = new_node;
    }

    // Delete node from the head
    void DeleteFromHead() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // If the list becomes empty
        }
        delete temp;
    }

    // Delete last node
    void DeleteFromTail() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr; // If the list becomes empty
        }
        delete temp;
    }

    // Delete node with a particular value
    void DeleteNodeByValue(int value) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        // Special case: if head contains the value
        if (head->value == value) {
            DeleteFromHead();
            return;
        }

        Node* temp = head;
        while (temp && temp->value != value) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Value " << value << " not found in the list." << endl;
            return;
        }

        if (temp == tail) {
            DeleteFromTail();
            return;
        }

        temp->prev->next = temp->next;
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        delete temp;
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
};

int main(int argc, char const *argv[]) {
    DublyLinkedList dll;
    dll.InsertAtHead(10);
    dll.InsertAtTail(20);
    dll.InsertAtTail(30);
    dll.InsertBeforeGivenValue(5, 10);
    dll.InsertAt_AfterGivenValue(25, 20);

    cout << "List after insertion operations:" << endl;
    dll.display();

    dll.DeleteFromHead();
    cout << "List after deleting from head:" << endl;
    dll.display();

    dll.DeleteFromTail();
    cout << "List after deleting from tail:" << endl;
    dll.display();

    dll.DeleteNodeByValue(20);
    cout << "List after deleting node with value 20:" << endl;
    dll.display();

    return 0;
}
