#include <iostream>
using namespace std;

void binarySearch(int a[], int h, int l, int k){
    int mid;
    while(l<=h){
        mid = (l+h)/2;
        if(a[mid] == k)
            cout<<"Found at ["<<mid<<"]\n";
        else if(a[mid]>k)
            h = mid-1;
        else
            l = mid+1;        
    }
}

int main(){
    int n, j, l, k, i, p;
    cout<<"Length: ";
    cin>>n;

    int a[n];
    cout<<"Elements: ";
    for(i=0; i<n; i++)
        cin>>a[i];

    // get pivot
    for(i=0; i<n; i++){
        if(a[i] < a[i+1])
            p=i;
    }    

    cout<<"Enter key: ";
    cin>>k;

    if(k<=a[p])
        binarySearch(a, p, 0, k);
    else
        binarySearch(a, n, p, k);

    return 0;    
}