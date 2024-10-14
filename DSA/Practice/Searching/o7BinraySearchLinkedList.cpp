#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Singly linked list class
class SinglyLinkedList {
public:
    SinglyLinkedList() : head(nullptr) {}

    // Method to insert a node at the end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Linear search method
    Node* linearSearch(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Value not found
    }

    // Binary search method
    Node* binarySearch(int value) {
        int size = getSize();
        Node* start = head;
        Node* end = nullptr;
        for (int i = 0; i < size; ++i) {
            Node* middle = getMiddle(start, end);
            if (middle->data == value) {
                return middle;
            } else if (middle->data < value) {
                start = middle->next;
            } else {
                end = middle;
            }
            if (start == end) {
                break;
            }
        }
        return nullptr; // Value not found
    }

    // Method to get the size of the list
    int getSize() {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Method to get the middle node between two nodes
    Node* getMiddle(Node* start, Node* end) {
        if (!start) return nullptr;
        Node* slow = start;
        Node* fast = start;
        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Print the list method
    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    Node* head;
};

int main() {
    SinglyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "List: ";
    list.printList();

    // Linear Search
    int value = 3;
    Node* result = list.linearSearch(value);
    if (result) {
        cout << "Linear Search: Value " << value << " found." << endl;
    } else {
        cout << "Linear Search: Value " << value << " not found." << endl;
    }

    // Binary Search (works only if the list is sorted)
    value = 4;
    result = list.binarySearch(value);
    if (result) {
        cout << "Binary Search: Value " << value << " found." << endl;
    } else {
        cout << "Binary Search: Value " << value << " not found." << endl;
    }

    return 0;
}
