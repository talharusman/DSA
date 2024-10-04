#include<iostream>
using namespace std;


int factorialNonTail(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorialNonTail(n - 1); 
    }
}

int factorialTail(int n, int temp = 1) {
    if (n == 0) {
        return temp; 
    } else {
        // cout<<temp<<" "<<endl;
        return factorialTail(n - 1, n * temp); 
    }
}

int main() {
    int num = 5;
    std::cout << "Non-Tail: " << factorialNonTail(num) << std::endl;
    std::cout << "Tail: " << factorialTail(num) << std::endl;
    return 0;
}
