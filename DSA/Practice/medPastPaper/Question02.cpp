#include<iostream>
using namespace std;

unsigned int CountOnes(unsigned int n) {
    // Base case: if n is 0, there are no 1's in its binary representation
    if (n == 0) {
        return 0;
    }
    // Recursive case: add 1 if the least significant bit is 1, then shift right and recurse
    else if (n==1)
        return 1;
    else
    {
        return CountOnes(n/2)+ CountOnes(n%2);
    }
}

int main() {
    unsigned int number = 28;
    cout << "Number of 1's in binary representation of " << number << " is: " << CountOnes(number) << endl;
    return 0;
}
