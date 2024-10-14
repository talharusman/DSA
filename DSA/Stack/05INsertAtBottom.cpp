#include<iostream>
#include<stack>
using namespace std;

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


void InsertAtBottomUsingRecursion(stack<int> &st,int x){
    /**
     * Time: O(N)
     * Space: O(N)
     **/
    if(st.empty()){
        st.push(x);
        return;
    }
    int curr = st.top();
    st.pop();
    InsertAtBottomUsingRecursion(st,x);
    st.push(curr);
    return;


}




int main(int argc, char const *argv[])
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);// top
    // InsertAtBottom(st,4);
    InsertAtBottomUsingRecursion(st,4);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
