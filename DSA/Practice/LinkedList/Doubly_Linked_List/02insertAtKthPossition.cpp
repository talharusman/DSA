#include<iostream>
using namespace std;

class Node{
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

class doubleLinkedList{
    public:
    Node* head;
    Node* tail;
    doubleLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void InsertAtHead(int value){
        Node* newNode = new Node(value);
        if(!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void InsertAtTail(int value){
        Node* newNode = new Node(value);
        if(!tail)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;

    }

    void display(){
        Node* temp = head;
        while (temp != nullptr)
        {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
        
    }

    void InsertAtKthPos(int value,int k){
        Node* newNode = new Node(value);
        // assuming k is less or epual to length of doubly linked list
        if(k == 1){
            InsertAtHead(value);
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < k-1)
        {
            temp = temp->next;
            count++;

        }// temp will be pointion to the node at (k-1)th position
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;

    }
};

int main(){
    doubleLinkedList dll;
    dll.InsertAtTail(1);
    dll.InsertAtTail(2);
    dll.InsertAtTail(3);
    dll.InsertAtHead(0);
    dll.display();

    dll.InsertAtKthPos(4,3);
    dll.display();

    return 0;
}