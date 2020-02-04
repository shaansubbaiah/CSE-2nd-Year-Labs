#include <iostream>
using namespace std;

int search(int arr[], int n, int x){
    for(int i=0; i<n; i++){
        if (arr[i] == x)
            return 1;
    }
    return -1;    
}

int main(){
    // t-> times, n-> len of array, x-> key
    int t, n, x, j;
    cin>>t;
    while(t>0){
        cin>>n>>x;

        int arr[n];
        for(j=0; j<n; j++)
            cin>>arr[j];

        cout<<search(arr, n, x)<<endl;
        t--;
    }
    return 0;
}