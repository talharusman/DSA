#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node(int data){
        value = data;
        next = NULL;
    }

};
void insertAtTail(Node* &Head,int value){
    Node* new_node = new Node(value);
    Node* temp = Head;
    while (temp->next!= NULL)
    {
        temp = temp->next;
    }
    // temp has reached last node
    temp->next = new_node;
    
}
void insertAtHead(Node* &head,int value){
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->value<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtPosition(Node* &head,int value,int pos){
    Node* new_node = new Node(value);
    Node* temp = head;
    int Current_Postion = 0;
    if(pos == 0){
        insertAtHead(head,value);
    }
    while (Current_Postion != pos - 1){
        temp = temp->next;
        Current_Postion++;

    }
    // temp is pointing to node at pos-1
    new_node->next = temp->next;
    temp->next = new_node;
}

void updateAtPosition(Node* head,int value,int k){
    Node* temp = head;
    int current_position = 0;
    while (current_position != k)
    {
        temp = temp->next;
        current_position++;

    }
    // temp will be pointing to hte kth node
    temp->value = value;

}

void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleatAtTail(Node* &head){
    // --------Approch 1-------
    // Node* temp = head;
    // Node* temp2 = head->next;
    // while (temp2->next != NULL)
    // {
    //     temp = temp->next;
    //     temp2 = temp->next;

    // }
    // temp->next = nullptr;
    // free(temp2);
    // ------------------------
    // --------Approch 2-------
    Node* secend_Last = head;
    Node* last = head->next;
    while (secend_Last->next->next != nullptr){
        secend_Last = secend_Last->next;
    }
    last = secend_Last->next;
    secend_Last->next = nullptr;
    free(last);
}

void deleteAtPosion(Node* &head,int pos){
    //------Aproche 1-----------
    // Node* temp = head;
    // Node* temp2 = head->next;
    // int current_position = 0;
    // while (current_position != pos - 1)
    // {
    //     temp = temp->next;
    //     current_position++;
    // }
    // temp2 = temp->next;

    // temp->next=  temp2->next;
    // free(temp2);
    // -------------------------
    // ------Aproche 2-----------
    if(pos == 0){
        deleteAtHead(head);
        return;
    }
    int current_position = 0;
    Node* previce = head;
    while (current_position != pos -1)
    {
        previce = previce->next;
        current_position++;
    }
    Node* temp = previce->next;
    previce->next = temp->next;
    free(temp);
    


}


int main(int argc, char const *argv[])
{
   cout<<endl; 
   cout<<endl; 
   Node* head = NULL;
   insertAtHead(head,1);
   display(head);
  

   insertAtHead(head,2);
   display(head);
   
   
   insertAtTail(head,3);
   display(head);

   insertAtPosition(head,4,1);
   display(head);

   updateAtPosition(head,9,2);
   display(head);

   deleteAtPosion(head,2);
   display(head);

   deleteAtHead(head);
   display(head);
   deleatAtTail(head);
   display(head);

   
   cout<<endl; 
   cout<<endl; 
    return 0;
}
