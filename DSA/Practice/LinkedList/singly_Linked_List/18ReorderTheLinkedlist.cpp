#include<iostream>
using namespace std;
/*
you are given the head of a singlu linked-list. The list can be
represented as:
L0 -> L1 -> ... -> Ln - 1 -> Ln
Reorder the list to be on the following form:
L0 -> Ln -> L1 -> Ln - 1 -> L2 -> Ln - 2
You may not modify the values in the list's nodes. Only nodes
may be reordered.
*/
class Node {
public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class linkedList {
public:
    Node* head;
    linkedList() {
        head = nullptr;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Step 1: finding the middle element using slow and fast pointer
// Step 2: Reverse the second half of the linked list
// Step 3: Merge the two halves of the linked list

Node* ReorderLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        // No need to reorder if the list has less than 3 elements
        return head;
    }

    // 1. Finding the middle element
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // 2. Separate and reverse the second half of the linked list
    Node* curr = slow->next;
    slow->next = nullptr;
    Node* prev = nullptr;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // 3. Merging the two halves of the linked list
    Node* firstHalf = head;
    Node* secondHalf = prev;
    while (secondHalf) {
        Node* temp1 = firstHalf->next;
        Node* temp2 = secondHalf->next;
        firstHalf->next = secondHalf;
        if (temp1 == nullptr) break;
        secondHalf->next = temp1;
        firstHalf = temp1;
        secondHalf = temp2;
    }

    return head;
}

int main(int argc, char const* argv[]) {
    linkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.insertAtTail(7);
    // list.insertAtTail(8);

    list.display();
    list.head = ReorderLinkedList(list.head);
    list.display();

    return 0;
}
