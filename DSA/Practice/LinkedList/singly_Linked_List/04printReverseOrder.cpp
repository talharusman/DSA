#include<iostream>
using namespace std;

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
        }else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

void printINreversOrder(Node* head){
    if(head == nullptr){
        cout<<"NULL ";
        return;
    } 

    printINreversOrder(head->next);
    cout<<head->value<<" ";
    return;
}

int main(int argc, char const *argv[])
{
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    cout<<"orgent Linked List"<<endl;
    ll.display();
    cout<<"Linked List in reverse order"<<endl;
    Node* temp = ll.head;
    printINreversOrder(temp);


    return 0;
}
