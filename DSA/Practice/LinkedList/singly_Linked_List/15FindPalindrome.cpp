#include<iostream>
using namespace std;
// Question of Slow Fast pointer 

//-------------------- SOLUTION ---------------------
//Stap 1: find Middle Element using slow and fast ptr
//Stap 2: break Linked List into 2 part
//Stap 3: Reverse 2nd part of Linked List
//Stap 4: Compare 1st part with 2nd part of Linked List
//Stap 5: If both are same then return true else false

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

 bool isPlaindrome(Node*  head){
    // find middle element
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // now slow is pointing to middle element
    //2. break the linked list in th middle
    Node* curr = slow->next;
    Node* prev = slow;
    slow->next = nullptr;

    //3. reverse the secand halpf of linked list
    while(curr){

        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //4. chack if the linked list are equal
    Node* head1 = head;
    Node* head2 = prev;
    while(head2){
        if(head1->value != head2->value)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;

    }
    return true;

    
 }

int main(int argc, char const *argv[])
{
    linkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3); 
    list.insertAtTail(4);
    list.insertAtTail(4);
    list.insertAtTail(3);
    list.insertAtTail(2);
    list.insertAtTail(1);

    list.display();
    cout<<isPlaindrome(list.head);

    
    return 0;
}
