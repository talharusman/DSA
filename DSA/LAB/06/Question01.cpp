#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;

public:
   
    void push(int value) {
        elements.push_back(value);
    }

    
    int pop() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        int value = elements.back();
        elements.pop_back();
        return value;
    }

   
    bool isEmpty() const {
        return elements.empty();
    }

    
    int size() const {
        return elements.size();
    }
};

void separateEvenOdd(Stack& inputStack, Stack& evenStack, Stack& oddStack) {
    while (!inputStack.isEmpty()) {
        int value = inputStack.pop();
        if (value % 2 == 0) {
            evenStack.push(value);
        } else {
            oddStack.push(value);
        }
    }
}

void printStack(Stack& stack) {

    Stack tempStack;
    while (!stack.isEmpty()) {
        int value = stack.pop();
        cout << value << " ";
        tempStack.push(value);
    }

    while (!tempStack.isEmpty()) {
        stack.push(tempStack.pop());
    }
}

int main() {
    Stack inputStack;
    Stack evenStack;
    Stack oddStack;

    inputStack.push(1);
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);
    inputStack.push(5);
    inputStack.push(6);

    separateEvenOdd(inputStack, evenStack, oddStack);

    cout << "Even Stack: ";
    printStack(evenStack);
    cout << "\nOdd Stack: ";
    printStack(oddStack);
    cout << std::endl;

    return 0;
}
