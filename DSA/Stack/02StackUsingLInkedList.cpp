#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }

};

class Stack{
    Node* head;
    int capacity;
    int currentSize;  // Renamed from size to currentSize

    public:
    Stack(int cap) {
        capacity = cap;
        currentSize = 0;
        head = nullptr;
    }

    bool isEmpty() {
        return this->head == nullptr;
    }
    
    bool isFull() {
        return this->currentSize == this->capacity;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        if (this->isFull()) {
            cout << "Stack is full. Cannot push " << value << endl;
            delete newNode;
            return;
        }
        if (this->isEmpty()) {
            this->head = newNode;
            this->currentSize++;
            return;
        }
        newNode->next = head;
        this->head = newNode;
        this->currentSize++;

    }

    void pop(){
        if (this->isEmpty()) {
            cout << "Stack is empty. Cannot pop" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        this->currentSize--;

    }

    int getTop() {
        if (this->isEmpty()) {
            cout << "Stack is empty. Cannot get top element" << endl;
            return INT_MIN;
        }
        return this->head->value;
    }

    int getSize(){  // Renamed from size to getSize
        return this->currentSize;
    }
};

int main(int argc, char const *argv[])
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "Top of stack: " << st.getTop() << endl;
    st.push(5);
    st.push(4);
    st.pop();
    st.push(1);
    cout << "Top of stack: " << st.getTop() << endl; 
    st.push(2);
    
    cout << "Size is " << st.getSize() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << "Size is " << st.getSize() << endl;
    st.pop();
    st.pop();
    st.pop();

    return 0;
}
