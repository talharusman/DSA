#include<iostream>
#include<stack>
using namespace std;

/**
 * Rule 1: b1 + b2 -> balanced -> if you concatenate 2 strings that are balanced, then the result will be balanced.
 * Rule 2: If we wrap a balanced string with a pair of brackets, the result will be balanced.
 **/
// approch 1
bool isValid(string str) {
    stack<char> st;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        } else {
            // Check if the stack is empty before accessing the top
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if (str[i] == ')' and top != '(') return false;
            if (str[i] == ']' and top != '[') return false;
            if (str[i] == '}' and top != '{') return false;
        }
    }
    return st.empty();
}


// approch 2
// bool isValid( string str){
//     stack<char> st;
//     for(int i = 0; i < str.size();i++){
//         if(str[i] == '(' or str[i] == '{' or str[i] == '[')
//         st.push(str[i]);
//         else {
//             // closing bracket
//             char top = st.top();
//             if(str[i] == ')' and !st.empty() and st.top() == '(')
//                 st.pop();
//             else if(str[i] == ']' and !st.empty() and st.top() == '[')
//                 st.pop();
//             else if(str[i] == '}' and !st.empty() and st.top() == '{')
//                  st.pop();
//             else return false;
            

//         }
//     }
//    return st.empty();
// }




int main(int argc, char const *argv[])
{
    string str = "({[]})";
    if (isValid(str))
        cout << "String is valid" << endl;
    else
        cout << "String is not valid" << endl;

    return 0;
}
