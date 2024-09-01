#include<iostream>
using namespace std;
// Question of Slow Fast pointer 
// Given head, the head of a linked list, determine if the linked list
// has a cycle in it, and remove it

// for remove cycle of linked list we can use floyed algorethem
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


bool DetectCycle(Node* head){
    if(!head){
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            return true;
    }
    return false;
}

void RemoveCycle(Node* &head){ // assuming that teh linked list has a cycle
    Node* slow = head;
    Node* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while (slow != fast);

    fast = head;
    while (slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = nullptr;
    
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

    list.head->next->next->next->next->next->next->next->next = list.head->next->next;
    // list.display();
    if(DetectCycle(list.head))
       cout<<"Cycle Detected"<<endl;
    else
       cout<<"No Cycle"<<endl;

    RemoveCycle(list.head);

    cout<<"After removeing the cycle"<<endl;
    if(DetectCycle(list.head))
       cout<<"Cycle Detected"<<endl;
    else
       cout<<"No Cycle"<<endl;
    
    list.display();

    
    return 0;
}
