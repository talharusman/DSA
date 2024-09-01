#include<iostream>
using namespace std;
//Given the head of a doubly linked list,reverse it.


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

void Revers(Node* &head,Node* &tail){
    Node* currptr = head;
    while (currptr)
    {
        Node* nextptr = currptr->next;
        currptr->next = currptr->prev;
        currptr->prev = nextptr;
        currptr = nextptr;
    }

    Node* newHead = tail;
    tail = head;
    head = newHead;

    
}

int main() {
    doubleLinkedList dll;
    cout << "before reversing the linked list" << endl;
    dll.InsertAtTail(1);
    dll.InsertAtTail(2);
    dll.InsertAtTail(3);
    dll.InsertAtTail(4);
    dll.InsertAtTail(5);
    dll.display();
    cout<<"after reversing the linked list"<<endl;
    Revers(dll.head,dll.tail);
    dll.display();

    return 0;
}
