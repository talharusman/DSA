#include<iostream>
using namespace std;
// Question of Slow Fast pointer 

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

Node* findMiddleElement(Node* &head){
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
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
    list.display();

    Node* mid = findMiddleElement(list.head);
    cout<<mid->value<<endl;
    
    return 0;
}
