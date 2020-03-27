#include <iostream>
using namespace std;

int IsEven(int n){
    int count=0;
    while(n > 0){
        if(n%2 == 1)
            count++;
        n/=2;
    }
    if(count%2==0)
        return 1;
    else
        return 0;
}

int sum(int evenOne[],int n){
    int sum=0;

    for(int i=0; i<n; i++){
        while(evenOne[i]>0){
            int temp = evenOne[i]%10;
            sum += temp;
            evenOne[i]/=10;
        }
    }
    return sum;
}

void main(){
    int n;
    cout<<"Enter no of elements in array: ";
    cin>>n;

    int a[n], evenOne[n], j=0;

    cout<<"Enter elements in array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(IsEven(a[i])){
            evenOne[j] = a[i];
            j++;
        }
    }
    cout<<"Sum of digits of elements with even 1's in its binary repr. = "<<sum(evenOne, j);
}