#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* split(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = slow->next;
    slow->next = nullptr;
    return temp;
}

Node* merge(Node* first, Node* second) {

    if (!first) return second;
    if (!second) return first;

    Node dummy;
    Node* tail = &dummy;
    dummy.prev = nullptr;

    while (first && second) {
        if (first->data < second->data) {
            tail->next = first;
            first->prev = tail;
            first = first->next;
        } else {
            tail->next = second;
            second->prev = tail;
            second = second->next;
        }
        tail = tail->next;
    }

    if (first) {
        tail->next = first;
        first->prev = tail;
    } else {
        tail->next = second;
        if (second) {
            second->prev = tail;
        }
    }

    return dummy.next;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}

void insert(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insert(head, 10);
    insert(head, 3);
    insert(head, 15);
    insert(head, 8);
    insert(head, 5);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
