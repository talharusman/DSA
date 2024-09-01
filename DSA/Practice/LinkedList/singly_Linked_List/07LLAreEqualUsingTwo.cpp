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

bool ChackEquealLL(Node* head1,Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while (ptr1 && ptr2)
    {
        if(ptr1->value != ptr2->value)
        {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // at theis point eithe rptr1 is nulll, or ptr2 is null or both null

    if(ptr1 != nullptr || ptr2 != nullptr)
        return false;
    else
    return true;
    
}

int main(int argc, char const *argv[])
{
    linkedList ll1,ll2;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);

    ll2.insertAtTail(1);
    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    ll2.insertAtTail(4);
    ll2.insertAtTail(5);
    // ll2.insertAtTail(6);

    ll1.display();
    ll2.display();

    cout<<ChackEquealLL(ll1.head,ll2.head);
    return 0;
}
