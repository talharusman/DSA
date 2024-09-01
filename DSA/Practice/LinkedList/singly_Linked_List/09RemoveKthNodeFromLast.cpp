#include<iostream>
using namespace std;

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
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void removeKthNodeFromLast(int k) {
        Node* ptr1 = head;
        Node* ptr2 = head;
        // move ptr2 k steps ahead
        for (int i = 0; i < k; i++) {
            ptr2 = ptr2->next;
        }
        if (ptr2 == nullptr) { // k is equal to length of linked list
            // we have to delete the head node
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // now ptr2 is k steps ahead of ptr1
        // when ptr2 is at the end, ptr1 will be at the node before the node to be deleted
        while (ptr2->next != nullptr) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        // now ptr1 is pointing to the node before the kth node from the end
        // node to be deleted is ptr1->next

        Node* kThNode = ptr1->next;
        ptr1->next = ptr1->next->next;
        delete kThNode;
    }
};

// ------------------ APROCHE 2 ----------------------
//__________________WRONG APROCHE_____________________

//  void removeKthNodeFromLast(Node* head,int k) {
//         Node* ptr1 = head;
//         Node* ptr2 = head;
//         // move ptr2 k steps ahead
//         for (int i = 0; i < k; i++) {
//             ptr2 = ptr2->next;
//         }
//         if (ptr2 == nullptr) { // k is equal to length of linked list
//             // we have to delete the head node
//             Node* temp = head;
//             head = head->next;
//             delete temp;
//             return;
//         }

//         // now ptr2 is k steps ahead of ptr1
//         // when ptr2 is at the end, ptr1 will be at the node before the node to be deleted
//         while (ptr2->next != nullptr) {
//             ptr1 = ptr1->next;
//             ptr2 = ptr2->next;
//         }
//         // now ptr1 is pointing to the node before the kth node from the end
//         // node to be deleted is ptr1->next

//         Node* kThNode = ptr1->next;
//         ptr1->next = ptr1->next->next;
//         delete kThNode;
//     }

int main(int argc, char const *argv[]) {
    linkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);

    cout << "Original list: "<<endl;
    list.display();

    // removeKthNodeFromLast(list.head,5);
    list.removeKthNodeFromLast(5);

    cout << "After removing "<<5<<"th node from last: "<<endl;
    list.display();

    return 0;
}
