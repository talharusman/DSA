#include<iostream>
using namespace std;
/*
    Given a linked list, swap every two adjacent nodes and return its head. you may 
    mot modify the values in the list's nodes. only nodes themselves may be changed.
    eg
    1 -> 2 -> 3 -> 4 -> 5 -> 6 
    2 -> 1 -> 4 -> 3 -> 6 -> 5 

*/
class Node {
public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class linkedList {
public:
    Node* head;
    linkedList() {
        head = nullptr;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


Node* SwapAdjacent(Node* &head){
    // base case
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    //recursive case
    Node* secondNode = head->next;
    head->next = SwapAdjacent(secondNode->next);
    secondNode->next = head;// Reversing the link between first and second node
    return secondNode;
}

int main(int argc, char const* argv[]) {
    linkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.insertAtTail(7);
    list.insertAtTail(8);
    list.display();
    list.head = SwapAdjacent(list.head);

    list.display();

    return 0;
}
