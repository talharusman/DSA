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

    // Insert a new node at the head of the list
    void InsertAtHead(int value){
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
    }

    // Insert a new node at the tail of the list
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
        temp->next = new_node; // corrected line
        return;
    }

    // Insert a new node before a given value
    void InsertAt_BeforeGivenValue(int New_value, int value){
        Node* new_node = new Node(New_value);
        if(!head){
            head = new_node;
            return;
        }
        
        if(head->value == value){
            new_node->next = head;
            head = new_node;
            return;
        }

        Node* temp = head;
        bool flag = false;
        while(temp->next != NULL){
            if(temp->next->value == value){
                flag = true;
                break;
            }else 
                temp = temp->next;
        }
        if(flag){
            new_node->next = temp->next;
            temp->next = new_node;
        }else 
            cout<<"Error! this value is not exist"<<endl;
    }

    // Insert a new node after a given value
    void InsertAt_After_Given_value(int New_value, int value){
        if(head != NULL){
            Node* new_node = new Node(New_value);
            Node* temp = head;
            while(temp->value != value){
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node; // corrected line

        }else 
            cout<<"There is no Node with the given value:"<<endl;
    }

    // Delete the node at the head of the list
    void deleteAtHead(){
        if(head){
            Node* temp = head;
            head = head->next;
            free(temp);
        }else{
            cout << "List is empty" << endl;
        }
    }

    // Delete the node at the tail of the list
    void deleteAtTail(){
        if(head){
            if(head->next == nullptr){
                free(head);
                head = nullptr;
                return;
            }
            Node* second_last = head;
            while (second_last->next->next != nullptr){
                second_last = second_last->next;
            }
            Node* last = second_last->next;
            second_last->next = nullptr;
            free(last);
        }else{
            cout << "List is empty" << endl;
        }
    }

    // Delete a node with a given value
    void deleteFromValue(int value){
        if(head){
            if(head->value == value){
                Node* temp = head;
                head = head->next;
                free(temp);
                return;
            }
            Node* previous = head;
            while (previous->next != nullptr){
                if(previous->next->value == value){
                    Node* temp = previous->next;
                    previous->next = temp->next;
                    free(temp);
                    return;
                }
                previous = previous->next;
            }
            cout<<"Given value is not exist:"<<endl;
        }else 
            cout<<"List is empty"<<endl;
    }

    // Count the number of nodes in the list
    int count(){
        int num = 0;
        if(head){
            Node* temp = head;
            while(temp){
                temp = temp->next;
                num++;
            }
        }
        return num;
    }

    // Display the list
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->value<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList list;
    cout << "Inserting 10, 20, 30 at head:" << endl;
    list.InsertAtHead(10);
    list.InsertAtHead(20);
    list.InsertAtHead(30);
    cout << "List: ";
    list.display(); // prints: 30->20->10->NULL
    cout << endl;

    cout << "Inserting 40 at tail:" << endl;
    list.InsertAtTail(40);
    cout << "List: ";
    list.display(); // prints: 30->20->10->40->NULL
    cout << endl;

    cout << "Inserting 25 before 20:" << endl;
    list.InsertAt_BeforeGivenValue(25, 20);
    cout << "List: ";
    list.display(); // prints: 30->25->20->10->40->NULL
    cout << endl;

    cout << "Inserting 35 after 30:" << endl;
    list.InsertAt_After_Given_value(35, 30);
    cout << "List: ";
    list.display(); // prints: 30->35->25->20->10->40->NULL
    cout << endl;

    cout << "Deleting node at head:" << endl;
    list.deleteAtHead();
    cout << "List: ";
    list.display(); // prints: 35->25->20->10->40->NULL
    cout << endl;

    cout << "Deleting node at tail:" << endl;
    list.deleteAtTail();
    cout << "List: ";
    list.display(); // prints: 35->25->20->10->NULL
    cout << endl;

    cout << "Deleting node with value 25:" << endl;
    list.deleteFromValue(25);
    cout << "List: ";
    list.display(); // prints: 35->20->10->NULL
    cout << endl;

    cout << "Number of nodes: " << list.count() << endl; // prints: 3
    return 0;
}
