
#include<iostream>
using namespace std;

int Fibonacci(int n, int res = 1, int prev = 1, int count = 2){
    if(count == n){ 
        return res;
    }
    int temp = res;
    res += prev;
    prev = temp;
    return Fibonacci(n, res, prev, count + 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is " << Fibonacci(n) << endl;

    return 0;
}
