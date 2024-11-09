#include <iostream>
#include <string>
using namespace std;



struct Node {
    string data;
    Node* next;
    Node(const string &data) : data(data), next(nullptr) {}
};

class LinkedListTicketQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedListTicketQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(const string &passenger) {
        Node* newNode = new Node(passenger);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << passenger << " has been added to the queue." << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. No passengers to remove." << endl;
            return;
        }
        Node* temp = front;
        cout << front->data << " has purchased a ticket and is removed from the queue." << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void displayQueue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current Queue: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedListTicketQueue() {
        while (front != nullptr) {
            dequeue();
        }
    }
};

int main() {
    LinkedListTicketQueue ticketQueue;

    // Adding passengers to the queue
    for (int i = 1; i <= 10; i++) {
        ticketQueue.enqueue("Passenger " + to_string(i));
    }
    ticketQueue.displayQueue();

    // Removing the first 5 passengers
    for (int i = 0; i < 5; i++) {
        ticketQueue.dequeue();
    }
    ticketQueue.displayQueue();

    // Adding 5 more passengers
    for (int i = 11; i <= 15; i++) {
        ticketQueue.enqueue("Passenger " + to_string(i));
    }
    ticketQueue.displayQueue();

    return 0;
}
