#include<iostream>
#include<cstdlib>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    bool Visted = false; 
    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

int getLength(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp != nullptr){
        length++;
        temp = temp->next;
    }
    return length;
}

Node* moveHeadByK(Node* Head,int k){
     Node* temp = Head;
     for(int i = 0; i < k; i++){
        temp = temp->next;
     }
     return temp;
}

Node* getIntersection(Node* head1,Node* head2){
    //Stap 1: calculate length of both Linked List
   int length1 = getLength(head1);
   int length2 = getLength(head2);
   
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    int k = abs(length1 - length2);

   // Stap 2: find differesce K between linkedlist and move K staps longer linkedlist ptr
   if(length1 > length2){
    ptr1 = moveHeadByK(head1,k);
   }else{
     ptr2 = moveHeadByK(head2,k);
   }

   // Stap 3: compare ptr1 and ptr2
   while(ptr1 != nullptr && ptr2 != nullptr){
     if(ptr1 == ptr2){
        return ptr1;
      }
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
   }
   return nullptr;
   }


class LinkedList{
        public:
    Node* head;

    LinkedList(){
        head = nullptr;
    }

    void insertAtTail(int value){
        Node* new_node = new Node(value);
        if(head == nullptr){
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new_node;;
        return;
    }

    void display(){
        Node* temp = head;

        while(temp){
            cout<<temp->value<<"->";
            temp = temp->next;
        }
        cout<<"nullptr"<<endl;
    }
};



int main(int argc, char const *argv[])
{   
    LinkedList list1;
    list1.insertAtTail(1);
    list1.insertAtTail(2);
    list1.insertAtTail(3);
    list1.insertAtTail(4);
    list1.insertAtTail(5);
    list1.display();
    //1->2->3->4->5->nullptr

    LinkedList list2;
    list2.insertAtTail(6);
    list2.insertAtTail(7);
    list2.head->next->next = list1.head->next->next->next;
    list2.display();
    //6->7->4->5->nullptr

    Node* intersection = getIntersection(list1.head,list2.head);

    if(intersection){
        cout<<"Intersection is "<<intersection->value<<endl;
    }else cout<<"-1"<<endl;
   
    
    return 0;
}
