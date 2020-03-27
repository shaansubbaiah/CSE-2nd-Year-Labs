#include <iostream>
#include <ctime>
using namespace std;

void merge(int a[],int b[],int c[],int p, int q){
    int i=0, j=0, k=0;
    while(i<p && j<q){
        if(b[i]<c[j])
            a[k++] = b[i++];
        else
            a[k++] = c[j++];
    }
    if(i==p){
        for(int l=j; l<q; l++)
            a[k++] = c[l];
    }
    else{
        for(int l=i; l<p; l++)
            a[k++] = b[l];
    }
}

void mergeSort(int a[],int n){
    if(n>1){
        int c[n/2], b[n/2];
        for(int i=0; i<n/2; i++)
            b[i] = a[i];
        for(int i=0, j=n/2; j<n; i++, j++)
            c[i] = a[j];
        mergeSort(b, n/2);
        mergeSort(c, n-n/2);
        merge(a, b, c, n/2, n-n/2);
    }
}

void main(){
    int n;

    cout<<"Enter n:";
    cin>>n;

    int a[n];

    cout<<"Enter elements:";
    for(int i=0; i<n; i++)
        cin>>a[i];

    clock_t start=clock();
    mergeSort(a, n);

    cout<<"Sorted: ";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    cout<<endl<<"Time: "<<(clock()-start)<<"clock cycles";
}