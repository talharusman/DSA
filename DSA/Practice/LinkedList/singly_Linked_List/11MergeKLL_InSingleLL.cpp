#include <iostream>
#include <vector>
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
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(){
        Node* temp  = head;
        while(temp != nullptr){
            cout<<temp->value<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

Node* MergeInSingleLL(Node* &head1,Node* &head2){
    Node *DumyHeadNode = new Node(-1);
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = DumyHeadNode;
    while(ptr1&& ptr2 ){
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
    }else{
        ptr3->next = ptr2;
    }
    return DumyHeadNode->next;
}

Node* mergKLinkedList(vector<Node*>&lists){
    if(lists.size() == 0){
        return nullptr;
    }
    while (lists.size()>1)
    {
        Node* MergedHead = MergeInSingleLL(lists[0],lists[1]);
        lists.push_back(MergedHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());

    }
    return lists[0];
}

//head1, head2, head3, head4
//1. head1 and head2 ll will be merged
// head3, head4, mergedHead1_2
//2. head3 and head4 ll will be merged
// mergedHead1_2, mergedHead3_4
//3. mergedHead1_2 and mergedHead3_4 ll will be merged
// mergedHead1_2_3_4


int main(int argc, char const *argv[])
{
    
    linkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(5);
    ll1.insertAtTail(10);
    cout<<"LL1=>";
    ll1.display();
    linkedList ll2;
    ll2.insertAtTail(2);
    ll2.insertAtTail(6);
    ll2.insertAtTail(9);
    cout<<"LL2=>";
    ll2.display();

    linkedList ll3;
    ll3.insertAtTail(4);
    ll3.insertAtTail(7);
    ll3.insertAtTail(12);
    cout<<"LL3=>";
    ll3.display();
    
    linkedList ll4;
    ll4.insertAtTail(3);
    ll4.insertAtTail(8);
    ll4.insertAtTail(11);
    cout<<"LL4=>";
    ll4.display();
    
    vector<Node*>list;
    list.push_back(ll1.head);
    list.push_back(ll2.head);
    list.push_back(ll3.head);
    list.push_back(ll4.head);


    linkedList mergedHead;
    mergedHead.head = mergKLinkedList(list);
    cout<<"Merged LL=>";
    mergedHead.display();




    return 0;
}
