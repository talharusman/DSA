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

    void DeleteAtStart(){
        if(head == nullptr){
            cout << "List is empty" << endl;
            return;
        }
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }// now temp point to end of linked list 
        temp->next = head->next;// delete head node
        delete head;
        head = temp->next;// update head
        
    }

    void DeleteAttail(){
        if(head == nullptr){
            cout << "List is empty" << endl;
            return;
        }
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }// now temp point to 2nd last node
        Node* temp1 = temp->next;
        temp->next = head;
        delete temp1;
        head = temp->next;// update head


    }
    

};

int main(int argc, char const *argv[])
{
    CircularLinkedList cll;
    cll.InsertAttail(10);
    cll.InsertAttail(20);
    cll.InsertAttail(30);
    cll.InsertAttail(40);
    cll.InsertAttail(50);
    cll.InsertAttail(60);

    cll.display();

    cll.DeleteAtStart();
    cll.display();
    cll.DeleteAttail();
    cll.display();
    
    
    
    return 0;
}
