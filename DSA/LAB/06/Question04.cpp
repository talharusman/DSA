#include <iostream>
using namespace std;


class Stack {
private:
    int *arr;
    int top;
    int capacity;


public:
    Stack(int capacity) {

        this->capacity = capacity;
        this->arr = new int[capacity];
        this->top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int element) {
        if (top == capacity - 1) {
            std::cout << "Stack overflow!" << std::endl;
            return;


        }

        arr[++top] = element;
    }

    int pop() {
        if (top == -1) {


            std::cout << "Stack underflow!" << std::endl;
            return -1;
        }
        return arr[top--];

    }

    bool isEmpty() {

        return top == -1;
    }
};

class Queue {
private:
    Stack stack1;
    Stack stack2;


public:
    Queue(int capacity) : stack1(capacity), stack2(capacity) {}

    void enqueue(int element) {

        stack1.push(element);
    }

    int dequeue() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }

    bool isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
        
    }
};



int main() {
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " ";
    }

    return 0;
}