#include<iostream>
using namespace std;

class Stack{
private:
    int capacity;
    int *arr;
    int top;

public:
    Stack(int capacity){
            this->capacity = capacity;
            arr = new int[this->capacity];
            this->top = -1;
    }

    void push(int data){
        if(this->top == this->capacity -1)
        {
            cout<<"OVERFLOW"<<endl;
            return;
        }
        this->top++;
        this->arr[this->top] = data;
        
    }

    int pop(){
        if(this->top == -1){
            cout<<"UNDERFLOW"<<endl;
            return INT_MIN;
        }
        this->top--;

    }

    int gettop(){
        if(this->top == -1){
            cout<<"UNDERFLOW"<<endl;
            return INT_MIN;
        }
        return this->arr[this->top];
    }

    bool IsEmpty(){
        return this->top == -1;
    }

    bool IsFull(){
        return this->top == this->capacity - 1;
    }

    int size(){
        return top + 1;
    }

};

int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<"top stack "<<st.gettop()<<endl;
    st.push(5);
    st.push(4);
    st.pop();
    st.push(1);
    cout<<"top stack "<<st.gettop()<<endl; 
    st.push(2);
    
    cout<<"Size is "<<st.size()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<"Size is "<<st.size()<<endl;
    st.pop();
    st.pop();
    st.pop();




    
    return 0;
}
