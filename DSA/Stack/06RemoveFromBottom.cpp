#include<iostream>
#include<stack>
using namespace std;

void removeAtbottem(stack<int> &st){
    stack<int> temp;
    int n = st.size();
    int count = 0;
    while (st.size() != 1)
    {
        count++;
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.pop();
    while (not temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
    
}

int main(int argc, char const *argv[])
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);    
    st.push(5);

    removeAtbottem(st);
    while (not st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
   
    
    return 0;
}
