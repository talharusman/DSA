#include<iostream>
using namespace std;
/*
Given the head of a singly linked list, group all the nodes with odd indices together 
followed by the nodes with even indices. adn rethrn teh reordered list.
*/

class Node{
    public:
    int value;
    Node* next;
    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class linkedList{
    public:
    Node* head;
    linkedList(){
        head = nullptr;
    }

    void insertAtTail(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        }else
        {
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;

        }
    }

    void display(){
        Node* temp = head;

        while (temp != nullptr){
            cout<<temp->value<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
        
    }

};

Node* oddEvenLinkedList(Node* &head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    
    Node* evenHead = head->next;
    Node* oddptr = head;
    Node* evenptr = evenHead;

    while(evenptr && evenptr->next){
        oddptr->next = oddptr->next->next;
        evenptr->next = evenptr->next->next;
        oddptr = oddptr->next;
        evenptr = evenptr->next;

    }
    oddptr->next = evenHead;
    return head;
}

int main(int argc, char const *argv[])
{
    linkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.insertAtTail(7);
    list.insertAtTail(8);
    
    list.display();
    list.head = oddEvenLinkedList(list.head);
    list.display();
   
    
    return 0;
}
