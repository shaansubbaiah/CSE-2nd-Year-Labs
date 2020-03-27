#include <iostream>
using namespace std;
int j=2;

void fibonacci(int fib[], int n){
    fib[0]=0;
    fib[1]=1;

    while(fib[j-1] < n){
        fib[j] = fib[j-1] + fib[j-2];
        j++;
    }
}

int minSteps(int a[], int fib[], int n, int j){
    int i=0, step=0, it, l;
    while(i<n){
        for(l=j; l>0; l--){
            it = fib[l]+i;
            if(it<n && a[it]==1){
                step++;
                i=it;
                break;
            }
            if(l == 1){
                i = n;
            }
        }
    }
    if(step == 0)
        return -1;
    else
        return step+1;
}

void main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int a[n],fib[n+2];

    cout<<"Enter array: ";
    for(int i=1;i<=n;i++)
        cin>>a[i];

    fibonacci(fib,n);
    
    cout<<"Minimum Steps= "<<minSteps(a, fib, n, j);
}