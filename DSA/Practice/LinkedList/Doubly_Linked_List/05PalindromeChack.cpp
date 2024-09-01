#include<iostream>
using namespace std;
//given the head of a doubly linked list, find if it's a palindrome or not.
class Node {
public:
    int value;
    Node* next;
    Node* prev;
    Node(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class doubleLinkedList {
public:
    Node* head;
    Node* tail;
    doubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void InsertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
};
// --------------- Approch 1 -----------------------
// bool ispalindrom(Node* head,Node* tail){
//     if(head==tail){
//         return true;
//         }
//         if(head->value!=tail->value){
//             return false;
//         }
//         return ispalindrom(head->next,tail->prev);

// }
//----------------------------------------------------
//-------------------- Approch 2 ---------------------
bool ispalindrom(Node* head,Node* tail){
    if(head==tail){
        return true;
    }
    while (head != tail && tail != head->prev)
    {
        if (head->value != tail->value)
        {
            return false;
        }
        head = head->next;
        tail = tail->prev;

    }
    return true;
    
}
    
int main() {
    doubleLinkedList dll;
    cout << "before reversing the linked list" << endl;
    dll.InsertAtTail(1);
    dll.InsertAtTail(2);
    dll.InsertAtTail(3);
    dll.InsertAtTail(2);
    dll.InsertAtTail(1);
    dll.display();

    cout<<ispalindrom(dll.head,dll.tail)<<endl;
    dll.display();

    return 0;
}
