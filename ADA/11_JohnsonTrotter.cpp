#include <iostream>
using namespace std;

int calFact(int n){
    if(n==1)
        return 1;
    else
        return n*calFact(n-1);
}

int getMobile(int a[], char d[], int n){
    int mob=0, prev=0;

    for(int i=1; i<=n; i++){
        if(d[a[i]]=='L' && i!=1){
            if(a[i]>a[i-1] && a[i]>prev){
                mob = a[i];
                prev = mob;
            }
        }
        else if(d[a[i]]=='R' && i!=n){
            if(a[i]>a[i+1] && a[i]>prev){
                mob = a[i];
                prev = mob;
            }
        }
    }

    if(mob==0 && prev==0)
        return 0;
    else 
        return mob;
}

int getPos(int a[], int n, int m){
    for(int i=1; i<=n; i++){
        if(a[i] == m)
            return i;
    }
}

void findPermutation(int a[], char d[], int n){
    int m = getMobile(a, d, n);
    int pos = getPos(a, n, m);
    int temp;

    if(d[a[pos]-1] == 'L'){
        temp = a[pos];
        a[pos] = a[pos-1];
        a[pos-1] = temp; 
    }
    else if(d[a[pos]-1] == 'R'){
        temp = a[pos];
        a[pos] = a[pos+1];
        a[pos+1] = temp;
    }

    for(int i=1; i<=n; i++){
        if(a[i] > m){
            if(d[a[i] -1] == 'L')
                d[a[i] -1] = 'R';
            else 
                d[a[i] -1] = 'L';
        }
    }

    for(int i=1; i<=n; i++){
        cout<<a[i];
    }
    cout<<endl;

}

int main(){
    int a[10], n, mob, prev;
    char dir[10];
    
    cout<<"Number of digits:";
    cin>>n;

    for(int i=1; i<=n; i++){
        a[i] = i;
        dir[i] = 'L';
        cout<<a[i];    
    }
    cout<<endl;

    mob = prev = a[n];

    for(int i=1; i<=calFact(n); i++){
        findPermutation(a, dir, n);
    }

    return 0;
}