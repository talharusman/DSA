//Given the head of doubly linked list, delete the node whose neighbors have the s
//ame value.Traverse the list from right to left.
#include<iostream>
using namespace std;



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

void DeleteNeihborNodes(Node* &head,Node* &tail){
    Node* currptr = tail->prev;
    // Node* nextptr = currptr->next;
    while(currptr != head){
        Node* prevNode = currptr->prev;
        Node* nextNode = currptr->next;
        if(prevNode->value == nextNode->value ){
            // i need to delete the curr node
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            free(currptr);

        }
        currptr = currptr->prev;
    }
}

int main() {
    doubleLinkedList dll;
    cout << "before deleting  the Nodes of linked list" << endl;
    dll.InsertAtTail(2);
    dll.InsertAtTail(1);
    dll.InsertAtTail(1);
    dll.InsertAtTail(2);
    dll.InsertAtTail(1);
    dll.display();
    DeleteNeihborNodes(dll.head,dll.tail);
    dll.display(); 
    

    return 0;
}
