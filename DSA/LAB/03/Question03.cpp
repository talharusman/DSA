#include<iostream>
using namespace std;

class Node {
    int value;
    Node* next;
    public:
    Node(int val) {
        value = val;
        next = nullptr;
    }
    friend class LinkedList;
    void friend segregate_even_and_odd(Node* &head);
};

class LinkedList {
    Node* head;
    public:
    LinkedList() {
        head = nullptr;
    }

    void InsertAtTail(int value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node; // corrected line
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    Node* &getHead() {
        return head;
    }
};

void segregate_even_and_odd(Node* &head) {
    Node* evenHead = nullptr;
    Node* oddHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddTail = nullptr;

    Node* current = head;

    while (current) {
        if (current->value % 2 == 0) {
            // Even node
            if (!evenHead) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        } else {
            // Odd node
            if (!oddHead) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }
        current = current->next;
    }

    // If there are no even nodes, return the odd list as the head
    if (!evenHead) {
        head = oddHead;
    } else {
        evenTail->next = oddHead; // Append odd list to the even list
        head = evenHead;
    }

    // Ensure the last node of the odd list (or even list if no odds) points to nullptr
    if (oddTail) {
        oddTail->next = nullptr;
    }
}

int main(int argc, char const *argv[]) {
    LinkedList List;
    List.InsertAtTail(17);
    List.InsertAtTail(13);
    List.InsertAtTail(6);
    List.InsertAtTail(10);
    List.InsertAtTail(7);
    List.InsertAtTail(4);
    List.InsertAtTail(9);

    cout << "Original List: "<<endl;
    List.display();

    segregate_even_and_odd(List.getHead());

    cout << "List after segregating even and odd: "<<endl;
    List.display();

    return 0;
}
