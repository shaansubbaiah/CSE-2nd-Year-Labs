#include <iostream>
using namespace std;

int gcd(int n1, int n2){
    if(n1 == 0)
        return n2;
    else
        return gcd(n2%(n1), n1); 
}

int main(){
    int num1, num2;
    cout<<"Enter 2 numbers:";
    cin>>num1>>num2;
    cout<<"GCD:"<<gcd(num1, num2)<<endl;

    return 0;
}