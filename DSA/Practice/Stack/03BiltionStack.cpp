#include<iostream>
#include<stack>
using namespace std;



int main()
{
    stack<int> s;
    // s.pop();
    cout<<s.empty()<<endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    cout<<s.top()<<endl;
    s.push(50);
    s.push(60);
    cout<<s.empty()<<endl;
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    
    
    return 0;
}
