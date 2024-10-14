#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to get the tail (last node) of the linked list
Node* getTail(Node* head) {
    while (head != nullptr && head->next != nullptr)
        head = head->next;
    return head;
}

// Helper function to insert a node at the end of the linked list
void push(Node** headRef, int newData) {
    Node* newNode = new Node(newData);
    if (*headRef == nullptr) {
        *headRef = newNode;
        return;
    }

    Node* temp = *headRef;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

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


Node* partition(Node* head,Node* tail){
    Node* pivot = head;
    Node* prev = head;
    Node* curr = head->next;
    while (curr != tail->next)
    {
        if(pivot->data > curr->data){
            swapNodes(&head,prev,curr);
            prev = prev->next;
        }
        else curr = curr->next;
            
    }
    swapNodes(&head,prev,pivot);
    return pivot;
    
}

void SortRec(Node* head,Node* tail){
    if(head==tail || head == nullptr || tail == nullptr){
        return;
    }

    Node* pivoit = partition(head,tail);
    SortRec(head,pivoit);
    SortRec(pivoit->next,tail);


}

void QuickSort(struct Node** headRef)
{
    Node* head = *headRef;
    if (head == nullptr || head->next == nullptr)
        return;
        // Find the tail of the linked list
        Node* tail = getTail(*headRef);
        SortRec(head,tail);

}


// Main function
int main() {
    Node* head = nullptr;

    // Create a linked list
    push(&head, 30);
    push(&head, 3);
    push(&head, 4);
    push(&head, 20);
    push(&head, 5);

    cout << "Linked List before sorting: ";
    printList(head);

    QuickSort(&head); // Call the QuickSort function

    cout << "Linked List after sorting: ";
    printList(head);

    return 0;
}