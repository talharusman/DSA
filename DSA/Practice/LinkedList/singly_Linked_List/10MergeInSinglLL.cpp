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

    void insetrAtTail(int value){
        Node* new_Node = new Node(value);

        if(head == nullptr){
            head = new_Node;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new_Node;

    }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->value<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

Node* mergeLinkedLists(Node* &head1,Node* &head2){
      Node* dummyHeadNode = new Node(-1);
      Node* ptr1 = head1;
      Node* ptr2 = head2;
      Node* ptr3 = dummyHeadNode;
      while(ptr1 && ptr2){
        if(ptr1->value < ptr2->value){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;

        }
        ptr3 = ptr3->next;
      }
      if(ptr1){
        ptr3->next = ptr1;
      }
      if(ptr2){
        ptr3->next = ptr2;
      }
    return dummyHeadNode->next;
}

int main(int argc, char const *argv[])
{   
    linkedList l1;
    l1.insetrAtTail(1);
    l1.insetrAtTail(4);
    l1.insetrAtTail(5);
    l1.display();

    linkedList l2;
    l2.insetrAtTail(2);
    l2.insetrAtTail(3);
    l2.insetrAtTail(6);
    l2.display();
    

    linkedList merged;
    merged.head = mergeLinkedLists(l1.head,l2.head);
    merged.display();
    

    
    
    return 0;
}
