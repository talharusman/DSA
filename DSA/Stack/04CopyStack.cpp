#include<iostream>
#include <stack>
using namespace std;

// Function to copy contents of one stack to another in the same order
stack<int> copyStack(stack<int>& s){  // pass by reference
    stack<int> tempStack;
    
    // Copy contents of the original stack to tempStack (this reverses the order)
    while(!s.empty()){
        tempStack.push(s.top());
        s.pop();
    }
    
    stack<int> result;
    
    // Copy contents of tempStack to result (this restores the original order)
    while (!tempStack.empty()) {
        result.push(tempStack.top());
        s.push(tempStack.top());  // Push back to original stack to maintain original stack content
        tempStack.pop();
    }
    
    return result;
}

int main(int argc, char const *argv[])
{
    stack<int> s1, s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    s2 = copyStack(s1);  // Copy stack before emptying s1

    cout << "Stack 1: ";
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
   
    cout << "Stack 2: ";
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    return 0;
}
