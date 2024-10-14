#include <iostream>
using namespace std;
class testClass{
    public:
    int& test(){
        return n;
    }
    void print(){
        cout<<"n = "<<n<<endl;
    }
    private:
    int n=-10;
};

int main() {
    testClass obj1;
//a is a reference to n. Changes to a also change n in obj1
    int &a=obj1.test();


//a is a separate variable that holds a copy of n's value. Changes to a do not affect n.
    //int a=obj1.test(); 


    a=11;
    cout<<"a = "<<a<<endl;
    obj1.print();

    return 0;
}