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

    void insetAttail(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next )
        {
            temp = temp->next;
        }
        temp->next = newNode;
        
    }
    void display(){
        Node* temp = head;
        while(temp ){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<"Null"<<endl;
    }
};

// ------------  Approch 1 ---------------------

// Node* Revers(Node* head){
//     Node* prev = nullptr;
//     Node* current = head;
//     Node* next = head->next;
//     // move all the ptrs by one stap
//     while (current){
//         current->next = prev;
//         prev = current;
//         current = next;
//         if(next){
//             next = next->next;
//             }

//     }
//     return prev; 
      
// }

//---------------- Approch 2 -------------------
// Node* Revers(Node* head){

Node* reversLrecursion(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    
    //recursive case
    Node* new_head = reversLrecursion(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

int main(int argc, char const *argv[])
{
    linkedList l;
    l.insetAttail(1);
    l.insetAttail(2);
    l.insetAttail(3);
    l.insetAttail(4);
    l.insetAttail(5);
    l.display();

    // l.head = Revers(l.head);
    l.head = reversLrecursion(l.head);

    l.display();
    
    
    return 0; 
}