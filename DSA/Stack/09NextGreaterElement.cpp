#include<iostream>
#include<stack>
#include<vector>
using namespace std;
// ------------- APROCH 1 -------------------------------
// vector<int> NextGreaterElement(vector<int> input) {
//     stack<int> s;
//     vector<int> result(input.size(), -1);

//     for (int i = input.size() - 1; i >= 0; i--) {
//         while (!s.empty() && s.top() <= input[i]) {
//             s.pop();
//         }
//         if (!s.empty()) {
//             result[i] = s.top();
//         }
//         s.push(input[i]);
//     }

//     return result;
// }
// ------------- APROCH 2 -------------------------------
vector<int> NextGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> output(n, -1);
    stack<int> s;// indexes 
    s.push(0);
    for (int i = 1; i < n; i++) {
        while(not s.empty() and arr[i] > arr[s.top()]){
            output[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    while(not s.empty()){// not mandarory while loop
        output[s.top()] = -1;
        s.pop();

    }
    return output;
}

int main(int argc, char const *argv[])
{
    vector<int> input = {1, 6, 3, 5, 6, 3, 2, 5, 9, 4, 2, 3};
    vector<int> result = NextGreaterElement(input);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    /*
    The corrected code will now output the correct next greater elements:
    6 9 5 6 9 5 5 9 -1 -1 3 -1

    The code defines a function `NextGreaterElement` that takes a vector of integers as input and returns
    a vector of integers representing the next greater element for each element in the input vector. The
    function uses a stack to keep track of the elements that have not yet found their next greater element
    The function iterates over the input vector from right to left, and for each element, it
    pops elements from the stack that are less than or equal to the current element. If the stack
    is not empty after popping, the top element of the stack is the next greater element for the
    current element. The function then pushes the current element onto the stack.
    The main function demonstrates the usage of the `NextGreaterElement` function by creating a
    vector of integers and passing it to the function. The result is then printed to the console.
    */

    return 0;
}
