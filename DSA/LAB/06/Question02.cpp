#include <iostream>
#include<algorithm>
using namespace std;

class Node {
    Node* next;
    char val;
public:
    friend class Stack;
    Node(): next(nullptr), val(0) {}
    Node(char v, Node* next = nullptr): val(v), next(next) {}
};

class Stack {
    Node* head;
    
public:
    Stack(): head(nullptr) {}
    
    void Push(char x) {
        Node* newnode = new Node(x, head);  
        head = newnode;  
    }
    
    char Pop() {
        if (head == nullptr) {
            cout << "Stack is Empty" << endl;
            return -1; 
        }
        Node* temp = head;
        char i = temp->val;
        head = head->next;  
        delete temp;  
        return i;
    }
    
    char Peek(){
        if(head != NULL) return head->val;
        cout<<"Stack is Empty"<<endl; return 0;
    }
    
    bool isEmpty(){
        if(head == NULL) return true;
        return false;
    }
};

int precedence(char i){
    if(i == '^') return 3;
    if( i == '*' || i == '/') return 2;
    if(i == '+' || i== '-') return 1;
    return -1;
}
string Infix_to_Postfix(string s){
    Stack st;
    string res;

    for(int i=0;i<s.length();++i){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
            res += s[i];
        }else{
            if(s[i] == '('){
                st.Push(s[i]);   
            }
            else if(s[i] == ')'){
                while(!st.isEmpty() && st.Peek() != '('){
                res += st.Pop();
            }
            st.Pop();
            }else{
                while(!st.isEmpty() && precedence(st.Peek()) >= precedence(s[i])){
                res += st.Pop();
                }
            st.Push(s[i]);
            }
            
        }
    }

    while(!st.isEmpty()){
        res += st.Pop();
    }
    
    return res;
}
string Infix_to_Prefix(string s){
    Stack st;
    string res;
    reverse(s.begin(), s.end());
    for(int i=0;i<s.length();++i){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
            res += s[i];
        }else{
            if(s[i] == ')'){
                st.Push(s[i]);   
            }
            else if(s[i] == '('){
                while(!st.isEmpty() && st.Peek() != ')'){
                res += st.Pop();
            }
            st.Pop();
            }else{
                while(!st.isEmpty() && precedence(st.Peek()) > precedence(s[i])){
                res += st.Pop();
                }
            st.Push(s[i]);
            }
            
        }
    }

    while(!st.isEmpty()){
        res += st.Pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){

    string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";
    
    cout<<"Infix: "<<infix<<endl;
     cout<<"Post Fix: "<<Infix_to_Postfix(infix)<<endl;
     cout<<"Pre Fix: "<< Infix_to_Prefix(infix)<<endl;
  
   
    return 0;
}