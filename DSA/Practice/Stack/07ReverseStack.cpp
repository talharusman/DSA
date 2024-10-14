#include<iostream>
#include<stack>
using namespace std;

void ReverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    stack<int> temp1,temp2;
    while (not st.empty())
    {
        temp1.push(st.top());
        st.pop();
    }
    while (not temp1.empty())
    {
        temp2.push(temp1.top());
        temp1.pop();

    }
    while(not temp2.empty()){
        st.push(temp2.top());
        temp2.pop();

    }
    
}

void InsertAtBottom(stack <int> &iniput,int value){
    /**
     * time: O(N)
     * Space: O(N)
    **/
    if(iniput.empty()){
        iniput.push(value);
        return;
    }
    stack<int> temp;
    while(!iniput.empty()){
        temp.push(iniput.top());
        iniput.pop();
    }
    iniput.push(value);// this i sthe point where value got inserted at bottem
    while(!temp.empty()){
        iniput.push(temp.top());
        temp.pop();
    }
    return;
}

void ReverseUsingRecursionn(stack<int> &st){
     if(st.empty()){
        return;
     }
     int curr = st.top();
     st.pop();
     ReverseUsingRecursionn(st);
     InsertAtBottom(st,curr);
    return;  
}

int main(int argc, char const *argv[])
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);    
    st.push(5);
    // ReverseStack(st);
    ReverseUsingRecursionn(st);
    while(not st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }


    
    while (not st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
   
    
    return 0;
}
