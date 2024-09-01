#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;
    Node(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class doubleLinkedList {
public:
    Node* head;
    Node* tail;
    doubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void InsertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

vector<int> pairSumDLL(Node* head, Node* tail, int x) {
    vector<int> ans(2, -1);
    Node* start = head;
    Node* end = tail;

    while (start != nullptr && end != nullptr && start != end) {
        int sum = start->value + end->value;
        if (sum == x) {
            ans[0] = start->value;
            ans[1] = end->value;
            return ans;
        }
        if (sum < x) {
            start = start->next;
        } else {
            end = end->prev;
        }
    }

    return ans;
}

int main() {
    doubleLinkedList dll;
    cout << "Initial linked list:" << endl;
    dll.InsertAtTail(1);
    dll.InsertAtTail(2);
    dll.InsertAtTail(3);
    dll.InsertAtTail(5);
    dll.InsertAtTail(6);
    dll.display();

    vector<int> ans = pairSumDLL(dll.head, dll.tail, 5);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
