#include <iostream>
using namespace std;

void bitwiseXor(int n){
    int a[n][n], x=0;
    for (int i=0; i<n/4; i++) { 
        for (int j=0; j<n/4; j++){ 
            for (int k=0; k<4; k++){ 
                for (int l=0; l<4; l++){ 
                    a[i*4+k][j*4+l] = x++;
                }
            } 
        } 
    } 
    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
    }
}

void main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int a[n][n];

    if(n%4 != 0)
        cout<<"N is not a multiple of 4";
    else
        bitwiseXor(n);
}