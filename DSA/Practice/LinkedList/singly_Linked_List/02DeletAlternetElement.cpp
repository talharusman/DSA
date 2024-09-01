#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }

};
// ------------------------ approche 1---------------------------------------

// void insertAtTail(Node* &head,int value){
//     Node* n = new Node(value);
//     Node* temp = head;
//     while(temp->next!=nullptr){
//         temp = temp->next;
//     }
//     temp->next = n;
// }

void deletAlternet(Node* &head){
   Node* current = head;
   Node* next = current->next;
   Node* temp = current->next;
   while (current != nullptr && current->next != nullptr)
   {
        next = current->next;
        current->next = current->next->next;
        free(next);
        current = current->next;
   }
   return;    
}

// void display(Node* head){
//     Node* temp = head;
//     while (temp != nullptr)
//     {
//         cout<<temp->data<<"->";
//         temp = temp->next;
//     }
//     cout<<"NILL"<<endl;
// }


//--------------- approche 2 ---------------------
class linkedlist{
    public:
    Node* head;
    linkedlist(){
        head = nullptr;
    }
    void insertTail(int value){
        Node* n = new Node(value);
        if(head==nullptr){
            head = n;
        }
        else{
            Node* temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
                temp->next = n;
        }

    }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    
};


int main(int argc, char const *argv[])
{
    //Node* head = new Node(1);
    // insertAtTail(head,2);
    // insertAtTail(head,3);
    // insertAtTail(head,4);
    // insertAtTail(head,5);
    // insertAtTail(head,6);
    // insertAtTail(head,7);
    // display(head);

    // deletAlternet(head);
    // display(head);
    linkedlist ll;
    ll.insertTail(1);
    ll.insertTail(2);
    ll.insertTail(3);
    ll.insertTail(4);
    ll.insertTail(5);

    ll.display();

    deletAlternet(ll.head);
    ll.display();


    
    return 0;
}
