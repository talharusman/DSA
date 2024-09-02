#include<iostream>
using namespace std;
class Node{
    private:
    int value;
    Node* next;
    public:
    Node(int value){
        this->value = value;
        this->next = NULL;
    }
    friend class LinkedList;
};
class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void InsertAtHead(int value){
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
    }
    void InsertAtTail(int value){
        Node* new_node = new Node(value);
        if(!head){
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
        	temp = temp->next;
		}
            
        temp = new_node;
        return;
    }
    
    void InsetrtAt_BeforeGivenPos(int New_value,int value){
    	Node* new_node = new Node(New_value);
        if(!head){
            head = new_node;
            return;
        }
        
        Node* temp = head;
        bool flage = false;
        while(temp->next != NULL){
        	if(temp->next->next->value == value){
        		flage = true;
        		break;
			}else temp = temp->next;
        		
		}
		if(flage){
			new_node->next= temp->next->next;
			temp->next=new_node;
		}else cout<<"Error! this value is not exist"<<endl;
	}
	
};
int main(){
    
    return 0;
}
