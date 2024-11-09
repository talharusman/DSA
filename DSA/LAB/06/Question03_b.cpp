#include <iostream>
#include <string>
using namespace std;

class CircularTicketQueue {
private:
    int front, rear, size;
    static const int maxSize = 10;
    string queue[maxSize];

public:
    CircularTicketQueue() : front(-1), rear(-1), size(0) {}

    void enqueue(const string &passenger) {
        if (size == maxSize) {
            cout << "Queue is full. Cannot add more passengers." << endl;
            return;
        }
        if (rear == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }
        queue[rear] = passenger;
        size++;
        cout << passenger << " has been added to the queue." << endl;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty. No passengers to remove." << endl;
            return;
        }
        cout << queue[front] << " has purchased a ticket and is removed from the queue." << endl;
        front = (front + 1) % maxSize;
        size--;
    }

    void displayQueue() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current Queue: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % maxSize] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularTicketQueue ticketQueue;

    // Adding 10 passengers to the queue
    for (int i = 1; i <= 10; i++) {
        ticketQueue.enqueue("Passenger " + to_string(i));
    }
    ticketQueue.displayQueue();

    // Removing the first 5 passengers
    for (int i = 0; i < 5; i++) {
        ticketQueue.dequeue();
    }
    ticketQueue.displayQueue();

    // Attempting to add 5 more passengers
    for (int i = 11; i <= 15; i++) {
        ticketQueue.enqueue("Passenger " + to_string(i));
    }
    ticketQueue.displayQueue();

    return 0;
}
