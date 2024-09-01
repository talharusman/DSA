#include<iostream>
using namespace std;

class Node{
    public:
     int date;
    Node* next;
   
    Node(int date) {
        this->date = date;
        next = nullptr;
    }

    
};



class CircularLinkedList{
    public:
    Node* head;

    CircularLinkedList(){
        head = nullptr;
    }
    void insertAtStart(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;// circular linked list
            return;
        }

        Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }// now tail is pointing to the last node
        tail->next = newNode;// now tail is pointing to the new node
        newNode->next = head;// circular linked list
        head = newNode;
           
    }

    void InsertAttail(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;// circular linked list
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;// circular linked list

    }

    void InsertAtarbitrarypos(int value, int k){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;// circular linked list
            return;
        }
        if(k == 0){
            insertAtStart(value);
            return;
        }
        Node* temp = head;
        for(int i = 0; i < k-2 ; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;


    }

    void display(){
        Node* temp = head;
        if(head == nullptr){
            cout << "List is empty" << endl;
            return;
        }
        do
        {
            cout << temp->date << " ";
            temp = temp->next;
            
        } while (temp != head);
        cout<<endl;
    }


    void printCircular(){
        Node* temp = this->head;
    for(int i =0; i < 10;i++){
        cout<<temp->date<<" ";
        temp = temp->next;
    }
   }

};

int main(int argc, char const *argv[])
{
    CircularLinkedList cll;
    cll.insertAtStart(1);
    cll.insertAtStart(2);
    cll.insertAtStart(3);
    cll.InsertAttail(4);
    cll.InsertAttail(5);
    cll.InsertAtarbitrarypos(6,3);

    cll.display();
    // cll.printCircular();
    
    return 0;
}
