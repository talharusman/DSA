#include<iostream>
using namespace std;

class Node{
 public:
 int data;
 Node* next;
 Node(int data)
 {
    this->data=data;
    this->next=NULL;
 }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = nullptr;
    }

    void insertAtTail(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next ){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(){
        Node* temp = head;
        while (temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
        
    }
};


Node* reversKll(Node* &head, int k){
    Node* prev = NULL;
    Node* curr = head;

    int counter =0;//for countion first k node

    while(counter<k && curr){// reversion frist k nodes
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        counter++;
    }

    // current pointer will give us (k+1)th Node 
    if(curr != nullptr){
        Node* new_head = reversKll(curr,k);// recursive call
        head->next = new_head;

    }
    return prev; // previce pointer will give the new_head of connected linkedlists
}


int main(int argc, char const *argv[])
{
     LinkedList l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.insertAtTail(6);
    l.display();

    // l.head = Revers(l.head);
    l.head = reversKll(l.head,2);

    l.display();
    return 0;
}
