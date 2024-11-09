#include <iostream>
#include <string>
using namespace std;

class TicketQueue {
private:
    int front, rear, size;
    static const int maxSize = 10;
    string queue[maxSize];

public:
    // Constructor to initialize the queue
    TicketQueue() : front(0), rear(-1), size(0) {}

    // Method to add a passenger to the queue
    void enqueue(const string &passenger) {
        if (size == maxSize) {
            cout << "Queue is full. Cannot add more passengers." << endl;
            return;
        }
        rear++;
        queue[rear] = passenger;
        size++;
        cout << passenger << " has been added to the queue." << endl;
    }

    // Method to remove a passenger from the queue
    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty. No passengers to remove." << endl;
            return;
        }
        cout << queue[front] << " has purchased a ticket and is removed from the queue." << endl;
        front++;
        size--;
    }

    // Method to display the current passengers in the queue
    void displayQueue() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TicketQueue ticketQueue;

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
