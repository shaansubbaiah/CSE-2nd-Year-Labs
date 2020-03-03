#include <iostream>
#include <ctime>
using namespace std;

void insertionSort(int a[], int n){
    for(int i=1; i<n; i++){
        int temp = a[i];
        int j = i;
        while(temp<a[j-1] && j>0){
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
    }
}

int main(){
    int n, i;
    clock_t timeTaken;

    cout<<"Length: ";
    cin>>n;

    int arr[n];
    cout<<"Elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    timeTaken = clock();
    insertionSort(arr, n);
    timeTaken = clock() - timeTaken;

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\nTime Taken: "<<timeTaken<<" cycles.\n";

    return 0;    
}