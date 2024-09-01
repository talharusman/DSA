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
//=============== wrong =========================
// void deleatDuplicat(Node* head){
//    Node* current = head;
//    Node* runner = head->next;
//    while(runner != nullptr){
//       if(current->value == runner->value){
//         Node* temp = runner;
//         current->next = runner->next;
//         delete temp;
//       }else{
//         current = current->next;
        
//       }
//       runner = runner->next;
//    }
   
   
// }


// ------------------ Approch 1 -----------------
// void deleteDuplicate(Node* head) {
//     if (head == nullptr) return;  // Check if the list is empty

//     Node* current = head;
    
//     while (current) {
//         Node* runner = current;
//         while (runner->next != nullptr) {
//             if (runner->next->value == current->value) {
            
//                 Node* temp = runner->next;
//                 runner->next = runner->next->next;
//                 delete temp;
//             } else {
//                 runner = runner->next;
//             }
//         }
//         current = current->next;
//     }
// }

// ------------------ Approch 2 -----------------
 void deleteDuplicate(Node* head) {
    if (head == nullptr) return;  // Check if the list is empty
    Node* current = head;
    while (current)
    {
        while(current->next && current->value == current->next->value){
            // delete current->next
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);

        }// this loop ends when current node and next node values are different 
        current = current->next;
    }
    
 }

int main(int argc, char const *argv[])
{
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(5);

    ll.display();
    
    deleteDuplicate(ll.head);
    // deleatDuplicat(ll.head);
    ll.display();
    return 0;
}
