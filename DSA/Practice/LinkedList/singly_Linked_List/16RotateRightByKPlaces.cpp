#include<iostream>
using namespace std;
// Question of Slow Fast pointer 
// Rearrangement of node in a list

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

// Stap 1: To find Total Lenth of linked list
// Stap 2: Find tail node
// Stap 3: tail->next = head


Node* rotateByK(Node* &head, int k){
    //1. find lenght of ll
    int n = 0;
    //2. find tail node
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
        n++;
    }
    n++;// fofr including last node

    k = k%n;
    if(k == 0){
        return head;
    }
    tail->next = head;
    //3. triverse n-k node
    Node* temp = head;
    for(int i = 1; i < n - k;i++){
        temp = temp->next;
    }
    //temp i snow pointion to (n-k)th node

    Node* newhead = temp->next;
    temp->next = nullptr;
    return newhead;
    
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
   list.head = rotateByK(list.head,3);
   list.display();

    
    return 0;
}
