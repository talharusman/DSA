#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to swap two nodes in the linked list by passing the nodes themselves
void swapNodes(Node** head, Node* node1, Node* node2) {
    // If node1 and node2 are the same, no need to swap
    if (node1 == node2) return;

    Node *prevNode1 = nullptr, *prevNode2 = nullptr;
    Node *curr = *head;

    // Find the previous node for node1 and node2
    while (curr != nullptr && curr->next != nullptr) {
        if(prevNode1 && prevNode2)
           break;
        if (curr->next == node1)
            prevNode1 = curr;
        if (curr->next == node2)
            prevNode2 = curr;
        curr = curr->next;
    }

    // If node1 or node2 is not in the list, return
    if (node1 == nullptr || node2 == nullptr) return;

    // If node1 is not the head, update the previous node's next to node2
    if (prevNode1 != nullptr)
        prevNode1->next = node2;
    else // Else update the head pointer
        *head = node2;

    // If node2 is not the head, update the previous node's next to node1
    if (prevNode2 != nullptr)
        prevNode2->next = node1;
    else // Else update the head pointer
        *head = node1;

    // Swap the next pointers of node1 and node2
    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

// Helper function to insert a node at the end of the linked list
void push(Node** headRef, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Main function to test the swapNodes function
int main() {
    Node* head = nullptr;

    // Create a linked list
    push(&head, 10);
    push(&head, 15);
   

    cout << "Linked list before swapping: ";
    printList(head);

    // Find the nodes to swap (for example, we can manually set node1 and node2)
    Node* node1 = head; // Node with value 13
    Node* node2 = head->next; // Node with value 10

    // Swap the two nodes
    swapNodes(&head, node1, node2);

    cout << "Linked list after swapping 13 and 10: ";
    printList(head);

    return 0;
}
